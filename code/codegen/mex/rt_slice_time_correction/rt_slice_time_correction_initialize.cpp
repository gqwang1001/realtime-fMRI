//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction_initialize.cpp
//
//  Code generation for function 'rt_slice_time_correction_initialize'
//


// Include files
#include "rt_slice_time_correction_initialize.h"
#include "_coder_rt_slice_time_correction_mex.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"
#include "rt_slice_time_correction_data.h"

// Function Definitions
void rt_slice_time_correction_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (rt_slice_time_correction_initialize.cpp)
