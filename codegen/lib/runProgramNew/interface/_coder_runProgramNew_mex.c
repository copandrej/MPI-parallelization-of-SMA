/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_runProgramNew_mex.c
 *
 * Code generation for function 'runProgramNew'
 *
 */

/* Include files */
#include "_coder_runProgramNew_mex.h"
#include "_coder_runProgramNew_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)plhs;
  mexAtExit(&runProgramNew_atexit);
  runProgramNew_initialize();
  unsafe_runProgramNew_mexFunction(nlhs, nrhs, prhs);
  runProgramNew_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void unsafe_runProgramNew_mexFunction(int32_T nlhs, int32_T nrhs,
                                      const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        13, "runProgramNew");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "runProgramNew");
  }
  /* Call the function. */
  runProgramNew_api(prhs);
}

/* End of code generation (_coder_runProgramNew_mex.c) */
