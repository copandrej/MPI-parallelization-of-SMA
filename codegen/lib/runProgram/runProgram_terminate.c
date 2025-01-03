/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgram_terminate.c
 *
 * Code generation for function 'runProgram_terminate'
 *
 */

/* Include files */
#include "runProgram_terminate.h"
#include "rt_nonfinite.h"
#include "runProgram_data.h"
#include "omp.h"

/* Function Definitions */
void runProgram_terminate(void)
{
  omp_destroy_nest_lock(&runProgram_nestLockGlobal);
  isInitialized_runProgram = false;
}

/* End of code generation (runProgram_terminate.c) */
