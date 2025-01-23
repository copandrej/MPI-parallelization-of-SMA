#include "main.h"
#include "rt_nonfinite.h"
#include "runProgramNew.h"
#include "runProgramNew_terminate.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <showPlot> <NrCard>\n", argv[0]);
    return 1;
  }

  runProgramNew(argc, argv);
  return 0;
}
