/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgramNew_terminate.c
 *
 * Code generation for function 'runProgramNew_terminate'
 *
 */

/* Include files */
#include "runProgramNew_terminate.h"
#include "rt_nonfinite.h"
#include "runProgramNew_data.h"
#include "omp.h"

/* Function Definitions */
void runProgramNew_terminate(void)
{
  omp_destroy_nest_lock(&runProgramNew_nestLockGlobal);
  isInitialized_runProgramNew = false;
}

/* End of code generation (runProgramNew_terminate.c) */
