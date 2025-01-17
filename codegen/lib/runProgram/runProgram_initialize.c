/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgram_initialize.c
 *
 * Code generation for function 'runProgram_initialize'
 *
 */

/* Include files */
#include "runProgram_initialize.h"
#include "CoderTimeAPI.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"
#include "runProgram_data.h"
#include "timeKeeper.h"

/* Function Definitions */
void runProgram_initialize(void)
{
  c_CoderTimeAPI_callCoderClockGe();
  timeKeeper_init();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_runProgram = true;
}

/* End of code generation (runProgram_initialize.c) */
