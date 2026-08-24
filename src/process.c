#include "process.h"

#include <stdio.h>
#include <string.h>


void initialise_process(
    Process *process,
    int pid,
    const char *name,
    int priority,
    int cpu_burst
)
{
    if (
        process == NULL ||
        name == NULL
    )
    {
        return;
    }


    process->pid = pid;

    strncpy(
        process->name,
        name,
        PROCESS_NAME_LENGTH - 1
    );

    process->name[
        PROCESS_NAME_LENGTH - 1
    ] = '\0';


    process->priority = priority;

    process->cpu_burst = cpu_burst;

    process->remaining_burst = cpu_burst;

    process->state = PROCESS_NEW;
}


void set_process_state(
    Process *process,
    ProcessState state
)
{
    if (process == NULL)
    {
        return;
    }

    process->state = state;
}


const char *process_state_name(
    ProcessState state
)
{
    switch (state)
    {
        case PROCESS_NEW:
            return "NEW";

        case PROCESS_READY:
            return "READY";

        case PROCESS_RUNNING:
            return "RUNNING";

        case PROCESS_WAITING:
            return "WAITING";

        case PROCESS_TERMINATED:
            return "TERMINATED";

        default:
            return "UNKNOWN";
    }
}


void print_process(
    const Process *process
)
{
    if (process == NULL)
    {
        return;
    }


    printf(
        "PID=%d | %-16s | priority=%d | burst=%d | remaining=%d | %s\n",

        process->pid,

        process->name,

        process->priority,

        process->cpu_burst,

        process->remaining_burst,

        process_state_name(
            process->state
        )
    );
}