// $Id$

#include "ace/Sched_Params.h"
#include "ace/Get_Opt.h"
#include "tao/Strategies/advanced_resource.h"
#include "tao/ORB_Core.h"
#include "Base_Server.h"
#include "AMH_Servant.h"

#include "TestC.h"


Base_Server::Base_Server (int* argc, char **argv)
  : argc_ (argc)
  , argv_ (argv)
{
  this->ior_output_file_ = ACE_const_cast (char*, "test.ior");
}

// @@ Mayur, empty parameter lists should be denoted with "(void)",
//    not "()".  Again, this is detailed in the guidelines.
Base_Server::~Base_Server ()
{
  ACE_TRY_NEW_ENV
    {
      this->root_poa_->destroy (1, 1 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      this->orb_->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught while destroying Base_Server \n");
    }
  ACE_ENDTRY;
}

int
Base_Server::parse_args ()
{
  // *** To get correct behaviour, set ** POSIXLY_CORECT=1 ** on Linux
  // systems!!! ***
  ACE_Get_Opt get_opts (*(this->argc_), this->argv_, "o:");
  int c;
  int count_argv = 0;

  while ((c = get_opts ()) != -1)
    {
      ++count_argv;
      switch (c)
        {
        case 'o':
          {
            this->ior_output_file_ = get_opts.opt_arg ();

            // Remove the option '-o' from argv []
            // to avoid any confusion that might result.
            {
              for (int i = count_argv; i <= *(this->argc_); ++i)
                this->argv_ [i] = this->argv_ [i+2];
            }

            // Decrement the value of this->argc_ to reflect the removal
            // of '-o' option.
            *(this->argc_) = *(this->argc_) - 2;

            return 1;
          }
        case '?':
        default:
          // Don't do anything.
          break;
        }
    }

  return 0;
}

void
Base_Server::try_RT_scheduling (void)
{
  int priority =
    (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
     + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2;
  priority = ACE_Sched_Params::next_priority (ACE_SCHED_FIFO,
                                              priority);

  // Enable FIFO scheduling, e.g., RT scheduling class on Solaris.
  if (ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                              priority,
                                              ACE_SCOPE_PROCESS)) != 0)
    {
      if (ACE_OS::last_error () == EPERM)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "server (%P|%t): user is not superuser, "
                      "test runs in time-shared class\n"));
        }
      else
        ACE_ERROR ((LM_ERROR,
                    "server (%P|%t): sched_params failed\n"));
    }
}

int
Base_Server::start_orb_and_poa (void)
{
  ACE_TRY_NEW_ENV
    {
      this->orb_ = CORBA::ORB_init (*(this->argc_),
                                    this->argv_,
                                    "" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var poa_object =
        this->orb_->resolve_initial_references("RootPOA"
                                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      this->root_poa_ = PortableServer::POA::_narrow (poa_object.in ()
                                                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        this->root_poa_->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception raised initialising ORB or POA");
      return -1;
    }
  ACE_ENDTRY;

  // If we have got to this point, everything has gone well.  return
  // normally
  return 1;
}

void
Base_Server::register_servant (AMH_Servant *servant)
{
  ACE_TRY_NEW_ENV
    {
      Test::Roundtrip_var roundtrip =
        servant->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::String_var ior =
        this->orb_->object_to_string (roundtrip.in ()
                                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      (void) this->write_ior_to_file (ior);
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception raised while registering servant");
    }
  ACE_ENDTRY;
}

// @@ Mayur, empty parameter lists should be denoted with "(void)",
//    not "()".  Again, this is detailed in the guidelines.
void
Base_Server::run_event_loop ()
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      ACE_Time_Value period (0, 11000);
      while (1)
        {
          // @@ Mayur, where's the work_pending() call?
          //
          // @@ Mayur, you're missing the ACE_ENV_ARG_PARAMETER macro
          //    in the below perform_work() call.  The ACE_TRY_CHECK
          //    below is useless without it.
          this->orb_->perform_work (&period);
          ACE_TRY_CHECK;
        }
      // @@ Mayur, why is this redundant ACE_TRY_CHECK here?
      ACE_TRY_CHECK;
    }
  // @@ Mayur, please put these on separate lines.  It's less
  //    confusing, and is our convention.  Why don't you at least
  //    print the exception?  You just ignore it.  For example:
  //
  //      ACE_CATCHANY
  //        {
  //           ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
  //                                "Caught exception");
  //        }
  //      ACE_ENDTRY;
  ACE_CATCHANY {} ACE_ENDTRY;
}

int
Base_Server::write_ior_to_file (CORBA::String_var ior)
{
  // @@ Mayur, what use is there in passing the CORBA::String_var by
  //    value?  It just needless incurs additional memory
  //    allocations.  Just pass the contents of the String_var (a
  //    const char *) via the ".in()" accessor.

  // If the ior_output_file exists, output the ior to it
  FILE *output_file =
    ACE_OS::fopen (this->ior_output_file_, "w");

  if (output_file == 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "Cannot open output file for writing IOR: %s",
                  this->ior_output_file_));
      return -1;
    }

  ACE_OS::fprintf (output_file, "%s", ior.in ());
  ACE_OS::fclose (output_file);
  return 0;
}
