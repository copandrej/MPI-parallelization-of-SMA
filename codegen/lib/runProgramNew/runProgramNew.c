/* Include files */
#include "runProgramNew.h"
#include "CreateModelSMA.h"
#include "Get_Functions_SMA.h"
#include "SMA.h"
#include "abs.h"
#include "atanh.h"
#include "coder_posix_time.h"
#include "diff.h"
#include "mod.h"
#include "pause.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "runProgramNew_data.h"
#include "runProgramNew_emxutil.h"
#include "runProgramNew_initialize.h"
#include "runProgramNew_types.h"
#include "sort.h"
#include "sprintf.h"
#include "sum.h"
#include "tic.h"
#include "toc.h"
#include "unifrnd.h"
#include <emmintrin.h>
#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define DEBUG

/* Function Definitions */
void runProgramNew(int argc, char **argv)
{
  coderTimespec savedTime;
  emxArray_char_T *AllFitness;
  emxArray_char_T *b_Destination_fitness;
  emxArray_real_T *model_robs;
  emxArray_real_T *model_xobs;
  emxArray_real_T *model_yobs;
  double X_data[6400];
  double weight_data[6400];
  double Convergence_curve_data[1000];
  double b_tmp_data[999];
  double tmp_data[999];
  double AllFitness_data[400];
  double b_expl_temp[200];
  double c_expl_temp[200];
  double expl_temp[200];
  double d_expl_temp[199];
  double e_expl_temp[199];
  double bestPositions_data[16];
  double lb_data[16];
  double ub_data[16];
  double vb_data[16];
  double vc_data[16];
  double b_expl_temp_data[10];
  double c_expl_temp_data[10];
  double expl_temp_data[10];
  double Destination_fitness;
  double N;
  double S;
  double T;
  double a;
  double bestFitness;
  double dim;
  double lb;
  double model_xs;
  double model_xt;
  double model_ys;
  double model_yt;
  double ub;
  int iidx_data[400];
  int Convergence_curve_size[2];
  int X_size[2];
  int b_expl_temp_size[2];
  int bestPositions_size[2];
  int c_expl_temp_size[2];
  int expl_temp_size[2];
  int lb_size[2];
  int ub_size[2];
  int AllFitness_size;
  int b_i;
  int b_loop_ub;
  int i;
  int i1;
  int it;
  int loop_ub;
  int loop_ub_tmp;
  int vectorUB;
  int weight_size_idx_0;
  bool exitg1;
  bool f_expl_temp;

  double showPlot = atof(argv[1]);
  double NrCard = atof(argv[2]);

  if (!isInitialized_runProgramNew) {
    runProgramNew_initialize();
  }
  /*     %% Initialization */
  /* showPlot = 0;    % Plot frequency (0: never, 1: every iteration, 2: every
   * second iteration, etc.) */
  /* NrCard = 7;     % Number of card (Card 7 and 11 are interesting for us) */
  /*  F00: path finding for mobile robots */
  /*  Maximum iterations without improvement before stopping */
  /*  Convergence threshold */
  /*     %% Setup */
  /*  Initialize map with start and end points */
  emxInit_real_T(&model_xobs);
  emxInit_real_T(&model_yobs);
  emxInit_real_T(&model_robs);
  model_xs =
      CreateModelSMA(NrCard, model_xobs, model_yobs, model_robs, &model_ys,
                     &model_xt, &model_yt, &bestFitness, &lb, &ub, &S, &T, &N);
  dim = S * 2.0;
  /*     %% Run SMA Algorithm */
  tic(&savedTime);

  // Initialize MPI
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // Calculate number of entities per rank
  int b_loop_ub_all = b_loop_ub;
  int b_loop_ub = b_loop_ub_all / size + ((b_loop_ub_all % size > rank) ? 1 : 0);

  int N_all = N;
  int N = N_all / size + ((N_all % size > rank) ? 1 : 0);

  // alocate mem for local vb_data_all and AllFitness_data_all
  // double vb_data_all[b_loop_ub*16];
  double AllFitness_data_all[b_loop_ub];
  double *X_data_all = X_data;
  double X_data[b_loop_ub*16];

#ifdef DEBUG
  printf("Rank %d of %d\n", rank, size);
#endif

  /*  initialize position */
  bestPositions_size[0] = 1;
  loop_ub_tmp = (int)dim;
  loop_ub = (int)dim;
  bestPositions_size[1] = (int)dim;
  if (loop_ub_tmp - 1 >= 0) {
    memset(&bestPositions_data[0], 0,
           (unsigned int)loop_ub_tmp * sizeof(double));
  }
  Destination_fitness = rtInf;
  /* change this to -inf for maximization problems */
  i = (int)N;
  b_loop_ub = (int)N;
  AllFitness_size = (int)N;
  for (i1 = 0; i1 < i; i1++) {
    AllFitness_data[i1] = rtInf;
  }
  /* record the fitness of all slime mold */
  weight_size_idx_0 = (int)N;
  i = (int)N * (int)dim;
  for (i1 = 0; i1 < i; i1++) {
    weight_data[i1] = 1.0;
  }
  /* fitness weight of each slime mold */
  /* Initialize the set of random solutions */
  /*  This function initialize the first population of search agents */
  /*  numnber of boundaries */
  /*  If the boundaries of all variables are equal and user enter a signle */
  /*  number for both ub and lb */
  b_rand(N, dim, X_data, X_size);
  i = X_size[0] * X_size[1];
  bestFitness = ub - lb;
  it = (i / 2) << 1;
  vectorUB = it - 2;
  for (i1 = 0; i1 <= vectorUB; i1 += 2) {
    __m128d r;
    r = _mm_loadu_pd(&X_data[i1]);
    _mm_storeu_pd(
        &X_data[i1],
        _mm_add_pd(_mm_mul_pd(r, _mm_set1_pd(bestFitness)), _mm_set1_pd(lb)));
  }
  for (i1 = it; i1 < i; i1++) {
    X_data[i1] = X_data[i1] * bestFitness + lb;
  }
  /*  If each variable has a different lb and ub */
  i = (int)T;
  if (i - 1 >= 0) {
    memset(&Convergence_curve_data[0], 0, (unsigned int)i * sizeof(double));
  }
  it = 1;
  /* Number of iterations */
  lb_size[0] = 1;
  lb_size[1] = (int)dim;
  /*  lower boundary  */
  ub_size[0] = 1;
  ub_size[1] = (int)dim;
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    lb_data[i1] = lb;
    ub_data[i1] = ub;
  }
  /*  upper boundary */
  /*  parameter */
  /*  Main loop */
  exitg1 = false;
  // save best position (array) for each iteration and bestFitness (double) in
  // a format of num_iter,x1,y1,x2,y2,...,fitness
  if (rank == 0) {
    FILE *fptr;
    fptr = fopen("bestPositions.csv", "w");
    // header
    fprintf(fptr, "iter,");
    for (i = 0; i < dim / 2; i++) {
      fprintf(fptr, "x%d,y%d,", i, i);
    }
    fprintf(fptr, "fitness\n");
  }

  while ((!exitg1) && (it <= T)) {
    double y_data[400];
    double a_tmp;
    short Rank_data[400];
    bool guard1;
    /* sort the fitness */
    Convergence_curve_size[0] = 1;
    for (b_i = 0; b_i < b_loop_ub; b_i++) {
      bool Flag4lb_data[16];
      bool Flag4ub_data[16];
      /*  Check if solutions go outside the search space and bring them back */
      loop_ub_tmp = X_size[1];
      Convergence_curve_size[1] = X_size[1];
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        bestFitness = X_data[b_i + X_size[0] * i1];
        Flag4ub_data[i1] = (bestFitness > ub_data[i1]);
        Flag4lb_data[i1] = (bestFitness < lb_data[i1]);
      }
      if (X_size[1] == 1) {
        i = ub_size[1];
      } else {
        i = X_size[1];
      }
      if ((ub_size[1] == X_size[1]) && (X_size[1] == ub_size[1]) &&
          (lb_size[1] == X_size[1]) && (i == lb_size[1])) {
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          bool b;
          f_expl_temp = Flag4ub_data[i1];
          b = Flag4lb_data[i1];
          i = b_i + X_size[0] * i1;
          X_data[i] = (X_data[i] * (double)(f_expl_temp + b == 0) +
                       ub_data[i1] * (double)f_expl_temp) +
                      lb_data[i1] * (double)b;
        }
      } else {
        binary_expand_op(X_data, X_size, b_i, Flag4ub_data,
                         Convergence_curve_size, Flag4lb_data,
                         Convergence_curve_size, ub_data, ub_size, lb_data,
                         lb_size);
      }
      /*  Check if the F00 Function is used which requires different */
      /*  inputs */
      loop_ub_tmp = X_size[1];
      Convergence_curve_size[1] = X_size[1];
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        vb_data[i1] = X_data[b_i + X_size[0] * i1];
      }
      bestFitness =
          F00(vb_data, Convergence_curve_size, model_xs, model_ys, model_xt,
              model_yt, model_xobs, model_yobs, model_robs, expl_temp_data,
              expl_temp_size, b_expl_temp_data, b_expl_temp_size,
              c_expl_temp_data, c_expl_temp_size, expl_temp, b_expl_temp,
              c_expl_temp, d_expl_temp, e_expl_temp, &S, &lb, &f_expl_temp);
      if ((unsigned int)b_i + 1U <= (unsigned int)AllFitness_size) {
        AllFitness_data[b_i] = bestFitness;
        /*  Zugriff auf das Array */
      }
    }

    MPI_Allgather(X_data, b_loop_ub*16, MPI_DOUBLE, X_data_all, b_loop_ub*16, MPI_DOUBLE, MPI_COMM_WORLD);
    MPI_ALlgather(AllFitness_data, b_loop_ub, MPI_DOUBLE, AllFitness_data_all, b_loop_ub, MPI_DOUBLE, MPI_COMM_WORLD);


    /* Eq.(2.6) */
    /*  plus eps to avoid denominator zero */
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y_data[i1] = AllFitness_data[i1];
      Rank_data[i1] = 0;
    }
    i = sort(y_data, &b_loop_ub, iidx_data);
    bestFitness = y_data[0];
    S = (y_data[0] - y_data[(int)N - 1]) + 2.2204460492503131E-16;
    for (i1 = 0; i1 < i; i1++) {
      Rank_data[iidx_data[i1] - 1] = (short)(i1 + 1);
    }

    // shift
    int rest = b_loop_ub_all % size;
    int cs = rank * (b_loop_ub_all / size) + (rest > rank ? rank : rest);
    
    /* calculate the fitness weight of each slime mold */
    for (b_i = cs; b_i < b_loop_ub + cs; b_i++) {
      short i2;
      i2 = Rank_data[b_i];
      for (vectorUB = 0; vectorUB < loop_ub; vectorUB++) {
        if (i2 <= N / 2.0) {
          /* Eq.(2.5) */
          weight_data[b_i + weight_size_idx_0 * vectorUB] =
              1.0 + c_rand() * log10((bestFitness - y_data[i2 - 1]) / S + 1.0);
        } else {
          weight_data[b_i + weight_size_idx_0 * vectorUB] =
              1.0 - c_rand() * log10((bestFitness - y_data[i2 - 1]) / S + 1.0);
        }
      }
    }
    /* update the best fitness value and best position */
    if (y_data[0] < Destination_fitness) {
      bestPositions_size[0] = 1;
      i = X_size[1];
      bestPositions_size[1] = X_size[1];
      for (i1 = 0; i1 < i; i1++) {
        bestPositions_data[i1] = X_data[(iidx_data[0] + X_size[0] * i1) - 1];
      }
      Destination_fitness = y_data[0];
    }
    a_tmp = (double)it / T;
    a = -a_tmp + 1.0;
    b_atanh(&a);
    /* Eq.(2.4) */
    /*  Update the Position of search agents */
    for (b_i = 0; b_i < b_loop_ub; b_i++) {
      if (c_rand() < 0.03) {
        /* Eq.(2.7) */
        S = c_rand();
        i = X_size[1];
        for (i1 = 0; i1 < i; i1++) {
          bestFitness = lb_data[i1];
          X_data[b_i + X_size[0] * i1] =
              (ub_data[i1] - bestFitness) * S + bestFitness;
        }
      } else {
        bestFitness = tanh(fabs(AllFitness_data[b_i] - Destination_fitness));
        /* Eq.(2.2) */
        unifrnd(-a, a, dim, vb_data, Convergence_curve_size);
        /* Eq.(2.3) */
        unifrnd(-(1.0 - a_tmp), 1.0 - a_tmp, dim, vc_data, expl_temp_size);
        for (vectorUB = 0; vectorUB < loop_ub; vectorUB++) {
          S = c_rand();
          lb = c_rand();
          lb = floor(lb * ((N_all - 1.0) + 1.0)) + 1.0;
          /*  two positions randomly selected from population */
          ub = c_rand();
          ub = floor(ub * ((N_all - 1.0) + 1.0)) + 1.0;
          if (S < bestFitness) {
            /* Eq.(2.1) */
            i = X_size[0] * vectorUB;
            X_data[b_i + i] =
                bestPositions_data[vectorUB] +
                vb_data[vectorUB] *
                    (weight_data[b_i + weight_size_idx_0 * vectorUB] *
                         X_data_all[((int)lb + i) - 1] -
                     X_data_all[((int)ub + i) - 1]);
          } else {
            i = b_i + X_size[0] * vectorUB;
            X_data[i] *= vc_data[vectorUB];
          }
        }
      }
      /*          if ~isvalid(X(i,:)) %prüfen ob Spline zwischen den Punkte in
       * den Hindernissen liegt */
      /*              X(i,:) = unifrnd(lb,ub,dim); %Wenn Punkte nicht korrekt
       * liegen werden sie zufällig auf dem Gebiet gleichverteilt */
      /*          end */
    }
    Convergence_curve_data[it - 1] = Destination_fitness;
    guard1 = false;
    if (it > 200) {
      double b_Convergence_curve_data[1000];
      if (it - 100 > it) {
        i1 = 0;
        vectorUB = 0;
      } else {
        i1 = it - 101;
        vectorUB = it;
      }
      Convergence_curve_size[0] = 1;
      i = vectorUB - i1;
      Convergence_curve_size[1] = i;
      for (vectorUB = 0; vectorUB < i; vectorUB++) {
        b_Convergence_curve_data[vectorUB] =
            Convergence_curve_data[i1 + vectorUB];
      }
      b_diff(b_Convergence_curve_data, Convergence_curve_size, tmp_data,
             expl_temp_size);
      b_abs(tmp_data, expl_temp_size, b_tmp_data, b_expl_temp_size);
      if (sum(b_tmp_data, b_expl_temp_size) < 0.01) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      it++;
    }
    if (rank == 0) {
      fprintf(fptr, "%d,", it - 1);
      for (int i = 0; i < dim; i++) {
        fprintf(fptr, "%f,", bestPositions_data[i]);
      }
      fprintf(fptr, "%f\n", Destination_fitness);
    }
  }
  MPI_Finalize();
  fclose(fptr);
  toc(&savedTime);
  /*     %% Visualization */
  /*  Plot convergence history */
  /*  Plot final path */
  bestFitness =
      F00(bestPositions_data, bestPositions_size, model_xs, model_ys, model_xt,
          model_yt, model_xobs, model_yobs, model_robs, expl_temp_data,
          expl_temp_size, b_expl_temp_data, b_expl_temp_size, c_expl_temp_data,
          c_expl_temp_size, expl_temp, b_expl_temp, c_expl_temp, d_expl_temp,
          e_expl_temp, &S, &lb, &f_expl_temp);
  emxFree_real_T(&model_robs);
  emxFree_real_T(&model_yobs);
  emxFree_real_T(&model_xobs);
  emxInit_char_T(&AllFitness);
  b_sprintf(bestFitness, AllFitness);
  emxFree_char_T(&AllFitness);
  /* display(['The best location of SMA is: ', sprintf('%.2f',bestPositions)]);
   */
  emxInit_char_T(&b_Destination_fitness);
  b_sprintf(Destination_fitness, b_Destination_fitness);
  emxFree_char_T(&b_Destination_fitness);
}

/* End of code generation (runProgramNew.c) */
