#ifndef NEXUS_CONCURRENCY_H
#define NEXUS_CONCURRENCY_H

typedef struct
{
    int locked;

} NexusMutex;


void mutex_init(
    NexusMutex *mutex
);


int mutex_lock(
    NexusMutex *mutex
);


int mutex_unlock(
    NexusMutex *mutex
);

#endif