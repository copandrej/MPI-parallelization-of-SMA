/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgramNew_data.c
 *
 * Code generation for function 'runProgramNew_data'
 *
 */

/* Include files */
#include "runProgramNew_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
double freq;

bool freq_not_empty;

unsigned int state[625];

omp_nest_lock_t runProgramNew_nestLockGlobal;

bool isInitialized_runProgramNew = false;

/* End of code generation (runProgramNew_data.c) */
