//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  spline.cpp
//
//  Code generation for function 'spline'
//


// Include files
#include "spline.h"
#include "fliplr.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo u_emlrtRSI = { 22,  // lineNo
  "spline",                            // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 35,  // lineNo
  "splinepp",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 41,  // lineNo
  "splinepp",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

static emlrtRSInfo bb_emlrtRSI = { 164,// lineNo
  "splinepp",                          // fcnName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pathName 
};

static emlrtRTEInfo h_emlrtRTEI = { 43,// lineNo
  19,                                  // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static emlrtRTEInfo i_emlrtRTEI = { 39,// lineNo
  1,                                   // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static emlrtRTEInfo j_emlrtRTEI = { 37,// lineNo
  15,                                  // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static emlrtRTEInfo k_emlrtRTEI = { 33,// lineNo
  15,                                  // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static emlrtDCInfo emlrtDCI = { 63,    // lineNo
  32,                                  // colNo
  "splinepp",                          // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 64,  // lineNo
  35,                                  // colNo
  "splinepp",                          // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo c_emlrtDCI = { 32,  // lineNo
  37,                                  // colNo
  "pwchcore",                          // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  4                                    // checkKind
};

static emlrtRTEInfo eb_emlrtRTEI = { 22,// lineNo
  10,                                  // colNo
  "spline",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pName 
};

static emlrtRTEInfo fb_emlrtRTEI = { 164,// lineNo
  6,                                   // colNo
  "spline",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pName 
};

static emlrtRTEInfo gb_emlrtRTEI = { 22,// lineNo
  5,                                   // colNo
  "spline",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pName 
};

static emlrtRTEInfo hb_emlrtRTEI = { 41,// lineNo
  10,                                  // colNo
  "spline",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/lib/matlab/polyfun/spline.m"// pName 
};

// Function Definitions
void spline(const emlrtStack *sp, const coder::array<real_T, 2U> &x, const coder::
            array<real_T, 2U> &y, coder::array<real_T, 2U> &output_breaks, coder::
            array<real_T, 2U> &output_coefs)
{
  boolean_T has_endslopes;
  int32_T k;
  boolean_T exitg1;
  coder::array<real_T, 2U> s;
  real_T c_data[4];
  coder::array<real_T, 2U> dvdf;
  coder::array<real_T, 2U> dx;
  real_T pp1_coefs[4];
  coder::array<real_T, 2U> md;
  coder::array<real_T, 2U> pp_coefs;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &u_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  if (x.size(1) < 2) {
    emlrtErrorWithMessageIdR2018a(&b_st, &k_emlrtRTEI,
      "MATLAB:chckxy:NotEnoughPts", "MATLAB:chckxy:NotEnoughPts", 0);
  }

  has_endslopes = ((!muDoubleScalarIsInf(x[0])) && (!muDoubleScalarIsNaN(x[0])));
  if (has_endslopes) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x.size(1) - 2)) {
      if (!(x[k] < x[k + 1])) {
        has_endslopes = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if ((!has_endslopes) || muDoubleScalarIsInf(x[x.size(1) - 1])) {
    has_endslopes = false;
  }

  if (!has_endslopes) {
    emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
      "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing",
      "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing", 0);
  }

  has_endslopes = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= y.size(1) - 1)) {
    if (muDoubleScalarIsNaN(y[k])) {
      has_endslopes = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (has_endslopes) {
    emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
      "Coder:toolbox:UnsupportedNaN", "Coder:toolbox:UnsupportedNaN", 0);
  }

  if ((y.size(1) != x.size(1)) && (y.size(1) != x.size(1) + 2)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
      "MATLAB:chckxy:NumSitesMismatchValues",
      "MATLAB:chckxy:NumSitesMismatchValues", 4, 12, x.size(1), 12, y.size(1));
  }

  has_endslopes = (y.size(1) == x.size(1) + 2);
  if ((x.size(1) <= 2) || ((x.size(1) <= 3) && (!has_endslopes))) {
    int32_T szs_idx_1;
    b_st.site = &w_emlrtRSI;
    has_endslopes = (y.size(1) == x.size(1) + 2);
    if (x.size(1) <= 2) {
      if (has_endslopes) {
        szs_idx_1 = 4;
      } else {
        szs_idx_1 = 2;
      }

      if (has_endslopes) {
        real_T szdvdf_idx_1;
        real_T dnnm2;
        real_T r;
        real_T dzzdx;
        dnnm2 = y[0];
        r = x[1] - x[0];
        szdvdf_idx_1 = (y[2] - y[1]) / r;
        dzzdx = (szdvdf_idx_1 - dnnm2) / r;
        szdvdf_idx_1 = (y[y.size(1) - 1] - szdvdf_idx_1) / r;
        pp1_coefs[0] = (szdvdf_idx_1 - dzzdx) / r;
        pp1_coefs[1] = 2.0 * dzzdx - szdvdf_idx_1;
        pp1_coefs[2] = dnnm2;
        pp1_coefs[3] = y[1];
        if (0 <= szs_idx_1 - 1) {
          memcpy(&c_data[0], &pp1_coefs[0], szs_idx_1 * sizeof(real_T));
        }
      } else {
        c_data[0] = (y[1] - y[0]) / (x[1] - x[0]);
        c_data[1] = y[0];
      }

      output_breaks.set_size((&hb_emlrtRTEI), (&b_st), 1, 2);
      for (k = 0; k < 2; k++) {
        output_breaks[k] = x[k];
      }
    } else {
      real_T szdvdf_idx_1;
      real_T dnnm2;
      szs_idx_1 = 3;
      szdvdf_idx_1 = x[1] - x[0];
      dnnm2 = (y[1] - y[0]) / szdvdf_idx_1;
      c_data[0] = ((y[2] - y[1]) / (x[2] - x[1]) - dnnm2) / (x[2] - x[0]);
      c_data[1] = dnnm2 - c_data[0] * szdvdf_idx_1;
      c_data[2] = y[0];
      output_breaks.set_size((&hb_emlrtRTEI), (&b_st), 1, 2);
      output_breaks[0] = x[0];
      output_breaks[1] = x[2];
    }

    output_coefs.set_size((&gb_emlrtRTEI), (&st), 1, szs_idx_1);
    for (k = 0; k < szs_idx_1; k++) {
      output_coefs[k] = c_data[k];
    }
  } else {
    int32_T nxm1;
    real_T szdvdf_idx_1;
    int32_T szs_idx_1;
    int32_T yoffset;
    real_T dnnm2;
    real_T r;
    nxm1 = x.size(1) - 1;
    if (has_endslopes) {
      szdvdf_idx_1 = static_cast<real_T>(y.size(1)) - 3.0;
      szs_idx_1 = y.size(1) - 2;
      yoffset = 1;
    } else {
      szdvdf_idx_1 = static_cast<real_T>(y.size(1)) - 1.0;
      szs_idx_1 = y.size(1);
      yoffset = 0;
    }

    s.set_size((&eb_emlrtRTEI), (&st), 1, s.size(1));
    if (szs_idx_1 < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(szs_idx_1), &emlrtDCI, &st);
    }

    s.set_size((&eb_emlrtRTEI), (&st), s.size(0), szs_idx_1);
    dvdf.set_size((&eb_emlrtRTEI), (&st), 1, dvdf.size(1));
    k = static_cast<int32_T>(szdvdf_idx_1);
    if (k < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(k), &b_emlrtDCI, &st);
    }

    dvdf.set_size((&eb_emlrtRTEI), (&st), dvdf.size(0), k);
    dx.set_size((&eb_emlrtRTEI), (&st), 1, (x.size(1) - 1));
    for (k = 0; k < nxm1; k++) {
      szdvdf_idx_1 = x[k + 1] - x[k];
      dx[k] = szdvdf_idx_1;
      szs_idx_1 = yoffset + k;
      dvdf[k] = (y[szs_idx_1 + 1] - y[szs_idx_1]) / szdvdf_idx_1;
    }

    for (k = 2; k <= nxm1; k++) {
      s[k - 1] = 3.0 * (dx[k - 1] * dvdf[k - 2] + dx[k - 2] * dvdf[k - 1]);
    }

    if (has_endslopes) {
      szdvdf_idx_1 = 0.0;
      dnnm2 = 0.0;
      s[0] = dx[1] * y[0];
      s[x.size(1) - 1] = dx[x.size(1) - 3] * y[x.size(1) + 1];
    } else {
      szdvdf_idx_1 = x[2] - x[0];
      dnnm2 = x[x.size(1) - 1] - x[x.size(1) - 3];
      s[0] = ((dx[0] + 2.0 * szdvdf_idx_1) * dx[1] * dvdf[0] + dx[0] * dx[0] *
              dvdf[1]) / szdvdf_idx_1;
      s[x.size(1) - 1] = ((dx[x.size(1) - 2] + 2.0 * dnnm2) * dx[x.size(1) - 3] *
                          dvdf[x.size(1) - 2] + dx[x.size(1) - 2] * dx[x.size(1)
                          - 2] * dvdf[x.size(1) - 3]) / dnnm2;
    }

    md.set_size((&eb_emlrtRTEI), (&st), x.size(0), x.size(1));
    md[0] = dx[1];
    md[x.size(1) - 1] = dx[x.size(1) - 3];
    for (k = 2; k <= nxm1; k++) {
      md[k - 1] = 2.0 * (dx[k - 1] + dx[k - 2]);
    }

    r = dx[1] / md[0];
    md[1] = md[1] - r * szdvdf_idx_1;
    s[1] = s[1] - r * s[0];
    for (k = 3; k <= nxm1; k++) {
      r = dx[k - 1] / md[k - 2];
      md[k - 1] = md[k - 1] - r * dx[k - 3];
      s[k - 1] = s[k - 1] - r * s[k - 2];
    }

    r = dnnm2 / md[x.size(1) - 2];
    md[x.size(1) - 1] = md[x.size(1) - 1] - r * dx[x.size(1) - 3];
    s[x.size(1) - 1] = s[x.size(1) - 1] - r * s[x.size(1) - 2];
    s[x.size(1) - 1] = s[x.size(1) - 1] / md[x.size(1) - 1];
    for (k = nxm1; k >= 2; k--) {
      s[k - 1] = (s[k - 1] - dx[k - 2] * s[k]) / md[k - 1];
    }

    s[0] = (s[0] - szdvdf_idx_1 * s[1]) / md[0];
    b_st.site = &bb_emlrtRSI;
    nxm1 = x.size(1);
    szs_idx_1 = s.size(1) - 1;
    k = s.size(1) - 1;
    if (k < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(k), &c_emlrtDCI, &b_st);
    }

    pp_coefs.set_size((&fb_emlrtRTEI), (&b_st), k, 4);
    for (k = 0; k <= nxm1 - 2; k++) {
      real_T dzzdx;
      szdvdf_idx_1 = dvdf[k];
      dnnm2 = s[k];
      r = dx[k];
      dzzdx = (szdvdf_idx_1 - dnnm2) / r;
      szdvdf_idx_1 = (s[k + 1] - szdvdf_idx_1) / r;
      pp_coefs[k] = (szdvdf_idx_1 - dzzdx) / r;
      pp_coefs[szs_idx_1 + k] = 2.0 * dzzdx - szdvdf_idx_1;
      pp_coefs[(szs_idx_1 << 1) + k] = dnnm2;
      pp_coefs[3 * szs_idx_1 + k] = y[yoffset + k];
    }

    output_breaks.set_size((&gb_emlrtRTEI), (&st), 1, x.size(1));
    szs_idx_1 = x.size(1);
    for (k = 0; k < szs_idx_1; k++) {
      output_breaks[k] = x[k];
    }

    output_coefs.set_size((&gb_emlrtRTEI), (&st), pp_coefs.size(0), 4);
    szs_idx_1 = pp_coefs.size(0) * pp_coefs.size(1);
    for (k = 0; k < szs_idx_1; k++) {
      output_coefs[k] = pp_coefs[k];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (spline.cpp)
