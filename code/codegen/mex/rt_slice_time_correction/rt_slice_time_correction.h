//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction.h
//
//  Code generation for function 'rt_slice_time_correction'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "rt_slice_time_correction_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CODEGEN_EXPORT_SYM void rt_slice_time_correction(const emlrtStack *sp, const
  coder::array<real_T, 2U> &volRaw, const coder::array<real_T, 2U> &slice_times,
  const coder::array<boolean_T, 1U> &slice_indices, real_T tr, real_T update,
  coder::array<real_T, 2U> &vol_q);

// End of code generation (rt_slice_time_correction.h)
