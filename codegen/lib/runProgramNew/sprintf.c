/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprintf.c
 *
 * Code generation for function 'sprintf'
 *
 */

/* Include files */
#include "sprintf.h"
#include "rt_nonfinite.h"
#include "runProgramNew_emxutil.h"
#include "runProgramNew_types.h"
#include <stddef.h>
#include <stdio.h>

/* Function Definitions */
void b_sprintf(double varargin_1, emxArray_char_T *str)
{
  int i;
  int nbytes;
  char *str_data;
  nbytes = snprintf(NULL, 0, "%.2f", varargin_1);
  i = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes + 1;
  emxEnsureCapacity_char_T(str, i);
  str_data = str->data;
  snprintf(&str_data[0], (size_t)(nbytes + 1), "%.2f", varargin_1);
  i = str->size[0] * str->size[1];
  if (nbytes < 1) {
    str->size[1] = 0;
  } else {
    str->size[1] = nbytes;
  }
  emxEnsureCapacity_char_T(str, i);
}

/* End of code generation (sprintf.c) */
