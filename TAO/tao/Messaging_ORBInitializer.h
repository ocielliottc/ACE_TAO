// -*- C++ -*-
//
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     Messaging_ORBInitializer.h
//
// = AUTHOR
//     Ossama Othman <ossama@uci.edu>
//
// ============================================================================

#ifndef TAO_MESSAGING_ORB_INITIALIZER_H
#define TAO_MESSAGING_ORB_INITIALIZER_H

#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if TAO_HAS_CORBA_MESSAGING == 1

#include "tao/PortableInterceptorC.h"
#include "tao/LocalObject.h"

// This is to remove "inherits via dominance" warnings from MSVC.
// MSVC is being a little too paranoid.
#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

/// Messaging ORB initializer.
class TAO_Export TAO_Messaging_ORBInitializer :
  public virtual PortableInterceptor::ORBInitializer,
  public virtual TAO_Local_RefCounted_Object
{
public:

  virtual void pre_init (PortableInterceptor::ORBInitInfo_ptr info
                         TAO_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void post_init (PortableInterceptor::ORBInitInfo_ptr info
                          TAO_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:

  void register_policy_factories (
         PortableInterceptor::ORBInitInfo_ptr info
         TAO_ENV_ARG_DECL);
  ///< Register Messaging policy factories.

};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif  /* TAO_HAS_CORBA_MESSAGING == 1 */

#include "ace/post.h"

#endif /* TAO_MESSAGING_ORB_INITIALIZER_H */
