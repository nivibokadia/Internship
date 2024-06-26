#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"
#include "value.h"

typedef enum{       //defining opcodes
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_SET_GLOBAL,
    OP_GET_GLOBAL,
    OP_GET_UPVALUE,
    OP_SET_UPVALUE,
    OP_DEFINE_GLOBAL,
    OP_GET_PROPERTY,
    OP_SET_PROPERTY,
    OP_GET_SUPER,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_NEGATE,
    OP_PRINT,
    OP_JUMP,
    OP_JUMP_IF_FALSE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_LOOP,
    OP_CALL,
    OP_INVOKE,
    OP_SUPER_INVOKE,
    OP_CLOSURE,
    OP_CLOSE_UPVALUE,
    OP_RETURN,
    OP_CLASS,
    OP_INHERIT,
    OP_METHOD,
}OpCode;

typedef struct{             //chunk data structure to hold bytecode
    int count;              //no. of bytecode instructions currently in the chunk
    int capacity;           //allocated capacity of the bytecode array
    uint8_t* code;          //pointer to the array of bytecode instructions
    int* lines;             //array to store line numbers for debugging
    ValueArray constants;   //array to store constants
}Chunk;

void initChunk(Chunk* chunk);                               //initialize chunk
void freeChunk(Chunk* chunk);                               //free chunk after using
void writeChunk(Chunk* chunk, uint8_t byte, int line);      //add a chunk
int addConstant(Chunk* chunk, Value value);                 //add const
//void writeValueArray(Chunk* chunk, Value value);

#endif