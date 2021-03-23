//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  interp1.h
//
//  Code generation for function 'interp1'
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
void interp1(const emlrtStack *sp, const coder::array<real_T, 2U> &varargin_1,
             const coder::array<real_T, 2U> &varargin_2, const coder::array<
             real_T, 2U> &varargin_3, coder::array<real_T, 2U> &Vq);

// End of code generation (interp1.h)
