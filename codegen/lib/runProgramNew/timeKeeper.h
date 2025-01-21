/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * timeKeeper.h
 *
 * Code generation for function 'timeKeeper'
 *
 */

#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

/* Include files */
#include "rtwtypes.h"
#include "coder_posix_time.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_timeKeeper(const coderTimespec *savedTime, double *outTime_tv_nsec);

void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec,
                coderTimespec *savedTime);

void timeKeeper_init(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (timeKeeper.h) */
