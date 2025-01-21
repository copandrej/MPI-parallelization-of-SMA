/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.h
 *
 * Code generation for function 'rand'
 *
 */

#ifndef RAND_H
#define RAND_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_rand(double varargin_1, double varargin_2, double r_data[],
            int r_size[2]);

double c_rand(void);

void d_rand(const double varargin_1[2], double r_data[], int r_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (rand.h) */
