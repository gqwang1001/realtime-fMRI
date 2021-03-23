//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction.cpp
//
//  Code generation for function 'rt_slice_time_correction'
//


// Include files
#include "rt_slice_time_correction.h"
#include "eml_int_forloop_overflow_check.h"
#include "fliplr.h"
#include "indexShapeCheck.h"
#include "interp1.h"
#include "mwmathutil.h"
#include "ppval.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction_data.h"
#include "spline.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 11,    // lineNo
  "rt_slice_time_correction",          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 16,  // lineNo
  "rt_slice_time_correction",          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 26,  // lineNo
  "rt_slice_time_correction",          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 30,  // lineNo
  "rt_slice_time_correction",          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 41,  // lineNo
  "find",                              // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/find.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 153, // lineNo
  "eml_find",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/find.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 377, // lineNo
  "find_first_indices",                // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/find.m"// pathName 
};

static emlrtRSInfo h_emlrtRSI = { 397, // lineNo
  "find_first_indices",                // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/find.m"// pathName 
};

static emlrtRSInfo gb_emlrtRSI = { 263,// lineNo
  "interp1SplineOrPCHIP",              // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  30,                                  // lineNo
  17,                                  // colNo
  "ind",                               // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  30,                                  // lineNo
  17,                                  // colNo
  "vol_q",                             // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  54,                                  // colNo
  "ind",                               // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  30,                                  // lineNo
  52,                                  // colNo
  "ind",                               // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  23,                                  // colNo
  "ind",                               // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  29,                                  // lineNo
  36,                                  // colNo
  "slice_times",                       // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo e_emlrtRTEI = { 387,// lineNo
  1,                                   // colNo
  "find_first_indices",                // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

static emlrtECInfo emlrtECI = { -1,    // nDims
  16,                                  // lineNo
  17,                                  // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  23,                                  // colNo
  "vol_q",                             // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  30,                                  // lineNo
  52,                                  // colNo
  "volRaw",                            // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  54,                                  // colNo
  "volRaw",                            // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  15,                                  // lineNo
  41,                                  // colNo
  "slice_times",                       // aName
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo l_emlrtRTEI = { 24,// lineNo
  5,                                   // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo m_emlrtRTEI = { 26,// lineNo
  20,                                  // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo n_emlrtRTEI = { 153,// lineNo
  13,                                  // colNo
  "find",                              // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

static emlrtRTEInfo o_emlrtRTEI = { 41,// lineNo
  5,                                   // colNo
  "find",                              // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

static emlrtRTEInfo p_emlrtRTEI = { 26,// lineNo
  9,                                   // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo q_emlrtRTEI = { 28,// lineNo
  9,                                   // colNo
  "colon",                             // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/ops/colon.m"// pName
};

static emlrtRTEInfo r_emlrtRTEI = { 29,// lineNo
  17,                                  // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo s_emlrtRTEI = { 30,// lineNo
  45,                                  // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo u_emlrtRTEI = { 7, // lineNo
  5,                                   // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo v_emlrtRTEI = { 8, // lineNo
  5,                                   // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo w_emlrtRTEI = { 11,// lineNo
  20,                                  // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo x_emlrtRTEI = { 11,// lineNo
  9,                                   // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo y_emlrtRTEI = { 15,// lineNo
  22,                                  // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

static emlrtRTEInfo ab_emlrtRTEI = { 16,// lineNo
  47,                                  // colNo
  "rt_slice_time_correction",          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/rt_slice_time_correction.m"// pName 
};

// Function Definitions
void rt_slice_time_correction(const emlrtStack *sp, const coder::array<real_T,
  2U> &volRaw, const coder::array<real_T, 2U> &slice_times, const coder::array<
  boolean_T, 1U> &slice_indices, real_T tr, real_T update, coder::array<real_T,
  2U> &vol_q)
{
  int32_T nt;
  coder::array<real_T, 2U> Ts;
  coder::array<boolean_T, 1U> x;
  coder::array<int32_T, 1U> ii;
  int32_T iv[2];
  coder::array<uint32_T, 1U> ind;
  int32_T i2;
  int32_T loop_ub;
  int32_T i3;
  real_T xtmp;
  int32_T b_j1;
  coder::array<real_T, 2U> varargin_2;
  coder::array<real_T, 2U> pp_breaks;
  coder::array<real_T, 2U> b_varargin_2;
  coder::array<real_T, 2U> pp_coefs;
  real_T Vq;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  Calculate the slice time correction
  //  Created by Guoqing Wang, 08/05/2020
  nt = volRaw.size(1);
  if (update == 0.0) {
    int32_T idx;
    int32_T i;
    if (volRaw.size(1) < 1) {
      Ts.set_size((&q_emlrtRTEI), sp, 1, 0);
    } else {
      Ts.set_size((&q_emlrtRTEI), sp, 1, (static_cast<int32_T>
        (static_cast<real_T>(volRaw.size(1)) - 1.0) + 1));
      idx = static_cast<int32_T>(static_cast<real_T>(volRaw.size(1)) - 1.0);
      for (i = 0; i <= idx; i++) {
        Ts[i] = static_cast<real_T>(i) + 1.0;
      }
    }

    i = Ts.size(0) * Ts.size(1);
    Ts.set_size((&u_emlrtRTEI), sp, 1, Ts.size(1));
    idx = i - 1;
    for (i = 0; i <= idx; i++) {
      Ts[i] = tr * Ts[i];
    }

    uint32_T unnamed_idx_0;
    uint32_T unnamed_idx_1;
    unnamed_idx_0 = static_cast<uint32_T>(volRaw.size(0));
    unnamed_idx_1 = static_cast<uint32_T>(volRaw.size(1));
    vol_q.set_size((&v_emlrtRTEI), sp, (static_cast<int32_T>(unnamed_idx_0)), (
      static_cast<int32_T>(unnamed_idx_1)));
    idx = static_cast<int32_T>(unnamed_idx_0) * static_cast<int32_T>
      (unnamed_idx_1);
    for (i = 0; i < idx; i++) {
      vol_q[i] = 0.0;
    }

    i = slice_times.size(1);
    for (int32_T j = 0; j < i; j++) {
      int32_T i1;
      int32_T nx;
      int32_T b_ii;
      boolean_T exitg1;
      st.site = &emlrtRSI;
      idx = slice_indices.size(0);
      x.set_size((&w_emlrtRTEI), (&st), slice_indices.size(0));
      for (i1 = 0; i1 < idx; i1++) {
        x[i1] = (slice_indices[i1] == j + 1);
      }

      b_st.site = &e_emlrtRSI;
      nx = x.size(0);
      c_st.site = &f_emlrtRSI;
      idx = 0;
      ii.set_size((&n_emlrtRTEI), (&c_st), x.size(0));
      d_st.site = &g_emlrtRSI;
      if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        e_st.site = &i_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= nx - 1)) {
        if (x[b_ii]) {
          idx++;
          ii[idx - 1] = b_ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            b_ii++;
          }
        } else {
          b_ii++;
        }
      }

      if (idx > x.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          ii.set_size((&o_emlrtRTEI), (&c_st), 0);
        }
      } else {
        if (1 > idx) {
          i1 = 0;
        } else {
          i1 = idx;
        }

        iv[0] = 1;
        iv[1] = i1;
        d_st.site = &h_emlrtRSI;
        indexShapeCheck(&d_st, ii.size(0), iv);
        ii.set_size((&o_emlrtRTEI), (&c_st), i1);
      }

      ind.set_size((&x_emlrtRTEI), (&st), ii.size(0));
      idx = ii.size(0);
      for (i1 = 0; i1 < idx; i1++) {
        ind[i1] = static_cast<uint32_T>(ii[i1]);
      }

      if (ind.size(0) != 0) {
        i1 = ind.size(0);
        if (0 <= ind.size(0) - 1) {
          xtmp = slice_times[j];
          loop_ub = Ts.size(0) * Ts.size(1);
          i2 = volRaw.size(1);
          b_j1 = volRaw.size(1);
          iv[0] = 1;
        }

        for (int32_T k = 0; k < i1; k++) {
          i3 = j + 1;
          if ((i3 < 1) || (i3 > slice_times.size(1))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, slice_times.size(1),
              &j_emlrtBCI, sp);
          }

          i3 = k + 1;
          if ((i3 < 1) || (i3 > ind.size(0))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, ind.size(0), &e_emlrtBCI, sp);
          }

          i3 = static_cast<int32_T>(ind[i3 - 1]);
          if ((i3 < 1) || (i3 > vol_q.size(0))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, vol_q.size(0), &g_emlrtBCI, sp);
          }

          i3 = k + 1;
          if ((i3 < 1) || (i3 > ind.size(0))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, ind.size(0), &c_emlrtBCI, sp);
          }

          b_ii = static_cast<int32_T>(ind[i3 - 1]);
          if ((b_ii < 1) || (b_ii > volRaw.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[i3 - 1]), 1,
              volRaw.size(0), &i_emlrtBCI, sp);
          }

          pp_breaks.set_size((&y_emlrtRTEI), sp, 1, Ts.size(1));
          for (i3 = 0; i3 < loop_ub; i3++) {
            pp_breaks[i3] = Ts[i3] + xtmp;
          }

          b_varargin_2.set_size((&ab_emlrtRTEI), sp, 1, i2);
          for (i3 = 0; i3 < b_j1; i3++) {
            b_varargin_2[i3] = volRaw[(static_cast<int32_T>(ind[k]) +
              volRaw.size(0) * i3) - 1];
          }

          st.site = &b_emlrtRSI;
          interp1(&st, pp_breaks, b_varargin_2, Ts, varargin_2);
          iv[1] = vol_q.size(1);
          emlrtSubAssignSizeCheckR2012b(&iv[0], 2, varargin_2.size(), 2,
            &emlrtECI, sp);
          idx = varargin_2.size(1);
          for (i3 = 0; i3 < idx; i3++) {
            vol_q[(static_cast<int32_T>(ind[k]) + vol_q.size(0) * i3) - 1] =
              varargin_2[i3];
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  } else {
    real_T Ts_q;
    int32_T idx;
    int32_T i;
    Ts_q = tr * static_cast<real_T>(volRaw.size(1));
    vol_q.set_size((&l_emlrtRTEI), sp, volRaw.size(0), 1);
    idx = volRaw.size(0);
    for (i = 0; i < idx; i++) {
      vol_q[i] = 0.0;
    }

    i = slice_times.size(1);
    for (int32_T j = 0; j < i; j++) {
      int32_T i1;
      int32_T nx;
      int32_T b_ii;
      boolean_T exitg1;
      st.site = &c_emlrtRSI;
      idx = slice_indices.size(0);
      x.set_size((&m_emlrtRTEI), (&st), slice_indices.size(0));
      for (i1 = 0; i1 < idx; i1++) {
        x[i1] = (slice_indices[i1] == j + 1);
      }

      b_st.site = &e_emlrtRSI;
      nx = x.size(0);
      c_st.site = &f_emlrtRSI;
      idx = 0;
      ii.set_size((&n_emlrtRTEI), (&c_st), x.size(0));
      d_st.site = &g_emlrtRSI;
      if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        e_st.site = &i_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= nx - 1)) {
        if (x[b_ii]) {
          idx++;
          ii[idx - 1] = b_ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            b_ii++;
          }
        } else {
          b_ii++;
        }
      }

      if (idx > x.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          ii.set_size((&o_emlrtRTEI), (&c_st), 0);
        }
      } else {
        if (1 > idx) {
          i1 = 0;
        } else {
          i1 = idx;
        }

        iv[0] = 1;
        iv[1] = i1;
        d_st.site = &h_emlrtRSI;
        indexShapeCheck(&d_st, ii.size(0), iv);
        ii.set_size((&o_emlrtRTEI), (&c_st), i1);
      }

      ind.set_size((&p_emlrtRTEI), (&st), ii.size(0));
      idx = ii.size(0);
      for (i1 = 0; i1 < idx; i1++) {
        ind[i1] = static_cast<uint32_T>(ii[i1]);
      }

      if (ind.size(0) != 0) {
        i1 = ind.size(0);
        if (0 <= ind.size(0) - 1) {
          i2 = volRaw.size(1);
          loop_ub = volRaw.size(1);
          i3 = volRaw.size(1);
        }

        for (int32_T k = 0; k < i1; k++) {
          if (nt < 1) {
            Ts.set_size((&q_emlrtRTEI), sp, 1, 0);
          } else {
            Ts.set_size((&q_emlrtRTEI), sp, 1, nt);
            idx = nt - 1;
            for (b_ii = 0; b_ii <= idx; b_ii++) {
              Ts[b_ii] = static_cast<real_T>(b_ii) + 1.0;
            }
          }

          b_ii = Ts.size(0) * Ts.size(1);
          Ts.set_size((&r_emlrtRTEI), sp, 1, Ts.size(1));
          idx = j + 1;
          if ((idx < 1) || (idx > slice_times.size(1))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, slice_times.size(1),
              &f_emlrtBCI, sp);
          }

          xtmp = slice_times[idx - 1];
          idx = b_ii - 1;
          for (b_ii = 0; b_ii <= idx; b_ii++) {
            Ts[b_ii] = tr * Ts[b_ii] + xtmp;
          }

          st.site = &d_emlrtRSI;
          b_ii = k + 1;
          if ((b_ii < 1) || (b_ii > ind.size(0))) {
            emlrtDynamicBoundsCheckR2012b(b_ii, 1, ind.size(0), &d_emlrtBCI, &st);
          }

          idx = static_cast<int32_T>(ind[b_ii - 1]);
          if ((idx < 1) || (idx > volRaw.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[b_ii - 1]), 1,
              volRaw.size(0), &h_emlrtBCI, &st);
          }

          varargin_2.set_size((&s_emlrtRTEI), (&st), 1, i2);
          for (b_ii = 0; b_ii < loop_ub; b_ii++) {
            varargin_2[b_ii] = volRaw[(static_cast<int32_T>(ind[k]) +
              volRaw.size(0) * b_ii) - 1];
          }

          b_st.site = &k_emlrtRSI;
          nx = Ts.size(1);
          if (Ts.size(1) != i3) {
            emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
              "Coder:MATLAB:interp1_YInvalidLength",
              "Coder:MATLAB:interp1_YInvalidLength", 0);
          }

          if (Ts.size(1) <= 1) {
            emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
              "MATLAB:interp1:NotEnoughPts", "MATLAB:interp1:NotEnoughPts", 0);
          }

          c_st.site = &l_emlrtRSI;
          if (Ts.size(1) > 2147483646) {
            d_st.site = &i_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          idx = 0;
          int32_T exitg2;
          do {
            exitg2 = 0;
            if (idx <= nx - 1) {
              if (muDoubleScalarIsNaN(Ts[idx])) {
                emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                  "MATLAB:interp1:NaNinX", "MATLAB:interp1:NaNinX", 0);
              } else {
                idx++;
              }
            } else {
              if (Ts[1] < Ts[0]) {
                idx = nx >> 1;
                c_st.site = &m_emlrtRSI;
                for (b_j1 = 0; b_j1 < idx; b_j1++) {
                  xtmp = Ts[b_j1];
                  b_ii = (nx - b_j1) - 1;
                  Ts[b_j1] = Ts[b_ii];
                  Ts[b_ii] = xtmp;
                }

                c_st.site = &n_emlrtRSI;
                fliplr(varargin_2);
              }

              c_st.site = &o_emlrtRSI;
              if (nx > 2147483646) {
                d_st.site = &i_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }

              for (idx = 2; idx <= nx; idx++) {
                if (Ts[idx - 1] <= Ts[idx - 2]) {
                  emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
                    "Coder:toolbox:interp1_nonMonotonicX",
                    "Coder:toolbox:interp1_nonMonotonicX", 0);
                }
              }

              c_st.site = &p_emlrtRSI;
              b_varargin_2.set_size((&t_emlrtRTEI), (&c_st), 1, varargin_2.size
                                    (1));
              idx = varargin_2.size(1);
              for (b_ii = 0; b_ii < idx; b_ii++) {
                b_varargin_2[b_ii] = varargin_2[b_ii];
              }

              d_st.site = &r_emlrtRSI;
              spline(&d_st, Ts, b_varargin_2, pp_breaks, pp_coefs);
              d_st.site = &gb_emlrtRSI;
              Vq = ppval(&d_st, pp_breaks, pp_coefs, Ts_q);
              exitg2 = 1;
            }
          } while (exitg2 == 0);

          b_ii = k + 1;
          if ((b_ii < 1) || (b_ii > ind.size(0))) {
            emlrtDynamicBoundsCheckR2012b(b_ii, 1, ind.size(0), &emlrtBCI, sp);
          }

          idx = static_cast<int32_T>(ind[b_ii - 1]);
          if ((idx < 1) || (idx > vol_q.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind[b_ii - 1]), 1,
              vol_q.size(0), &b_emlrtBCI, sp);
          }

          vol_q[idx - 1] = Vq;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (rt_slice_time_correction.cpp)
