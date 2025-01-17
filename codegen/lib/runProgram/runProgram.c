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
#include "SMA.h"
#include "abs.h"
#include "atanh.h"
#include "diff.h"
#include "mod.h"
#include "pause.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "runProgram_data.h"
#include "runProgram_emxutil.h"
#include "runProgram_initialize.h"
#include "runProgram_internal_types.h"
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
void runProgram(double showPlot, double NrCard)
{
  static const double dv[45] = {
      3.0,  3.5,  4.0,  4.5,  5.0,  5.5,  6.0,  6.5,  7.0, 8.0, 8.5, 9.0,
      9.5,  10.0, 10.5, 11.0, 11.5, 12.0, 1.0,  1.5,  2.0, 2.5, 3.0, 3.4,
      4.0,  4.5,  5.0,  6.0,  6.5,  7.0,  7.5,  8.0,  8.5, 9.0, 9.5, 10.0,
      10.0, 10.5, 11.0, 11.5, 12.0, 10.0, 10.5, 11.0, 11.5};
  static const double dv1[40] = {
      3.0, 4.5, 6.0, 7.5, 9.0,  10.5, 12.0, 13.5, 15.0, 3.0,
      4.5, 6.0, 7.5, 9.0, 10.5, 12.0, 13.5, 15.0, 3.0,  4.5,
      6.0, 7.5, 3.0, 3.0, 3.0,  3.0,  3.0,  3.0,  8.0,  8.0,
      8.0, 8.0, 8.0, 8.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0};
  static const double dv2[40] = {
      3.0,  3.0,  3.0,  3.0,  3.0,  3.0,  3.0,  3.0,  3.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 8.0, 8.0,
      8.0,  8.0,  3.0,  4.5,  6.0,  7.5,  9.0,  10.5, 3.0, 4.5,
      6.0,  7.5,  9.0,  10.5, 3.0,  4.5,  6.0,  7.5,  9.0, 10.5};
  static const double b[15] = {1.0,
                               0.91952777255145068,
                               0.69106264898686476,
                               0.35137482408134274,
                               -0.044864830350514862,
                               -0.43388373911755806,
                               -0.75307146600361086,
                               -0.95105651629515353,
                               -0.99597429399523907,
                               -0.88059553185673811,
                               -0.62348980185873371,
                               -0.26603684556667528,
                               0.1342332658176553,
                               0.512899277405906,
                               0.80901699437494734};
  static const double b_b[15] = {0.0,
                                 0.39302503165392361,
                                 0.72279486382739155,
                                 0.9362348706397372,
                                 0.9989930665413147,
                                 0.90096886790241915,
                                 0.6579387259397127,
                                 0.30901699437494751,
                                 -0.089639308903433371,
                                 -0.47386866247299853,
                                 -0.78183148246802969,
                                 -0.96396286069585324,
                                 -0.99094976176793481,
                                 -0.85844879360186621,
                                 -0.58778525229247336};
  static const double d_varargin_2[12] = {5.0,
                                          6.3636363636363633,
                                          7.7272727272727266,
                                          9.09090909090909,
                                          10.454545454545453,
                                          11.818181818181817,
                                          13.181818181818182,
                                          14.545454545454545,
                                          15.909090909090908,
                                          17.272727272727273,
                                          18.636363636363633,
                                          20.0};
  static const double e_varargin_2[8] = {5.0,
                                         7.8571428571428577,
                                         10.714285714285715,
                                         13.571428571428571,
                                         16.428571428571431,
                                         19.285714285714285,
                                         22.142857142857142,
                                         25.0};
  static const signed char iv[45] = {
      4,  4,  4,  4,  4,  4,  4,  4,  4,  6,  6,  6,  6,  6,  6,
      6,  6,  6,  8,  8,  8,  8,  8,  8,  8,  8,  8,  10, 10, 10,
      10, 10, 10, 10, 10, 10, 12, 12, 12, 12, 12, 14, 14, 14, 14};
  static const signed char c_varargin_2[11] = {5,  9, 13, 17, 22, 22,
                                               22, 5, 9,  13, 17};
  static const signed char varargin_2[11] = {2,  2,  2,  2,  8, 13,
                                             18, 23, 23, 23, 23};
  static const signed char b_varargin_2[8] = {3, 3, 3, 15, 22, 27, 27, 27};
  static const signed char f_varargin_2[8] = {8, 16, 24, 27, 27, 8, 16, 24};
  b_struct_T a__1;
  coderTimespec savedTime;
  emxArray_char_T *AllFitness;
  emxArray_char_T *b_Destination_fitness;
  emxArray_real_T *b_xobs;
  emxArray_real_T *model_robs;
  emxArray_real_T *xobs;
  emxArray_real_T *yobs;
  double X_data[6400];
  double weight_data[6400];
  double Convergence_curve_data[1000];
  double b_tmp_data[999];
  double tmp_data[999];
  double AllFitness_data[400];
  double y_data[400];
  double bestPositions_data[16];
  double vb_data[16];
  double vc_data[16];
  double Destination_fitness;
  double a;
  double bestFitness;
  double *model_robs_data;
  double *xobs_data;
  double *yobs_data;
  int iidx_data[400];
  int X_size[2];
  int bestPositions_size[2];
  int tmp_size[2];
  int ub_size[2];
  int N;
  int T;
  int dim;
  int i;
  int it;
  int lb;
  int loop_ub;
  int loop_ub_tmp;
  int model_xs;
  int model_xt;
  int model_ys;
  int model_yt;
  int r;
  int ub;
  signed char lb_data[16];
  signed char ub_data[16];
  bool exitg1;
  if (!isInitialized_runProgram) {
    runProgram_initialize();
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
  /*  */
  /*  Copyright (c) 2015, Yarpiz (www.yarpiz.com) */
  /*  All rights reserved. Please read the "license.txt" for license terms. */
  /*  */
  /*  Project Code: YPAP115 */
  /*  Project Title: Path Planning using PSO in MATLAB */
  /*  Publisher: Yarpiz (www.yarpiz.com) */
  /*   */
  /*  Developer: S. Mostapha Kalami Heris (Member of Yarpiz Team) */
  /*   */
  /*  Contact Info: sm.kalami@gmail.com, info@yarpiz.com */
  /*  */
  /*  Source */
  emxInit_real_T(&xobs);
  xobs_data = xobs->data;
  xobs->size[0] = 0;
  xobs->size[1] = 0;
  emxInit_real_T(&yobs);
  yobs_data = yobs->data;
  yobs->size[0] = 0;
  yobs->size[1] = 0;
  /*  Target (Destination) */
  emxInit_real_T(&model_robs);
  emxInit_real_T(&b_xobs);
  switch ((int)NrCard) {
  case 7:
    /*  Check lengths of generated arrays */
    /*  Increased spacing */
    /*  Reduced number of obstacles due to larger size */
    model_xs = 2;
    model_ys = 2;
    i = xobs->size[0] * xobs->size[1];
    xobs->size[0] = 1;
    xobs->size[1] = 40;
    emxEnsureCapacity_real_T(xobs, i);
    xobs_data = xobs->data;
    /*  Adjusted spacing */
    i = yobs->size[0] * yobs->size[1];
    yobs->size[0] = 1;
    yobs->size[1] = 40;
    emxEnsureCapacity_real_T(yobs, i);
    yobs_data = yobs->data;
    i = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = 40;
    emxEnsureCapacity_real_T(model_robs, i);
    model_robs_data = model_robs->data;
    for (i = 0; i < 40; i++) {
      xobs_data[i] = dv1[i];
      yobs_data[i] = dv2[i];
      model_robs_data[i] = 0.8;
    }
    /*  Doubled obstacle size */
    model_xt = 14;
    model_yt = 14;
    lb = 0;
    ub = 17;
    r = 5;
    T = 500;
    N = 50;
    break;
  case 9:
    /*  Reduced number of obstacles */
    model_xs = 1;
    model_ys = 1;
    /*  Reduced number of circles */
    for (ub = 0; ub < 4; ub++) {
      r = (ub + 1) << 2;
      /*  Increased spacing between circles */
      if ((xobs->size[0] != 0) && (xobs->size[1] != 0)) {
        loop_ub = xobs->size[1];
      } else {
        loop_ub = 0;
      }
      i = b_xobs->size[0] * b_xobs->size[1];
      b_xobs->size[0] = 1;
      b_xobs->size[1] = loop_ub + 15;
      emxEnsureCapacity_real_T(b_xobs, i);
      model_robs_data = b_xobs->data;
      for (i = 0; i < loop_ub; i++) {
        model_robs_data[b_xobs->size[0] * i] = xobs_data[i];
      }
      for (i = 0; i < 15; i++) {
        model_robs_data[b_xobs->size[0] * (i + loop_ub)] =
            (double)r * b[i] + 12.0;
      }
      i = xobs->size[0] * xobs->size[1];
      xobs->size[0] = 1;
      it = b_xobs->size[1];
      xobs->size[1] = b_xobs->size[1];
      emxEnsureCapacity_real_T(xobs, i);
      xobs_data = xobs->data;
      for (i = 0; i < it; i++) {
        xobs_data[i] = model_robs_data[i];
      }
      i = b_xobs->size[0] * b_xobs->size[1];
      b_xobs->size[0] = 1;
      b_xobs->size[1] = loop_ub + 15;
      emxEnsureCapacity_real_T(b_xobs, i);
      model_robs_data = b_xobs->data;
      for (i = 0; i < loop_ub; i++) {
        model_robs_data[b_xobs->size[0] * i] = yobs_data[i];
      }
      for (i = 0; i < 15; i++) {
        model_robs_data[b_xobs->size[0] * (i + loop_ub)] =
            (double)r * b_b[i] + 12.0;
      }
      i = yobs->size[0] * yobs->size[1];
      yobs->size[0] = 1;
      yobs->size[1] = it;
      emxEnsureCapacity_real_T(yobs, i);
      yobs_data = yobs->data;
      for (i = 0; i < it; i++) {
        yobs_data[i] = model_robs_data[i];
      }
    }
    i = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = 60;
    emxEnsureCapacity_real_T(model_robs, i);
    model_robs_data = model_robs->data;
    for (i = 0; i < 60; i++) {
      model_robs_data[i] = 0.75;
    }
    /*  More than doubled obstacle size */
    model_xt = 23;
    model_yt = 23;
    lb = 0;
    ub = 24;
    r = 8;
    T = 600;
    N = 150;
    break;
  case 10:
    /*  Warehouse layout with storage racks, main aisles and workstations */
    /*  Start and goal positions (near entrance and shipping area) */
    model_xs = 2;
    model_ys = 2;
    model_xt = 22;
    model_yt = 22;
    /*  Generate storage rack rows (6 double-sided rack rows) */
    /*  Space between rack rows for aisles */
    /*  Create double-sided storage racks */
    for (lb = 0; lb < 6; lb++) {
      r = (lb << 2) + 5;
      /*  First side of rack */
      /*  Second side of rack */
      if ((xobs->size[0] != 0) && (xobs->size[1] != 0)) {
        loop_ub = xobs->size[1];
      } else {
        loop_ub = 0;
      }
      i = b_xobs->size[0] * b_xobs->size[1];
      b_xobs->size[0] = 1;
      b_xobs->size[1] = loop_ub + 24;
      emxEnsureCapacity_real_T(b_xobs, i);
      model_robs_data = b_xobs->data;
      for (i = 0; i < loop_ub; i++) {
        model_robs_data[b_xobs->size[0] * i] = xobs_data[i];
      }
      for (i = 0; i < 12; i++) {
        model_robs_data[b_xobs->size[0] * (i + loop_ub)] = r;
      }
      for (i = 0; i < 12; i++) {
        model_robs_data[b_xobs->size[0] * ((i + loop_ub) + 12)] =
            (double)r + 1.0;
      }
      i = xobs->size[0] * xobs->size[1];
      xobs->size[0] = 1;
      it = b_xobs->size[1];
      xobs->size[1] = b_xobs->size[1];
      emxEnsureCapacity_real_T(xobs, i);
      xobs_data = xobs->data;
      for (i = 0; i < it; i++) {
        xobs_data[i] = model_robs_data[i];
      }
      i = b_xobs->size[0] * b_xobs->size[1];
      b_xobs->size[0] = 1;
      b_xobs->size[1] = loop_ub + 24;
      emxEnsureCapacity_real_T(b_xobs, i);
      model_robs_data = b_xobs->data;
      for (i = 0; i < loop_ub; i++) {
        model_robs_data[b_xobs->size[0] * i] = yobs_data[i];
      }
      for (i = 0; i < 12; i++) {
        model_robs_data[b_xobs->size[0] * (i + loop_ub)] = d_varargin_2[i];
      }
      for (i = 0; i < 12; i++) {
        model_robs_data[b_xobs->size[0] * ((i + loop_ub) + 12)] =
            d_varargin_2[i];
      }
      i = yobs->size[0] * yobs->size[1];
      yobs->size[0] = 1;
      yobs->size[1] = it;
      emxEnsureCapacity_real_T(yobs, i);
      yobs_data = yobs->data;
      for (i = 0; i < it; i++) {
        yobs_data[i] = model_robs_data[i];
      }
    }
    /*  Add workstations along the walls */
    /*  Combine all obstacles */
    if ((xobs->size[0] != 0) && (xobs->size[1] != 0)) {
      r = xobs->size[1];
    } else {
      r = 0;
    }
    i = b_xobs->size[0] * b_xobs->size[1];
    b_xobs->size[0] = 1;
    b_xobs->size[1] = r + 11;
    emxEnsureCapacity_real_T(b_xobs, i);
    model_robs_data = b_xobs->data;
    for (i = 0; i < r; i++) {
      model_robs_data[b_xobs->size[0] * i] = xobs_data[i];
    }
    for (i = 0; i < 11; i++) {
      model_robs_data[b_xobs->size[0] * (i + r)] = varargin_2[i];
    }
    i = xobs->size[0] * xobs->size[1];
    xobs->size[0] = 1;
    loop_ub = b_xobs->size[1];
    xobs->size[1] = b_xobs->size[1];
    emxEnsureCapacity_real_T(xobs, i);
    xobs_data = xobs->data;
    for (i = 0; i < loop_ub; i++) {
      xobs_data[i] = model_robs_data[i];
    }
    i = b_xobs->size[0] * b_xobs->size[1];
    b_xobs->size[0] = 1;
    b_xobs->size[1] = r + 11;
    emxEnsureCapacity_real_T(b_xobs, i);
    model_robs_data = b_xobs->data;
    for (i = 0; i < r; i++) {
      model_robs_data[b_xobs->size[0] * i] = yobs_data[i];
    }
    for (i = 0; i < 11; i++) {
      model_robs_data[b_xobs->size[0] * (i + r)] = c_varargin_2[i];
    }
    i = yobs->size[0] * yobs->size[1];
    yobs->size[0] = 1;
    yobs->size[1] = loop_ub;
    emxEnsureCapacity_real_T(yobs, i);
    yobs_data = yobs->data;
    for (i = 0; i < loop_ub; i++) {
      yobs_data[i] = model_robs_data[i];
    }
    /*  Set parameters */
    /*  Total number of obstacles */
    i = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = loop_ub;
    emxEnsureCapacity_real_T(model_robs, i);
    model_robs_data = model_robs->data;
    for (i = 0; i < loop_ub; i++) {
      model_robs_data[i] = 0.9;
    }
    /*  Uniform obstacle size */
    /*  Set boundaries */
    lb = 0;
    ub = 25;
    /*  Algorithm parameters */
    r = 6;
    /*  More waypoints for complex navigation */
    T = 600;
    /*  High number of iterations for better path finding */
    N = 300;
    /*  Sufficient number of search agents */
    break;
  case 11:
    /*  Warehouse layout with storage racks, main aisles and workstations */
    /*  Start and goal positions (forcing path through the warehouse) */
    model_xs = 5;
    model_ys = 3;
    model_xt = 27;
    model_yt = 27;
    /*  Generate storage rack rows (6 double-sided rack rows) */
    /*  Reduced number of obstacles per row */
    /*  Increased space between rack rows for aisles */
    /*  Create double-sided storage racks with larger gaps */
    for (lb = 0; lb < 6; lb++) {
      r = lb * 6 + 5;
      /*  First side of rack */
      /*  Second side of rack (increased separation within rack) */
      if ((xobs->size[0] != 0) && (xobs->size[1] != 0)) {
        loop_ub = xobs->size[1];
      } else {
        loop_ub = 0;
      }
      i = b_xobs->size[0] * b_xobs->size[1];
      b_xobs->size[0] = 1;
      b_xobs->size[1] = loop_ub + 16;
      emxEnsureCapacity_real_T(b_xobs, i);
      model_robs_data = b_xobs->data;
      for (i = 0; i < loop_ub; i++) {
        model_robs_data[b_xobs->size[0] * i] = xobs_data[i];
      }
      for (i = 0; i < 8; i++) {
        model_robs_data[b_xobs->size[0] * (i + loop_ub)] = r;
      }
      for (i = 0; i < 8; i++) {
        model_robs_data[b_xobs->size[0] * ((i + loop_ub) + 8)] =
            (double)r + 1.5;
      }
      i = xobs->size[0] * xobs->size[1];
      xobs->size[0] = 1;
      it = b_xobs->size[1];
      xobs->size[1] = b_xobs->size[1];
      emxEnsureCapacity_real_T(xobs, i);
      xobs_data = xobs->data;
      for (i = 0; i < it; i++) {
        xobs_data[i] = model_robs_data[i];
      }
      i = b_xobs->size[0] * b_xobs->size[1];
      b_xobs->size[0] = 1;
      b_xobs->size[1] = loop_ub + 16;
      emxEnsureCapacity_real_T(b_xobs, i);
      model_robs_data = b_xobs->data;
      for (i = 0; i < loop_ub; i++) {
        model_robs_data[b_xobs->size[0] * i] = yobs_data[i];
      }
      for (i = 0; i < 8; i++) {
        model_robs_data[b_xobs->size[0] * (i + loop_ub)] = e_varargin_2[i];
      }
      for (i = 0; i < 8; i++) {
        model_robs_data[b_xobs->size[0] * ((i + loop_ub) + 8)] =
            e_varargin_2[i];
      }
      i = yobs->size[0] * yobs->size[1];
      yobs->size[0] = 1;
      yobs->size[1] = it;
      emxEnsureCapacity_real_T(yobs, i);
      yobs_data = yobs->data;
      for (i = 0; i < it; i++) {
        yobs_data[i] = model_robs_data[i];
      }
    }
    /*  Add blocking walls to force internal routing */
    /*  Top wall */
    /*  Bottom wall */
    /*  Left wall */
    /*  Right wall */
    /*  Add workstations with adjusted positions */
    /*  Combine all obstacles */
    if ((xobs->size[0] != 0) && (xobs->size[1] != 0)) {
      r = xobs->size[1];
    } else {
      r = 0;
    }
    i = b_xobs->size[0] * b_xobs->size[1];
    b_xobs->size[0] = 1;
    b_xobs->size[1] = r + 48;
    emxEnsureCapacity_real_T(b_xobs, i);
    model_robs_data = b_xobs->data;
    for (i = 0; i < r; i++) {
      model_robs_data[b_xobs->size[0] * i] = xobs_data[i];
    }
    for (i = 0; i < 8; i++) {
      model_robs_data[b_xobs->size[0] * (i + r)] = b_varargin_2[i];
    }
    for (i = 0; i < 10; i++) {
      bestFitness = 3.3333333333333335 * (double)i;
      it = i + r;
      model_robs_data[b_xobs->size[0] * (it + 8)] = bestFitness;
      model_robs_data[b_xobs->size[0] * (it + 18)] = bestFitness;
      model_robs_data[b_xobs->size[0] * (it + 28)] = 0.0;
      model_robs_data[b_xobs->size[0] * (it + 38)] = 30.0;
    }
    i = xobs->size[0] * xobs->size[1];
    xobs->size[0] = 1;
    loop_ub = b_xobs->size[1];
    xobs->size[1] = b_xobs->size[1];
    emxEnsureCapacity_real_T(xobs, i);
    xobs_data = xobs->data;
    for (i = 0; i < loop_ub; i++) {
      xobs_data[i] = model_robs_data[i];
    }
    i = b_xobs->size[0] * b_xobs->size[1];
    b_xobs->size[0] = 1;
    b_xobs->size[1] = r + 48;
    emxEnsureCapacity_real_T(b_xobs, i);
    model_robs_data = b_xobs->data;
    for (i = 0; i < r; i++) {
      model_robs_data[b_xobs->size[0] * i] = yobs_data[i];
    }
    for (i = 0; i < 8; i++) {
      model_robs_data[b_xobs->size[0] * (i + r)] = f_varargin_2[i];
    }
    for (i = 0; i < 10; i++) {
      it = i + r;
      model_robs_data[b_xobs->size[0] * (it + 8)] = 30.0;
      model_robs_data[b_xobs->size[0] * (it + 18)] = 0.0;
      bestFitness = 3.3333333333333335 * (double)i;
      model_robs_data[b_xobs->size[0] * (it + 28)] = bestFitness;
      model_robs_data[b_xobs->size[0] * (it + 38)] = bestFitness;
    }
    i = yobs->size[0] * yobs->size[1];
    yobs->size[0] = 1;
    yobs->size[1] = loop_ub;
    emxEnsureCapacity_real_T(yobs, i);
    yobs_data = yobs->data;
    for (i = 0; i < loop_ub; i++) {
      yobs_data[i] = model_robs_data[i];
    }
    /*  Set parameters */
    /*  Total number of obstacles */
    i = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = r + 48;
    emxEnsureCapacity_real_T(model_robs, i);
    model_robs_data = model_robs->data;
    for (i = 0; i < loop_ub; i++) {
      model_robs_data[i] = 1.0;
    }
    /*  Slightly larger obstacles */
    /*  Set tight boundaries to prevent external routing */
    lb = 0;
    ub = 30;
    /*  Algorithm parameters */
    r = 6;
    /*  More waypoints for complex navigation */
    T = 1000;
    /*  High number of iterations for better path finding */
    N = 400;
    /*  Sufficient number of search agents */
    break;
  default:
    model_xs = 3;
    model_ys = 3;
    i = xobs->size[0] * xobs->size[1];
    xobs->size[0] = 1;
    xobs->size[1] = 45;
    emxEnsureCapacity_real_T(xobs, i);
    xobs_data = xobs->data;
    i = yobs->size[0] * yobs->size[1];
    yobs->size[0] = 1;
    yobs->size[1] = 45;
    emxEnsureCapacity_real_T(yobs, i);
    yobs_data = yobs->data;
    i = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = 45;
    emxEnsureCapacity_real_T(model_robs, i);
    model_robs_data = model_robs->data;
    for (i = 0; i < 45; i++) {
      xobs_data[i] = iv[i];
      yobs_data[i] = dv[i];
      model_robs_data[i] = 0.4;
    }
    model_xt = 15;
    model_yt = 15;
    lb = -1;
    ub = 19;
    r = 4;
    T = 400;
    /*  Maximum number of iterations */
    N = 30;
    /*  Number of search agents */
    break;
  }
  emxFree_real_T(&b_xobs);
  dim = r << 1;
  /*  Each point has x and y coordinates */
  /*  Load benchmark function parameters */
  /*  ------------------------------------------------------------------------------
   */
  /*   Please refer to the main paper: */
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
  /*  ------------------------------------------------------------------------------
   */
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
  bestPositions_size[0] = 1;
  bestPositions_size[1] = dim;
  memset(&bestPositions_data[0], 0, (unsigned int)dim * sizeof(double));
  Destination_fitness = rtInf;
  /* change this to -inf for maximization problems */
  for (i = 0; i < N; i++) {
    AllFitness_data[i] = rtInf;
  }
  /* record the fitness of all slime mold */
  loop_ub_tmp = N * dim;
  for (i = 0; i < loop_ub_tmp; i++) {
    weight_data[i] = 1.0;
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
  b_rand(N, dim, X_data, X_size);
  loop_ub_tmp = X_size[0] * X_size[1];
  r = ub - lb;
  it = (loop_ub_tmp / 2) << 1;
  loop_ub = it - 2;
  for (i = 0; i <= loop_ub; i += 2) {
    __m128d b_r;
    b_r = _mm_loadu_pd(&X_data[i]);
    _mm_storeu_pd(&X_data[i],
                  _mm_add_pd(_mm_mul_pd(b_r, _mm_set1_pd(r)), _mm_set1_pd(lb)));
  }
  for (i = it; i < loop_ub_tmp; i++) {
    X_data[i] = X_data[i] * (double)r + (double)lb;
  }
  /*  If each variable has a different lb and ub */
  memset(&Convergence_curve_data[0], 0, (unsigned int)T * sizeof(double));
  it = 1;
  /* Number of iterations */
  ub_size[1] = dim;
  /*  lower boundary  */
  ub_size[0] = 1;
  for (i = 0; i < dim; i++) {
    lb_data[i] = (signed char)lb;
    ub_data[i] = (signed char)ub;
  }
  /*  upper boundary */
  /*  parameter */
  /*  Main loop */
  exitg1 = false;
  while ((!exitg1) && (it <= T)) {
    double S;
    double a_tmp;
    int vc_size[2];
    bool guard1;
    /* sort the fitness */
    tmp_size[0] = 1;
    for (ub = 0; ub < N; ub++) {
      bool Flag4lb_data[16];
      bool Flag4ub_data[16];
      /*  Check if solutions go outside the search space and bring them back */
      loop_ub_tmp = X_size[1];
      tmp_size[1] = X_size[1];
      for (i = 0; i < loop_ub_tmp; i++) {
        bestFitness = X_data[ub + X_size[0] * i];
        Flag4ub_data[i] = (bestFitness > ub_data[i]);
        Flag4lb_data[i] = (bestFitness < lb_data[i]);
      }
      if (X_size[1] == 1) {
        lb = ub_size[1];
      } else {
        lb = X_size[1];
      }
      if ((ub_size[1] == X_size[1]) && (X_size[1] == ub_size[1]) &&
          (ub_size[1] == X_size[1]) && (lb == ub_size[1])) {
        for (i = 0; i < loop_ub_tmp; i++) {
          bool b1;
          bool c_b;
          c_b = Flag4ub_data[i];
          b1 = Flag4lb_data[i];
          r = ub + X_size[0] * i;
          X_data[r] = (X_data[r] * (double)(c_b + b1 == 0) +
                       (double)ub_data[i] * (double)c_b) +
                      (double)lb_data[i] * (double)b1;
        }
      } else {
        binary_expand_op(X_data, X_size, ub, Flag4ub_data, tmp_size,
                         Flag4lb_data, tmp_size, ub_data, ub_size, lb_data,
                         ub_size);
      }
      /*  Check if the F00 Function is used which requires different */
      /*  inputs */
      loop_ub_tmp = X_size[1];
      tmp_size[1] = X_size[1];
      for (i = 0; i < loop_ub_tmp; i++) {
        vb_data[i] = X_data[ub + X_size[0] * i];
      }
      bestFitness = F00(vb_data, tmp_size, model_xs, model_ys, model_xt,
                        model_yt, xobs, yobs, model_robs, &a__1);
      if (ub + 1 <= N) {
        AllFitness_data[ub] = bestFitness;
        /*  Zugriff auf das Array */
      }
    }
    memcpy(&y_data[0], &AllFitness_data[0], (unsigned int)N * sizeof(double));
    sort(y_data, &N, iidx_data);
    /* Eq.(2.6) */
    bestFitness = y_data[0];
    S = (y_data[0] - y_data[N - 1]) + 2.2204460492503131E-16;
    /*  plus eps to avoid denominator zero */
    /* calculate the fitness weight of each slime mold */
    for (ub = 0; ub < N; ub++) {
      for (lb = 0; lb < dim; lb++) {
        if ((double)ub + 1.0 <= (double)N / 2.0) {
          /* Eq.(2.5) */
          weight_data[(iidx_data[ub] + N * lb) - 1] =
              1.0 + c_rand() * log10((bestFitness - y_data[ub]) / S + 1.0);
        } else {
          weight_data[(iidx_data[ub] + N * lb) - 1] =
              1.0 - c_rand() * log10((bestFitness - y_data[ub]) / S + 1.0);
        }
      }
    }
    /* update the best fitness value and best position */
    if (y_data[0] < Destination_fitness) {
      bestPositions_size[0] = 1;
      loop_ub = X_size[1];
      bestPositions_size[1] = X_size[1];
      for (i = 0; i < loop_ub; i++) {
        bestPositions_data[i] = X_data[(iidx_data[0] + X_size[0] * i) - 1];
      }
      Destination_fitness = y_data[0];
    }
    a_tmp = (double)it / (double)T;
    a = -a_tmp + 1.0;
    b_atanh(&a);
    /* Eq.(2.4) */
    /*  Update the Position of search agents */
    for (ub = 0; ub < N; ub++) {
      if (c_rand() < 0.03) {
        /* Eq.(2.7) */
        bestFitness = c_rand();
        loop_ub = X_size[1];
        for (i = 0; i < loop_ub; i++) {
          signed char i1;
          i1 = lb_data[i];
          X_data[ub + X_size[0] * i] =
              (double)(ub_data[i] - i1) * bestFitness + (double)i1;
        }
      } else {
        bestFitness = tanh(fabs(AllFitness_data[ub] - Destination_fitness));
        /* Eq.(2.2) */
        unifrnd(-a, a, dim, vb_data, tmp_size);
        /* Eq.(2.3) */
        unifrnd(-(1.0 - a_tmp), 1.0 - a_tmp, dim, vc_data, vc_size);
        for (lb = 0; lb < dim; lb++) {
          double A;
          double B;
          S = c_rand();
          A = c_rand();
          A = floor(A * (((double)N - 1.0) + 1.0)) + 1.0;
          /*  two positions randomly selected from population */
          B = c_rand();
          B = floor(B * (((double)N - 1.0) + 1.0)) + 1.0;
          if (S < bestFitness) {
            /* Eq.(2.1) */
            r = X_size[0] * lb;
            X_data[ub + r] = bestPositions_data[lb] +
                             vb_data[lb] * (weight_data[ub + N * lb] *
                                                X_data[((int)A + r) - 1] -
                                            X_data[((int)B + r) - 1]);
          } else {
            r = ub + X_size[0] * lb;
            X_data[r] *= vc_data[lb];
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
        i = 0;
        r = 0;
      } else {
        i = it - 101;
        r = it;
      }
      tmp_size[0] = 1;
      loop_ub = r - i;
      tmp_size[1] = loop_ub;
      for (r = 0; r < loop_ub; r++) {
        b_Convergence_curve_data[r] = Convergence_curve_data[i + r];
      }
      b_diff(b_Convergence_curve_data, tmp_size, tmp_data, vc_size);
      b_abs(tmp_data, vc_size, b_tmp_data, tmp_size);
      if (sum(b_tmp_data, tmp_size) < 0.01) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      it++;
      /*  Plot Solution */
      if ((b_mod((double)it - 1.0, showPlot) == 0.0) && (showPlot != 0.0)) {
        pause();
      }
    }
  }
  toc(&savedTime);
  /*     %% Visualization */
  /*  Plot convergence history */
  /*  Plot final path */
  bestFitness = F00(bestPositions_data, bestPositions_size, model_xs, model_ys,
                    model_xt, model_yt, xobs, yobs, model_robs, &a__1);
  emxFree_real_T(&yobs);
  emxFree_real_T(&xobs);
  emxFree_real_T(&model_robs);
  emxInit_char_T(&AllFitness);
  b_sprintf(bestFitness, AllFitness);
  emxFree_char_T(&AllFitness);
  /* display(['The best location of SMA is: ', sprintf('%.2f',bestPositions)]);
   */
  emxInit_char_T(&b_Destination_fitness);
  b_sprintf(Destination_fitness, b_Destination_fitness);
  emxFree_char_T(&b_Destination_fitness);
}

/* End of code generation (runProgram.c) */
