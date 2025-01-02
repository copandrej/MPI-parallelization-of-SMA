/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "mean.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double mean(const double x[200])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 199; k++) {
    y += x[k + 1];
  }
  y /= 200.0;
  return y;
}

/* End of code generation (mean.c) */
