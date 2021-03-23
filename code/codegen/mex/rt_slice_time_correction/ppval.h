//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ppval.h
//
//  Code generation for function 'ppval'
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
real_T ppval(const emlrtStack *sp, const coder::array<real_T, 2U> &pp_breaks,
             const coder::array<real_T, 2U> &pp_coefs, real_T x);

// End of code generation (ppval.h)
