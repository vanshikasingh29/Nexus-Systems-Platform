#ifndef NEXUS_PROCESS_H
#define NEXUS_PROCESS_H

#define MAX_PROCESSES 64
#define PROCESS_NAME_LENGTH 64

typedef enum
{
    PROCESS_NEW,
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_WAITING,
    PROCESS_TERMINATED

} ProcessState;


typedef struct
{
    int pid;

    char name[PROCESS_NAME_LENGTH];

    int priority;

    int cpu_burst;

    int remaining_burst;

    ProcessState state;

} Process;


void initialise_process(
    Process *process,
    int pid,
    const char *name,
    int priority,
    int cpu_burst
);


void set_process_state(
    Process *process,
    ProcessState state
);


const char *process_state_name(
    ProcessState state
);


void print_process(
    const Process *process
);

#endif