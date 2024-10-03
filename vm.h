#include "chunk.h"
#include "common.h"
#include "value.h"

#define STACKSIZE 256

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

typedef struct VM{
    Chunk* chunk;
    uint8_t *ip;
    Value stack[STACKSIZE];
    Value *stackTop;

}VM;

void initVM();
InterpretResult interpret(Chunk *chunk);
void push(Value value);
Value pop();
void freeVM();