/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SMA.c
 *
 * Code generation for function 'SMA'
 *
 */

/* Include files */
#include "SMA.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void binary_expand_op(double in1_data[], const int in1_size[2], int in2,
                      const bool in3_data[], const int in3_size[2],
                      const bool in4_data[], const int in4_size[2],
                      const double in5_data[], const int in5_size[2],
                      const double in6_data[], const int in6_size[2])
{
  double b_in1_data[16];
  int i;
  int stride_0_1;
  int stride_1_1_tmp;
  int stride_2_1_tmp;
  int stride_3_1;
  int stride_5_1;
  int unnamed_idx_1_tmp;
  unnamed_idx_1_tmp = in1_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1_tmp = (in3_size[1] != 1);
  stride_2_1_tmp = (in4_size[1] != 1);
  stride_3_1 = (in5_size[1] != 1);
  stride_5_1 = (in6_size[1] != 1);
  for (i = 0; i < unnamed_idx_1_tmp; i++) {
    bool b_in1_tmp;
    bool in1_tmp;
    in1_tmp = in3_data[i * stride_1_1_tmp];
    b_in1_tmp = in4_data[i * stride_2_1_tmp];
    b_in1_data[i] = (in1_data[in2 + in1_size[0] * (i * stride_0_1)] *
                         (double)(in1_tmp + b_in1_tmp == 0) +
                     in5_data[i * stride_3_1] * (double)in1_tmp) +
                    in6_data[i * stride_5_1] * (double)b_in1_tmp;
  }
  for (i = 0; i < unnamed_idx_1_tmp; i++) {
    in1_data[in2 + in1_size[0] * i] = b_in1_data[i];
  }
}

/* End of code generation (SMA.c) */
