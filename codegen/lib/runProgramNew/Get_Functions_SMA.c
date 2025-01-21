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
#include "linspace.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include "runProgramNew_types.h"
#include "spline.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
double F00(const double x_data[], const int x_size[2], double model_xs,
           double model_ys, double model_xt, double model_yt,
           const emxArray_real_T *model_xobs, const emxArray_real_T *model_yobs,
           const emxArray_real_T *model_robs, double sol_TS_data[],
           int sol_TS_size[2], double sol_XS_data[], int sol_XS_size[2],
           double sol_YS_data[], int sol_YS_size[2], double sol_tt[200],
           double sol_xx[200], double sol_yy[200], double sol_dx[199],
           double sol_dy[199], double *sol_L, double *sol_Violation,
           bool *sol_IsFeasible)
{
  __m128d r;
  __m128d r1;
  double v[200];
  double y[199];
  double dv[2];
  double dv1[2];
  const double *model_robs_data;
  const double *model_xobs_data;
  const double *model_yobs_data;
  double o;
  int b_loop_ub;
  int i;
  int loop_ub;
  model_robs_data = model_robs->data;
  model_yobs_data = model_yobs->data;
  model_xobs_data = model_xobs->data;
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
  sol_XS_size[0] = 1;
  loop_ub = (x_size[1] - 1) / 2;
  sol_XS_size[1] = loop_ub + 3;
  sol_XS_data[0] = model_xs;
  for (i = 0; i <= loop_ub; i++) {
    sol_XS_data[i + 1] = x_data[i << 1];
  }
  sol_XS_data[loop_ub + 2] = model_xt;
  sol_YS_size[0] = 1;
  b_loop_ub = (x_size[1] - 2) / 2;
  sol_YS_size[1] = b_loop_ub + 3;
  sol_YS_data[0] = model_ys;
  for (i = 0; i <= b_loop_ub; i++) {
    sol_YS_data[i + 1] = x_data[(i << 1) + 1];
  }
  sol_YS_data[b_loop_ub + 2] = model_yt;
  linspace(loop_ub + 3, sol_TS_data, sol_TS_size);
  /*  Generate spline interpolation */
  spline(sol_TS_data, sol_TS_size, sol_XS_data, sol_XS_size, sol_xx);
  spline(sol_TS_data, sol_TS_size, sol_YS_data, sol_YS_size, sol_yy);
  /*  Calculate path differences */
  diff(sol_xx, sol_dx);
  diff(sol_yy, sol_dy);
  /*  Calculate total path length */
  for (loop_ub = 0; loop_ub <= 196; loop_ub += 2) {
    r = _mm_loadu_pd(&sol_dx[loop_ub]);
    r1 = _mm_loadu_pd(&sol_dy[loop_ub]);
    _mm_storeu_pd(&y[loop_ub], _mm_sqrt_pd(_mm_add_pd(_mm_mul_pd(r, r),
                                                      _mm_mul_pd(r1, r1))));
  }
  y[198] = sqrt(sol_dx[198] * sol_dx[198] + sol_dy[198] * sol_dy[198]);
  *sol_L = y[0];
  for (loop_ub = 0; loop_ub < 198; loop_ub++) {
    *sol_L += y[loop_ub + 1];
  }
  /*  Check for obstacle collisions */
  *sol_Violation = 0.0;
  i = model_xobs->size[0] * model_xobs->size[1];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    o = model_robs_data[loop_ub];
    for (b_loop_ub = 0; b_loop_ub <= 198; b_loop_ub += 2) {
      r = _mm_loadu_pd(&sol_xx[b_loop_ub]);
      r = _mm_sub_pd(r, _mm_set1_pd(model_xobs_data[loop_ub]));
      r1 = _mm_loadu_pd(&sol_yy[b_loop_ub]);
      r1 = _mm_sub_pd(r1, _mm_set1_pd(model_yobs_data[loop_ub]));
      _mm_storeu_pd(
          &dv[0],
          _mm_sub_pd(_mm_set1_pd(1.0),
                     _mm_div_pd(_mm_sqrt_pd(_mm_add_pd(_mm_mul_pd(r, r),
                                                       _mm_mul_pd(r1, r1))),
                                _mm_set1_pd(o))));
      dv1[0] = fmax(dv[0], 0.0);
      dv1[1] = fmax(dv[1], 0.0);
      r = _mm_loadu_pd(&dv1[0]);
      _mm_storeu_pd(&v[b_loop_ub], r);
    }
    *sol_Violation += mean(v);
  }
  /*  Store results */
  for (i = 0; i < 200; i++) {
    sol_tt[i] = 0.0050251256281407036 * (double)i;
  }
  *sol_IsFeasible = (*sol_Violation == 0.0);
  return *sol_L * (300.0 * *sol_Violation + 1.0);
}

/* End of code generation (Get_Functions_SMA.c) */
