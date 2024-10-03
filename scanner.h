#include "common.h"

typedef enum TokenType {
    // Keywords
    CLASS,
    FUN,
    CONST,
    LET,
    VAR,
    FOR,
    IF,
    ELSE,
    WHILE,
    PRINT,
    RETURN,
    NEW,
    DOT,
    THIS,

    // Literals
    IDENTIFIER,
    STRING,
    NUMBER,
    FLOAT,
    NIL,

    // Operators and Punctuation
    PLUS,
    PLUS_PLUS,
    MINUS,
    DIVIDE,
    ASTERISK,
    SLASH,
    EQUAL,
    EQUAL_EQUAL,
    BANG_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESSER,
    LESSER_EQUAL,
    BANG,
    BITWISE_AND,
    BITWISE_OR,
    LOGICAL_OR,
    LOGICAL_AND,
    SEMICOLON,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,

    // Booleans
    TRUE,
    FALSE,

    // Miscellaneous
    END_OF_FILE,
    TOKEN_ERROR
} TokenType;

typedef struct Token {
    TokenType type;
    const char *start;
    int line;
    int length;
} Token;

typedef struct TokenArray {
    int count;
    int capacity;
    Token **tokens;
} TokenArray;

void lexer(char *source);
Token scanToken();