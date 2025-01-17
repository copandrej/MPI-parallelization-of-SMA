/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * atanh.c
 *
 * Code generation for function 'atanh'
 *
 */

/* Include files */
#include "atanh.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void b_atanh(double *x)
{
  bool negx;
  if (*x < 0.0) {
    negx = true;
    *x = -*x;
  } else {
    negx = false;
  }
  if (*x > 1.0) {
    *x = rtNaN;
  } else if (*x < 0.5) {
    double t;
    t = *x + *x;
    t += t * (*x / (1.0 - *x));
    if (!(t < 2.2204460492503131E-16)) {
      t = log(t + 1.0) * (t / ((t + 1.0) - 1.0));
    }
    *x = t / 2.0;
  } else if (*x == 1.0) {
    *x = rtInf;
  } else {
    double t;
    t = (*x + *x) / (1.0 - *x);
    if ((t > 4.503599627370496E+15) || rtIsNaN(t)) {
      t++;
      t = log(t);
    } else {
      t = log(t + 1.0) * (t / ((t + 1.0) - 1.0));
    }
    *x = t / 2.0;
  }
  if (negx) {
    *x = -*x;
  }
}

/* End of code generation (atanh.c) */
