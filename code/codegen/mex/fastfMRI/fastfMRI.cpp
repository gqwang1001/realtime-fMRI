//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  fastfMRI.cpp
//
//  Code generation for function 'fastfMRI'
//


// Include files
#include "fastfMRI.h"
#include "blas.h"
#include "fastfMRI_data.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 14,    // lineNo
  "fastfMRI",                          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 16,  // lineNo
  "fastfMRI",                          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 17,  // lineNo
  "fastfMRI",                          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 21,  // lineNo
  "fastfMRI",                          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 22,  // lineNo
  "fastfMRI",                          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 25,  // lineNo
  "fastfMRI",                          // fcnName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 79,  // lineNo
  "eml_mtimes_helper",                 // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pathName 
};

static emlrtRSInfo h_emlrtRSI = { 48,  // lineNo
  "eml_mtimes_helper",                 // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pathName 
};

static emlrtRSInfo n_emlrtRSI = { 27,  // lineNo
  "cat",                               // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/eml/+coder/+internal/cat.m"// pathName 
};

static emlrtRSInfo o_emlrtRSI = { 102, // lineNo
  "cat_impl",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/eml/+coder/+internal/cat.m"// pathName 
};

static emlrtRTEInfo emlrtRTEI = { 118, // lineNo
  23,                                  // colNo
  "dynamic_size_checks",               // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 123,// lineNo
  23,                                  // colNo
  "dynamic_size_checks",               // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

static emlrtRTEInfo c_emlrtRTEI = { 283,// lineNo
  27,                                  // colNo
  "check_non_axis_size",               // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/eml/+coder/+internal/cat.m"// pName 
};

static emlrtECInfo emlrtECI = { 2,     // nDims
  25,                                  // lineNo
  9,                                   // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  22,                                  // lineNo
  7,                                   // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtECInfo c_emlrtECI = { 2,   // nDims
  21,                                  // lineNo
  6,                                   // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtECInfo d_emlrtECI = { 2,   // nDims
  17,                                  // lineNo
  10,                                  // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 79,// lineNo
  5,                                   // colNo
  "eml_mtimes_helper",                 // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

static emlrtRTEInfo f_emlrtRTEI = { 74,// lineNo
  9,                                   // colNo
  "eml_mtimes_helper",                 // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"// pName 
};

static emlrtRTEInfo g_emlrtRTEI = { 17,// lineNo
  1,                                   // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtRTEInfo h_emlrtRTEI = { 21,// lineNo
  1,                                   // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtRTEInfo i_emlrtRTEI = { 22,// lineNo
  13,                                  // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtRTEInfo j_emlrtRTEI = { 22,// lineNo
  1,                                   // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

static emlrtRTEInfo k_emlrtRTEI = { 25,// lineNo
  1,                                   // colNo
  "fastfMRI",                          // fName
  "/Users/guoqingwang/Dropbox/projects/fastfMRI/realtime_rsfMRI/matlabcode/code/fastfMRI.m"// pName 
};

// Function Declarations
static void dynamic_size_checks(const emlrtStack *sp, const coder::array<real_T,
  2U> &a, const coder::array<real_T, 2U> &b, int32_T innerDimA, int32_T
  innerDimB);

// Function Definitions
static void dynamic_size_checks(const emlrtStack *sp, const coder::array<real_T,
  2U> &a, const coder::array<real_T, 2U> &b, int32_T innerDimA, int32_T
  innerDimB)
{
  if (innerDimA != innerDimB) {
    if (((a.size(0) == 1) && (a.size(1) == 1)) || ((b.size(0) == 1) && (b.size(1)
          == 1))) {
      emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }
}

void fastfMRI(const emlrtStack *sp, const coder::array<real_T, 2U> &XT, const
              coder::array<real_T, 2U> &YT, const coder::array<real_T, 2U>
              &ATInv, const coder::array<real_T, 1U> &xT1, const coder::array<
              real_T, 1U> &yT1, coder::array<real_T, 2U> &eVec, coder::array<
              real_T, 2U> &AT1Inv)
{
  coder::array<real_T, 2U> y;
  int32_T loop_ub;
  int32_T i;
  char_T TRANSB1;
  char_T TRANSA1;
  real_T alpha1;
  real_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  real_T bT1;
  coder::array<real_T, 2U> betaT;
  int32_T b_loop_ub;
  int32_T i1;
  coder::array<real_T, 2U> b_y;
  coder::array<real_T, 2U> eT;
  coder::array<real_T, 1U> eT1;
  boolean_T empty_non_axis_sizes;
  int32_T input_sizes_idx_1;
  int8_T sizes_idx_1;
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

  //  This function implements the fastFMRI algorithm
  //  INPUT
  //    XT (T-by-p) : the collection of nuisance variable. xT' = [x1 x2 ... xT]; 
  //    YT (n-by-T) : a voxel at tr 1:T;
  //    ATinv (p-by-p) : ATinv = inv(XT' * XT)
  //    xT1 (p-by-1) : a collection of nuisance vairable at tr (T+1)
  //    yT1 (n-by-1) : a voxel at tr (T+1)
  //  OUTPUT
  //    eVec ((T+1)-by-1) : eVec = (I - XT1*inv(XT1' * XT1)* XT1')* YT1
  //    the residueal for the next TR after having regressed out nuisances
  //    AT1Inv (p-by-p) : AT1Inv = inv(XT1' * XT1)
  st.site = &emlrtRSI;
  b_st.site = &h_emlrtRSI;
  if (xT1.size(0) != ATInv.size(0)) {
    if ((xT1.size(0) == 1) || ((ATInv.size(0) == 1) && (ATInv.size(1) == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  b_st.site = &g_emlrtRSI;
  if ((xT1.size(0) == 0) || (ATInv.size(0) == 0) || (ATInv.size(1) == 0)) {
    y.set_size((&e_emlrtRTEI), (&b_st), 1, ATInv.size(1));
    loop_ub = ATInv.size(1);
    for (i = 0; i < loop_ub; i++) {
      y[i] = 0.0;
    }
  } else {
    c_st.site = &i_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)ATInv.size(1);
    k_t = (ptrdiff_t)xT1.size(0);
    lda_t = (ptrdiff_t)xT1.size(0);
    ldb_t = (ptrdiff_t)ATInv.size(0);
    ldc_t = (ptrdiff_t)1;
    y.set_size((&d_emlrtRTEI), (&c_st), 1, ATInv.size(1));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((coder::array<real_T,
             1U> *)&xT1)->data())[0], &lda_t, &(((coder::array<real_T, 2U> *)
            &ATInv)->data())[0], &ldb_t, &beta1, &y[0], &ldc_t);
  }

  st.site = &emlrtRSI;
  b_st.site = &h_emlrtRSI;
  if (y.size(1) != xT1.size(0)) {
    if ((y.size(1) == 1) || (xT1.size(0) == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  b_st.site = &g_emlrtRSI;
  if (y.size(1) < 1) {
    bT1 = 0.0;
  } else {
    n_t = (ptrdiff_t)y.size(1);
    m_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)1;
    bT1 = ddot(&n_t, &y[0], &m_t, &(((coder::array<real_T, 1U> *)&xT1)->data())
               [0], &k_t);
  }

  //  betaT = ATInv * XT' * YT;
  st.site = &b_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  dynamic_size_checks(&b_st, YT, XT, YT.size(1), XT.size(0));
  b_st.site = &g_emlrtRSI;
  mtimes(&b_st, YT, XT, y);
  st.site = &b_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  dynamic_size_checks(&b_st, y, ATInv, y.size(1), ATInv.size(1));
  b_st.site = &g_emlrtRSI;
  b_mtimes(&b_st, y, ATInv, betaT);

  //  n by p
  y.set_size((&f_emlrtRTEI), sp, xT1.size(0), xT1.size(0));
  loop_ub = xT1.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = xT1.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y[i1 + y.size(0) * i] = xT1[i1] * xT1[i];
    }
  }

  st.site = &c_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  dynamic_size_checks(&b_st, ATInv, y, ATInv.size(1), y.size(0));
  b_st.site = &g_emlrtRSI;
  mtimes(&b_st, ATInv, y, b_y);
  st.site = &c_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  dynamic_size_checks(&b_st, b_y, ATInv, b_y.size(1), ATInv.size(0));
  b_st.site = &g_emlrtRSI;
  mtimes(&b_st, b_y, ATInv, AT1Inv);
  loop_ub = AT1Inv.size(0) * AT1Inv.size(1);
  for (i = 0; i < loop_ub; i++) {
    AT1Inv[i] = AT1Inv[i] / (bT1 + 1.0);
  }

  emlrtSizeEqCheckNDR2012b(((coder::array<real_T, 2U> *)&ATInv)->size(),
    AT1Inv.size(), &d_emlrtECI, sp);
  loop_ub = ATInv.size(0) * ATInv.size(1);
  AT1Inv.set_size((&g_emlrtRTEI), sp, ATInv.size(0), ATInv.size(1));
  for (i = 0; i < loop_ub; i++) {
    AT1Inv[i] = ATInv[i] - AT1Inv[i];
  }

  //  eT = YT - XT * betaT;
  //  eT1 = yT1 - xT1' * betaT;
  st.site = &d_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  dynamic_size_checks(&b_st, betaT, XT, betaT.size(1), XT.size(1));
  b_st.site = &g_emlrtRSI;
  b_mtimes(&b_st, betaT, XT, eT);
  emlrtSizeEqCheckNDR2012b(((coder::array<real_T, 2U> *)&YT)->size(), eT.size(),
    &c_emlrtECI, sp);
  loop_ub = YT.size(0) * YT.size(1);
  eT.set_size((&h_emlrtRTEI), sp, YT.size(0), YT.size(1));
  for (i = 0; i < loop_ub; i++) {
    eT[i] = YT[i] - eT[i];
  }

  //  n by T
  st.site = &e_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  if (betaT.size(1) != xT1.size(0)) {
    if (((betaT.size(0) == 1) && (betaT.size(1) == 1)) || (xT1.size(0) == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  b_st.site = &g_emlrtRSI;
  if ((betaT.size(0) == 0) || (betaT.size(1) == 0) || (xT1.size(0) == 0)) {
    eT1.set_size((&i_emlrtRTEI), (&b_st), betaT.size(0));
    loop_ub = betaT.size(0);
    for (i = 0; i < loop_ub; i++) {
      eT1[i] = 0.0;
    }
  } else {
    c_st.site = &i_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)betaT.size(0);
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)betaT.size(1);
    lda_t = (ptrdiff_t)betaT.size(0);
    ldb_t = (ptrdiff_t)xT1.size(0);
    ldc_t = (ptrdiff_t)betaT.size(0);
    eT1.set_size((&d_emlrtRTEI), (&c_st), betaT.size(0));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(betaT.data())[0],
          &lda_t, &(((coder::array<real_T, 1U> *)&xT1)->data())[0], &ldb_t,
          &beta1, &(eT1.data())[0], &ldc_t);
  }

  if (yT1.size(0) != eT1.size(0)) {
    emlrtSizeEqCheck1DR2012b(yT1.size(0), eT1.size(0), &b_emlrtECI, sp);
  }

  eT1.set_size((&j_emlrtRTEI), sp, yT1.size(0));
  loop_ub = yT1.size(0);
  for (i = 0; i < loop_ub; i++) {
    eT1[i] = yT1[i] - eT1[i];
  }

  //  n by 1
  //  eVec = [eT - XT * ATInv * xT1 * eT1 / (1+bT1) ; eT1 / (1+bT1)];
  y.set_size((&f_emlrtRTEI), sp, eT1.size(0), xT1.size(0));
  loop_ub = xT1.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = eT1.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y[i1 + y.size(0) * i] = eT1[i1] * xT1[i];
    }
  }

  st.site = &f_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  dynamic_size_checks(&b_st, y, ATInv, y.size(1), ATInv.size(1));
  b_st.site = &g_emlrtRSI;
  b_mtimes(&b_st, y, ATInv, b_y);
  st.site = &f_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  dynamic_size_checks(&b_st, b_y, XT, b_y.size(1), XT.size(1));
  b_st.site = &g_emlrtRSI;
  b_mtimes(&b_st, b_y, XT, y);
  loop_ub = y.size(0) * y.size(1);
  for (i = 0; i < loop_ub; i++) {
    y[i] = y[i] / (bT1 + 1.0);
  }

  emlrtSizeEqCheckNDR2012b(eT.size(), y.size(), &emlrtECI, sp);
  st.site = &f_emlrtRSI;
  loop_ub = eT.size(0) * eT.size(1);
  for (i = 0; i < loop_ub; i++) {
    eT[i] = eT[i] - y[i];
  }

  loop_ub = eT1.size(0);
  for (i = 0; i < loop_ub; i++) {
    eT1[i] = eT1[i] / (bT1 + 1.0);
  }

  b_st.site = &n_emlrtRSI;
  if ((eT.size(0) != 0) && (eT.size(1) != 0)) {
    b_loop_ub = eT.size(0);
  } else if (eT1.size(0) != 0) {
    b_loop_ub = eT1.size(0);
  } else {
    i = eT.size(0);
    b_loop_ub = muIntScalarMax_sint32(i, 0);
  }

  c_st.site = &o_emlrtRSI;
  if ((eT.size(0) != b_loop_ub) && ((eT.size(0) != 0) && (eT.size(1) != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((eT1.size(0) != b_loop_ub) && (eT1.size(0) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (b_loop_ub == 0);
  if (empty_non_axis_sizes || ((eT.size(0) != 0) && (eT.size(1) != 0))) {
    input_sizes_idx_1 = eT.size(1);
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes || (eT1.size(0) != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }

  eVec.set_size((&k_emlrtRTEI), (&b_st), b_loop_ub, (input_sizes_idx_1 +
    sizes_idx_1));
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      eVec[i1 + eVec.size(0) * i] = eT[i1 + b_loop_ub * i];
    }
  }

  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      eVec[i1 + eVec.size(0) * input_sizes_idx_1] = eT1[i1];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (fastfMRI.cpp)
