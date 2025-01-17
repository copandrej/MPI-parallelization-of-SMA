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
#include "runProgram_internal_types.h"
#include "runProgram_types.h"
#include "spline.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
double F00(const double x_data[], const int x_size[2], double model_xs,
           double model_ys, double model_xt, double model_yt,
           const emxArray_real_T *model_xobs, const emxArray_real_T *model_yobs,
           const emxArray_real_T *model_robs, b_struct_T *sol)
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
  double Violation;
  double o;
  int i;
  int k;
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
  sol->XS.size[0] = 1;
  loop_ub = (x_size[1] - 1) / 2;
  sol->XS.size[1] = loop_ub + 3;
  sol->XS.data[0] = model_xs;
  for (i = 0; i <= loop_ub; i++) {
    sol->XS.data[i + 1] = x_data[i << 1];
  }
  sol->XS.data[loop_ub + 2] = model_xt;
  sol->YS.size[0] = 1;
  loop_ub = (x_size[1] - 2) / 2;
  sol->YS.size[1] = loop_ub + 3;
  sol->YS.data[0] = model_ys;
  for (i = 0; i <= loop_ub; i++) {
    sol->YS.data[i + 1] = x_data[(i << 1) + 1];
  }
  sol->YS.data[loop_ub + 2] = model_yt;
  linspace(sol->XS.size[1], sol->TS.data, sol->TS.size);
  /*  Generate spline interpolation */
  spline(sol->TS.data, sol->TS.size, sol->XS.data, sol->XS.size, sol->xx);
  spline(sol->TS.data, sol->TS.size, sol->YS.data, sol->YS.size, sol->yy);
  /*  Calculate path differences */
  diff(sol->xx, sol->dx);
  diff(sol->yy, sol->dy);
  /*  Calculate total path length */
  for (loop_ub = 0; loop_ub <= 196; loop_ub += 2) {
    r = _mm_loadu_pd(&sol->dx[loop_ub]);
    r1 = _mm_loadu_pd(&sol->dy[loop_ub]);
    _mm_storeu_pd(&y[loop_ub], _mm_sqrt_pd(_mm_add_pd(_mm_mul_pd(r, r),
                                                      _mm_mul_pd(r1, r1))));
  }
  y[198] = sqrt(sol->dx[198] * sol->dx[198] + sol->dy[198] * sol->dy[198]);
  o = y[0];
  for (loop_ub = 0; loop_ub < 198; loop_ub++) {
    o += y[loop_ub + 1];
  }
  /*  Check for obstacle collisions */
  Violation = 0.0;
  i = model_xobs->size[0] * model_xobs->size[1];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    double b_model_robs;
    b_model_robs = model_robs_data[loop_ub];
    for (k = 0; k <= 198; k += 2) {
      r = _mm_loadu_pd(&sol->xx[k]);
      r = _mm_sub_pd(r, _mm_set1_pd(model_xobs_data[loop_ub]));
      r1 = _mm_loadu_pd(&sol->yy[k]);
      r1 = _mm_sub_pd(r1, _mm_set1_pd(model_yobs_data[loop_ub]));
      _mm_storeu_pd(
          &dv[0],
          _mm_sub_pd(_mm_set1_pd(1.0),
                     _mm_div_pd(_mm_sqrt_pd(_mm_add_pd(_mm_mul_pd(r, r),
                                                       _mm_mul_pd(r1, r1))),
                                _mm_set1_pd(b_model_robs))));
      dv1[0] = fmax(dv[0], 0.0);
      dv1[1] = fmax(dv[1], 0.0);
      r = _mm_loadu_pd(&dv1[0]);
      _mm_storeu_pd(&v[k], r);
    }
    Violation += mean(v);
  }
  /*  Store results */
  o *= 300.0 * Violation + 1.0;
  return o;
}

/* End of code generation (Get_Functions_SMA.c) */
