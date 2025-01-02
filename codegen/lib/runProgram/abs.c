/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "abs.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void b_abs(const double x_data[], const int x_size[2], double y_data[],
           int y_size[2])
{
  int i;
  int k;
  i = x_size[1];
  y_size[0] = 1;
  y_size[1] = x_size[1];
  for (k = 0; k < i; k++) {
    y_data[k] = fabs(x_data[k]);
  }
}

/* End of code generation (abs.c) */
