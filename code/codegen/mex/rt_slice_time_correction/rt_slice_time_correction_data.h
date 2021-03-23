//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction_data.h
//
//  Code generation for function 'rt_slice_time_correction_data'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "rt_slice_time_correction_types.h"

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo i_emlrtRSI;
extern emlrtRSInfo k_emlrtRSI;
extern emlrtRSInfo l_emlrtRSI;
extern emlrtRSInfo m_emlrtRSI;
extern emlrtRSInfo n_emlrtRSI;
extern emlrtRSInfo o_emlrtRSI;
extern emlrtRSInfo p_emlrtRSI;
extern emlrtRSInfo q_emlrtRSI;
extern emlrtRSInfo r_emlrtRSI;
extern emlrtRSInfo x_emlrtRSI;
extern emlrtRSInfo y_emlrtRSI;
extern emlrtRSInfo ab_emlrtRSI;
extern emlrtRSInfo cb_emlrtRSI;
extern emlrtRSInfo db_emlrtRSI;
extern emlrtRTEInfo emlrtRTEI;
extern emlrtRTEInfo b_emlrtRTEI;
extern emlrtRTEInfo c_emlrtRTEI;
extern emlrtRTEInfo d_emlrtRTEI;
extern emlrtRTEInfo t_emlrtRTEI;

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (rt_slice_time_correction_data.h)
