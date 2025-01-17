/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
int sort(double x_data[], const int *x_size, int idx_data[])
{
  double vwork_data[400];
  int iidx_data[400];
  int b;
  int b_b;
  int i;
  int i1;
  int idx_size;
  int j;
  int k;
  idx_size = *x_size;
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 1; j++) {
      double xwork_data[400];
      double x4[4];
      int iwork_data[400];
      int bLen;
      int bLen2;
      int b_i;
      int i2;
      int i3;
      int i4;
      int ib;
      int iidx_tmp;
      int wOffset_tmp;
      short idx4[4];
      for (k = 0; k < idx_size; k++) {
        vwork_data[k] = x_data[k];
        iidx_data[k] = 0;
        iwork_data[k] = 0;
      }
      x4[0] = 0.0;
      idx4[0] = 0;
      x4[1] = 0.0;
      idx4[1] = 0;
      x4[2] = 0.0;
      idx4[2] = 0;
      x4[3] = 0.0;
      idx4[3] = 0;
      bLen2 = 0;
      ib = 0;
      for (k = 0; k < idx_size; k++) {
        if (rtIsNaN(vwork_data[k])) {
          iidx_tmp = (idx_size - bLen2) - 1;
          iidx_data[iidx_tmp] = k + 1;
          xwork_data[iidx_tmp] = vwork_data[k];
          bLen2++;
        } else {
          ib++;
          idx4[ib - 1] = (short)(k + 1);
          x4[ib - 1] = vwork_data[k];
          if (ib == 4) {
            double d;
            double d1;
            ib = k - bLen2;
            if (x4[0] <= x4[1]) {
              i1 = 1;
              i2 = 2;
            } else {
              i1 = 2;
              i2 = 1;
            }
            if (x4[2] <= x4[3]) {
              i3 = 3;
              i4 = 4;
            } else {
              i3 = 4;
              i4 = 3;
            }
            d = x4[i1 - 1];
            d1 = x4[i3 - 1];
            if (d <= d1) {
              d = x4[i2 - 1];
              if (d <= d1) {
                b_i = i1;
                bLen = i2;
                i1 = i3;
                i2 = i4;
              } else if (d <= x4[i4 - 1]) {
                b_i = i1;
                bLen = i3;
                i1 = i2;
                i2 = i4;
              } else {
                b_i = i1;
                bLen = i3;
                i1 = i4;
              }
            } else {
              d1 = x4[i4 - 1];
              if (d <= d1) {
                if (x4[i2 - 1] <= d1) {
                  b_i = i3;
                  bLen = i1;
                  i1 = i2;
                  i2 = i4;
                } else {
                  b_i = i3;
                  bLen = i1;
                  i1 = i4;
                }
              } else {
                b_i = i3;
                bLen = i4;
              }
            }
            iidx_data[ib - 3] = idx4[b_i - 1];
            iidx_data[ib - 2] = idx4[bLen - 1];
            iidx_data[ib - 1] = idx4[i1 - 1];
            iidx_data[ib] = idx4[i2 - 1];
            vwork_data[ib - 3] = x4[b_i - 1];
            vwork_data[ib - 2] = x4[bLen - 1];
            vwork_data[ib - 1] = x4[i1 - 1];
            vwork_data[ib] = x4[i2 - 1];
            ib = 0;
          }
        }
      }
      wOffset_tmp = idx_size - bLen2;
      if (ib > 0) {
        signed char perm[4];
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        if (ib == 1) {
          perm[0] = 1;
        } else if (ib == 2) {
          if (x4[0] <= x4[1]) {
            perm[0] = 1;
            perm[1] = 2;
          } else {
            perm[0] = 2;
            perm[1] = 1;
          }
        } else if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        b_i = (unsigned char)ib;
        for (k = 0; k < b_i; k++) {
          iidx_tmp = (wOffset_tmp - ib) + k;
          bLen = perm[k];
          iidx_data[iidx_tmp] = idx4[bLen - 1];
          vwork_data[iidx_tmp] = x4[bLen - 1];
        }
      }
      i1 = bLen2 >> 1;
      for (k = 0; k < i1; k++) {
        ib = wOffset_tmp + k;
        i2 = iidx_data[ib];
        iidx_tmp = (idx_size - k) - 1;
        iidx_data[ib] = iidx_data[iidx_tmp];
        iidx_data[iidx_tmp] = i2;
        vwork_data[ib] = xwork_data[iidx_tmp];
        vwork_data[iidx_tmp] = xwork_data[ib];
      }
      if (((unsigned int)bLen2 & 1U) != 0U) {
        ib = wOffset_tmp + i1;
        vwork_data[ib] = xwork_data[ib];
      }
      ib = 2;
      if (wOffset_tmp > 1) {
        if (idx_size >= 256) {
          int nBlocks;
          nBlocks = wOffset_tmp >> 8;
          if (nBlocks > 0) {
            for (b = 0; b < nBlocks; b++) {
              double xwork[256];
              short iwork[256];
              i4 = (b << 8) - 1;
              for (b_b = 0; b_b < 6; b_b++) {
                bLen = 1 << (b_b + 2);
                bLen2 = bLen << 1;
                b_i = 256 >> (b_b + 3);
                for (k = 0; k < b_i; k++) {
                  i2 = (i4 + k * bLen2) + 1;
                  for (i1 = 0; i1 < bLen2; i1++) {
                    ib = i2 + i1;
                    iwork[i1] = (short)iidx_data[ib];
                    xwork[i1] = vwork_data[ib];
                  }
                  i3 = 0;
                  i1 = bLen;
                  ib = i2 - 1;
                  int exitg1;
                  do {
                    exitg1 = 0;
                    ib++;
                    if (xwork[i3] <= xwork[i1]) {
                      iidx_data[ib] = iwork[i3];
                      vwork_data[ib] = xwork[i3];
                      if (i3 + 1 < bLen) {
                        i3++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      iidx_data[ib] = iwork[i1];
                      vwork_data[ib] = xwork[i1];
                      if (i1 + 1 < bLen2) {
                        i1++;
                      } else {
                        ib -= i3;
                        for (i1 = i3 + 1; i1 <= bLen; i1++) {
                          iidx_tmp = ib + i1;
                          iidx_data[iidx_tmp] = iwork[i1 - 1];
                          vwork_data[iidx_tmp] = xwork[i1 - 1];
                        }
                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }
            ib = nBlocks << 8;
            i1 = wOffset_tmp - ib;
            if (i1 > 0) {
              merge_block(iidx_data, vwork_data, ib, i1, 2, iwork_data,
                          xwork_data);
            }
            ib = 8;
          }
        }
        merge_block(iidx_data, vwork_data, 0, wOffset_tmp, ib, iwork_data,
                    xwork_data);
      }
      memcpy(&x_data[0], &vwork_data[0],
             (unsigned int)idx_size * sizeof(double));
      memcpy(&idx_data[0], &iidx_data[0], (unsigned int)idx_size * sizeof(int));
    }
  }
  return idx_size;
}

/* End of code generation (sort.c) */
