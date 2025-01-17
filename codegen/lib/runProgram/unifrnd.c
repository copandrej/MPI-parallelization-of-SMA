/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unifrnd.c
 *
 * Code generation for function 'unifrnd'
 *
 */

/* Include files */
#include "unifrnd.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Function Definitions */
void unifrnd(double a, double b, double varargin_2, double r_data[],
             int r_size[2])
{
  double b_data[40];
  double dv[2];
  double ak;
  double bk;
  int i;
  int loop_ub;
  int scalarLB;
  int vectorUB;
  dv[0] = 1.0;
  dv[1] = (int)varargin_2;
  d_rand(dv, b_data, r_size);
  r_size[0] = 1;
  loop_ub = r_size[1];
  scalarLB = (r_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    __m128d r;
    r = _mm_loadu_pd(&b_data[i]);
    _mm_storeu_pd(&r_data[i], _mm_sub_pd(_mm_mul_pd(_mm_set1_pd(2.0), r),
                                         _mm_set1_pd(1.0)));
  }
  for (i = scalarLB; i < loop_ub; i++) {
    r_data[i] = 2.0 * b_data[i] - 1.0;
  }
  i = r_size[1];
  ak = a / 2.0;
  bk = b / 2.0;
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if (bk >= ak) {
      r_data[loop_ub] = (ak + bk) + (bk - ak) * r_data[loop_ub];
    } else {
      r_data[loop_ub] = rtNaN;
    }
  }
}

/* End of code generation (unifrnd.c) */
