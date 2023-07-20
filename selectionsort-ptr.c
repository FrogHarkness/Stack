
#include "selectionsort-ptr.h"
#include "cs136-trace.h"
#include <assert.h>

// See selectionsort-ptr.h for documentation
// See selectionsort-ptr.h for documentation
void array_sort_ptr(int *start, int *end) {
  assert(start <= end);

  for(int *i = start; i < end; ++i) {
    int *smallest_ptr = i; 
    for(int *j = i; j <= end; ++j) {
      if (*j < *smallest_ptr) {
        smallest_ptr = j;
      }
    }
    int tmp = *i;
    *i = *smallest_ptr;
    *smallest_ptr = tmp;
  }
}
