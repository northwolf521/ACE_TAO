// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_UIOP_ENDPOINTSC_H_
#define _TAO_IDL_ORIG_UIOP_ENDPOINTSC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "strategies_export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Strategies_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_type.cpp:258

struct TAO_UIOP_Endpoint_Info;

typedef
  TAO_Var_Var_T<
      TAO_UIOP_Endpoint_Info
    >
  TAO_UIOP_Endpoint_Info_var;

typedef
  TAO_Out_T<
      TAO_UIOP_Endpoint_Info,
      TAO_UIOP_Endpoint_Info_var
    >
  TAO_UIOP_Endpoint_Info_out;

// TAO_IDL - Generated from
// be\be_visitor_structure/structure_ch.cpp:52

struct TAO_Strategies_Export TAO_UIOP_Endpoint_Info
{
  typedef TAO_UIOP_Endpoint_Info_var _var_type;
  
  static void _tao_any_destructor (void *);
  TAO_String_Manager rendezvous_point;
  CORBA::Short priority;
};

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_decl.cpp:44

extern TAO_Strategies_Export ::CORBA::TypeCode_ptr const _tc_TAO_UIOP_Endpoint_Info;

// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_TAO_UIOPENDPOINTSEQUENCE_CH_)
#define _TAO_UIOPENDPOINTSEQUENCE_CH_

class TAO_UIOPEndpointSequence;

typedef
  TAO_VarSeq_Var_T<
      TAO_UIOPEndpointSequence,
      TAO_UIOP_Endpoint_Info
    >
  TAO_UIOPEndpointSequence_var;

typedef
  TAO_Seq_Out_T<
      TAO_UIOPEndpointSequence,
      TAO_UIOPEndpointSequence_var,
      TAO_UIOP_Endpoint_Info
    >
  TAO_UIOPEndpointSequence_out;

class TAO_Strategies_Export TAO_UIOPEndpointSequence
  : public
      TAO_Unbounded_Sequence<
          TAO_UIOP_Endpoint_Info
        >
{
public:
  TAO_UIOPEndpointSequence (void);
  TAO_UIOPEndpointSequence (CORBA::ULong max);
  TAO_UIOPEndpointSequence (
      CORBA::ULong max,
      CORBA::ULong length,
      TAO_UIOP_Endpoint_Info* buffer, 
      CORBA::Boolean release = 0
    );
  TAO_UIOPEndpointSequence (const TAO_UIOPEndpointSequence &);
  ~TAO_UIOPEndpointSequence (void);
  
  static void _tao_any_destructor (void *);
  
  typedef TAO_UIOPEndpointSequence_var _var_type;
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_decl.cpp:44

extern TAO_Strategies_Export ::CORBA::TypeCode_ptr const _tc_TAO_UIOPEndpointSequence;

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_Strategies_Export void operator<<= (CORBA::Any &, const TAO_UIOP_Endpoint_Info &); // copying version
TAO_Strategies_Export void operator<<= (CORBA::Any &, TAO_UIOP_Endpoint_Info*); // noncopying version
TAO_Strategies_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_UIOP_Endpoint_Info *&); // deprecated
TAO_Strategies_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_UIOP_Endpoint_Info *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Strategies_Export void operator<<= (CORBA::Any &, const TAO_UIOPEndpointSequence &); // copying version
TAO_Strategies_Export void operator<<= (CORBA::Any &, TAO_UIOPEndpointSequence*); // noncopying version
TAO_Strategies_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_UIOPEndpointSequence *&); // deprecated
TAO_Strategies_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_UIOPEndpointSequence *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Strategies_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_UIOP_Endpoint_Info &);
TAO_Strategies_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_UIOP_Endpoint_Info &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_TAO_UIOPEndpointSequence_H_
#define _TAO_CDR_OP_TAO_UIOPEndpointSequence_H_

TAO_Strategies_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const TAO_UIOPEndpointSequence &
  );
TAO_Strategies_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    TAO_UIOPEndpointSequence &
  );

#endif /* _TAO_CDR_OP_TAO_UIOPEndpointSequence_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:958

#if defined (__ACE_INLINE__)
#include "uiop_endpointsC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


