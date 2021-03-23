//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_fastfMRI_api.cpp
//
//  Code generation for function '_coder_fastfMRI_api'
//


// Include files
#include "_coder_fastfMRI_api.h"
#include "fastfMRI.h"
#include "fastfMRI_data.h"
#include "mtimes.h"
#include "rt_nonfinite.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xT1, const
  char_T *identifier, coder::array<real_T, 1U> &y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 1U> &y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *XT, const
  char_T *identifier, coder::array<real_T, 2U> &y);
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 1U> &ret);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xT1, const
  char_T *identifier, coder::array<real_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(xT1), &thisId, y);
  emlrtDestroyArray(&xT1);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 1U> &y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv[2] = { true, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.prealloc((iv[0] * iv[1]));
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  ret.set(((real_T *)emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *XT, const
  char_T *identifier, coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(XT), &thisId, y);
  emlrtDestroyArray(&XT);
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 1U> &ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv[1] = { true };

  int32_T iv[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv[0],
    iv);
  ret.prealloc(iv[0]);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0]);
  ret.set(((real_T *)emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

void fastfMRI_api(const mxArray * const prhs[5], int32_T nlhs, const mxArray
                  *plhs[2])
{
  coder::array<real_T, 2U> XT;
  coder::array<real_T, 2U> YT;
  coder::array<real_T, 2U> ATInv;
  coder::array<real_T, 1U> xT1;
  coder::array<real_T, 1U> yT1;
  coder::array<real_T, 2U> eVec;
  coder::array<real_T, 2U> AT1Inv;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  XT.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "XT", XT);
  YT.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "YT", YT);
  ATInv.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "ATInv", ATInv);
  xT1.no_free();
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "xT1", xT1);
  yT1.no_free();
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "yT1", yT1);

  // Invoke the target function
  fastfMRI(&st, XT, YT, ATInv, xT1, yT1, eVec, AT1Inv);

  // Marshall function outputs
  eVec.no_free();
  plhs[0] = emlrt_marshallOut(eVec);
  if (nlhs > 1) {
    AT1Inv.no_free();
    plhs[1] = emlrt_marshallOut(AT1Inv);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_fastfMRI_api.cpp)
