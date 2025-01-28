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

//#define DEBUGBEST

/* Function Definitions */
void runProgramNew(int argc, char **argv)
{
  coderTimespec savedTime;
  emxArray_char_T *AllFitness;
  emxArray_char_T *b_Destination_fitness;
  emxArray_real_T *model_robs;
  emxArray_real_T *model_xobs;
  emxArray_real_T *model_yobs;
  // double X_data_all[6400];
  double weight_data[6400];
  double Convergence_curve_data[1000];
  double b_tmp_data[999];
  double tmp_data[999];
  // double AllFitness_data_all[400];
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
  double ranRankA;
  double ranRankB;
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
  int iidx;
  int index;
  int diff;
  bool exitg1;
  bool f_expl_temp;

  // double showPlot = atof(argv[1]);
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
  int b_loop_ub_all = N;
  b_loop_ub = b_loop_ub_all / size + ((b_loop_ub_all % size > rank) ? 1 : 0);

  // Allocate recv_counts and displs arrays
  int recv_counts_X[size], displs_X[size];
  int recv_counts_Fitness[size], displs_Fitness[size];

  // Calculate recv_counts and displs for X_data_all
  for (int i = 0; i < size; i++) {
      recv_counts_X[i] = (b_loop_ub_all / size + ((b_loop_ub_all % size > i) ? 1 : 0)) * dim;
      if (rank == 0) {
          printf("Rank %d recv_counts_X: %d\n", i, recv_counts_X[i]);
      }
  }

  displs_X[0] = 0;
  for (int i = 1; i < size; i++) {
      displs_X[i] = displs_X[i - 1] + recv_counts_X[i - 1];
      if (rank == 0) {
          printf("Rank %d displs_X: %d\n", i, displs_X[i]);
      }
  }

  // Calculate recv_counts and displs for AllFitness_data_all
  for (int i = 0; i < size; i++) {
      recv_counts_Fitness[i] = b_loop_ub_all / size + ((b_loop_ub_all % size > i) ? 1 : 0);
      if (rank == 0) {
          printf("Rank %d recv_counts_Fitness: %d\n", i, recv_counts_Fitness[i]);
      }
  }

  displs_Fitness[0] = 0;
  for (int i = 1; i < size; i++) {
      displs_Fitness[i] = displs_Fitness[i - 1] + recv_counts_Fitness[i - 1];
      if (rank == 0) {
          printf("Rank %d displs_Fitness: %d\n", i, displs_Fitness[i]);
      }
  }

  // Allocate the receive buffers
  int total_recv_count_X = displs_X[size - 1] + recv_counts_X[size - 1];
  int total_recv_count_Fitness = displs_Fitness[size - 1] + recv_counts_Fitness[size - 1];

  double *X_data_all = (double *)malloc(total_recv_count_X * sizeof(double));
  double *AllFitness_data_all = (double *)malloc(total_recv_count_Fitness * sizeof(double));

  int N_all = N;
  N = N_all / size + ((N_all % size > rank) ? 1 : 0);

  double AllFitness_data[b_loop_ub];
  double X_data[b_loop_ub * (int)dim];

  
  int shifts[size];
  for (int i = 0; i < size; i++) {
    shifts[i] = i * b_loop_ub_all / size + ((i < b_loop_ub_all % size) ? i : b_loop_ub_all % size);
  }
#ifdef DEBUG
  //print shifts
  for (int i = 0; i < size; i++) {
    printf("Rank %d shift: %d\n", i, shifts[i]);
  }
#endif

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
  FILE *fptr;
  fptr = fopen("bestPositions.csv", "w");
  if (rank == 0) {
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
      loop_ub_tmp = X_size[1]; // dim
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
    MPI_Allgatherv(X_data, b_loop_ub * dim, MPI_DOUBLE, X_data_all, recv_counts_X, displs_X, MPI_DOUBLE, MPI_COMM_WORLD);
    MPI_Allgatherv(AllFitness_data, b_loop_ub, MPI_DOUBLE, AllFitness_data_all, recv_counts_Fitness, displs_Fitness, MPI_DOUBLE, MPI_COMM_WORLD);

    // MPI_Allgather(X_data, b_loop_ub*dim, MPI_DOUBLE, X_data_all, b_loop_ub*dim, MPI_DOUBLE, MPI_COMM_WORLD);
    // MPI_Allgather(AllFitness_data, b_loop_ub, MPI_DOUBLE, AllFitness_data_all, b_loop_ub, MPI_DOUBLE, MPI_COMM_WORLD);

    if(it<2){
      //print All_Fitness_data_all and AllFitness_data
      if (rank == 0) {
        printf("Rank %d:\n", rank);
        printf("AllFitness_data_all:\n");
        for (int i = 0; i < b_loop_ub_all; i++) {
          printf("%f, ", AllFitness_data_all[i]);
        }
        printf("\n");
        printf("AllFitness_data:\n");
        for (int i = 0; i < b_loop_ub; i++) {
          printf("%f, ", AllFitness_data[i]);
        }
        printf("\n");
        fflush(stdout);
      }
      MPI_Barrier(MPI_COMM_WORLD);
      // check if AllFitness_data_all and AllFitness_data are the same
      if (rank == 0) {
        printf("Rank %d:\n", rank);
        for (int i = 0; i < b_loop_ub; i++) {
          if (AllFitness_data[i] != AllFitness_data_all[i]) {
            printf("AllFitness_data[%d] = %f, AllFitness_data_all[%d] = %f\n", i, AllFitness_data[i], i, AllFitness_data_all[i]);
          }
        }
        fflush(stdout);
      }
      MPI_Barrier(MPI_COMM_WORLD);

      //print X_data_all and X_data
      if(rank == 0){
        printf("\n");
        printf("Rank %d:\n", rank);
        printf("X_data_all:\n");
        for(int i = 0; i < b_loop_ub_all; i++){
          for(int j = 0; j < dim; j++){
            printf("%f, ", X_data_all[i*(int)dim + j]);
          }
          printf("\n");
        }
        printf("\n");
      }
        printf("\n");
        
        printf("X_data for rank %d:\n", rank);
        for(int i = 0; i < b_loop_ub; i++){
          for(int j = 0; j < dim; j++){
            printf("%f, ", X_data[i*(int)dim + j]);
          }
          printf("\n");
        }
        fflush(stdout);
      

      //check if X_data_all and X_data are the same
      if(rank == 0){
        for(int i = 0; i < b_loop_ub; i++){
          for(int j = 0; j < dim; j++){
            if(X_data[i*(int)dim + j] != X_data_all[i*(int)dim + j]){
              printf("X_data[%d][%d] = %f, X_data_all[%d][%d] = %f\n", i, j, X_data[i*(int)dim + j], i, j, X_data_all[i*(int)dim + j]);
            }
          }
        }
      }
      MPI_Barrier(MPI_COMM_WORLD);
    }
#ifdef DEBUG
    printf("DEBUG all gather: I am still alive on rank %d\n iteration %d\n", rank, it);
    // print X_data_all (array of length) and AllFitness_data_all 
    for (int r = 0; r < size; r++) {
      if (rank == 0) {
        printf("Rank %d:\n", rank);
        fflush(stdout);
      }
      MPI_Barrier(MPI_COMM_WORLD);
    }
#endif

    /* Eq.(2.6) */
    /*  plus eps to avoid denominator zero */
    for (i1 = 0; i1 < b_loop_ub_all; i1++) {
      y_data[i1] = AllFitness_data_all[i1];
      Rank_data[i1] = 0;
    }
    i = sort(y_data, &b_loop_ub_all, iidx_data);
    bestFitness = y_data[0];
    S = (y_data[0] - y_data[(int)N_all - 1]) + 2.2204460492503131E-16;
    for (i1 = 0; i1 < i; i1++) {
      Rank_data[iidx_data[i1] - 1] = (short)(i1 + 1);
    }

    // shift
    int rest = b_loop_ub_all % size;
    int cs = rank * (b_loop_ub_all / size) + (rest > rank ? rank : rest);
    
    /* calculate the fitness weight of each slime mold */
    for (b_i = 0; b_i < b_loop_ub + 0; b_i++) {
      short i2;
      i2 = Rank_data[b_i+cs];
      for (vectorUB = 0; vectorUB < loop_ub; vectorUB++) {
        if (i2 <= N_all / 2.0) {
          /* Eq.(2.5) */
          weight_data[b_i + weight_size_idx_0 * vectorUB] =
              1.0 + c_rand() * log10((bestFitness - y_data[i2 - 1]) / S + 1.0);
        } else {
          weight_data[b_i + weight_size_idx_0 * vectorUB] =
              1.0 - c_rand() * log10((bestFitness - y_data[i2 - 1]) / S + 1.0);
        }
      }
    }

    //print weight_data
    if (it < 5) {
      if (rank == 0) {
        printf("Weight Data Rank %d:\n", rank);
        for (int i = 0; i < b_loop_ub; i++) {
          for (int j = 0; j < dim; j++) {
            printf("%f, ", weight_data[i + weight_size_idx_0 * j]);
          }
          printf("\n");
        }
        fflush(stdout);
      }
      MPI_Barrier(MPI_COMM_WORLD);
    }

    //print y data
    if (it < 5) {
      if (rank == 0) {
        printf("Y-Data Rank %d:\n", rank);
        for (int i = 0; i < b_loop_ub_all; i++) {
          printf("%f, ", y_data[i]);
        }
        printf("\n");
        fflush(stdout);
      }
      MPI_Barrier(MPI_COMM_WORLD);
    }
    
    /* update the best fitness value and best position */
    if (y_data[0] < Destination_fitness) {
      bestPositions_size[0] = 1;
      i = X_size[1];
      bestPositions_size[1] = X_size[1];

      // find the index of the best fitness value
      iidx = iidx_data[0];
      index = -1;
      diff = 0;

      // Search for the largest element less than or equal to iidx
      for (int i = 0; i < size; i++) {
          if (shifts[i] < iidx) {
              index = i;
          } else {
              break; // Since the array is sorted in ascending order, we can break the loop
          }
      }
      // Calculate the difference
      if (index != -1) {
          diff = iidx - shifts[index];
#ifdef DEBUGBEST
          printf("Iteration: %d, Rank: %d, Shift: %d, New Index: %d, Old Index: %d\n", it, index, shifts[index], diff, iidx);
#endif
      } else {
          printf("No element less than or equal to %d found\n", iidx);
      }

      for (i1 = 0; i1 < i; i1++) {
        // bestPositions_data[i1] = X_data_all[(iidx_data[0] + X_size[0] * i1) - 1];
        bestPositions_data[i1] = X_data_all[(diff + index*b_loop_ub*(int)dim + X_size[0] * i1) - 1];
        //print curren index seperated by comma at the end
#ifdef DEBUGBEST
        printf("%d,", (diff + index*b_loop_ub*(int)dim + X_size[0] * i1) - 1);
#endif
      }
#ifdef DEBUGBEST
      printf("\n");
      for (i1 = 0; i1 < i; i1++) {
        printf("%d,", (iidx_data[0] + X_size[0] * i1) - 1);
      }
      printf("\n \n");
#endif
      Destination_fitness = y_data[0];
    }
    a_tmp = (double)it / T;
    a = -a_tmp + 1.0;
    b_atanh(&a);
#ifdef DEBUG
    printf("DEBUG Eq 2.4: I am still alive on rank %d\n iteration %d\n", rank, it);
    fflush(stdout);
#endif
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
        bestFitness = tanh(fabs(AllFitness_data_all[b_i+cs] - Destination_fitness));
        /* Eq.(2.2) */
        unifrnd(-a, a, dim, vb_data, Convergence_curve_size);
        /* Eq.(2.3) */
        unifrnd(-(1.0 - a_tmp), 1.0 - a_tmp, dim, vc_data, expl_temp_size);
        for (vectorUB = 0; vectorUB < loop_ub; vectorUB++) { //loop_ub = dim
          S = c_rand();
          lb = c_rand();
          lb = floor(lb * ((N - 1.0) + 1.0)) + 1.0;
          /*  two positions randomly selected from population */
          ub = c_rand();
          ub = floor(ub * ((N - 1.0) + 1.0)) + 1.0;

          // randomly choosing the rank
          ranRankA = c_rand();
          #ifdef DEBUG
          printf("Random Rank: %d, ranRankA: %f\n", rank, ranRankA);
          #endif
          ranRankA = floor(ranRankA *size);
          ranRankA = shifts[(int)ranRankA]*dim;
          #ifdef DEBUG
          printf("Random Rank: %d, ranRankA: %d\n", rank, (int)ranRankA);
          #endif
          ranRankB = c_rand();
          
          ranRankB = floor(ranRankB *size);
          ranRankB = shifts[(int)ranRankB]*dim;

          if (S < bestFitness) {
            /* Eq.(2.1) */
            i = X_size[0] * vectorUB;
            //print i for the first usage
            X_data[b_i + i] =
                bestPositions_data[vectorUB] +
                vb_data[vectorUB] *
                    (weight_data[b_i + weight_size_idx_0 * vectorUB] *
                         X_data_all[((int)lb + i) - 1+ (int) ranRankA] -
                     X_data_all[((int)ub + i) - 1 + (int) ranRankB]); //unsure, maybe change i for X_data_all
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
  fclose(fptr);

  MPI_Finalize();
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
