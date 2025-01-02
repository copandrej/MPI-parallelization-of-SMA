/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * timeKeeper.c
 *
 * Code generation for function 'timeKeeper'
 *
 */

/* Include files */
#include "timeKeeper.h"
#include "rt_nonfinite.h"
#include "runProgram_data.h"
#include "coder_posix_time.h"

/* Variable Definitions */
static bool savedTime_not_empty;

/* Function Definitions */
double b_timeKeeper(const coderTimespec *savedTime, double *outTime_tv_nsec)
{
  double outTime_tv_sec;
  outTime_tv_sec = savedTime->tv_sec;
  *outTime_tv_nsec = savedTime->tv_nsec;
  return outTime_tv_sec;
}

void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec,
                coderTimespec *savedTime)
{
  if (!savedTime_not_empty) {
    coderTimespec b_timespec;
    if (!freq_not_empty) {
      freq_not_empty = true;
      coderInitTimeFunctions(&freq);
    }
    coderTimeClockGettimeMonotonic(&b_timespec, freq);
    savedTime_not_empty = true;
  }
  savedTime->tv_sec = newTime_tv_sec;
  savedTime->tv_nsec = newTime_tv_nsec;
}

void timeKeeper_init(void)
{
  savedTime_not_empty = false;
}

/* End of code generation (timeKeeper.c) */
