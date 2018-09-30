#include <stdio.h>
#include "./debug_macro.h"

void func(int *pvalue);  // prototype definition
int getaverage(int data[10]);
// this also works like notations below
// int getaverage(int data[]);
// int getaverage(int *data);

int main() {
    int *p;
    int i;
    p = &i;
    *p = 10;

    DEBUG(p, p);
    DEBUG(p, &i);
    DEBUG(d, i);

    // use pointer in function

    int value = 5;

    DEBUG(p, &value);
    DEBUG(d, value);
    func(&value);
    DEBUG(d, value);

    // array pointer

    int average, array[10] = { 14, 2, 34, 458, 4, 24, 5435, 43, 99, 100 };
    average = getaverage(array);
    DEBUG(d, average);

    return 0;
}

void func(int *pvalue) {
    DEBUG(p, pvalue);
    *pvalue = 100;
    return;
}

int getaverage(int data[10]) {
    int i, average = 0;
    for (i = 0; i < 10; i++) {
        average += data[i];
    }
    return average / 10;
}
