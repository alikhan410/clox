#include "value.h"
#include "memory.h"

void initValueArray(ValueArray *array) {
    array->capacity = 0;
    array->count = 0;
    array->values = NULL;
};

void writeValueArray(ValueArray *array, Value value) {
    if (array->count >= array->capacity) {
        int oldSize = array->capacity;
        array->capacity = GROW_CAPACITY(array->capacity);
        array->values = GROW_ARRAY(Value, array->values, oldSize, array->capacity);
    }
    array->values[array->count++] = value;
};

void freeValueArray(ValueArray *array) {
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
};

void printValue(Value value) {
    printf("%g", value);
}