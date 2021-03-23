//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_rt_slice_time_correction_api.cpp
//
//  Code generation for function '_coder_rt_slice_time_correction_api'
//


// Include files
#include "_coder_rt_slice_time_correction_api.h"
#include "fliplr.h"
#include "rt_nonfinite.h"
#include "rt_slice_time_correction.h"
#include "rt_slice_time_correction_data.h"
#include "spline.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *slice_times,
  const char_T *identifier, coder::array<real_T, 2U> &y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *slice_indices, const char_T *identifier, coder::array<boolean_T, 1U> &y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *volRaw, const
  char_T *identifier, coder::array<real_T, 2U> &y);
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<boolean_T, 1U> &y);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tr, const
  char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<boolean_T, 1U> &ret);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *slice_times,
  const char_T *identifier, coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(slice_times), &thisId, y);
  emlrtDestroyArray(&slice_times);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *slice_indices, const char_T *identifier, coder::array<boolean_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(slice_indices), &thisId, y);
  emlrtDestroyArray(&slice_indices);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *volRaw, const
  char_T *identifier, coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(volRaw), &thisId, y);
  emlrtDestroyArray(&volRaw);
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

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<boolean_T, 1U> &y)
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tr, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(tr), &thisId);
  emlrtDestroyArray(&tr);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.prealloc((iv[0] * iv[1]));
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  ret.set(((real_T *)emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<boolean_T, 1U> &ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv[1] = { true };

  int32_T iv[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "logical", false, 1U, dims, &bv[0],
    iv);
  ret.prealloc(iv[0]);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0]);
  ret.set(((boolean_T *)emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void rt_slice_time_correction_api(const mxArray * const prhs[5], int32_T, const
  mxArray *plhs[1])
{
  coder::array<real_T, 2U> volRaw;
  coder::array<real_T, 2U> slice_times;
  coder::array<boolean_T, 1U> slice_indices;
  real_T tr;
  real_T update;
  coder::array<real_T, 2U> vol_q;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  volRaw.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "volRaw", volRaw);
  slice_times.no_free();
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "slice_times", slice_times);
  slice_indices.no_free();
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "slice_indices", slice_indices);
  tr = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "tr");
  update = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "update");

  // Invoke the target function
  rt_slice_time_correction(&st, volRaw, slice_times, slice_indices, tr, update,
    vol_q);

  // Marshall function outputs
  vol_q.no_free();
  plhs[0] = emlrt_marshallOut(vol_q);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_rt_slice_time_correction_api.cpp)
