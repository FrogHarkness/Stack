/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//
// Name: YizhongShao
// login ID: y3shao
//////////////////////////////////////////////////////////////////////////////////////////

#include "shelf.h"
#include "box.h"
#include "cs136-trace.h"
#include <stdio.h>


// maximum number of boxes that can be stored on the shelf
static const int SHELF_CAPACITY = 10;

// See box.h for documentation.
struct shelf shelf_init(void) {
    struct shelf a; 
    for (int i = 0; i < SHELF_CAPACITY; ++i) {
        a.pboxes[i] = NULL;
    }
    a.count = 0;
    return a;
};
 

// See box.h for documentation.
// This function fails if the shelf capacity has been exceeded.
bool shelf_push(struct shelf *sh, char id, int volume, int weight) {
    assert(sh);
    assert((65 <= id && 90 >= id )|| (97 <= id && id <= 122));
    assert(volume > 0);
    assert(weight > 0);
    if (sh->count > SHELF_CAPACITY) {
        return false;
    }else{
        sh->boxes[sh->count] = box_init(id, volume, weight);
        sh->pboxes[sh->count] = &sh->boxes[sh->count];
        sh->count++;
        return true;
    }
}

// See box.h for documentation.
// This function fails if the shelf is empty.


bool shelf_pop(struct shelf *sh, struct box *popped) {
    assert(sh);
    assert(popped);
    if (sh->count == 0) {
        return false;
    }else{
    *popped = sh->boxes[sh->count - 1];
    for (int i = 0; i < sh->count; i++) {
        if (sh->pboxes[i] == &sh->boxes[sh->count - 1]) {
            for (int j = i; j < sh->count - 1; j++) {
                sh->pboxes[j] = sh->pboxes[j + 1];
            }
            sh->pboxes[sh->count - 1] = NULL;
            break;
        }
    }
    sh->count--;
    return true;
    }
}
// See box.h for documentation.
// This function fails if the shelf is empty.
bool shelf_top(const struct shelf *sh, const struct box **top) {
    if (sh->count == 0) {
        return false;
    }else{
    *top = &(sh->boxes[sh->count - 1]);
    return true;
    }
}
// See box.h for documentation.
void shelf_sort(struct shelf *sh, int(comp)(const struct box *, const struct box *)) {
    for(int i = 0; i < (sh->count - 1); ++i) {
        for(int j=0; j < (sh->count-i - 1); ++j) {
            if(comp(sh->pboxes[j], sh->pboxes[j + 1]) > 0) {
                struct box* temp = sh->pboxes[j];
                sh->pboxes[j] = sh->pboxes[j+1];
                sh->pboxes[j + 1] = temp;
            }
        }
    }
}

// See box.h for documentation.
void shelf_print(const struct shelf *sh) {
    assert(sh);
    printf("=== SHELF (actual) =========\n");
    for (int i = 0; i < sh->count; ++i) {
        box_print(&(sh->boxes[i]));
    }
    printf("============================\n");
}

// See box.h for documentation.
void shelf_print_refs(const struct shelf *sh) {
    assert(sh);
    printf("=== SHELF (references) =====\n");
    for (int i = 0; i < sh->count; ++i) {
        box_print(sh->pboxes[i]);
    }
    printf("============================\n");
}