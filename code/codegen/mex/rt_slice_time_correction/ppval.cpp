//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ppval.cpp
//
//  Code generation for function 'ppval'
//


// Include files
#include "ppval.h"
#include "eml_int_forloop_overflow_check.h"
#include "fliplr.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"
#include "rt_slice_time_correction_data.h"

// Variable Definitions
static emlrtRSInfo eb_emlrtRSI = { 90, // lineNo
  "ppval",                             // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/ppval.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 136,// lineNo
  "scalar_evaluatepp",                 // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/ppval.m"// pathName 
};

// Function Definitions
real_T ppval(const emlrtStack *sp, const coder::array<real_T, 2U> &pp_breaks,
             const coder::array<real_T, 2U> &pp_coefs, real_T x)
{
  real_T v;
  int32_T numTerms;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  numTerms = pp_coefs.size(1);
  st.site = &eb_emlrtRSI;
  if (muDoubleScalarIsNaN(x)) {
    v = x;
  } else {
    int32_T high_i;
    int32_T low_i;
    int32_T low_ip1;
    real_T xloc;
    high_i = pp_breaks.size(1);
    low_i = 1;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      int32_T mid_i;
      mid_i = (low_i >> 1) + (high_i >> 1);
      if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
        mid_i++;
      }

      if (x >= pp_breaks[mid_i - 1]) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    xloc = x - pp_breaks[low_i - 1];
    v = pp_coefs[low_i - 1];
    b_st.site = &fb_emlrtRSI;
    if (pp_coefs.size(1) > 2147483646) {
      c_st.site = &i_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (high_i = 2; high_i <= numTerms; high_i++) {
      v = xloc * v + pp_coefs[(low_i + (high_i - 1) * (pp_breaks.size(1) - 1)) -
        1];
    }
  }

  return v;
}

// End of code generation (ppval.cpp)
