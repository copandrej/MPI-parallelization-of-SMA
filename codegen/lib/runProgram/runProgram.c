/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgram.c
 *
 * Code generation for function 'runProgram'
 *
 */

/* Include files */
#include "runProgram.h"
#include "Get_Functions_SMA.h"
#include "abs.h"
#include "atanh.h"
#include "diff.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "runProgram_data.h"
#include "runProgram_emxutil.h"
#include "runProgram_initialize.h"
#include "runProgram_types.h"
#include "sort.h"
#include "sprintf.h"
#include "sum.h"
#include "tic.h"
#include "toc.h"
#include "unifrnd.h"
#include "coder_posix_time.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
void runProgram(void)
{
  coderTimespec savedTime;
  emxArray_char_T *b_AllFitness;
  emxArray_char_T *b_Destination_fitness;
  double Convergence_curve[500];
  double X[500];
  double weight[500];
  double b_tmp_data[499];
  double tmp_data[499];
  double d_expl_temp[200];
  double e_expl_temp[200];
  double f_expl_temp[200];
  double g_expl_temp[199];
  double h_expl_temp[199];
  double AllFitness[50];
  double y[50];
  double bestPositions[10];
  double b_expl_temp[7];
  double c_expl_temp[7];
  double expl_temp[7];
  double A;
  double Destination_fitness;
  double S;
  double a;
  double bestFitness;
  int tmp_size[2];
  int b_i;
  int i;
  int it;
  int j;
  bool exitg1;
  bool i_expl_temp;
  if (!isInitialized_runProgram) {
    runProgram_initialize();
  }
  /*     %% Initialization */
  /*  Plot frequency (0: never, 1: every iteration, 2: every second iteration,
   * etc.) */
  /*  Number of card (Card 7 and 11 are interesting for us) */
  /*  F00: path finding for mobile robots */
  /*  Maximum iterations without improvement before stopping */
  /*  Convergence threshold */
  /*     %% Setup */
  /*  Initialize map with start and end points */
  /*  Each point has x and y coordinates */
  /*  Load benchmark function parameters */
  /*     %% Run SMA Algorithm */
  tic(&savedTime);
  /*  The following is in large part the original code of the SMA. Only small */
  /*  parts of the code are applied to the path finding problem  */
  /*  */
  /*  Christian Karg and Jonas Jakob Schwämmle */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*  Source codes demo version 1.0 */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*  Main paper (Please refer to the main paper): */
  /*  Slime Mould Algorithm: A New Method for Stochastic Optimization */
  /*  Shimin Li, Huiling Chen, Mingjing Wang, Ali Asghar Heidari, Seyedali
   * Mirjalili */
  /*  Future Generation Computer Systems,2020 */
  /*  DOI: https://doi.org/10.1016/j.future.2020.03.055 */
  /*  https://www.sciencedirect.com/science/article/pii/S0167739X19320941 */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*  Website of SMA: http://www.alimirjalili.com/SMA.html */
  /*  You can find and run the SMA code online at
   * http://www.alimirjalili.com/SMA.html */
  /*  You can find the SMA paper at https://doi.org/10.1016/j.future.2020.03.055
   */
  /*  Please follow the paper for related updates in researchgate:
   * https://www.researchgate.net/publication/340431861_Slime_mould_algorithm_A_new_method_for_stochastic_optimization
   */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*   Main idea: Shimin Li */
  /*   Author and programmer: Shimin Li,Ali Asghar Heidari,Huiling Chen */
  /*   e-Mail: simonlishimin@foxmail.com */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*   Co-author: */
  /*              Huiling Chen(chenhuiling.jlu@gmail.com) */
  /*              Mingjing Wang(wangmingjing.style@gmail.com) */
  /*              Ali Asghar Heidari(aliasghar68@gmail.com, as_heidari@ut.ac.ir)
   */
  /*              Seyedali Mirjalili(ali.mirjalili@gmail.com) */
  /*               */
  /*              Researchgate: Ali Asghar Heidari
   * https://www.researchgate.net/profile/Ali_Asghar_Heidari */
  /*              Researchgate: Seyedali Mirjalili
   * https://www.researchgate.net/profile/Seyedali_Mirjalili */
  /*              Researchgate: Huiling Chen
   * https://www.researchgate.net/profile/Huiling_Chen */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*  _____________________________________________________ */
  /*   Co-author and Advisor: Seyedali Mirjalili */
  /*  */
  /*          e-Mail: ali.mirjalili@gmail.com */
  /*  */
  /*        Homepage: http://www.alimirjalili.com */
  /*  _____________________________________________________ */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Max_iter: maximum iterations, N: populatoin size, Convergence_curve:
   * Convergence curve */
  /*  To run SMA:
   * [Destination_fitness,bestPositions,Convergence_curve]=SMA(N,Max_iter,lb,ub,dim,fobj)
   */
  /*  disp('SMA is now tackling your problem') */
  /*  initialize position */
  memset(&bestPositions[0], 0, 10U * sizeof(double));
  Destination_fitness = rtInf;
  /* change this to -inf for maximization problems */
  /* record the fitness of all slime mold */
  for (j = 0; j < 500; j++) {
    weight[j] = 1.0;
  }
  /* fitness weight of each slime mold */
  /* Initialize the set of random solutions */
  /* ___________________________________________________________________% */
  /*                                                                    % */
  /*   Developed in MATLAB R2018b                                       % */
  /*                                                                    % */
  /*   Author and programmer: Seyedali Mirjalili                        % */
  /*                                                                    % */
  /*          e-Mail: ali.mirjalili@gmail.com                           % */
  /*                  seyedali.mirjalili@griffithuni.edu.au             % */
  /*                                                                    % */
  /*  Source codes demo version 1.0 */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*  Main paper (Please refer to the main paper): */
  /*  Slime Mould Algorithm: A New Method for Stochastic Optimization */
  /*  Shimin Li, Huiling Chen, Mingjing Wang, Ali Asghar Heidari, Seyedali
   * Mirjalili */
  /*  Future Generation Computer Systems,2020 */
  /*  DOI: https://doi.org/10.1016/j.future.2020.03.055 */
  /*  https://www.sciencedirect.com/science/article/pii/S0167739X19320941 */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*  Website of SMA: http://www.alimirjalili.com/SMA.html */
  /*  You can find and run the SMA code online at
   * http://www.alimirjalili.com/SMA.html */
  /*  You can find the SMA paper at https://doi.org/10.1016/j.future.2020.03.055
   */
  /*  Please follow the paper for related updates in researchgate:
   * https://www.researchgate.net/publication/340431861_Slime_mould_algorithm_A_new_method_for_stochastic_optimization
   */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*   Main idea: Shimin Li */
  /*   Author and programmer: Shimin Li,Ali Asghar Heidari,Huiling Chen */
  /*   e-Mail: simonlishimin@foxmail.com */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*   Co-author: */
  /*              Huiling Chen(chenhuiling.jlu@gmail.com) */
  /*              Mingjing Wang(wangmingjing.style@gmail.com) */
  /*              Ali Asghar Heidari(aliasghar68@gmail.com, as_heidari@ut.ac.ir)
   */
  /*              Seyedali Mirjalili(ali.mirjalili@gmail.com) */
  /*               */
  /*              Researchgate: Ali Asghar Heidari
   * https://www.researchgate.net/profile/Ali_Asghar_Heidari */
  /*              Researchgate: Seyedali Mirjalili
   * https://www.researchgate.net/profile/Seyedali_Mirjalili */
  /*              Researchgate: Huiling Chen
   * https://www.researchgate.net/profile/Huiling_Chen */
  /*  ------------------------------------------------------------------------------------------------------------
   */
  /*  _____________________________________________________ */
  /*   Co-author and Advisor: Seyedali Mirjalili */
  /*  */
  /*          e-Mail: ali.mirjalili@gmail.com */
  /*  */
  /*        Homepage: http://www.alimirjalili.com */
  /*  _____________________________________________________ */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  This function initialize the first population of search agents */
  /*  numnber of boundaries */
  /*  If the boundaries of all variables are equal and user enter a signle */
  /*  number for both ub and lb */
  b_rand(X);
  /*  If each variable has a different lb and ub */
  for (j = 0; j <= 498; j += 2) {
    __m128d r;
    r = _mm_loadu_pd(&X[j]);
    _mm_storeu_pd(&X[j], _mm_mul_pd(r, _mm_set1_pd(17.0)));
    _mm_storeu_pd(&Convergence_curve[j], _mm_set1_pd(0.0));
  }
  it = 1;
  /* Number of iterations */
  /*  lower boundary  */
  /*  upper boundary */
  /*  parameter */
  /*  Main loop */
  exitg1 = false;
  while ((!exitg1) && (it <= 500)) {
    double vb[10];
    double a_tmp;
    int iidx[50];
    int X_tmp;
    /* sort the fitness */
    for (i = 0; i < 50; i++) {
      /*  Check if solutions go outside the search space and bring them back */
      /*  Check if the F00 Function is used which requires different */
      /*  inputs */
      for (j = 0; j < 10; j++) {
        b_i = i + 50 * j;
        bestFitness = X[b_i];
        i_expl_temp = (bestFitness > 17.0);
        bestFitness =
            bestFitness * (double)(i_expl_temp + (bestFitness < 0.0) == 0) +
            17.0 * (double)i_expl_temp;
        X[b_i] = bestFitness;
        vb[j] = bestFitness;
      }
      AllFitness[i] = F00(vb, expl_temp, b_expl_temp, c_expl_temp, d_expl_temp,
                          e_expl_temp, f_expl_temp, g_expl_temp, h_expl_temp,
                          &bestFitness, &S, &i_expl_temp);
    }
    memcpy(&y[0], &AllFitness[0], 50U * sizeof(double));
    sort(y, iidx);
    /* Eq.(2.6) */
    bestFitness = y[0];
    S = (y[0] - y[49]) + 2.2204460492503131E-16;
    /*  plus eps to avoid denominator zero */
    /* calculate the fitness weight of each slime mold */
    for (i = 0; i < 50; i++) {
      for (j = 0; j < 10; j++) {
        if (i + 1 <= 25) {
          /* Eq.(2.5) */
          weight[(iidx[i] + 50 * j) - 1] =
              1.0 + c_rand() * log10((bestFitness - y[i]) / S + 1.0);
        } else {
          weight[(iidx[i] + 50 * j) - 1] =
              1.0 - c_rand() * log10((bestFitness - y[i]) / S + 1.0);
        }
      }
    }
    /* update the best fitness value and best position */
    if (y[0] < Destination_fitness) {
      for (j = 0; j < 10; j++) {
        bestPositions[j] = X[(iidx[0] + 50 * j) - 1];
      }
      Destination_fitness = y[0];
    }
    a_tmp = (double)it / 500.0;
    a = -a_tmp + 1.0;
    b_atanh(&a);
    /* Eq.(2.4) */
    /*  Update the Position of search agents */
    for (i = 0; i < 50; i++) {
      if (c_rand() < 0.03) {
        /* Eq.(2.7) */
        bestFitness = c_rand();
        for (j = 0; j < 10; j++) {
          X[i + 50 * j] = 17.0 * bestFitness;
        }
      } else {
        double vc[10];
        bestFitness = tanh(fabs(AllFitness[i] - Destination_fitness));
        /* Eq.(2.2) */
        unifrnd(-a, a, vb);
        /* Eq.(2.3) */
        unifrnd(-(1.0 - a_tmp), 1.0 - a_tmp, vc);
        for (j = 0; j < 10; j++) {
          double B;
          S = c_rand();
          A = c_rand();
          /*  two positions randomly selected from population */
          B = c_rand();
          if (S < bestFitness) {
            /* Eq.(2.1) */
            X_tmp = i + 50 * j;
            X[X_tmp] =
                bestPositions[j] +
                vb[j] * (weight[X_tmp] *
                             X[((int)(floor(A * 50.0) + 1.0) + 50 * j) - 1] -
                         X[((int)(floor(B * 50.0) + 1.0) + 50 * j) - 1]);
          } else {
            X_tmp = i + 50 * j;
            X[X_tmp] *= vc[j];
          }
        }
      }
      /*          if ~isvalid(X(i,:)) %prüfen ob Spline zwischen den Punkte in
       * den Hindernissen liegt */
      /*              X(i,:) = unifrnd(lb,ub,dim); %Wenn Punkte nicht korrekt
       * liegen werden sie zufällig auf dem Gebiet gleichverteilt */
      /*          end */
    }
    Convergence_curve[it - 1] = Destination_fitness;
    if (it > 200) {
      double Convergence_curve_data[500];
      if (it - 100 > it) {
        j = 0;
        b_i = 0;
      } else {
        j = it - 101;
        b_i = it;
      }
      tmp_size[0] = 1;
      X_tmp = b_i - j;
      tmp_size[1] = X_tmp;
      for (b_i = 0; b_i < X_tmp; b_i++) {
        Convergence_curve_data[b_i] = Convergence_curve[j + b_i];
      }
      int b_tmp_size[2];
      b_diff(Convergence_curve_data, tmp_size, tmp_data, b_tmp_size);
      b_abs(tmp_data, b_tmp_size, b_tmp_data, tmp_size);
      if (sum(b_tmp_data, tmp_size) < 0.01) {
        exitg1 = true;
      } else {
        it++;
        /*  Plot Solution */
      }
    } else {
      it++;
      /*  Plot Solution */
    }
  }
  toc(&savedTime);
  /*     %% Visualization */
  /*  Plot convergence history */
  /*  Plot final path */
  A = F00(bestPositions, expl_temp, b_expl_temp, c_expl_temp, d_expl_temp,
          e_expl_temp, f_expl_temp, g_expl_temp, h_expl_temp, &bestFitness, &S,
          &i_expl_temp);
  emxInit_char_T(&b_AllFitness);
  b_sprintf(A, b_AllFitness);
  emxFree_char_T(&b_AllFitness);
  /* display(['The best location of SMA is: ', sprintf('%.2f',bestPositions)]);
   */
  emxInit_char_T(&b_Destination_fitness);
  b_sprintf(Destination_fitness, b_Destination_fitness);
  emxFree_char_T(&b_Destination_fitness);
}

/* End of code generation (runProgram.c) */
