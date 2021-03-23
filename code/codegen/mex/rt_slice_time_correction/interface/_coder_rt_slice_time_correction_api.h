//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_rt_slice_time_correction_api.h
//
//  Code generation for function '_coder_rt_slice_time_correction_api'
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
void rt_slice_time_correction_api(const mxArray * const prhs[5], int32_T nlhs,
  const mxArray *plhs[1]);

// End of code generation (_coder_rt_slice_time_correction_api.h)
