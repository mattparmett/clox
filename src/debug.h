#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

/*
 * Disassembles all the instructions in an entire chunk.
 */
void disassembleChunk(Chunk* chunk, const char* name);

/*
 * Disassembles a single instruction within the given chunk.
 * Returns the offset of the next instruction, after the current
 * instruction is disassembled.
 */
int disassembleInstruction(Chunk* chunk, int offset);

#endif
