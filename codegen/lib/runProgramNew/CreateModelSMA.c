/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CreateModelSMA.c
 *
 * Code generation for function 'CreateModelSMA'
 *
 */

/* Include files */
#include "CreateModelSMA.h"
#include "rt_nonfinite.h"
#include "runProgramNew_emxutil.h"
#include "runProgramNew_types.h"
#include <stdio.h>

/* Function Definitions */
double CreateModelSMA(double i, emxArray_real_T *model_xobs,
                      emxArray_real_T *model_yobs, emxArray_real_T *model_robs,
                      double *model_ys, double *model_xt, double *model_yt,
                      double *model_n, double *lb, double *ub,
                      double *NumberofPoints, double *T, double *N)
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
  emxArray_real_T *b_model_xobs;
  double model_xs;
  double *model_robs_data;
  double *model_xobs_data;
  double *model_yobs_data;
  int b_N;
  int b_NumberofPoints;
  int b_T;
  int b_model_n;
  int b_model_xs;
  int b_model_xt;
  int b_model_ys;
  int b_model_yt;
  int b_ub;
  int r;
  model_yobs_data = model_yobs->data;
  model_xobs_data = model_xobs->data;
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
  model_xobs->size[0] = 0;
  model_xobs->size[1] = 0;
  model_yobs->size[0] = 0;
  model_yobs->size[1] = 0;
  /*  Target (Destination) */
  emxInit_real_T(&b_model_xobs);
  switch ((int)i) {
  case 1: //used to be 7, easy card
    /*  Check lengths of generated arrays */
    /*  Increased spacing */
    /*  Reduced number of obstacles due to larger size */
    b_model_xs = 2;
    b_model_ys = 2;
    b_N = model_xobs->size[0] * model_xobs->size[1];
    model_xobs->size[0] = 1;
    model_xobs->size[1] = 40;
    emxEnsureCapacity_real_T(model_xobs, b_N);
    model_xobs_data = model_xobs->data;
    /*  Adjusted spacing */
    b_N = model_yobs->size[0] * model_yobs->size[1];
    model_yobs->size[0] = 1;
    model_yobs->size[1] = 40;
    emxEnsureCapacity_real_T(model_yobs, b_N);
    model_yobs_data = model_yobs->data;
    b_model_n = 40;
    b_N = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = 40;
    emxEnsureCapacity_real_T(model_robs, b_N);
    model_robs_data = model_robs->data;
    for (b_N = 0; b_N < 40; b_N++) {
      model_xobs_data[b_N] = dv1[b_N];
      model_yobs_data[b_N] = dv2[b_N];
      model_robs_data[b_N] = 0.8;
    }
    /*  Doubled obstacle size */
    b_model_xt = 14;
    b_model_yt = 14;
    r = 0;
    b_ub = 17;
    b_NumberofPoints = 5;
    b_T = 500;
    b_N = 50;
    break;
  case 4: //used to be 9 (not really relevant)
    b_model_n = 60;
    /*  Reduced number of obstacles */
    b_model_xs = 1;
    b_model_ys = 1;
    /*  Reduced number of circles */
    for (b_T = 0; b_T < 4; b_T++) {
      r = (b_T + 1) << 2;
      /*  Increased spacing between circles */
      if ((model_xobs->size[0] != 0) && (model_xobs->size[1] != 0)) {
        b_NumberofPoints = model_xobs->size[1];
      } else {
        b_NumberofPoints = 0;
      }
      b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
      b_model_xobs->size[0] = 1;
      b_model_xobs->size[1] = b_NumberofPoints + 15;
      emxEnsureCapacity_real_T(b_model_xobs, b_N);
      model_robs_data = b_model_xobs->data;
      for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
        model_robs_data[b_model_xobs->size[0] * b_N] = model_xobs_data[b_N];
      }
      for (b_N = 0; b_N < 15; b_N++) {
        model_robs_data[b_model_xobs->size[0] * (b_N + b_NumberofPoints)] =
            (double)r * b[b_N] + 12.0;
      }
      b_N = model_xobs->size[0] * model_xobs->size[1];
      model_xobs->size[0] = 1;
      b_ub = b_model_xobs->size[1];
      model_xobs->size[1] = b_model_xobs->size[1];
      emxEnsureCapacity_real_T(model_xobs, b_N);
      model_xobs_data = model_xobs->data;
      for (b_N = 0; b_N < b_ub; b_N++) {
        model_xobs_data[b_N] = model_robs_data[b_N];
      }
      b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
      b_model_xobs->size[0] = 1;
      b_model_xobs->size[1] = b_NumberofPoints + 15;
      emxEnsureCapacity_real_T(b_model_xobs, b_N);
      model_robs_data = b_model_xobs->data;
      for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
        model_robs_data[b_model_xobs->size[0] * b_N] = model_yobs_data[b_N];
      }
      for (b_N = 0; b_N < 15; b_N++) {
        model_robs_data[b_model_xobs->size[0] * (b_N + b_NumberofPoints)] =
            (double)r * b_b[b_N] + 12.0;
      }
      b_N = model_yobs->size[0] * model_yobs->size[1];
      model_yobs->size[0] = 1;
      model_yobs->size[1] = b_ub;
      emxEnsureCapacity_real_T(model_yobs, b_N);
      model_yobs_data = model_yobs->data;
      for (b_N = 0; b_N < b_ub; b_N++) {
        model_yobs_data[b_N] = model_robs_data[b_N];
      }
    }
    b_N = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = 60;
    emxEnsureCapacity_real_T(model_robs, b_N);
    model_robs_data = model_robs->data;
    for (b_N = 0; b_N < 60; b_N++) {
      model_robs_data[b_N] = 0.75;
    }
    /*  More than doubled obstacle size */
    b_model_xt = 23;
    b_model_yt = 23;
    r = 0;
    b_ub = 24;
    b_NumberofPoints = 8;
    b_T = 600;
    b_N = 150;
    break;
  case 2: //used to be 10, best for scaling
    /*  Warehouse layout with storage racks, main aisles and workstations */
    /*  Start and goal positions (near entrance and shipping area) */
    b_model_xs = 2;
    b_model_ys = 2;
    b_model_xt = 22;
    b_model_yt = 22;
    /*  Generate storage rack rows (6 double-sided rack rows) */
    /*  Space between rack rows for aisles */
    /*  Create double-sided storage racks */
    for (b_T = 0; b_T < 6; b_T++) {
      r = (b_T << 2) + 5;
      /*  First side of rack */
      /*  Second side of rack */
      if ((model_xobs->size[0] != 0) && (model_xobs->size[1] != 0)) {
        b_NumberofPoints = model_xobs->size[1];
      } else {
        b_NumberofPoints = 0;
      }
      b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
      b_model_xobs->size[0] = 1;
      b_model_xobs->size[1] = b_NumberofPoints + 24;
      emxEnsureCapacity_real_T(b_model_xobs, b_N);
      model_robs_data = b_model_xobs->data;
      for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
        model_robs_data[b_model_xobs->size[0] * b_N] = model_xobs_data[b_N];
      }
      for (b_N = 0; b_N < 12; b_N++) {
        model_robs_data[b_model_xobs->size[0] * (b_N + b_NumberofPoints)] = r;
      }
      for (b_N = 0; b_N < 12; b_N++) {
        model_robs_data[b_model_xobs->size[0] *
                        ((b_N + b_NumberofPoints) + 12)] = (double)r + 1.0;
      }
      b_N = model_xobs->size[0] * model_xobs->size[1];
      model_xobs->size[0] = 1;
      b_ub = b_model_xobs->size[1];
      model_xobs->size[1] = b_model_xobs->size[1];
      emxEnsureCapacity_real_T(model_xobs, b_N);
      model_xobs_data = model_xobs->data;
      for (b_N = 0; b_N < b_ub; b_N++) {
        model_xobs_data[b_N] = model_robs_data[b_N];
      }
      b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
      b_model_xobs->size[0] = 1;
      b_model_xobs->size[1] = b_NumberofPoints + 24;
      emxEnsureCapacity_real_T(b_model_xobs, b_N);
      model_robs_data = b_model_xobs->data;
      for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
        model_robs_data[b_model_xobs->size[0] * b_N] = model_yobs_data[b_N];
      }
      for (b_N = 0; b_N < 12; b_N++) {
        model_robs_data[b_model_xobs->size[0] * (b_N + b_NumberofPoints)] =
            d_varargin_2[b_N];
      }
      for (b_N = 0; b_N < 12; b_N++) {
        model_robs_data[b_model_xobs->size[0] *
                        ((b_N + b_NumberofPoints) + 12)] = d_varargin_2[b_N];
      }
      b_N = model_yobs->size[0] * model_yobs->size[1];
      model_yobs->size[0] = 1;
      model_yobs->size[1] = b_ub;
      emxEnsureCapacity_real_T(model_yobs, b_N);
      model_yobs_data = model_yobs->data;
      for (b_N = 0; b_N < b_ub; b_N++) {
        model_yobs_data[b_N] = model_robs_data[b_N];
      }
    }
    /*  Add workstations along the walls */
    /*  Combine all obstacles */
    if ((model_xobs->size[0] != 0) && (model_xobs->size[1] != 0)) {
      b_ub = model_xobs->size[1];
    } else {
      b_ub = 0;
    }
    b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
    b_model_xobs->size[0] = 1;
    b_model_xobs->size[1] = b_ub + 11;
    emxEnsureCapacity_real_T(b_model_xobs, b_N);
    model_robs_data = b_model_xobs->data;
    for (b_N = 0; b_N < b_ub; b_N++) {
      model_robs_data[b_model_xobs->size[0] * b_N] = model_xobs_data[b_N];
    }
    for (b_N = 0; b_N < 11; b_N++) {
      model_robs_data[b_model_xobs->size[0] * (b_N + b_ub)] = varargin_2[b_N];
    }
    b_N = model_xobs->size[0] * model_xobs->size[1];
    model_xobs->size[0] = 1;
    b_NumberofPoints = b_model_xobs->size[1];
    model_xobs->size[1] = b_model_xobs->size[1];
    emxEnsureCapacity_real_T(model_xobs, b_N);
    model_xobs_data = model_xobs->data;
    for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
      model_xobs_data[b_N] = model_robs_data[b_N];
    }
    b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
    b_model_xobs->size[0] = 1;
    b_model_xobs->size[1] = b_ub + 11;
    emxEnsureCapacity_real_T(b_model_xobs, b_N);
    model_robs_data = b_model_xobs->data;
    for (b_N = 0; b_N < b_ub; b_N++) {
      model_robs_data[b_model_xobs->size[0] * b_N] = model_yobs_data[b_N];
    }
    for (b_N = 0; b_N < 11; b_N++) {
      model_robs_data[b_model_xobs->size[0] * (b_N + b_ub)] = c_varargin_2[b_N];
    }
    b_N = model_yobs->size[0] * model_yobs->size[1];
    model_yobs->size[0] = 1;
    model_yobs->size[1] = b_NumberofPoints;
    emxEnsureCapacity_real_T(model_yobs, b_N);
    model_yobs_data = model_yobs->data;
    for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
      model_yobs_data[b_N] = model_robs_data[b_N];
    }
    /*  Set parameters */
    b_model_n = model_xobs->size[1];
    /*  Total number of obstacles */
    b_N = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = b_NumberofPoints;
    emxEnsureCapacity_real_T(model_robs, b_N);
    model_robs_data = model_robs->data;
    for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
      model_robs_data[b_N] = 0.9;
    }
    /*  Uniform obstacle size */
    /*  Set boundaries */
    r = 0;
    b_ub = 25;
    /*  Algorithm parameters */
    b_NumberofPoints = 6;
    /*  More waypoints for complex navigation */
    b_T = 600;
    /*  High number of iterations for better path finding */
    b_N = 300;
    /*  Sufficient number of search agents */
    break;
  case 3: //used to be 11, in serial we get no proper solution
    /*  Warehouse layout with storage racks, main aisles and workstations */
    /*  Start and goal positions (forcing path through the warehouse) */
    b_model_xs = 5;
    b_model_ys = 3;
    b_model_xt = 27;
    b_model_yt = 27;
    /*  Generate storage rack rows (6 double-sided rack rows) */
    /*  Reduced number of obstacles per row */
    /*  Increased space between rack rows for aisles */
    /*  Create double-sided storage racks with larger gaps */
    for (b_T = 0; b_T < 6; b_T++) {
      r = b_T * 6 + 5;
      /*  First side of rack */
      /*  Second side of rack (increased separation within rack) */
      if ((model_xobs->size[0] != 0) && (model_xobs->size[1] != 0)) {
        b_NumberofPoints = model_xobs->size[1];
      } else {
        b_NumberofPoints = 0;
      }
      b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
      b_model_xobs->size[0] = 1;
      b_model_xobs->size[1] = b_NumberofPoints + 16;
      emxEnsureCapacity_real_T(b_model_xobs, b_N);
      model_robs_data = b_model_xobs->data;
      for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
        model_robs_data[b_model_xobs->size[0] * b_N] = model_xobs_data[b_N];
      }
      for (b_N = 0; b_N < 8; b_N++) {
        model_robs_data[b_model_xobs->size[0] * (b_N + b_NumberofPoints)] = r;
      }
      for (b_N = 0; b_N < 8; b_N++) {
        model_robs_data[b_model_xobs->size[0] *
                        ((b_N + b_NumberofPoints) + 8)] = (double)r + 1.5;
      }
      b_N = model_xobs->size[0] * model_xobs->size[1];
      model_xobs->size[0] = 1;
      b_ub = b_model_xobs->size[1];
      model_xobs->size[1] = b_model_xobs->size[1];
      emxEnsureCapacity_real_T(model_xobs, b_N);
      model_xobs_data = model_xobs->data;
      for (b_N = 0; b_N < b_ub; b_N++) {
        model_xobs_data[b_N] = model_robs_data[b_N];
      }
      b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
      b_model_xobs->size[0] = 1;
      b_model_xobs->size[1] = b_NumberofPoints + 16;
      emxEnsureCapacity_real_T(b_model_xobs, b_N);
      model_robs_data = b_model_xobs->data;
      for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
        model_robs_data[b_model_xobs->size[0] * b_N] = model_yobs_data[b_N];
      }
      for (b_N = 0; b_N < 8; b_N++) {
        model_robs_data[b_model_xobs->size[0] * (b_N + b_NumberofPoints)] =
            e_varargin_2[b_N];
      }
      for (b_N = 0; b_N < 8; b_N++) {
        model_robs_data[b_model_xobs->size[0] *
                        ((b_N + b_NumberofPoints) + 8)] = e_varargin_2[b_N];
      }
      b_N = model_yobs->size[0] * model_yobs->size[1];
      model_yobs->size[0] = 1;
      model_yobs->size[1] = b_ub;
      emxEnsureCapacity_real_T(model_yobs, b_N);
      model_yobs_data = model_yobs->data;
      for (b_N = 0; b_N < b_ub; b_N++) {
        model_yobs_data[b_N] = model_robs_data[b_N];
      }
    }
    /*  Add blocking walls to force internal routing */
    /*  Top wall */
    /*  Bottom wall */
    /*  Left wall */
    /*  Right wall */
    /*  Add workstations with adjusted positions */
    /*  Combine all obstacles */
    if ((model_xobs->size[0] != 0) && (model_xobs->size[1] != 0)) {
      b_ub = model_xobs->size[1];
    } else {
      b_ub = 0;
    }
    b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
    b_model_xobs->size[0] = 1;
    b_model_xobs->size[1] = b_ub + 48;
    emxEnsureCapacity_real_T(b_model_xobs, b_N);
    model_robs_data = b_model_xobs->data;
    for (b_N = 0; b_N < b_ub; b_N++) {
      model_robs_data[b_model_xobs->size[0] * b_N] = model_xobs_data[b_N];
    }
    for (b_N = 0; b_N < 8; b_N++) {
      model_robs_data[b_model_xobs->size[0] * (b_N + b_ub)] = b_varargin_2[b_N];
    }
    for (b_N = 0; b_N < 10; b_N++) {
      model_xs = 3.3333333333333335 * (double)b_N;
      r = b_N + b_ub;
      model_robs_data[b_model_xobs->size[0] * (r + 8)] = model_xs;
      model_robs_data[b_model_xobs->size[0] * (r + 18)] = model_xs;
      model_robs_data[b_model_xobs->size[0] * (r + 28)] = 0.0;
      model_robs_data[b_model_xobs->size[0] * (r + 38)] = 30.0;
    }
    b_N = model_xobs->size[0] * model_xobs->size[1];
    model_xobs->size[0] = 1;
    b_NumberofPoints = b_model_xobs->size[1];
    model_xobs->size[1] = b_model_xobs->size[1];
    emxEnsureCapacity_real_T(model_xobs, b_N);
    model_xobs_data = model_xobs->data;
    for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
      model_xobs_data[b_N] = model_robs_data[b_N];
    }
    b_N = b_model_xobs->size[0] * b_model_xobs->size[1];
    b_model_xobs->size[0] = 1;
    b_model_xobs->size[1] = b_ub + 48;
    emxEnsureCapacity_real_T(b_model_xobs, b_N);
    model_robs_data = b_model_xobs->data;
    for (b_N = 0; b_N < b_ub; b_N++) {
      model_robs_data[b_model_xobs->size[0] * b_N] = model_yobs_data[b_N];
    }
    for (b_N = 0; b_N < 8; b_N++) {
      model_robs_data[b_model_xobs->size[0] * (b_N + b_ub)] = f_varargin_2[b_N];
    }
    for (b_N = 0; b_N < 10; b_N++) {
      r = b_N + b_ub;
      model_robs_data[b_model_xobs->size[0] * (r + 8)] = 30.0;
      model_robs_data[b_model_xobs->size[0] * (r + 18)] = 0.0;
      model_xs = 3.3333333333333335 * (double)b_N;
      model_robs_data[b_model_xobs->size[0] * (r + 28)] = model_xs;
      model_robs_data[b_model_xobs->size[0] * (r + 38)] = model_xs;
    }
    b_N = model_yobs->size[0] * model_yobs->size[1];
    model_yobs->size[0] = 1;
    model_yobs->size[1] = b_NumberofPoints;
    emxEnsureCapacity_real_T(model_yobs, b_N);
    model_yobs_data = model_yobs->data;
    for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
      model_yobs_data[b_N] = model_robs_data[b_N];
    }
    /*  Set parameters */
    b_model_n = model_xobs->size[1];
    /*  Total number of obstacles */
    b_N = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = b_ub + 48;
    emxEnsureCapacity_real_T(model_robs, b_N);
    model_robs_data = model_robs->data;
    for (b_N = 0; b_N < b_NumberofPoints; b_N++) {
      model_robs_data[b_N] = 1.0;
    }
    /*  Slightly larger obstacles */
    /*  Set tight boundaries to prevent external routing */
    r = 0;
    b_ub = 30;
    /*  Algorithm parameters */
    b_NumberofPoints = 5;
    /*  More waypoints for complex navigation */
    b_T = 2000;
    /*  High number of iterations for better path finding */
    b_N = 400;
    /*  Sufficient number of search agents */
    break;
  default:
    b_model_n = 45;
    b_model_xs = 3;
    b_model_ys = 3;
    b_N = model_xobs->size[0] * model_xobs->size[1];
    model_xobs->size[0] = 1;
    model_xobs->size[1] = 45;
    emxEnsureCapacity_real_T(model_xobs, b_N);
    model_xobs_data = model_xobs->data;
    b_N = model_yobs->size[0] * model_yobs->size[1];
    model_yobs->size[0] = 1;
    model_yobs->size[1] = 45;
    emxEnsureCapacity_real_T(model_yobs, b_N);
    model_yobs_data = model_yobs->data;
    b_N = model_robs->size[0] * model_robs->size[1];
    model_robs->size[0] = 1;
    model_robs->size[1] = 45;
    emxEnsureCapacity_real_T(model_robs, b_N);
    model_robs_data = model_robs->data;
    for (b_N = 0; b_N < 45; b_N++) {
      model_xobs_data[b_N] = iv[b_N];
      model_yobs_data[b_N] = dv[b_N];
      model_robs_data[b_N] = 0.4;
    }
    b_model_xt = 15;
    b_model_yt = 15;
    r = -1;
    b_ub = 19;
    b_NumberofPoints = 4;
    b_T = 400;
    /*  Maximum number of iterations */
    b_N = 30;
    /*  Number of search agents */
    break;
  }


  FILE *file = fopen("output.txt", "w");
  if (file != NULL) {
      // Write individual integer values
      fprintf(file, "%d\n", b_model_xs);
      fprintf(file, "%d\n", b_model_ys);
      fprintf(file, "%d\n", b_model_xt);
      fprintf(file, "%d\n", b_model_yt);

      // Write arrays (the number of elements must be known, e.g., 'n_obs')
      for (int i = 0; i < model_xobs->size[1]; i++) {
          fprintf(file, "%f, ", model_xobs_data[i]);  // Write each value of xobs_data
      }

      fprintf(file, "\n");
      for (int i = 0; i < model_xobs->size[1]; i++) {
          fprintf(file, "%f, ", model_yobs_data[i]);  // Write each value of yobs_data
      }

      fprintf(file, "\n");
      for (int i = 0; i < model_xobs->size[1]; i++) {
          fprintf(file, "%f, ", model_robs_data[i]);  // Write each value of model_robs_data
      }

      fclose(file);
  } else {
      printf("Error opening the file!\n");
  }

  emxFree_real_T(&b_model_xobs);
  model_xs = b_model_xs;
  *model_ys = b_model_ys;
  *model_xt = b_model_xt;
  *model_yt = b_model_yt;
  *model_n = b_model_n;
  *lb = r;
  *ub = b_ub;
  *NumberofPoints = b_NumberofPoints;
  *T = b_T;
  *N = b_N;

  
  return model_xs;
}

/* End of code generation (CreateModelSMA.c) */
