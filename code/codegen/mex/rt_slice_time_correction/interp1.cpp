//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  interp1.cpp
//
//  Code generation for function 'interp1'
//


// Include files
#include "interp1.h"
#include "eml_int_forloop_overflow_check.h"
#include "fliplr.h"
#include "mwmathutil.h"
#include "ppval.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"
#include "rt_slice_time_correction_data.h"
#include "spline.h"

// Type Definitions
struct struct_T
{
  coder::array<real_T, 2U> breaks;
  coder::array<real_T, 2U> coefs;
};

// Variable Definitions
static emlrtRSInfo s_emlrtRSI = { 272, // lineNo
  "interp1SplineOrPCHIP",              // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 276, // lineNo
  "interp1SplineOrPCHIP",              // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRTEInfo bb_emlrtRTEI = { 50,// lineNo
  49,                                  // colNo
  "interp1",                           // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

static emlrtRTEInfo cb_emlrtRTEI = { 51,// lineNo
  25,                                  // colNo
  "interp1",                           // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

static emlrtRTEInfo db_emlrtRTEI = { 50,// lineNo
  9,                                   // colNo
  "interp1",                           // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName 
};

// Function Declarations
static void interp1SplineOrPCHIP(const emlrtStack *sp, const coder::array<real_T,
  2U> &y, const coder::array<real_T, 2U> &xi, coder::array<real_T, 2U> &yi,
  const coder::array<real_T, 2U> &x);

// Function Definitions
static void interp1SplineOrPCHIP(const emlrtStack *sp, const coder::array<real_T,
  2U> &y, const coder::array<real_T, 2U> &xi, coder::array<real_T, 2U> &yi,
  const coder::array<real_T, 2U> &x)
{
  coder::array<real_T, 2U> b_y;
  int32_T loop_ub;
  int32_T i;
  struct_T pp;
  int32_T k;
  real_T d;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b_y.set_size((&t_emlrtRTEI), sp, 1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i] = y[i];
  }

  st.site = &r_emlrtRSI;
  spline(&st, x, b_y, pp.breaks, pp.coefs);
  st.site = &s_emlrtRSI;
  if ((1 <= xi.size(1)) && (xi.size(1) > 2147483646)) {
    b_st.site = &i_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  loop_ub = xi.size(1) - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(d_st,d) \
 firstprivate(c_st,emlrtHadParallelError)

  {
    try {
      c_st.prev = sp;
      c_st.tls = emlrtAllocTLS((emlrtStack *)sp, omp_get_thread_num());
      c_st.site = NULL;
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
    } catch (...) {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (k = 0; k <= loop_ub; k++) {
      if (emlrtHadParallelError)
        continue;
      try {
        d = xi[k];
        if (muDoubleScalarIsNaN(d)) {
          yi[k] = rtNaN;
        } else {
          d_st.site = &t_emlrtRSI;
          yi[k] = ppval(&d_st, pp.breaks, pp.coefs, d);
        }
      } catch (...) {
        emlrtHadParallelError = true;
      }
    }
  }

  emlrtExitParallelRegion(sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void interp1(const emlrtStack *sp, const coder::array<real_T, 2U> &varargin_1,
             const coder::array<real_T, 2U> &varargin_2, const coder::array<
             real_T, 2U> &varargin_3, coder::array<real_T, 2U> &Vq)
{
  coder::array<real_T, 2U> y;
  int32_T n;
  int32_T nd2;
  coder::array<real_T, 2U> x;
  int32_T nx;
  uint32_T outsize_idx_1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &k_emlrtRSI;
  y.set_size((&bb_emlrtRTEI), (&st), 1, varargin_2.size(1));
  n = varargin_2.size(0) * varargin_2.size(1);
  for (nd2 = 0; nd2 < n; nd2++) {
    y[nd2] = varargin_2[nd2];
  }

  x.set_size((&cb_emlrtRTEI), (&st), 1, varargin_1.size(1));
  n = varargin_1.size(0) * varargin_1.size(1);
  for (nd2 = 0; nd2 < n; nd2++) {
    x[nd2] = varargin_1[nd2];
  }

  nx = varargin_1.size(1);
  if (varargin_1.size(1) != varargin_2.size(1)) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
      "Coder:MATLAB:interp1_YInvalidLength",
      "Coder:MATLAB:interp1_YInvalidLength", 0);
  }

  outsize_idx_1 = static_cast<uint32_T>(varargin_3.size(1));
  if (varargin_1.size(1) <= 1) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "MATLAB:interp1:NotEnoughPts", "MATLAB:interp1:NotEnoughPts", 0);
  }

  Vq.set_size((&db_emlrtRTEI), (&st), 1, (static_cast<int32_T>(outsize_idx_1)));
  n = static_cast<int32_T>(outsize_idx_1);
  for (nd2 = 0; nd2 < n; nd2++) {
    Vq[nd2] = 0.0;
  }

  if (varargin_3.size(1) != 0) {
    b_st.site = &l_emlrtRSI;
    if (varargin_1.size(1) > 2147483646) {
      c_st.site = &i_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    n = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (n <= nx - 1) {
        if (muDoubleScalarIsNaN(varargin_1[n])) {
          emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
            "MATLAB:interp1:NaNinX", "MATLAB:interp1:NaNinX", 0);
        } else {
          n++;
        }
      } else {
        if (varargin_1[1] < varargin_1[0]) {
          int32_T b_j1;
          real_T xtmp;
          n = nx >> 1;
          b_st.site = &m_emlrtRSI;
          for (b_j1 = 0; b_j1 < n; b_j1++) {
            xtmp = x[b_j1];
            nd2 = (nx - b_j1) - 1;
            x[b_j1] = x[nd2];
            x[nd2] = xtmp;
          }

          b_st.site = &n_emlrtRSI;
          n = y.size(1) - 1;
          nd2 = y.size(1) >> 1;
          for (b_j1 = 0; b_j1 < nd2; b_j1++) {
            int32_T j2;
            j2 = n - b_j1;
            xtmp = y[b_j1];
            y[b_j1] = y[j2];
            y[j2] = xtmp;
          }
        }

        b_st.site = &o_emlrtRSI;
        if (nx > 2147483646) {
          c_st.site = &i_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (n = 2; n <= nx; n++) {
          if (x[n - 1] <= x[n - 2]) {
            emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
              "Coder:toolbox:interp1_nonMonotonicX",
              "Coder:toolbox:interp1_nonMonotonicX", 0);
          }
        }

        b_st.site = &p_emlrtRSI;
        interp1SplineOrPCHIP(&b_st, y, varargin_3, Vq, x);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (interp1.cpp)
