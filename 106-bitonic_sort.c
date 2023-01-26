#include "sort.h"

void bitonic_sort(int *array, size_t size) {
    if(!array) return;
    int i, j, k;
    for(k = 2; k <= size; k = k*2) {
        for(j = k>>1; j > 0; j = j>>1) {
            for(i = 0; i < size; i++) {
                int ixj = i^j;
                if((ixj) > i) {
                    if((i & k) == 0 && array[i] > array[ixj]) {
                        int temp = array[i];
                        array[i] = array[ixj];
                        array[ixj] = temp;
                        printf("Swapped %d and %d\n", array[i], array[ixj]);
                    }
                    if((i & k) != 0 && array[i] < array[ixj]) {
                        int temp = array[i];
                        array[i] = array[ixj];
                        array[ixj] = temp;
                        printf("Swapped %d and %d\n", array[i], array[ixj]);
                    }
                }
            }
        }
    }
}
