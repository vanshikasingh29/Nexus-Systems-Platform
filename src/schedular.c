#include "scheduler.h"

#include <stdio.h>


void initialise_scheduler(
    Scheduler *scheduler
)
{
    if (scheduler == NULL)
    {
        return;
    }

    scheduler->process_count = 0;
}


int add_process(
    Scheduler *scheduler,
    const char *name,
    int priority,
    int cpu_burst
)
{
    if (
        scheduler == NULL ||
        scheduler->process_count >= MAX_PROCESSES
    )
    {
        return -1;
    }


    int pid =
        scheduler->process_count;


    initialise_process(
        &scheduler->processes[
            scheduler->process_count
        ],

        pid,

        name,

        priority,

        cpu_burst
    );


    scheduler->processes[
        scheduler->process_count
    ].state = PROCESS_READY;


    scheduler->process_count++;


    return pid;
}


/*
============================================================
First Come First Served

The simplest non-preemptive scheduling algorithm.

Processes execute in arrival order.
============================================================
*/

void schedule_fcfs(
    Scheduler *scheduler
)
{
    if (scheduler == NULL)
    {
        return;
    }


    for (
        int i = 0;
        i < scheduler->process_count;
        i++
    )
    {
        Process *process =
            &scheduler->processes[i];


        process->state =
            PROCESS_RUNNING;


        process->remaining_burst = 0;


        process->state =
            PROCESS_TERMINATED;
    }
}


void print_scheduler(
    const Scheduler *scheduler
)
{
    if (scheduler == NULL)
    {
        return;
    }


    printf(
        "\nProcess Scheduler\n"
    );

    printf(
        "------------------------------------------------------------\n"
    );


    for (
        int i = 0;
        i < scheduler->process_count;
        i++
    )
    {
        print_process(
            &scheduler->processes[i]
        );
    }
}