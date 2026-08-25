#include <stdio.h>

#include "compiler.h"


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
    Lexer lexer;


    initialise_lexer(
        &lexer,
        "42 + 7"
    );


    Token token =
        next_token(
            &lexer
        );


    assert_test(
        token.type == TOKEN_NUMBER &&
        token.value == 42,
        "Lexing integer"
    );


    token =
        next_token(
            &lexer
        );


    assert_test(
        token.type == TOKEN_PLUS,
        "Lexing operator"
    );


    token =
        next_token(
            &lexer
        );


    assert_test(
        token.type == TOKEN_NUMBER &&
        token.value == 7,
        "Lexing second integer"
    );


    token =
        next_token(
            &lexer
        );


    assert_test(
        token.type == TOKEN_END,
        "End-of-input detection"
    );


    printf(
        "\nPassed: %d\nFailed: %d\n",
        passed,
        failed
    );


    return failed != 0;
}