//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  fliplr.cpp
//
//  Code generation for function 'fliplr'
//


// Include files
#include "fliplr.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"

// Function Definitions
void fliplr(coder::array<real_T, 2U> &x)
{
  int32_T n;
  int32_T nd2;
  n = x.size(1) - 1;
  nd2 = x.size(1) >> 1;
  for (int32_T b_j1 = 0; b_j1 < nd2; b_j1++) {
    int32_T j2;
    real_T xtmp;
    j2 = n - b_j1;
    xtmp = x[b_j1];
    x[b_j1] = x[j2];
    x[j2] = xtmp;
  }
}

// End of code generation (fliplr.cpp)
