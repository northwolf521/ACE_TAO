//
// $Id$
//

#ifndef REPLY_HANDLER_H
#define REPLY_HANDLER_H
#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the AMI_AMI_BufferingHandler interface
class Reply_Handler
  : public virtual POA_Test::AMI_AMI_BufferingHandler
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Reply_Handler (void);

  // = The skeleton methods
  virtual void receive_data (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void receive_data_excep (Test::AMI_AMI_BufferingExceptionHolder *holder
                                   ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void sync (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void sync_excep (Test::AMI_AMI_BufferingExceptionHolder *holder
                           ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void shutdown_excep (Test::AMI_AMI_BufferingExceptionHolder *holder
                               ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
};

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* REPLY_HANDLER_H */
