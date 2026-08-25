#ifndef NEXUS_HYPERVISOR_H
#define NEXUS_HYPERVISOR_H

#define MAX_VIRTUAL_MACHINES 8

typedef struct
{
    int id;

    int vcpus;

    int memory_mb;

    int running;

} VirtualMachine;


typedef struct
{
    int host_cpus;

    int host_memory_mb;

    VirtualMachine machines[
        MAX_VIRTUAL_MACHINES
    ];

    int machine_count;

} Hypervisor;


void initialise_hypervisor(
    Hypervisor *hypervisor,
    int host_cpus,
    int host_memory_mb
);


int create_virtual_machine(
    Hypervisor *hypervisor,
    int vcpus,
    int memory_mb
);


int start_virtual_machine(
    Hypervisor *hypervisor,
    int id
);


void print_hypervisor(
    const Hypervisor *hypervisor
);

#endif