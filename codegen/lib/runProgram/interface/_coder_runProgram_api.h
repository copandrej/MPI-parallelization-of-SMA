/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_runProgram_api.h
 *
 * Code generation for function 'runProgram'
 *
 */

#ifndef _CODER_RUNPROGRAM_API_H
#define _CODER_RUNPROGRAM_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void runProgram(real_T showPlot, real_T NrCard);

void runProgram_api(const mxArray *const prhs[2]);

void runProgram_atexit(void);

void runProgram_initialize(void);

void runProgram_terminate(void);

void runProgram_xil_shutdown(void);

void runProgram_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_runProgram_api.h) */
