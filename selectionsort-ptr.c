/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// ERROR_NO_INTEGRITY_STATEMENT
//
// Name: Yiz
// login ID: y3shao
//////////////////////////////////////////////////////////////////////////////////////////

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
