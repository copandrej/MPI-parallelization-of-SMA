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
#include "runProgramNew_data.h"

/* Function Definitions */
void b_rand(double varargin_1, double varargin_2, double r_data[],
            int r_size[2])
{
  int i;
  int k;
  r_size[0] = (int)varargin_1;
  r_size[1] = (int)varargin_2;
  i = (int)varargin_1 * (int)varargin_2;
  for (k = 0; k < i; k++) {
    r_data[k] = b_eml_rand_mt19937ar(state);
  }
}

double c_rand(void)
{
  return b_eml_rand_mt19937ar(state);
}

void d_rand(const double varargin_1[2], double r_data[], int r_size[2])
{
  int i;
  int k;
  r_size[0] = 1;
  i = (int)varargin_1[1];
  r_size[1] = (int)varargin_1[1];
  for (k = 0; k < i; k++) {
    r_data[k] = b_eml_rand_mt19937ar(state);
  }
}

/* End of code generation (rand.c) */
