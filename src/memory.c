#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  // Stdlib function handles all non-free cases
  // When oldSize is 0, equivalent to calling malloc
  void* result = realloc(pointer, newSize);
  if (result == NULL) exit(1);
  return result;
}
