#include "vm.h"
#include "value.h"

static InterpretResult run();

VM vm;

void initVM() {}

InterpretResult interpret(Chunk *chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    vm.stackTop = vm.stack;
    return run();
}

static InterpretResult run() {

    for (;;) {
        uint8_t instruction = *vm.ip++;

        switch (instruction) {

            case OP_CONSTANT: {
                Value v = vm.chunk->constants.values[*vm.ip++];
                push(v);
                break;
            }
            case OP_ADD: {
                Value right = pop();
                Value left = pop();
                push(left + right);
                break;
            }

            case OP_RETURN: {
                return INTERPRET_OK;
            }

            default:
                break;
        }
    }
}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

void freeVM() {}