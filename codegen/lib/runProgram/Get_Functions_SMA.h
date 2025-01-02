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
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double F00(const double x[10], double sol_TS[7], double sol_XS[7],
           double sol_YS[7], double sol_tt[200], double sol_xx[200],
           double sol_yy[200], double sol_dx[199], double sol_dy[199],
           double *sol_L, double *sol_Violation, bool *sol_IsFeasible);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Get_Functions_SMA.h) */
