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

/* Function Definitions */
void unifrnd(double a, double b, double r[10])
{
  double ak;
  double bk;
  int k;
  d_rand(r);
  ak = a / 2.0;
  bk = b / 2.0;
  for (k = 0; k < 10; k++) {
    double d;
    d = 2.0 * r[k] - 1.0;
    r[k] = d;
    if (bk >= ak) {
      d = (ak + bk) + (bk - ak) * d;
      r[k] = d;
    } else {
      r[k] = rtNaN;
    }
  }
}

/* End of code generation (unifrnd.c) */
