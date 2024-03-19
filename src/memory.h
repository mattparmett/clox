#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

// Use min capacity of 8 to minimize number of grows
// for small arrays
#define GROW_CAPACITY(capacity) \
  ((capacity) < 8? 8 : (capacity) * 2)

/*
 * Wraps call to reallocate().
 * Gets the size of the array's element type
 * and casts the resulting void pointer back
 * to a pointer of the right type.
 */
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)reallocate(pointer, sizeof(type) * (oldCount), \
      sizeof(type) * (newCount))

/*
 * Wraps call to reallocate().
 * Frees memory by passing in 0 for newSize.
 */
#define FREE_ARRAY(type, pointer, oldCount) \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

/*
 * Used for all dynamic memory management in clox
 * (allocs, freeing, and changing size of existing alloc).
 *
 * Routing all these operations through a single function
 * is important for GC to keep track of how much memory is in use.
 *
 * The two size arguments control which operation to perform:
 *    - oldSize = 0, newSize nonzero: allocate a new block
 *    - oldSize nonzero, newSize = 0: free an allocation
 *    - oldSize nonzero, newSize < oldSize: shrink existing allocation
 *    - oldSize nonZero, newSize > oldSize: grow existing allocation
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif
