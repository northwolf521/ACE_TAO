
// $Id$

#include "shmem.h"

int
main (int, char *[])
{
        // Be sure the segment is sized to hold our object.
    ACE_Shared_Memory_SV shm_server (SHM_KEY, sizeof(SharedData), 
                                     ACE_Shared_Memory_SV::ACE_CREATE);

    char *shm = (char *) shm_server.malloc ();

    ACE_DEBUG ((LM_INFO, "(%P|%t) Shared Memory is at 0x%x\n",
                shm ));

        /*
          Use the placement new syntax to stuff the object into the
          correct location.  I think they generally reserve this for
          the advanced class...
         */
    SharedData * sd = new(shm) SharedData;

        // Use the set() method to put some data into the object
    sd->set();

        // Set the 'available' flag to zero so that we can wait on it
    sd->available(0);

        /*
          Another cheesy busy loop while we wait for the object to
          become available.  The cool way would be to hide a semaphore 
          or two behind this method call & eliminate the sleep.
        */
    while ( ! sd->available() )
        ACE_OS::sleep (1);

        // Show the user what's in the segment
    sd->show();

        // All done.
    if (shm_server.remove () < 0)
        ACE_ERROR ((LM_ERROR, "%p\n", "remove"));

    return 0;
}

