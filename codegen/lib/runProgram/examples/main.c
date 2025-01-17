#include "main.h"
#include "rt_nonfinite.h"
#include "runProgram.h"
#include "runProgram_terminate.h"
#include <stdlib.h>
#include <stdio.h>

/* Function Declarations */
static double argInit_real_T(void);

/* Function Definitions */
static double argInit_real_T(void)
{
  return 0.0;
}

int main(int argc, char **argv)
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <showPlot> <NrCard>\n", argv[0]);
    return 1;
  }

  double showPlot = atof(argv[1]);
  double NrCard = atof(argv[2]);

  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
  You can call entry-point functions multiple times. */
  runProgram(showPlot, NrCard);

  /* Terminate the application.
  You do not need to do this more than one time. */
  runProgram_terminate();
  return 0;
}

/* End of code generation (main.c) */