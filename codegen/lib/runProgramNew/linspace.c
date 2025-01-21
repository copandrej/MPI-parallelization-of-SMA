/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * linspace.c
 *
 * Code generation for function 'linspace'
 *
 */

/* Include files */
#include "linspace.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void linspace(double n, double y_data[], int y_size[2])
{
  double delta1;
  int i;
  int k;
  y_size[0] = 1;
  i = (int)floor(n);
  y_size[1] = i;
  y_data[i - 1] = 1.0;
  y_data[0] = 0.0;
  delta1 = 1.0 / ((double)i - 1.0);
  for (k = 0; k <= i - 3; k++) {
    y_data[k + 1] = ((double)k + 1.0) * delta1;
  }
}

/* End of code generation (linspace.c) */
