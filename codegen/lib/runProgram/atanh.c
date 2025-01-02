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
  if (*x < 0.5) {
    double absz;
    double t;
    t = *x + *x;
    t += t * (*x / (1.0 - *x));
    absz = fabs(t);
    if ((absz > 4.503599627370496E+15) || rtIsNaN(t)) {
      t++;
      t = log(t);
    } else if (!(absz < 2.2204460492503131E-16)) {
      t = log(t + 1.0) * (t / ((t + 1.0) - 1.0));
    }
    *x = t / 2.0;
  } else {
    double absz;
    double t;
    t = (*x + *x) / (1.0 - *x);
    absz = fabs(t);
    if ((absz > 4.503599627370496E+15) || rtIsNaN(t)) {
      t++;
      t = log(t);
    } else if (!(absz < 2.2204460492503131E-16)) {
      t = log(t + 1.0) * (t / ((t + 1.0) - 1.0));
    }
    *x = t / 2.0;
  }
}

/* End of code generation (atanh.c) */
