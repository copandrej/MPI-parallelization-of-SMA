/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.h
 *
 * Code generation for function 'sortIdx'
 *
 */

#ifndef SORTIDX_H
#define SORTIDX_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void merge_block(int idx_data[], double x_data[], int offset, int n,
                 int preSortLevel, int iwork_data[], double xwork_data[]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (sortIdx.h) */
