/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_runProgram_info.c
 *
 * Code generation for function 'runProgram'
 *
 */

/* Include files */
#include "_coder_runProgram_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8] = {
      "789ced58cd6ed3401076a0fc1ca00d170e4848dc3805b50da5044ee0343fb44e139ca84d"
      "1b48b7f6267659afa3f53a6a2af1064888d7e084c4850b524f3c0312"
      "4fc085672089b349ec6a9520bb861acf6532f9bcfbcdcc3a9f3623248a5242108445c1b1"
      "eff71d7f73142747fe92e0362f9e18f96b9e98d91561c1b58ee1ef47",
      "5e313185c7d4093030e078a56a1a3a0698567b1d28106899a80bd521d2d211acea0694a7"
      "83d220327253d038184083cfa2069537b26d0844b32619a2e960dc8f"
      "2f9c7a17e6ec87cce947d283ef6fbc129f346a16245643d4886e511de07b9b80b41b5953"
      "b10d88a9d5c8ebb4601f36a47231d501042004917e02a86ee294d94a",
      "c9d2b306b17199986d028c0786ab8e8ecf3a163db1b70e868b04020a255385a89fcfe4fb"
      "039ffc57b9fc0ea29af62182c19ddb0e97cf8d07746eeeb6f5cf6e56"
      "df96e6acc3eb27cf5f1ffa6fda8f211416df8ddd5f5fc3e463f6b7f88e39fbcdfb1edee6"
      "f0253d78ba70bcae64c8ea4a1b95c056a5bb5dd9b6a4fc248ff20c9e",
      "5979089c38acfda3a2c37edf875b33ea60781ed266cec6ca2029ab399462571e073ef358"
      "f0c4933c1c44d10099e63bf5c9b7c7e573e3019ddf99f68d8e31d6e5"
      "80f898455d976bcfdb92261b6b082fc31278b19211bb8f57c45897ff355d3ef059c7656e"
      "1d0ec21438a8fbf89227163ccf31bc3512b1a606b0dabf2033fe4f3e",
      "f9b766f0333ca0731b2b70acbfc1f0318bbafe566a0555872d1daf1689964dab3db970b4"
      "938d8efe5ef4df715873091debfd8c593af15c62cef372b72dc4b9c4"
      "9d7ab8fafbf43395c3e4631675fd3537db5265f5a45ac5c56c6d4faee2ee5e3d1721fd3d"
      "e5ac9fb78faf39fb273df8f9fdaf4de49697c39f4f9401b1a06c227b",
      "78390d7e3e314b972d4a6c855ed8f9c499f6853d9ff8b01fae3e7f3c7cfb334c3e6651d7"
      "e75cba50acd5d71f668eb6d637cb9d47f916aa6736a2a3cffffbfd98"
      "d7afa4c7979149a7f5e4a2ea709dcbe7c683d2614fdb980c47f69e7cf75d7c4f1e58d03a"
      "4c69ba4e4a19b8b321f64aed5dd8da7db90622744f8eca9c38d6e33f",
      "e38bf5f87cf9623d762cd6e3f9f6ff0d83b9af92",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 10224U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("runProgram"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\Users\\Christian "
          "Karg\\Documents\\GitHub\\MPI-parallelization-of-SMA\\runProgram.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739634.45917824074));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2806996 (R2024b) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("BDqKC7NwjjnJLRowT94jl"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_runProgram_info.c) */
