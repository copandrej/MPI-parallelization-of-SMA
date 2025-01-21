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
#include "runProgramNew_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double F00(const double x_data[], const int x_size[2], double model_xs,
           double model_ys, double model_xt, double model_yt,
           const emxArray_real_T *model_xobs, const emxArray_real_T *model_yobs,
           const emxArray_real_T *model_robs, double sol_TS_data[],
           int sol_TS_size[2], double sol_XS_data[], int sol_XS_size[2],
           double sol_YS_data[], int sol_YS_size[2], double sol_tt[200],
           double sol_xx[200], double sol_yy[200], double sol_dx[199],
           double sol_dy[199], double *sol_L, double *sol_Violation,
           bool *sol_IsFeasible);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Get_Functions_SMA.h) */
