#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// One-byte operation code (opcode)
// Controls the type of instruction (add, subtract, lookup, etc.)
typedef enum {
  OP_CONSTANT, // loads constant for use
  OP_RETURN, // return from the current function
} OpCode;

// Wrapper around dynamic array of bytes
typedef struct {
  int count;        // number of allocated entries in use
  int capacity;     // number of allocated entries
  uint8_t* code;
  ValueArray constants; // literals stored as array
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);
int addConstant(Chunk* chunk, Value value);

#endif
