/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * spline.c
 *
 * Code generation for function 'spline'
 *
 */

/* Include files */
#include "spline.h"
#include "ppval.h"
#include "rt_nonfinite.h"
#include "runProgram_internal_types.h"
#include <emmintrin.h>

/* Function Definitions */
void spline(const double y[7], double output[200])
{
  __m128d b_r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  __m128d r4;
  __m128d r5;
  struct_T expl_temp;
  double dv[200];
  double md[7];
  double s[7];
  double dvdf[6];
  double dx[6];
  double r;
  int k;
  for (k = 0; k < 6; k++) {
    r = 0.16666666666666666 * ((double)k + 1.0) -
        0.16666666666666666 * (double)k;
    dx[k] = r;
    dvdf[k] = (y[k + 1] - y[k]) / r;
  }
  s[0] = ((dx[0] + 0.66666666666666663) * dx[1] * dvdf[0] +
          dx[0] * dx[0] * dvdf[1]) /
         0.33333333333333331;
  s[6] = ((dx[5] + 0.66666666666666674) * dx[4] * dvdf[5] +
          dx[5] * dx[5] * dvdf[4]) /
         0.33333333333333337;
  md[0] = dx[1];
  md[6] = dx[4];
  b_r = _mm_loadu_pd(&dx[1]);
  r1 = _mm_loadu_pd(&dvdf[0]);
  r2 = _mm_loadu_pd(&dx[0]);
  r3 = _mm_loadu_pd(&dvdf[1]);
  r4 = _mm_set1_pd(3.0);
  _mm_storeu_pd(&s[1], _mm_mul_pd(r4, _mm_add_pd(_mm_mul_pd(b_r, r1),
                                                 _mm_mul_pd(r2, r3))));
  r5 = _mm_set1_pd(2.0);
  _mm_storeu_pd(&md[1], _mm_mul_pd(r5, _mm_add_pd(b_r, r2)));
  b_r = _mm_loadu_pd(&dx[3]);
  r1 = _mm_loadu_pd(&dvdf[2]);
  r2 = _mm_loadu_pd(&dx[2]);
  r3 = _mm_loadu_pd(&dvdf[3]);
  _mm_storeu_pd(&s[3], _mm_mul_pd(r4, _mm_add_pd(_mm_mul_pd(b_r, r1),
                                                 _mm_mul_pd(r2, r3))));
  _mm_storeu_pd(&md[3], _mm_mul_pd(r5, _mm_add_pd(b_r, r2)));
  s[5] = 3.0 * (dvdf[4] * dx[5] + dx[4] * dvdf[5]);
  md[5] = 2.0 * (dx[4] + dx[5]);
  r = dx[1] / md[0];
  md[1] -= r * 0.33333333333333331;
  s[1] -= r * s[0];
  r = dx[2] / md[1];
  md[2] -= r * dx[0];
  s[2] -= r * s[1];
  r = dx[3] / md[2];
  md[3] -= r * dx[1];
  s[3] -= r * s[2];
  r = dx[4] / md[3];
  md[4] -= r * dx[2];
  s[4] -= r * s[3];
  r = dx[5] / md[4];
  md[5] -= r * dx[3];
  s[5] -= r * s[4];
  r = 0.33333333333333337 / md[5];
  md[6] -= r * dx[4];
  s[6] -= r * s[5];
  s[6] /= md[6];
  for (k = 4; k >= 0; k--) {
    s[k + 1] = (s[k + 1] - dx[k] * s[k + 2]) / md[k + 1];
  }
  s[0] = (s[0] - 0.33333333333333331 * s[1]) / md[0];
  for (k = 0; k < 7; k++) {
    expl_temp.breaks[k] = 0.16666666666666666 * (double)k;
  }
  b_r = _mm_loadu_pd(&dvdf[0]);
  r1 = _mm_loadu_pd(&s[0]);
  r2 = _mm_loadu_pd(&dx[0]);
  r3 = _mm_div_pd(_mm_sub_pd(b_r, r1), r2);
  r4 = _mm_loadu_pd(&s[1]);
  b_r = _mm_div_pd(_mm_sub_pd(r4, b_r), r2);
  _mm_storeu_pd(&expl_temp.coefs[0], _mm_div_pd(_mm_sub_pd(b_r, r3), r2));
  _mm_storeu_pd(&expl_temp.coefs[6], _mm_sub_pd(_mm_mul_pd(r5, r3), b_r));
  _mm_storeu_pd(&expl_temp.coefs[12], r1);
  _mm_storeu_pd(&expl_temp.coefs[18], _mm_loadu_pd(&y[0]));
  b_r = _mm_loadu_pd(&dvdf[2]);
  r1 = _mm_loadu_pd(&s[2]);
  r2 = _mm_loadu_pd(&dx[2]);
  r3 = _mm_div_pd(_mm_sub_pd(b_r, r1), r2);
  r4 = _mm_loadu_pd(&s[3]);
  b_r = _mm_div_pd(_mm_sub_pd(r4, b_r), r2);
  _mm_storeu_pd(&expl_temp.coefs[2], _mm_div_pd(_mm_sub_pd(b_r, r3), r2));
  _mm_storeu_pd(&expl_temp.coefs[8], _mm_sub_pd(_mm_mul_pd(r5, r3), b_r));
  _mm_storeu_pd(&expl_temp.coefs[14], r1);
  _mm_storeu_pd(&expl_temp.coefs[20], _mm_loadu_pd(&y[2]));
  b_r = _mm_loadu_pd(&dvdf[4]);
  r1 = _mm_loadu_pd(&s[4]);
  r2 = _mm_loadu_pd(&dx[4]);
  r3 = _mm_div_pd(_mm_sub_pd(b_r, r1), r2);
  r4 = _mm_loadu_pd(&s[5]);
  b_r = _mm_div_pd(_mm_sub_pd(r4, b_r), r2);
  _mm_storeu_pd(&expl_temp.coefs[4], _mm_div_pd(_mm_sub_pd(b_r, r3), r2));
  _mm_storeu_pd(&expl_temp.coefs[10], _mm_sub_pd(_mm_mul_pd(r5, r3), b_r));
  _mm_storeu_pd(&expl_temp.coefs[16], r1);
  _mm_storeu_pd(&expl_temp.coefs[22], _mm_loadu_pd(&y[4]));
  for (k = 0; k < 200; k++) {
    dv[k] = 0.0050251256281407036 * (double)k;
  }
  ppval(&expl_temp, dv, output);
}

/* End of code generation (spline.c) */
