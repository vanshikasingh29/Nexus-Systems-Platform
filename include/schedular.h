#ifndef NEXUS_SCHEDULER_H
#define NEXUS_SCHEDULER_H

#include "process.h"

typedef struct
{
    Process processes[MAX_PROCESSES];

    int process_count;

} Scheduler;


void initialise_scheduler(
    Scheduler *scheduler
);


int add_process(
    Scheduler *scheduler,
    const char *name,
    int priority,
    int cpu_burst
);


void schedule_fcfs(
    Scheduler *scheduler
);


void print_scheduler(
    const Scheduler *scheduler
);

#endif