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
void sort(double x[50], int idx[50])
{
  double xwork[50];
  double x4[4];
  int iwork[50];
  int b_i1;
  int i;
  int i1;
  int i3;
  int ib;
  int k;
  int nNaNs;
  int quartetOffset;
  signed char idx4[4];
  memset(&idx[0], 0, 50U * sizeof(int));
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 50; k++) {
    if (rtIsNaN(x[k])) {
      idx[49 - nNaNs] = k + 1;
      xwork[49 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (signed char)(k + 1);
      x4[ib - 1] = x[k];
      if (ib == 4) {
        double d;
        double d1;
        int i4;
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          ib = 2;
        } else {
          i1 = 2;
          ib = 1;
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
          d = x4[ib - 1];
          if (d <= d1) {
            i = i1;
            b_i1 = ib;
            i1 = i3;
            ib = i4;
          } else if (d <= x4[i4 - 1]) {
            i = i1;
            b_i1 = i3;
            i1 = ib;
            ib = i4;
          } else {
            i = i1;
            b_i1 = i3;
            i1 = i4;
          }
        } else {
          d1 = x4[i4 - 1];
          if (d <= d1) {
            if (x4[ib - 1] <= d1) {
              i = i3;
              b_i1 = i1;
              i1 = ib;
              ib = i4;
            } else {
              i = i3;
              b_i1 = i1;
              i1 = i4;
            }
          } else {
            i = i3;
            b_i1 = i4;
          }
        }
        idx[quartetOffset - 3] = idx4[i - 1];
        idx[quartetOffset - 2] = idx4[b_i1 - 1];
        idx[quartetOffset - 1] = idx4[i1 - 1];
        idx[quartetOffset] = idx4[ib - 1];
        x[quartetOffset - 3] = x4[i - 1];
        x[quartetOffset - 2] = x4[b_i1 - 1];
        x[quartetOffset - 1] = x4[i1 - 1];
        x[quartetOffset] = x4[ib - 1];
        ib = 0;
      }
    }
  }
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
    i = (unsigned char)ib;
    for (k = 0; k < i; k++) {
      quartetOffset = ((k - nNaNs) - ib) + 50;
      b_i1 = perm[k];
      idx[quartetOffset] = idx4[b_i1 - 1];
      x[quartetOffset] = x4[b_i1 - 1];
    }
  }
  ib = (nNaNs >> 1) + 50;
  for (k = 0; k <= ib - 51; k++) {
    i1 = (k - nNaNs) + 50;
    quartetOffset = idx[i1];
    idx[i1] = idx[49 - k];
    idx[49 - k] = quartetOffset;
    x[i1] = xwork[49 - k];
    x[49 - k] = xwork[i1];
  }
  if (((unsigned int)nNaNs & 1U) != 0U) {
    i = ib - nNaNs;
    x[i] = xwork[i];
  }
  if (50 - nNaNs > 1) {
    memset(&iwork[0], 0, 50U * sizeof(int));
    i3 = (50 - nNaNs) >> 2;
    quartetOffset = 4;
    while (i3 > 1) {
      if (((unsigned int)i3 & 1U) != 0U) {
        i3--;
        ib = quartetOffset * i3;
        i1 = 50 - (nNaNs + ib);
        if (i1 > quartetOffset) {
          merge(idx, x, ib, quartetOffset, i1 - quartetOffset, iwork, xwork);
        }
      }
      ib = quartetOffset << 1;
      i3 >>= 1;
      for (k = 0; k < i3; k++) {
        merge(idx, x, k * ib, quartetOffset, quartetOffset, iwork, xwork);
      }
      quartetOffset = ib;
    }
    if (50 - nNaNs > quartetOffset) {
      merge(idx, x, 0, quartetOffset, 50 - (nNaNs + quartetOffset), iwork,
            xwork);
    }
  }
}

/* End of code generation (sort.c) */
