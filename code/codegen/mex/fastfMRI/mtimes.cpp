//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mtimes.cpp
//
//  Code generation for function 'mtimes'
//


// Include files
#include "mtimes.h"
#include "blas.h"
#include "fastfMRI.h"
#include "fastfMRI_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRTEInfo l_emlrtRTEI = { 140,// lineNo
  5,                                   // colNo
  "mtimes",                            // fName
  "/Applications/MATLAB_R2020a.app/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"// pName 
};

// Function Definitions
void b_mtimes(const emlrtStack *sp, const coder::array<real_T, 2U> &A, const
              coder::array<real_T, 2U> &B, coder::array<real_T, 2U> &C)
{
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
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(0) == 0) || (B.size(1) ==
       0)) {
    int32_T loop_ub;
    C.set_size((&l_emlrtRTEI), sp, A.size(0), B.size(0));
    loop_ub = A.size(0) * B.size(0);
    for (int32_T i = 0; i < loop_ub; i++) {
      C[i] = 0.0;
    }
  } else {
    st.site = &i_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A.size(0);
    n_t = (ptrdiff_t)B.size(0);
    k_t = (ptrdiff_t)A.size(1);
    lda_t = (ptrdiff_t)A.size(0);
    ldb_t = (ptrdiff_t)B.size(0);
    ldc_t = (ptrdiff_t)A.size(0);
    C.set_size((&d_emlrtRTEI), (&st), A.size(0), B.size(0));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((coder::array<real_T,
             2U> *)&A)->data())[0], &lda_t, &(((coder::array<real_T, 2U> *)&B)
           ->data())[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

void mtimes(const emlrtStack *sp, const coder::array<real_T, 2U> &A, const coder::
            array<real_T, 2U> &B, coder::array<real_T, 2U> &C)
{
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
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(0) == 0) || (B.size(1) ==
       0)) {
    int32_T loop_ub;
    C.set_size((&l_emlrtRTEI), sp, A.size(0), B.size(1));
    loop_ub = A.size(0) * B.size(1);
    for (int32_T i = 0; i < loop_ub; i++) {
      C[i] = 0.0;
    }
  } else {
    st.site = &i_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A.size(0);
    n_t = (ptrdiff_t)B.size(1);
    k_t = (ptrdiff_t)A.size(1);
    lda_t = (ptrdiff_t)A.size(0);
    ldb_t = (ptrdiff_t)B.size(0);
    ldc_t = (ptrdiff_t)A.size(0);
    C.set_size((&d_emlrtRTEI), (&st), A.size(0), B.size(1));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((coder::array<real_T,
             2U> *)&A)->data())[0], &lda_t, &(((coder::array<real_T, 2U> *)&B)
           ->data())[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

// End of code generation (mtimes.cpp)
