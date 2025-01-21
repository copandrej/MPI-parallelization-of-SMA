/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_runProgramNew_info.c
 *
 * Code generation for function 'runProgramNew'
 *
 */

/* Include files */
#include "_coder_runProgramNew_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8] = {
      "789ced58cd6ed3401076a0fc1ca035077a4042e2c6a9a83f94123815a749436bd76d129a"
      "9440bb7136b15bff44eb75482b71e68284b8f2089c90b87041ea8967"
      "40e209b8f00c24713689b75ac528ae21c673d94c3eef7e33b3cea7c97089ac98e0386e9a"
      "73edfb5d77bddef3f9de7a81f31a8d277aeb15ca2776899bf2ec23f8",
      "bbdeaa5826862dec3a2630607f67d532341398387fdc801c82b6a53761b58bd4341de635"
      "03e6861da9e319e921a8ef74a0ce674185ca51ce3138a4da8308f561"
      "a75f8f2f8c7ca77cd6e319a31e3c853f5f7b213c2a176c88ecb2a022cdc61a30ef6c0054"
      "2fa72cc531a089ed7246c3eb4ea52ccad9b9064040d7a1ae9d00ac59",
      "e69c559bcb89ab65e49832b2ea0818127c75cf18e4d118338f69caa7f320b88020c050b4"
      "aa506fc733f8fe604cfecb4c7e17a95a4e4587c1dddb2e93cf8b0774"
      "6fdeb2b52f6e54dd667ce641af83e7af76d76fea8f2e1416dfb5e2afaf61f211fb5b7c2d"
      "c6797edfc359061f4fe14bebad1525891617eaba0436b79b5bdb5bb6",
      "9819c4218fe0191507c7f0c33a3f2a3a3ceefb7063441e04cf40bc9f764ca51394bddf95"
      "e2ae05a5c753943f88c3451415a061bed331f9f6987c5e3ca0fb3b53"
      "bece1d0ee773c08837d6657f7cc4a2aecb85277551cd19cbba390f25f0742129341f2e08"
      "b12eff6bba7c30661e179979b80851e0a0faf119cae7a8e7085eeb89",
      "d8be0acc6abb4126fc9fc6e4df1cc14ff080eeadafc061e9c5ac1eaefebee13f4861f211"
      "9b54fdbdc9e0e3297c2763a41b96dc4a358e5677d5c3fc62515ead70"
      "d1d1df49ff1d873597d04cad1d3109279e4bf8bc2f6fd9429c4bdc2a85abbf8f3fe35c98"
      "7cc426557ffdf6bfd6465ddc5e3cc9e7cd6caab097cb9bcdbd523a15",
      "1dfd3d65ecf75bc7978cf3790a3fbfffb589f4fc7cf8f30919201be62cdde936a7c1cf27"
      "46e9b28d91a3e0899d4f9c295fd8f389f7cfc3d5e78f95d73fc3e423"
      "16757d4e2fad670ba595fbc9c3cd950db9f12053d34bc9b5e8e8f3ffde1fb3eac553abac"
      "5b78584f2655874b4c3e2f1e940e536523321cd93ef9f6dbb84fee58",
      "d03a8cf152094949b8bb261c4bf522ac1577964184fae4a8cc89633dfe33be588fcf972f"
      "d663d7623df677fe6f91dfb2bb",
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
                emlrtMxCreateString("runProgramNew"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "ResolvedFilePath",
                emlrtMxCreateString("C:\\Users\\Christian "
                                    "Karg\\Documents\\GitHub\\MPI-"
                                    "parallelization-of-SMA\\runProgramNew.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739638.67556712963));
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
                emlrtMxCreateString("cCc5Dkkuiix1TQHIc1LMpE"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_runProgramNew_info.c) */
