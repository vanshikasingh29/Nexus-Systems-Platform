#include <stdio.h>

#include "memory.h"


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
    MemoryManager manager;


    initialise_memory(
        &manager
    );


    assert_test(
        memory_used(&manager) == 0,
        "Initial memory usage"
    );


    void *a =
        memory_allocate(
            &manager,
            100
        );


    assert_test(
        a != NULL,
        "Memory allocation"
    );


    assert_test(
        memory_used(&manager) == 100,
        "Memory accounting"
    );


    void *b =
        memory_allocate(
            &manager,
            200
        );


    assert_test(
        b != NULL &&
        memory_used(&manager) == 300,
        "Multiple allocations"
    );


    assert_test(
        memory_free(
            &manager,
            a
        ),
        "Memory deallocation"
    );


    assert_test(
        memory_used(&manager) == 200,
        "Memory usage after free"
    );


    printf(
        "\nPassed: %d\nFailed: %d\n",
        passed,
        failed
    );


    return failed != 0;
}