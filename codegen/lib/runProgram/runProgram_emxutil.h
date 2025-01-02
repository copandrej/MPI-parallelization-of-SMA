/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgram_emxutil.h
 *
 * Code generation for function 'runProgram_emxutil'
 *
 */

#ifndef RUNPROGRAM_EMXUTIL_H
#define RUNPROGRAM_EMXUTIL_H

/* Include files */
#include "rtwtypes.h"
#include "runProgram_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel);

extern void emxFree_char_T(emxArray_char_T **pEmxArray);

extern void emxInit_char_T(emxArray_char_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (runProgram_emxutil.h) */
