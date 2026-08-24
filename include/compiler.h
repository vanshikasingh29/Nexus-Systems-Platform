#ifndef NEXUS_COMPILER_H
#define NEXUS_COMPILER_H

typedef enum
{
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_END,
    TOKEN_INVALID

} TokenType;


typedef struct
{
    TokenType type;

    int value;

} Token;


typedef struct
{
    const char *source;

    int position;

} Lexer;


void initialise_lexer(
    Lexer *lexer,
    const char *source
);


Token next_token(
    Lexer *lexer
);


void print_token(
    Token token
);

#endif