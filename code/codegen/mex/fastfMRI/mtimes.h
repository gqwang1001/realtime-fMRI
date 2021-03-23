//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mtimes.h
//
//  Code generation for function 'mtimes'
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
void b_mtimes(const emlrtStack *sp, const coder::array<real_T, 2U> &A, const
              coder::array<real_T, 2U> &B, coder::array<real_T, 2U> &C);
void mtimes(const emlrtStack *sp, const coder::array<real_T, 2U> &A, const coder::
            array<real_T, 2U> &B, coder::array<real_T, 2U> &C);

// End of code generation (mtimes.h)
