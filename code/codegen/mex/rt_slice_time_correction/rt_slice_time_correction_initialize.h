//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rt_slice_time_correction_initialize.h
//
//  Code generation for function 'rt_slice_time_correction_initialize'
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
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CODEGEN_EXPORT_SYM void rt_slice_time_correction_initialize();

// End of code generation (rt_slice_time_correction_initialize.h)
