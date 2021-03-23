//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_fastfMRI_mex.cpp
//
//  Code generation for function '_coder_fastfMRI_mex'
//


// Include files
#include "_coder_fastfMRI_mex.h"
#include "_coder_fastfMRI_api.h"
#include "fastfMRI.h"
#include "fastfMRI_data.h"
#include "fastfMRI_initialize.h"
#include "fastfMRI_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void fastfMRI_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[5]);

// Function Definitions
void fastfMRI_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const
  mxArray *prhs[5])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4, 8,
                        "fastfMRI");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "fastfMRI");
  }

  // Call the function.
  fastfMRI_api(prhs, nlhs, outputs);

  // Copy over outputs to the caller.
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&fastfMRI_atexit);

  // Module initialization.
  fastfMRI_initialize();

  // Dispatch the entry-point.
  fastfMRI_mexFunction(nlhs, plhs, nrhs, prhs);

  // Module termination.
  fastfMRI_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_fastfMRI_mex.cpp)
