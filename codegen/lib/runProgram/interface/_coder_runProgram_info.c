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
      "789ced58bd6fd3401477a07c2cb461614042b0212115f583d20626ea361f244e539cd0a6"
      "4d69afce25369ccfd1f91cb595909898901013ff0313120b6311e22f"
      "604162636363658224ce25b12b2b41760f6afc96cbcbcf77bff7de393fbd3c2196916282"
      "208c0bb67db96eaf17ba7ebcbb9e129ce6c663ddf59ccb6776461873",
      "ec63f8cbeeaa1898c23d6a3b18e8b0b7b36ae81a069816f71b5020d0345013563b484d43"
      "b0a8e9501e74f26d4f4f0e403da70db53f8b2a549ec8962e10d5ec47"
      "88069d5e3dde7be43b36623d648f7ac45df8e6f29678a7523221312ba24a34936a005fcb"
      "0252af2c198aa5434ccd4a4aa3696bb7221532930d40004210690780",
      "6a069e346a93b274af422c5c20469d00fda6eec8a3e1338f7197efce83e122818042c9a8"
      "42d48aa7fffd8e4ffeb39efc365235ac5d0483bbb7354f3e271ed0bd"
      "39cbd6babb61759b18310ff7da7ffe7c67fda07eed40bcf87e2dbcfec9938fd9dfe2dbf3"
      "386fd4f7f092075fdc85cfa6f7e695049999aea33cc8ad365756574c",
      "29d58fa3308467581c8287cfebfcb0e8b0dff7e1e2903c189e82743b6961a51d94b9dd91"
      "62471c3b3ee31873f9fd386c44510119e43bf4c9b7e1c9e7c403babf"
      "23e5eb5e23371df9c85997affef826f3e46316765d2e2dd62555d6e7109e8279707f3a21"
      "3617a6c54897ff355ddef199c769cf3c6c84297050fdf884cb175ccf",
      "31bcd615b16d15e06aab4166fc6f7df2e786f0333ca07beb29302fbdf8c4597f9f3dbff1"
      "99271fb3b0ebeffe62962c2c2673b97543ab3e9c13f33a6aa6d2e1d1"
      "df93fe3be63597d0b0d68a988513cd2546bc2f67d938ce252e97f9eaefdd7734ea7f85e0"
      "f5d7c8d6a5d59983621167964a1b72113737cac9a5f0e8efa1c7fe51",
      "ebf8c8e3fcb80b3fbeffb5b1e4d414fff944011013ca06b23acd69f0f38961ba6c526229"
      "f4c4ce278e948ff77ce2d5265f7d7eb3fbf43b4f3e6661d7e7e46c3a"
      "532acfdf4a3ccecd670b8ddba91a2a2796c3a3cfff7b7fec55afb86b2d20830eeac949d5"
      "e1b2279f130f4a875d6563321cda3ef9ca8ba84f6e5bd03a4ce96c99",
      "e413706d59dccfd7d7616dfdc11c08519f1c963971a4c77fc617e9f1f1f2457a6c5ba4c7"
      "a39dff1b742bb022",
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
                emlrtMxCreateDoubleScalar(739634.421261574));
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
                emlrtMxCreateString("2Zw9WhUhYNExE9ifYWc4T"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_runProgram_info.c) */
