//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  fastfMRI_terminate.cpp
//
//  Code generation for function 'fastfMRI_terminate'
//


// Include files
#include "fastfMRI_terminate.h"
#include "_coder_fastfMRI_mex.h"
#include "fastfMRI.h"
#include "fastfMRI_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void fastfMRI_atexit()
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

void fastfMRI_terminate()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (fastfMRI_terminate.cpp)
