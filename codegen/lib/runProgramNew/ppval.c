/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ppval.c
 *
 * Code generation for function 'ppval'
 *
 */

/* Include files */
#include "ppval.h"
#include "rt_nonfinite.h"
#include "runProgramNew_internal_types.h"

/* Function Definitions */
void ppval(const struct_T *pp, const double x[200], double v[200])
{
  double b_v;
  double xloc;
  int coefStride;
  int high_i;
  int ix;
  int low_i;
  int low_ip1;
  int mid_i;
  int numTerms;
  coefStride = pp->breaks.size[1] - 1;
  numTerms = pp->coefs.size[1];

  for (ix = 0; ix < 200; ix++) {
    high_i = pp->breaks.size[1];
    low_i = 1;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      mid_i = (low_i >> 1) + (high_i >> 1);
      if ((((unsigned int)low_i & 1U) == 1U) &&
          (((unsigned int)high_i & 1U) == 1U)) {
        mid_i++;
      }
      if (x[ix] >= pp->breaks.data[mid_i - 1]) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }
    xloc = x[ix] - pp->breaks.data[low_i - 1];
    b_v = pp->coefs.data[low_i - 1];
    for (high_i = 2; high_i <= numTerms; high_i++) {
      b_v =
          xloc * b_v + pp->coefs.data[(low_i + (high_i - 1) * coefStride) - 1];
    }
    v[ix] = b_v;
  }
}

/* End of code generation (ppval.c) */
