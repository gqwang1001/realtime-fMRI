//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  fastfMRI.h
//
//  Code generation for function 'fastfMRI'
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
#include "fastfMRI_types.h"

// Function Declarations
CODEGEN_EXPORT_SYM void fastfMRI(const emlrtStack *sp, const coder::array<real_T,
  2U> &XT, const coder::array<real_T, 2U> &YT, const coder::array<real_T, 2U>
  &ATInv, const coder::array<real_T, 1U> &xT1, const coder::array<real_T, 1U>
  &yT1, coder::array<real_T, 2U> &eVec, coder::array<real_T, 2U> &AT1Inv);

// End of code generation (fastfMRI.h)
