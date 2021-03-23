//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction_data.cpp
//
//  Code generation for function 'rt_slice_time_correction_data'
//


// Include files
#include "rt_slice_time_correction_data.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,// bFirstTime
  false,                               // bInitialized
  131594U,                             // fVersionInfo
  NULL,                                // fErrorFunction
  "rt_slice_time_correction",          // fFunctionName
  NULL,                                // fRTCallStack
  false,                               // bDebugMode
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },// fSigWrd
  NULL                                 // fSigMem
};

emlrtRSInfo i_emlrtRSI = { 21,         // lineNo
  "eml_int_forloop_overflow_check",    // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pathName 
};

emlrtRSInfo k_emlrtRSI = { 50,         // lineNo
  "interp1",                           // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

emlrtRSInfo l_emlrtRSI = { 162,        // lineNo
  "interp1_work",                      // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

emlrtRSInfo m_emlrtRSI = { 171,        // lineNo
  "interp1_work",                      // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

emlrtRSInfo n_emlrtRSI = { 177,        // lineNo
  "interp1_work",                      // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

emlrtRSInfo o_emlrtRSI = { 182,        // lineNo
  "interp1_work",                      // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

emlrtRSInfo p_emlrtRSI = { 209,        // lineNo
  "interp1_work",                      // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

emlrtRSInfo q_emlrtRSI = { 22,         // lineNo
  "fliplr",                            // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/fliplr.m"// pathName 
};

emlrtRSInfo r_emlrtRSI = { 249,        // lineNo
  "interp1SplineOrPCHIP",              // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

emlrtRSInfo x_emlrtRSI = { 70,         // lineNo
  "splinepp",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

emlrtRSInfo y_emlrtRSI = { 79,         // lineNo
  "splinepp",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

emlrtRSInfo ab_emlrtRSI = { 119,       // lineNo
  "splinepp",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

emlrtRSInfo cb_emlrtRSI = { 219,       // lineNo
  "degenerateSpline",                  // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

emlrtRSInfo db_emlrtRSI = { 44,        // lineNo
  "pwchcore",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m"// pathName 
};

emlrtRTEInfo emlrtRTEI = { 184,        // lineNo
  13,                                  // colNo
  "interp1_work",                      // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

emlrtRTEInfo b_emlrtRTEI = { 164,      // lineNo
  13,                                  // colNo
  "interp1_work",                      // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

emlrtRTEInfo c_emlrtRTEI = { 153,      // lineNo
  15,                                  // colNo
  "interp1_work",                      // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

emlrtRTEInfo d_emlrtRTEI = { 123,      // lineNo
  23,                                  // colNo
  "interp1_work",                      // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

emlrtRTEInfo t_emlrtRTEI = { 249,      // lineNo
  23,                                  // colNo
  "interp1",                           // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

// End of code generation (rt_slice_time_correction_data.cpp)
