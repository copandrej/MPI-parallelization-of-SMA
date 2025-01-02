/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Get_Functions_SMA.c
 *
 * Code generation for function 'Get_Functions_SMA'
 *
 */

/* Include files */
#include "Get_Functions_SMA.h"
#include "diff.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include "spline.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
double F00(const double x[10], double sol_TS[7], double sol_XS[7],
           double sol_YS[7], double sol_tt[200], double sol_xx[200],
           double sol_yy[200], double sol_dx[199], double sol_dy[199],
           double *sol_L, double *sol_Violation, bool *sol_IsFeasible)
{
  static const double dv[40] = {3.0,  4.5,  6.0,  7.5,  9.0,  10.5, 12.0, 13.5,
                                15.0, 3.0,  4.5,  6.0,  7.5,  9.0,  10.5, 12.0,
                                13.5, 15.0, 3.0,  4.5,  6.0,  7.5,  3.0,  3.0,
                                3.0,  3.0,  3.0,  3.0,  8.0,  8.0,  8.0,  8.0,
                                8.0,  8.0,  15.0, 15.0, 15.0, 15.0, 15.0, 15.0};
  static const double dv1[40] = {
      3.0,  3.0,  3.0,  3.0,  3.0,  3.0,  3.0,  3.0,  3.0, 15.0,
      15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 8.0, 8.0,
      8.0,  8.0,  3.0,  4.5,  6.0,  7.5,  9.0,  10.5, 3.0, 4.5,
      6.0,  7.5,  9.0,  10.5, 3.0,  4.5,  6.0,  7.5,  9.0, 10.5};
  __m128d r;
  __m128d r1;
  double v[200];
  double y[199];
  double dv2[2];
  double dv3[2];
  int k;
  int sol_XS_tmp;
  /* F00 */
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
  /*  Extract coordinates from input solution */
  /*  Get model parameters */
  /*  Combine path points including start and end */
  sol_XS[0] = 2.0;
  sol_XS[6] = 14.0;
  sol_YS[0] = 2.0;
  for (k = 0; k < 5; k++) {
    sol_XS_tmp = k << 1;
    sol_XS[k + 1] = x[sol_XS_tmp];
    sol_YS[k + 1] = x[sol_XS_tmp + 1];
  }
  sol_YS[6] = 14.0;
  /*  Generate spline interpolation */
  spline(sol_XS, sol_xx);
  spline(sol_YS, sol_yy);
  /*  Calculate path differences */
  diff(sol_xx, sol_dx);
  diff(sol_yy, sol_dy);
  /*  Calculate total path length */
  for (k = 0; k <= 196; k += 2) {
    r = _mm_loadu_pd(&sol_dx[k]);
    r1 = _mm_loadu_pd(&sol_dy[k]);
    _mm_storeu_pd(
        &y[k], _mm_sqrt_pd(_mm_add_pd(_mm_mul_pd(r, r), _mm_mul_pd(r1, r1))));
  }
  y[198] = sqrt(sol_dx[198] * sol_dx[198] + sol_dy[198] * sol_dy[198]);
  *sol_L = y[0];
  for (k = 0; k < 198; k++) {
    *sol_L += y[k + 1];
  }
  /*  Check for obstacle collisions */
  *sol_Violation = 0.0;
  for (k = 0; k < 40; k++) {
    for (sol_XS_tmp = 0; sol_XS_tmp <= 198; sol_XS_tmp += 2) {
      r = _mm_loadu_pd(&sol_xx[sol_XS_tmp]);
      r = _mm_sub_pd(r, _mm_set1_pd(dv[k]));
      r1 = _mm_loadu_pd(&sol_yy[sol_XS_tmp]);
      r1 = _mm_sub_pd(r1, _mm_set1_pd(dv1[k]));
      _mm_storeu_pd(
          &dv2[0],
          _mm_sub_pd(_mm_set1_pd(1.0),
                     _mm_div_pd(_mm_sqrt_pd(_mm_add_pd(_mm_mul_pd(r, r),
                                                       _mm_mul_pd(r1, r1))),
                                _mm_set1_pd(0.8))));
      dv3[0] = fmax(dv2[0], 0.0);
      dv3[1] = fmax(dv2[1], 0.0);
      r = _mm_loadu_pd(&dv3[0]);
      _mm_storeu_pd(&v[sol_XS_tmp], r);
    }
    *sol_Violation += mean(v);
  }
  /*  Store results */
  for (k = 0; k < 7; k++) {
    sol_TS[k] = 0.16666666666666666 * (double)k;
  }
  for (k = 0; k < 200; k++) {
    sol_tt[k] = 0.0050251256281407036 * (double)k;
  }
  *sol_IsFeasible = (*sol_Violation == 0.0);
  return *sol_L * (300.0 * *sol_Violation + 1.0);
}

/* End of code generation (Get_Functions_SMA.c) */
