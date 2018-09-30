#include <stdio.h>

#define SIZE 5

int main() {
    // set array
    int ar1[SIZE];
    char ar2[SIZE];
    int i;
    int* p1 = NULL;
    char* p2 = NULL;
    // set value
    for (i = 0; i < SIZE; i++) {
        ar1[i] = i;
        ar2[i] = 'A' + i;
    }
    // set address to pointer
    p1 = &ar1[0];
    p2 = &ar2[0];
    // print value
    for (i = 0; i < SIZE; i++) {
        printf("ar1[%d]=%d *(p1+%d)=%d ", i, ar1[i], i, *(p1 + i));
        printf("ar2[%d]=%d *(p2+%d)=%d\n", i, ar2[i], i, *(p2 + i));
    }
}
