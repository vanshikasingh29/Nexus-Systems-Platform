#include "hypervisor.h"

#include <stdio.h>


void initialise_hypervisor(
    Hypervisor *hypervisor,
    int host_cpus,
    int host_memory_mb
)
{
    if (hypervisor == NULL)
    {
        return;
    }


    hypervisor->host_cpus =
        host_cpus;

    hypervisor->host_memory_mb =
        host_memory_mb;

    hypervisor->machine_count =
        0;
}


int create_virtual_machine(
    Hypervisor *hypervisor,
    int vcpus,
    int memory_mb
)
{
    if (
        hypervisor == NULL ||
        hypervisor->machine_count >=
            MAX_VIRTUAL_MACHINES ||
        vcpus <= 0 ||
        memory_mb <= 0
    )
    {
        return -1;
    }


    int id =
        hypervisor->machine_count;


    VirtualMachine *vm =
        &hypervisor->machines[id];


    vm->id = id;

    vm->vcpus = vcpus;

    vm->memory_mb = memory_mb;

    vm->running = 0;


    hypervisor->machine_count++;


    return id;
}


int start_virtual_machine(
    Hypervisor *hypervisor,
    int id
)
{
    if (
        hypervisor == NULL ||
        id < 0 ||
        id >= hypervisor->machine_count
    )
    {
        return 0;
    }


    VirtualMachine *vm =
        &hypervisor->machines[id];


    if (vm->running)
    {
        return 0;
    }


    int used_cpus = 0;

    int used_memory = 0;


    for (
        int i = 0;
        i < hypervisor->machine_count;
        i++
    )
    {
        if (
            hypervisor->machines[i].running
        )
        {
            used_cpus +=
                hypervisor->machines[i].vcpus;

            used_memory +=
                hypervisor->machines[i].memory_mb;
        }
    }


    if (
        used_cpus + vm->vcpus >
        hypervisor->host_cpus
    )
    {
        return 0;
    }


    if (
        used_memory + vm->memory_mb >
        hypervisor->host_memory_mb
    )
    {
        return 0;
    }


    vm->running = 1;


    return 1;
}


void print_hypervisor(
    const Hypervisor *hypervisor
)
{
    if (hypervisor == NULL)
    {
        return;
    }


    printf(
        "\nVirtualisation Layer\n"
    );


    printf(
        "Host: %d CPUs / %d MB RAM\n",

        hypervisor->host_cpus,

        hypervisor->host_memory_mb
    );


    for (
        int i = 0;
        i < hypervisor->machine_count;
        i++
    )
    {
        const VirtualMachine *vm =
            &hypervisor->machines[i];


        printf(
            "VM %d | %d vCPU | %d MB | %s\n",

            vm->id,

            vm->vcpus,

            vm->memory_mb,

            vm->running
                ? "RUNNING"
                : "STOPPED"
        );
    }
}