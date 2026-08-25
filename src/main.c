/*
============================================================

NEXUS SYSTEMS PLATFORM

Phase 4 Capstone

Demonstrates the integration of the major systems
subsystems implemented throughout Phase 4.

============================================================
*/

#include <stdio.h>

#include "process.h"
#include "scheduler.h"
#include "memory.h"
#include "concurrency.h"
#include "compiler.h"
#include "network.h"
#include "hypervisor.h"


int main(void)
{
    printf("\n");
    printf("==================================================\n");
    printf("             NEXUS SYSTEMS PLATFORM\n");
    printf("==================================================\n");


    /*
    ========================================================
    PROCESS + CPU SCHEDULER
    ========================================================
    */

    printf("\n[1] PROCESS MANAGEMENT\n\n");


    Scheduler scheduler;


    initialise_scheduler(
        &scheduler
    );


    add_process(
        &scheduler,
        "web-server",
        1,
        5
    );


    add_process(
        &scheduler,
        "database",
        2,
        3
    );


    add_process(
        &scheduler,
        "compiler",
        3,
        7
    );


    print_scheduler(
        &scheduler
    );


    schedule_fcfs(
        &scheduler
    );


    printf(
        "\nAfter FCFS scheduling:\n"
    );


    print_scheduler(
        &scheduler
    );


    /*
    ========================================================
    MEMORY
    ========================================================
    */

    printf(
        "\n[2] MEMORY MANAGEMENT\n\n"
    );


    MemoryManager memory;


    initialise_memory(
        &memory
    );


    void *block_a =
        memory_allocate(
            &memory,
            128
        );


    void *block_b =
        memory_allocate(
            &memory,
            256
        );


    (void)block_a;
    (void)block_b;


    print_memory(
        &memory
    );


    memory_free(
        &memory,
        block_a
    );


    printf(
        "After freeing block A:\n"
    );


    print_memory(
        &memory
    );


    /*
    ========================================================
    CONCURRENCY
    ========================================================
    */

    printf(
        "\n[3] CONCURRENCY\n\n"
    );


    NexusMutex mutex;


    mutex_init(
        &mutex
    );


    printf(
        "Thread A lock: %s\n",

        mutex_lock(&mutex)
            ? "acquired"
            : "blocked"
    );


    printf(
        "Thread B lock: %s\n",

        mutex_lock(&mutex)
            ? "acquired"
            : "blocked"
    );


    mutex_unlock(
        &mutex
    );


    printf(
        "Thread B retry: %s\n",

        mutex_lock(&mutex)
            ? "acquired"
            : "blocked"
    );


    /*
    ========================================================
    COMPILER FRONT-END
    ========================================================
    */

    printf(
        "\n[4] COMPILER FRONT-END\n\n"
    );


    Lexer lexer;


    initialise_lexer(
        &lexer,
        "42 + 7 * 3"
    );


    Token token;


    do
    {
        token =
            next_token(
                &lexer
            );


        print_token(
            token
        );

    }
    while (
        token.type != TOKEN_END
    );


    /*
    ========================================================
    NETWORKING
    ========================================================
    */

    printf(
        "\n[5] NETWORKING\n\n"
    );


    NetworkPacket packet;


    create_packet(
        &packet,
        5000,
        8080,
        128
    );


    print_packet(
        &packet
    );


    /*
    ========================================================
    VIRTUALISATION
    ========================================================
    */

    printf(
        "\n[6] VIRTUALISATION\n\n"
    );


    Hypervisor hypervisor;


    initialise_hypervisor(
        &hypervisor,
        8,
        16384
    );


    int vm1 =
        create_virtual_machine(
            &hypervisor,
            2,
            4096
        );


    int vm2 =
        create_virtual_machine(
            &hypervisor,
            4,
            8192
        );


    start_virtual_machine(
        &hypervisor,
        vm1
    );


    start_virtual_machine(
        &hypervisor,
        vm2
    );


    print_hypervisor(
        &hypervisor
    );


    /*
    ========================================================
    COMPLETE
    ========================================================
    */

    printf(
        "\n==================================================\n"
    );

    printf(
        "Nexus systems simulation complete.\n"
    );

    printf(
        "==================================================\n\n"
    );


    return 0;
}