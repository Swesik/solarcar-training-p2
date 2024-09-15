/*************************************************************************
ALGLIB 4.01.0 (source code generated 2023-12-27)
Copyright (c) Sergey Bochkanov (ALGLIB project).

>>> SOURCE LICENSE >>>
This  program  is  a  Commercial Edition  of the ALGLIB package  licensed
to University of Michigan Solar Car Team (Licensee), agreement ID is AGR-20230512-1

As of 2024-01-02:
* COMPANYWIDE license plan is purchased (unlimited developers working  in
  same company)
* following developers are registered for this license:
  * umatthew@umich.edu
  * bansalsh@umich.edu
  * artate@umich.edu
  * rtmeng@umich.edu

========================== GENERAL INFORMATION ==========================

1. Only Licensee and  its Sublicensees  can  use/distribute  it according
to ALGLIB License Agreement (see below) between Licensor and Licensee.

2. All developers using ALGLIB should register themselves at alglib.net.

3. This  source  code  may  contain  modifications  made  by  Licensee or
Sublicensees  which  fall under the terms of the ALGLIB License Agreement
too.

4. Text  below  is  an excerpt from complete ALGLIB License Agreement,  a
part which governs usage and redistribution rights granted  to  Licensee.
See agreement-v8uk.pdf at the root of  ALGLIB distribution for a complete
text of the license agreement.

================ ALGLIB LICENSE AGREEMENT ( APPENDIX A ) ================

DEFINITIONS:
* "ALGLIB" – software delivered by Licensor  to  Licensee  under  present
  Agreement. ALGLIB may include  Binary  Components  (delivered  only  in
  binary form) and Source  Code  Components  (with  optional  precompiled
  binary form).  ALGLIB  includes  integrated  third  party  software  as
  defined by clause 1 of the Appendix B which is considered as a part  of
  ALGLIB for the purposes of the present Agreement. Optional third  party
  software (as defined by clause 2 of Appendix B) is not considered as  a
  part of ALGLIB (even when such software is bundled with ALGLIB) and has
  its own licensing terms.
* "Application"  -  program  developed  by  Licensee  (either  standalone
  application or software development library) which includes  ALGLIB  as
  one of its parts .
* "Sublicensee"  -  any  party  (including  resellers)   which   receives
  Application from Licensee or another Sublicensee.
* "Application License Agreement"  -  agreement  which   governs   usage/
  redistribution of the Application.
  
LICENSE GRANT:
Subject to the License Restrictions below, Licensor  grants  to  Licensee
the following non-exclusive royalty-free licenses:
A. To modify Source Code Components of ALGLIB and to use modified version
   on the terms of this Agreement.
B. To  develop  Applications  which  use  ALGLIB  and  to distribute such
   Applications in Binary and/or Source Code forms,  with  ALGLIB  either
   statically or dynamically linked. This right is granted provided that:
   * distribution of Source Code forms of Application/ALGLIB is performed
     subject to additional conditions set by clause H (this clause is not
     applied to binary-only distribution)
   * such Applications add significant  primary  functionality  different
     from that of the ALGLIB.
   * such Applications do not expose ALGLIB API (application  programming
     interface) either directly or indirectly
   * Sublicensee  has  no   right   to  use  ALGLIB  except  as  part  of
     the Application
   * any  subsequent  redistribution   respects    conditions    of   the
     present Agreement
   * all Licensee’s developers using ALGLIB should register at  company's
     account at www.alglib.net
C. To use Resellers for distribution of the  Application  (in  Binary  or
   Source Code forms), provided that the only activity Reseller  performs
   with Application is redistribution.
   
LICENSE RESTRICTIONS:
D. Licensee/Sublicensee may NOT use, copy or distribute ALGLIB except  as
   provided in this Agreement.
D2. Licensee/Sublicensee may NOT rent or lease ALGLIB to any third party.
E. Licensee/Sublicensee may NOT disassemble, reverse engineer, decompile,
   modify Binary Components of ALGLIB or compiled forms  of  Source  Code
   components.
F. Licensee/Sublicensee  may  NOT  remove  any  copyright notice from the
   Source Code / Binary Components.
G. Licensee/Sublicensee may NOT  disable/remove  code  which  checks  for
   presence of license keys (if such code is included in ALGLIB) from the
   Source Code / Binary Components.
H. Distribution of  Source  Code  forms  of  Application/ALGLIB  must  be
   performed subject to additional conditions:
   * Source Code Components of ALGLIB are distributed only as part of the
     Application. They are not  publicly  distributed.  Sublicensee  must
     explicitly accept Application License Agreement in order  to  access
     ALGLIB source code.
   * Sublicensee has no right to redistribute Application/ALGLIB (in  any
     form, Binary or Source Code), unless Sublicensee is Reseller who  is
     fully compliant with conditions set by clause C.
   * Sublicensee has no right to modify ALGLIB Source  Code,  except  for
     the purpose of fixing bugs
   * Sublicensee has no right to workaround "use ALGLIB only as  part  of
     the Application" limitation by sequentially modifying Application in
     a way which effectively creates new program with different  purpose.
     Application   License  Agreement  may  (a)  explicitly  forbid  such
     modifications, or (b) allow only limited set of "safe" modifications
     (developing plugins, fixing bugs, modifying only specific  parts  of
     the Application).
     
COPYRIGHT:
Title to the ALGLIB and all copies  thereof  remain with Licensor. ALGLIB
is copyrighted and is protected by international copyright laws. You will
not remove any copyright notice from  the  ALGLIB  files.  You  agree  to
prevent any unauthorized copying of ALGLIB. Except as expressly  provided
herein, Licensor does not grant any express or implied right to you under
Licensor patents, copyrights, trademarks, or trade secret information.
>>> END OF LICENSE >>>
*************************************************************************/
#ifndef _kernels_fma_h
#define _kernels_fma_h

#include "ap.h"

#define AE_USE_CPP



namespace alglib_impl
{
#if !defined(ALGLIB_NO_FAST_KERNELS) && defined(_ALGLIB_HAS_AVX2_INTRINSICS)

double rdotv_fma(const ae_int_t n,
    /* Real    */ const double* __restrict x,
    /* Real    */ const double* __restrict y,
    const ae_state* __restrict _state);
double rdotv2_fma(const ae_int_t n,
    /* Real    */ const double* __restrict x,
    const ae_state* __restrict _state);
void raddv_fma(const ae_int_t n,
     const double alpha,
     /* Real    */ const double* __restrict y,
     /* Real    */ double* __restrict x,
     const ae_state* __restrict _state);
void raddvx_fma(const ae_int_t n, const double alpha, const double* __restrict y, double* __restrict x, ae_state *_state);
void rmuladdv_fma(const ae_int_t n,
     const double* __restrict y,
     const double* __restrict z,
     double* __restrict x,
     const ae_state* _state);
void rnegmuladdv_fma(const ae_int_t n,
     const double* __restrict y,
     const double* __restrict z,
     double* __restrict x,
     const ae_state* _state);
void rcopymuladdv_fma(const ae_int_t n,
     const double* __restrict y,
     const double* __restrict z,
     const double* __restrict x,
     double* __restrict r,
     const ae_state* _state);
void rcopynegmuladdv_fma(const ae_int_t n,
     const double* __restrict y,
     const double* __restrict z,
     const double* __restrict x,
     double* __restrict r,
     const ae_state* _state);
void rgemv_straight_fma(const ae_int_t m, const ae_int_t n,
    const double alpha, const ae_matrix* __restrict a,
    const double* __restrict x, double* __restrict y, ae_state* _state);
void rgemv_transposed_fma(const ae_int_t m, const ae_int_t n,
    const double alpha, const ae_matrix* __restrict a,
    const double* __restrict x, double* __restrict y, ae_state* _state);
void rgemvx_straight_fma(const ae_int_t m, const ae_int_t n,
    const double alpha, const ae_matrix* __restrict a, const ae_int_t ia,
    const ae_int_t ja, const double* __restrict x,
    double* __restrict y, ae_state* _state);
void rgemvx_transposed_fma(const ae_int_t m, const ae_int_t n,
    const double alpha, const ae_matrix* __restrict a, const ae_int_t ia,
    const ae_int_t ja, const double* __restrict x, double* __restrict y,
    ae_state* _state);

void ablasf_dotblkh_fma(
    const double *src_a,
    const double *src_b,
    ae_int_t round_length,
    ae_int_t block_size,
    ae_int_t micro_size,
    double *dst,
    ae_int_t dst_stride);
void spchol_propagatefwd_fma(/* Real    */ const ae_vector* x,
     ae_int_t cols0,
     ae_int_t blocksize,
     /* Integer */ const ae_vector* superrowidx,
     ae_int_t rbase,
     ae_int_t offdiagsize,
     /* Real    */ const ae_vector* rowstorage,
     ae_int_t offss,
     ae_int_t sstride,
     /* Real    */ ae_vector* simdbuf,
     ae_int_t simdwidth,
     ae_state *_state);
ae_bool spchol_updatekernelabc4_fma(double* rowstorage,
     ae_int_t offss,
     ae_int_t twidth,
     ae_int_t offsu,
     ae_int_t uheight,
     ae_int_t urank,
     ae_int_t urowstride,
     ae_int_t uwidth,
     const double* diagd,
     ae_int_t offsd,
     const ae_int_t* raw2smap,
     const ae_int_t* superrowidx,
     ae_int_t urbase,
     ae_state *_state);
ae_bool spchol_updatekernel4444_fma(
     double*  rowstorage,
     ae_int_t offss,
     ae_int_t sheight,
     ae_int_t offsu,
     ae_int_t uheight,
     const double*  diagd,
     ae_int_t offsd,
     const ae_int_t* raw2smap,
     const ae_int_t* superrowidx,
     ae_int_t urbase,
     ae_state *_state);


/* ALGLIB_NO_FAST_KERNELS, _ALGLIB_HAS_AVX2_INTRINSICS */
#endif

}

#endif

