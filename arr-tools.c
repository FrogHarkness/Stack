/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// 
//
// Name: 
// login ID: 
//////////////////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdlib.h>
#include "arr-tools.h"
#include "cs136-trace.h"
#include <limits.h>
// See arr-tools.h for documentation.
int minmax_dist(int arr[], int len) {
    assert(len);
    assert(len >= 1);
    int min = INT_MAX;
    int max = INT_MIN;
    int posmin = 0;
    int posmax = 0;

    for(int i = 0; i < len; ++i) {
        if(arr[i] < min) {
            min = arr[i];
            posmin = i;
        }if (arr[i] > max) {
            max = arr[i];
            posmax = i;
        }
    }
    int diff = posmax - posmin;

    return abs(diff) ;
}

// See arr-tools.h for documentation.

int most_occurrences(int arr[], int len) {
    int max_count = 0;
    int max_idxpos = 0;
    
  
    for (int i = 0; i < len; ++i) {
        int count = 1;
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_idxpos = i;
        }
    }
    return arr[max_idxpos];
}


// See arr-tools.h for documentation.
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], size 2
//               ^                       ->   (2)/1 = 2
//               ^  ^                    -> (2+4)/2 = 3
//                  ^  ^                 -> (4+4)/2 = 4
//                     ^  ^              -> (4+2)/2 = 3
//                        ^  ^           -> (2+6)/2 = 4
//                           ^ ^         -> (6+2)/2 = 4
//                              ^  ^     -> (2+3)/2 = 2(.500)
//                                 ^  ^  -> (3+4)/2 = 4
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], size 4
//               ^                       ->       (2)/1 = 2
//               ^  ^                    ->     (2+4)/2 = 3
//               ^  ^  ^                 ->   (2+4+4)/3 = 3(.333)
//               ^  ^  ^  ^              -> (2+4+4+2)/4 = 3
//                  ^  ^  ^  ^           -> (4+4+2+6)/4 = 4
//                     ^  ^  ^ ^         -> (4+2+6+2)/4 = 3(.500)
//                        ^  ^  ^  ^     -> (2+6+2+3)/4 = 3(.250)
//                           ^  ^  ^  ^  -> (6+2+3+5)/4 = 4
void moving_average(int arr[], int len, int size) {
    int cum_sum[100]; 
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += arr[i];
        cum_sum[i] = sum;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (i >= size) {
            arr[i] = (cum_sum[i] - cum_sum[i - size]) / size;
        } else {
            arr[i] = cum_sum[i] / (i + 1);
        }
    }
}
