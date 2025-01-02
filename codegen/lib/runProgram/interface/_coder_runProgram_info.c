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
      "789ced58cd6ed3401076a0fc5c68cd0190404808712d2a2dd0064e25a9dd28751362a769"
      "d294d67536891b7b1dadd7551b89374042bc0627242e1cfb1e8807e0"
      "2dc88f3789b75a2592cd42accc6532f96c7f33b3cea7c908898c92100461511858fee9c0"
      "dff163d1f7d784a0d178c2f737a998d80d6121701fc13ffbde702006",
      "e7781040dd06c33b6b8e6d421d62eda20d04045cc73a03b53e52372da0993650c783dd5e"
      "644b63d030e841bdcfa926305aaa670ba8e98e32b4c683613f7e30ea"
      "5d98b21f2aa31f22851f6c1da6de548b2e406e35d544a68b4d1d3ec9eaa8514d3b866703"
      "88ddaa6ce26defa4aae433cb6d1de996052cb3a363d381cb4e7d5955",
      "36abc88379e434906e3fb70375b443d6b148c5741d044f21a063a038356075f3197d7f1c"
      "929ff55e893e5273bc130b44776e25265f108fe8dc826deb9edda4be"
      "2d4d5907ed47d7dfeefb67e59f7d8817df835f8f523cf988fd2bbe73c6f3a67d0fef33f8"
      "440a77d3957671a3902b38ebf2696bb5e129ad4e5a1ad3f5093c93f2",
      "101831afe7c74587c3be0f7727d4417019e023c983462f29f7a82fc5813c8e43e6b140c5"
      "a33c0688d1d4d138df6548be0a932f8847747e57dae71f636c75f956"
      "6b2fc3938fd8aceaf23d069f48e19e5694e4770d6953f33a3b1b20b72f5decd585b92eff"
      "6fba7c1cb28eebcc3a060851e0a8e6f1252a16a8eb085ef745eca8a9",
      "c35a774026fcdf42f2ef4ce0277844e73654605e7af190b3fe3efe84559e7cc466557fa7"
      "9d8b8dd3920c9595925b8672ee453a9b2ce432b518cdc5b3fe3be6b5"
      "9730a1d9cd98a433df4b4c795ec1b671dc4bf0d6dfb7dfe7fadbb3a8f5d7c93694f7ab1d"
      "4d839974b1a26af0ac5296d2f1d1df4bc6fdd3f6f103e3f92285ffbd",
      "ffb509696585ff7e22af2317a88ee5f587d3e8f7139374d9c5c833f0ccee27aeb48ff77e"
      "e2cb015f7dfe7af2f1374f3e6271d767696d3b532cafbf4c9eeeac67"
      "f3edd772dd2a27b7e2a3cf71d94f849d93597d13299fb71c3cae2bb3aac765265f108f4a"
      "8fa9b611398eedbc3cdf570c2c6a3dc678ad8c7693a0b495bad86dec",
      "83fa7ee1951e8379f90f5aba4fc3",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 8808U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("runProgram"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\Users\\Christian "
          "Karg\\Documents\\GitHub\\MPI-parallelization-of-SMA\\runProgram.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739619.4269907407));
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
                emlrtMxCreateString("W02E0DDyiMzQgNmrp55gFF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_runProgram_info.c) */
