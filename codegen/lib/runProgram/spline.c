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
#include <string.h>

/* Function Definitions */
void spline(const double x_data[], const int x_size[2], const double y_data[],
            const int y_size[2], double output[200])
{
  __m128d r;
  __m128d r1;
  struct_T expl_temp;
  double dv[200];
  double md_data[10];
  double s_data[10];
  double dvdf_data[9];
  double dx_data[9];
  double b_r;
  double d31;
  double dnnm2;
  double dzdxdx;
  int i;
  int k;
  int nxm1_tmp;
  int scalarLB;
  int vectorUB;
  int vectorUB_tmp;
  int yoffset;
  signed char szs_idx_1;
  bool has_endslopes;
  has_endslopes = (y_size[1] == x_size[1] + 2);
  nxm1_tmp = x_size[1] - 1;
  if (has_endslopes) {
    szs_idx_1 = (signed char)(y_size[1] - 2);
    yoffset = 1;
  } else {
    szs_idx_1 = (signed char)y_size[1];
    yoffset = 0;
  }
  i = (unsigned char)(x_size[1] - 1);
  scalarLB = ((unsigned char)(x_size[1] - 1) >> 1) << 1;
  vectorUB = scalarLB - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    r = _mm_sub_pd(_mm_loadu_pd(&x_data[k + 1]), _mm_loadu_pd(&x_data[k]));
    _mm_storeu_pd(&dx_data[k], r);
    vectorUB_tmp = yoffset + k;
    _mm_storeu_pd(&dvdf_data[k],
                  _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&y_data[vectorUB_tmp + 1]),
                                        _mm_loadu_pd(&y_data[vectorUB_tmp])),
                             r));
  }
  for (k = scalarLB; k < i; k++) {
    dzdxdx = x_data[k + 1] - x_data[k];
    dx_data[k] = dzdxdx;
    vectorUB = yoffset + k;
    dvdf_data[k] = (y_data[vectorUB + 1] - y_data[vectorUB]) / dzdxdx;
  }
  vectorUB = (((x_size[1] - 2) / 2) << 1) + 2;
  vectorUB_tmp = vectorUB - 2;
  for (k = 2; k <= vectorUB_tmp; k += 2) {
    __m128d r2;
    __m128d r3;
    r = _mm_loadu_pd(&dx_data[k - 1]);
    r1 = _mm_loadu_pd(&dvdf_data[k - 2]);
    r2 = _mm_loadu_pd(&dx_data[k - 2]);
    r3 = _mm_loadu_pd(&dvdf_data[k - 1]);
    _mm_storeu_pd(&s_data[k - 1],
                  _mm_mul_pd(_mm_set1_pd(3.0), _mm_add_pd(_mm_mul_pd(r, r1),
                                                          _mm_mul_pd(r2, r3))));
  }
  for (k = vectorUB; k <= nxm1_tmp; k++) {
    s_data[k - 1] = 3.0 * (dx_data[k - 1] * dvdf_data[k - 2] +
                           dx_data[k - 2] * dvdf_data[k - 1]);
  }
  if (has_endslopes) {
    d31 = 0.0;
    dnnm2 = 0.0;
    s_data[0] = y_data[0] * dx_data[1];
    s_data[x_size[1] - 1] = dx_data[x_size[1] - 3] * y_data[x_size[1] + 1];
  } else {
    d31 = x_data[2] - x_data[0];
    dnnm2 = x_data[x_size[1] - 1] - x_data[x_size[1] - 3];
    s_data[0] = ((dx_data[0] + 2.0 * d31) * dx_data[1] * dvdf_data[0] +
                 dx_data[0] * dx_data[0] * dvdf_data[1]) /
                d31;
    dzdxdx = dx_data[x_size[1] - 2];
    s_data[x_size[1] - 1] = ((dzdxdx + 2.0 * dnnm2) * dx_data[x_size[1] - 3] *
                                 dvdf_data[x_size[1] - 2] +
                             dzdxdx * dzdxdx * dvdf_data[x_size[1] - 3]) /
                            dnnm2;
  }
  scalarLB = x_size[1];
  md_data[0] = dx_data[1];
  dzdxdx = dx_data[x_size[1] - 3];
  md_data[x_size[1] - 1] = dzdxdx;
  for (k = 2; k <= vectorUB_tmp; k += 2) {
    r = _mm_loadu_pd(&dx_data[k - 1]);
    r1 = _mm_loadu_pd(&dx_data[k - 2]);
    _mm_storeu_pd(&md_data[k - 1],
                  _mm_mul_pd(_mm_set1_pd(2.0), _mm_add_pd(r, r1)));
  }
  for (k = vectorUB; k <= nxm1_tmp; k++) {
    md_data[k - 1] = 2.0 * (dx_data[k - 1] + dx_data[k - 2]);
  }
  b_r = dx_data[1] / md_data[0];
  md_data[1] -= b_r * d31;
  s_data[1] -= b_r * s_data[0];
  for (k = 3; k <= nxm1_tmp; k++) {
    b_r = dx_data[k - 1] / md_data[k - 2];
    md_data[k - 1] -= b_r * dx_data[k - 3];
    s_data[k - 1] -= b_r * s_data[k - 2];
  }
  b_r = dnnm2 / md_data[x_size[1] - 2];
  md_data[x_size[1] - 1] -= b_r * dzdxdx;
  s_data[x_size[1] - 1] -= b_r * s_data[x_size[1] - 2];
  s_data[x_size[1] - 1] /= md_data[x_size[1] - 1];
  for (k = nxm1_tmp; k >= 2; k--) {
    s_data[k - 1] =
        (s_data[k - 1] - dx_data[k - 2] * s_data[k]) / md_data[k - 1];
  }
  s_data[0] = (s_data[0] - d31 * s_data[1]) / md_data[0];
  expl_temp.coefs.size[0] = szs_idx_1 - 1;
  expl_temp.coefs.size[1] = 4;
  for (vectorUB = 0; vectorUB < i; vectorUB++) {
    dzdxdx = dvdf_data[vectorUB];
    b_r = s_data[vectorUB];
    d31 = dx_data[vectorUB];
    dnnm2 = (dzdxdx - b_r) / d31;
    dzdxdx = (s_data[vectorUB + 1] - dzdxdx) / d31;
    expl_temp.coefs.data[vectorUB] = (dzdxdx - dnnm2) / d31;
    expl_temp.coefs.data[(szs_idx_1 + vectorUB) - 1] = 2.0 * dnnm2 - dzdxdx;
    expl_temp.coefs.data[((szs_idx_1 - 1) << 1) + vectorUB] = b_r;
    expl_temp.coefs.data[3 * (szs_idx_1 - 1) + vectorUB] =
        y_data[yoffset + vectorUB];
  }
  expl_temp.breaks.size[0] = 1;
  expl_temp.breaks.size[1] = x_size[1];
  if (scalarLB - 1 >= 0) {
    memcpy(&expl_temp.breaks.data[0], &x_data[0],
           (unsigned int)scalarLB * sizeof(double));
  }
  for (i = 0; i < 200; i++) {
    dv[i] = 0.0050251256281407036 * (double)i;
  }
  ppval(&expl_temp, dv, output);
}

/* End of code generation (spline.c) */
