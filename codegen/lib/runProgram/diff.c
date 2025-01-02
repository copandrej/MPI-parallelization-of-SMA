/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_diff(const double x_data[], const int x_size[2], double y_data[],
            int y_size[2])
{
  int dimSize;
  int u0;
  dimSize = x_size[1];
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    u0 = x_size[1] - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y_size[0] = 1;
      y_size[1] = 0;
    } else {
      y_size[0] = 1;
      y_size[1] = x_size[1] - 1;
      if (x_size[1] - 1 != 0) {
        double work_data;
        work_data = x_data[0];
        for (u0 = 2; u0 <= dimSize; u0++) {
          double d;
          double tmp1;
          tmp1 = x_data[u0 - 1];
          d = tmp1;
          tmp1 -= work_data;
          work_data = d;
          y_data[u0 - 2] = tmp1;
        }
      }
    }
  }
}

void diff(const double x[200], double y[199])
{
  double work;
  int m;
  work = x[0];
  for (m = 0; m < 199; m++) {
    double tmp2;
    tmp2 = work;
    work = x[m + 1];
    y[m] = work - tmp2;
  }
}

/* End of code generation (diff.c) */
