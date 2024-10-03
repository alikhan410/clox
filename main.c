#include "chunk.c"
#include "debug.c"
#include "scanner.c"
#include "vm.c"

char *runFile(char *filename);

int main(int argc, char **argv) {
    // char *source = runFile(argv[1]);
    // lexer(source);
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    writeChunk(&chunk, OP_CONSTANT, 1);
    int constant1 = addConstant(&chunk, 5);
    writeChunk(&chunk, constant1, 1);

    writeChunk(&chunk, OP_CONSTANT, 1);
    int constant2 = addConstant(&chunk, 5);
    writeChunk(&chunk, constant2, 1);

    writeChunk(&chunk, OP_ADD, 1);

    disassembleChunk(&chunk, "test run");
    interpret(&chunk);

    freeChunk(&chunk);
    freeVM();

    // TokenArray *tokenArray = scanner(source);
    // for (size_t i = 0; i < tokenArray->count; i++) {
    //     printf("%s ", tokenTypeToString(tokenArray->tokens[i]->type));
    //     printf("%s ", tokenArray->tokens[i]->lexeme);
    //     printf("%d\n", tokenArray->tokens[i]->line);
    // }

    return 0;
}

char *runFile(char *fileName) {
    FILE *f = fopen(fileName, "r");
    if (f == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    rewind(f);

    char *buffer = malloc(fileSize + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(f);
        return NULL;
    }

    size_t bytesRead = fread(buffer, 1, fileSize, f);
    buffer[bytesRead] = '\0';

    fclose(f);
    return buffer;
}

// if (argc == 1) {
//     printf("[Error]: Expecting a file\n");
//     return 1;
// } else if (argc == 2) {

//     printf("Executing file: %s\n", argv[1]); // Print the file name being executed

//     scanner(runFile(argv[1]));

// } else {
//     for (int i = 0; i < argc; i++) {
//         printf("Argument %d: %s\n", i, argv[i]);
//     }
// }