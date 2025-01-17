/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SMA.h
 *
 * Code generation for function 'SMA'
 *
 */

#ifndef SMA_H
#define SMA_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void binary_expand_op(double in1_data[], const int in1_size[2], int in2,
                      const bool in3_data[], const int in3_size[2],
                      const bool in4_data[], const int in4_size[2],
                      const signed char in5_data[], const int in5_size[2],
                      const signed char in6_data[], const int in6_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (SMA.h) */
