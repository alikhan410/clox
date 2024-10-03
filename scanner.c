#include "scanner.h"
const char *tokenTypeToString(TokenType type) {
    const char *names[] = {
        "CLASS", "FUN", "CONST", "LET", "VAR", "FOR",
        "IF", "ELSE", "WHILE", "PRINT", "RETURN", "NEW",
        "DOT", "THIS", "IDENTIFIER", "STRING", "NUMBER",
        "FLOAT", "NIL", "PLUS", "PLUS_PLUS", "MINUS", "DIVIDE",
        "ASTERISK", "SLASH", "EQUAL", "EQUAL_EQUAL",
        "BANG_EQUAL", "GREATER", "GREATER_EQUAL",
        "LESSER", "LESSER_EQUAL", "BANG", "BITWISE_AND",
        "BITWISE_OR", "LOGICAL_OR", "LOGICAL_AND",
        "SEMICOLON", "LEFT_PAREN", "RIGHT_PAREN",
        "LEFT_BRACE", "RIGHT_BRACE", "COMMA",
        "TRUE", "FALSE", "EOF"};
    return names[type];
}
static Token makeToken(TokenType type);
static char peek();
static char advance();
// static bool match(char c);
static bool isAtEnd();
static Token errorToken(const char *message);

typedef struct Scanner {
    const char *start;
    const char *current;
    int line;
} Scanner;

Scanner scanner;

void initScanner(char *source) {
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}

void lexer(char *source) {
    initScanner(source);

    while (1) {

        if (!isAtEnd()) {
            Token token = scanToken();
            printf("%s: {\"start\": \"%.*s\", \"line\": %d, \"length\": %d}\n", tokenTypeToString(token.type),
                   token.length, token.start, token.line, token.length);
        } else
            break;
    }
    makeToken(END_OF_FILE);
}

static char advance() {
    return *scanner.current++;
}
static bool isAtEnd() {
    return peek() == '\0' ? true : false;
}
static char peek() {
    return *scanner.current;
}

// static bool match(char c) {

//     if (c == peek()) {
//         return true;
//     } else {
//         return false;
//     }
// }

Token scanToken() {
    scanner.start = scanner.current;
    char c = advance();
    switch (c) {
        case ',': return makeToken(COMMA);
        case '-': return makeToken(MINUS);
        case '+': return makeToken(PLUS);
        case '=': return makeToken(EQUAL);
        case '*': return makeToken(ASTERISK);
        case '(': return makeToken(LEFT_PAREN);
        case ')': return makeToken(RIGHT_PAREN);
        case '{': return makeToken(LEFT_BRACE);
        case '}': return makeToken(RIGHT_BRACE);
        // cases for ++, --, ==, &&, ||, /
        case '\n':
            scanner.line++;
            return;
        case ' ':
        case '\t':
        case '\r':
            break;
        // cases for digits and strings
        default:
            printf("Unknown keyword\n");
            return;
    }

    return errorToken("Unexpected character.");
}

static Token errorToken(const char *message) {
    Token token;
    token.type = TOKEN_ERROR;
    token.start = message;
    token.length = (int)strlen(message);
    token.line = scanner.line;
    return token;
}
static Token makeToken(TokenType type) {
    Token token;
    token.type = type;
    token.start = scanner.start;
    token.length = (int)(scanner.current - scanner.start);
    token.line = scanner.line;
    return token;
}