#include "stdio.h"
#include "./debug_macro.h"

void print_array(int array[], int n) {
    printf("[");

    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);

        if (i != n-1) {
            printf(", ");
        }
    }

    printf("]\n");
}

void SortBubble(int array[], int n) {
    print_array(array, n);

    int tmp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            if (array[j] < array[j - 1]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }

    print_array(array, n);
}


int main() {
    int target[] = { 10, 2, 3, 17, 37, 3, 22, 43, 32 };

    SortBubble(target, 9);

    return 0;
}
