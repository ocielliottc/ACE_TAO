// $Id$

#include "Shutdown.h"
#include "Consumer.h"
#include "Supplier.h"

ACE_RCSID(EC_Tests_Basic, Shutdown, "$Id$")

int
main (int argc, char *argv [])
{
  EC_Shutdown driver;
  return driver.run (argc, argv);
}

// ****************************************************************

EC_Shutdown::EC_Shutdown (void)
  :  consumer_disconnects_ (0),
     supplier_disconnects_ (0)
{
}

void
EC_Shutdown::execute_test (CORBA::Environment& ACE_TRY_ENV)
{
  if (this->verbose ())
    ACE_DEBUG ((LM_DEBUG, "EC_Shutdown (%P|%t) destroying EC\n"));

  this->destroy_ec (ACE_TRY_ENV);
  ACE_CHECK;

  if (this->verbose ())
    ACE_DEBUG ((LM_DEBUG, "EC_Shutdown (%P|%t) ec destroyed\n"));

  this->deactivate_ec (ACE_TRY_ENV);
  ACE_CHECK;

  if (this->verbose ())
    ACE_DEBUG ((LM_DEBUG, "EC_Shutdown (%P|%t) ec deactivated\n"));

  this->cleanup_ec ();

  if (this->verbose ())
    ACE_DEBUG ((LM_DEBUG, "EC_Shutdown (%P|%t) ec cleanup\n"));

  this->initialize_ec_impl (ACE_TRY_ENV);
  ACE_CHECK;
  this->connect_consumers (ACE_TRY_ENV);
  ACE_CHECK;
  this->connect_suppliers (ACE_TRY_ENV);
  ACE_CHECK;
  if (this->verbose ())
    ACE_DEBUG ((LM_DEBUG, "EC_Shutdown (%P|%t) status reset\n"));

  // this->EC_Driver::execute_test (ACE_TRY_ENV);
}

void
EC_Shutdown::dump_results (void)
{
  if (this->consumer_disconnects_ != this->n_consumers_)
    ACE_ERROR ((LM_ERROR,
                "Unexpected number (%d) of consumers disconnected\n",
                this->consumer_disconnects_));

  if (this->supplier_disconnects_ != this->n_suppliers_)
    ACE_ERROR ((LM_ERROR,
                "Unexpected number (%d) of suppliers disconnected\n",
                this->supplier_disconnects_));
}

void
EC_Shutdown::consumer_disconnect (void* cookie,
                                  CORBA::Environment&)
{
  this->consumer_disconnects_++;
  if (this->verbose ())
    ACE_DEBUG ((LM_DEBUG, "Consumer %x has been disconnected\n", cookie));
}

void
EC_Shutdown::supplier_disconnect (void* cookie,
                                  CORBA::Environment&)
{
  this->supplier_disconnects_++;
  if (this->verbose ())
    ACE_DEBUG ((LM_DEBUG, "Supplier %x has been disconnected\n", cookie));
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
