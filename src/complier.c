#include "compiler.h"

#include <ctype.h>
#include <stdio.h>


void initialise_lexer(
    Lexer *lexer,
    const char *source
)
{
    if (lexer == NULL)
    {
        return;
    }


    lexer->source = source;

    lexer->position = 0;
}


Token next_token(
    Lexer *lexer
)
{
    Token token;


    token.type =
        TOKEN_INVALID;

    token.value = 0;


    if (
        lexer == NULL ||
        lexer->source == NULL
    )
    {
        return token;
    }


    while (
        isspace(
            (unsigned char)
            lexer->source[
                lexer->position
            ]
        )
    )
    {
        lexer->position++;
    }


    char current =
        lexer->source[
            lexer->position
        ];


    if (current == '\0')
    {
        token.type =
            TOKEN_END;

        return token;
    }


    if (isdigit(
        (unsigned char)current
    ))
    {
        int value = 0;


        while (
            isdigit(
                (unsigned char)
                lexer->source[
                    lexer->position
                ]
            )
        )
        {
            value =
                value * 10 +
                (
                    lexer->source[
                        lexer->position
                    ] - '0'
                );


            lexer->position++;
        }


        token.type =
            TOKEN_NUMBER;

        token.value =
            value;


        return token;
    }


    lexer->position++;


    switch (current)
    {
        case '+':
            token.type =
                TOKEN_PLUS;
            break;

        case '-':
            token.type =
                TOKEN_MINUS;
            break;

        case '*':
            token.type =
                TOKEN_MULTIPLY;
            break;

        case '/':
            token.type =
                TOKEN_DIVIDE;
            break;

        default:
            token.type =
                TOKEN_INVALID;
    }


    return token;
}


void print_token(
    Token token
)
{
    switch (token.type)
    {
        case TOKEN_NUMBER:
            printf(
                "NUMBER(%d)\n",
                token.value
            );
            break;

        case TOKEN_PLUS:
            printf("PLUS\n");
            break;

        case TOKEN_MINUS:
            printf("MINUS\n");
            break;

        case TOKEN_MULTIPLY:
            printf("MULTIPLY\n");
            break;

        case TOKEN_DIVIDE:
            printf("DIVIDE\n");
            break;

        case TOKEN_END:
            printf("END\n");
            break;

        default:
            printf("INVALID\n");
    }
}