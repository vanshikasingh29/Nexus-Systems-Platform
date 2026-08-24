#include "concurrency.h"


void mutex_init(
    NexusMutex *mutex
)
{
    if (mutex == NULL)
    {
        return;
    }

    mutex->locked = 0;
}


int mutex_lock(
    NexusMutex *mutex
)
{
    if (mutex == NULL)
    {
        return 0;
    }


    if (mutex->locked)
    {
        return 0;
    }


    mutex->locked = 1;

    return 1;
}


int mutex_unlock(
    NexusMutex *mutex
)
{
    if (
        mutex == NULL ||
        !mutex->locked
    )
    {
        return 0;
    }


    mutex->locked = 0;

    return 1;
}