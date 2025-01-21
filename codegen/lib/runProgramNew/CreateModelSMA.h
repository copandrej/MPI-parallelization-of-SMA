/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CreateModelSMA.h
 *
 * Code generation for function 'CreateModelSMA'
 *
 */

#ifndef CREATEMODELSMA_H
#define CREATEMODELSMA_H

/* Include files */
#include "rtwtypes.h"
#include "runProgramNew_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double CreateModelSMA(double i, emxArray_real_T *model_xobs,
                      emxArray_real_T *model_yobs, emxArray_real_T *model_robs,
                      double *model_ys, double *model_xt, double *model_yt,
                      double *model_n, double *lb, double *ub,
                      double *NumberofPoints, double *T, double *N);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (CreateModelSMA.h) */
