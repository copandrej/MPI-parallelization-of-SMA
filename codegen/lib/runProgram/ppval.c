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
#include "runProgram_internal_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void ppval(const struct_T *pp, const double x[200], double v[200])
{
  double xloc;
  int high_i;
  int ix;
  int low_i;
  int low_ip1;
  int mid_i;

  for (ix = 0; ix < 200; ix++) {
    if (rtIsNaN(x[ix])) {
      xloc = rtNaN;
    } else {
      low_i = 0;
      low_ip1 = 2;
      high_i = 7;
      while (high_i > low_ip1) {
        mid_i = ((low_i + high_i) + 1) >> 1;
        if (x[ix] >= pp->breaks[mid_i - 1]) {
          low_i = mid_i - 1;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      xloc = x[ix] - pp->breaks[low_i];
      xloc = xloc * (xloc * (xloc * pp->coefs[low_i] + pp->coefs[low_i + 6]) +
                     pp->coefs[low_i + 12]) +
             pp->coefs[low_i + 18];
    }
    v[ix] = xloc;
  }
}

/* End of code generation (ppval.c) */