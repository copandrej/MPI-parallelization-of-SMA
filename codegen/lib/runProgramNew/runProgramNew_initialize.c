/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgramNew_initialize.c
 *
 * Code generation for function 'runProgramNew_initialize'
 *
 */

/* Include files */
#include "runProgramNew_initialize.h"
#include "CoderTimeAPI.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"
#include "runProgramNew_data.h"
#include "timeKeeper.h"

/* Function Definitions */
void runProgramNew_initialize(void)
{
  c_CoderTimeAPI_callCoderClockGe();
  timeKeeper_init();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_runProgramNew = true;
}

/* End of code generation (runProgramNew_initialize.c) */
