#include <stdio.h>

#include "process.h"


static int passed = 0;
static int failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf("[PASS] %s\n", name);
        passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        failed++;
    }
}


int main(void)
{
    Process process;


    initialise_process(
        &process,
        7,
        "worker",
        2,
        10
    );


    assert_test(
        process.pid == 7,
        "Process identifier"
    );


    assert_test(
        process.priority == 2,
        "Process priority"
    );


    assert_test(
        process.cpu_burst == 10 &&
        process.remaining_burst == 10,
        "CPU burst initialisation"
    );


    assert_test(
        process.state == PROCESS_NEW,
        "Initial process state"
    );


    set_process_state(
        &process,
        PROCESS_RUNNING
    );


    assert_test(
        process.state == PROCESS_RUNNING,
        "Process state transition"
    );


    printf(
        "\nPassed: %d\nFailed: %d\n",
        passed,
        failed
    );


    return failed != 0;
}