/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_runProgramNew_api.h
 *
 * Code generation for function 'runProgramNew'
 *
 */

#ifndef _CODER_RUNPROGRAMNEW_API_H
#define _CODER_RUNPROGRAMNEW_API_H

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
void runProgramNew(real_T showPlot, real_T NrCard);

void runProgramNew_api(const mxArray *const prhs[2]);

void runProgramNew_atexit(void);

void runProgramNew_initialize(void);

void runProgramNew_terminate(void);

void runProgramNew_xil_shutdown(void);

void runProgramNew_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_runProgramNew_api.h) */
