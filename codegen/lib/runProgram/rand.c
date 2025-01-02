/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.c
 *
 * Code generation for function 'rand'
 *
 */

/* Include files */
#include "rand.h"
#include "eml_rand_mt19937ar.h"
#include "rt_nonfinite.h"
#include "runProgram_data.h"

/* Function Definitions */
void b_rand(double r[500])
{
  int k;
  for (k = 0; k < 500; k++) {
    r[k] = b_eml_rand_mt19937ar(state);
  }
}

double c_rand(void)
{
  return b_eml_rand_mt19937ar(state);
}

void d_rand(double r[10])
{
  int k;
  for (k = 0; k < 10; k++) {
    r[k] = b_eml_rand_mt19937ar(state);
  }
}

/* End of code generation (rand.c) */
