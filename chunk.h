
#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum OpCode {
    OP_CONSTANT,
    OP_RETURN,
    OP_ADD,
    OP_SUBTRACT,
} OpCode;

typedef struct Chunk {
    int count;
    int capacity;
    int *lines;
    uint8_t *code;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
void freeChunk(Chunk *chunk);
int addConstant(Chunk *chunk, Value value);

// void *reallocate(void *pointer, size_t newCapacity, size_t oldCapacity);
#endif