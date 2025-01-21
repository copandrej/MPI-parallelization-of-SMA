/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * spline.h
 *
 * Code generation for function 'spline'
 *
 */

#ifndef SPLINE_H
#define SPLINE_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void spline(const double x_data[], const int x_size[2], const double y_data[],
            const int y_size[2], double output[200]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (spline.h) */
