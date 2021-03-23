//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction_mexutil.cpp
//
//  Code generation for function 'rt_slice_time_correction_mexutil'
//


// Include files
#include "rt_slice_time_correction_mexutil.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"
#include "rt_slice_time_correction_data.h"

// Function Definitions
emlrtCTX emlrtGetRootTLSGlobal()
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX aTLS,
  void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

// End of code generation (rt_slice_time_correction_mexutil.cpp)
