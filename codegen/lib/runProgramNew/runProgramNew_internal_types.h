/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runProgramNew_internal_types.h
 *
 * Code generation for function 'runProgramNew'
 *
 */

#ifndef RUNPROGRAMNEW_INTERNAL_TYPES_H
#define RUNPROGRAMNEW_INTERNAL_TYPES_H

/* Include files */
#include "rtwtypes.h"
#include "runProgramNew_types.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_1x10
#define struct_emxArray_real_T_1x10
struct emxArray_real_T_1x10 {
  double data[10];
  int size[2];
};
#endif /* struct_emxArray_real_T_1x10 */
#ifndef typedef_emxArray_real_T_1x10
#define typedef_emxArray_real_T_1x10
typedef struct emxArray_real_T_1x10 emxArray_real_T_1x10;
#endif /* typedef_emxArray_real_T_1x10 */

#ifndef struct_emxArray_real_T_9x4
#define struct_emxArray_real_T_9x4
struct emxArray_real_T_9x4 {
  double data[36];
  int size[2];
};
#endif /* struct_emxArray_real_T_9x4 */
#ifndef typedef_emxArray_real_T_9x4
#define typedef_emxArray_real_T_9x4
typedef struct emxArray_real_T_9x4 emxArray_real_T_9x4;
#endif /* typedef_emxArray_real_T_9x4 */

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  emxArray_real_T_1x10 breaks;
  emxArray_real_T_9x4 coefs;
} struct_T;
#endif /* typedef_struct_T */

#endif
/* End of code generation (runProgramNew_internal_types.h) */
