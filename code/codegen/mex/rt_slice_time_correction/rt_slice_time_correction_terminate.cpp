//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction_terminate.cpp
//
//  Code generation for function 'rt_slice_time_correction_terminate'
//


// Include files
#include "rt_slice_time_correction_terminate.h"
#include "_coder_rt_slice_time_correction_mex.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"
#include "rt_slice_time_correction_data.h"

// Function Definitions
void rt_slice_time_correction_atexit()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void rt_slice_time_correction_terminate()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (rt_slice_time_correction_terminate.cpp)
