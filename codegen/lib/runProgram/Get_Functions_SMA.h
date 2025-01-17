/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Get_Functions_SMA.h
 *
 * Code generation for function 'Get_Functions_SMA'
 *
 */

#ifndef GET_FUNCTIONS_SMA_H
#define GET_FUNCTIONS_SMA_H

/* Include files */
#include "rtwtypes.h"
#include "runProgram_internal_types.h"
#include "runProgram_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double F00(const double x_data[], const int x_size[2], double model_xs,
           double model_ys, double model_xt, double model_yt,
           const emxArray_real_T *model_xobs, const emxArray_real_T *model_yobs,
           const emxArray_real_T *model_robs, b_struct_T *sol);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Get_Functions_SMA.h) */
