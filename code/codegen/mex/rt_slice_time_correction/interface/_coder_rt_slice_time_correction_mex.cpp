//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_rt_slice_time_correction_mex.cpp
//
//  Code generation for function '_coder_rt_slice_time_correction_mex'
//


// Include files
#include "_coder_rt_slice_time_correction_mex.h"
#include "_coder_rt_slice_time_correction_api.h"
#include "rt_slice_time_correction.h"
#include "rt_slice_time_correction_data.h"
#include "rt_slice_time_correction_initialize.h"
#include "rt_slice_time_correction_mexutil.h"
#include "rt_slice_time_correction_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void c_rt_slice_time_correction_mexF(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[5]);

// Function Definitions
void c_rt_slice_time_correction_mexF(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[5])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        24, "rt_slice_time_correction");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "rt_slice_time_correction");
  }

  // Call the function.
  rt_slice_time_correction_api(prhs, nlhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexAtExit(&rt_slice_time_correction_atexit);

  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  // Module initialization.
  rt_slice_time_correction_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    // Dispatch the entry-point.
    c_rt_slice_time_correction_mexF(nlhs, plhs, nrhs, prhs);

    // Module termination.
    rt_slice_time_correction_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     &emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_rt_slice_time_correction_mex.cpp)
