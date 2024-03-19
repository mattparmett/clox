#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// One-byte operation code (opcode)
// Controls the type of instruction (add, subtract, lookup, etc.)
typedef enum {
  OP_RETURN, // return from the current function
} OpCode;

// Wrapper around dynamic array of bytes
typedef struct {
  int count;        // number of allocated entries in use
  int capacity;     // number of allocated entries
  uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif