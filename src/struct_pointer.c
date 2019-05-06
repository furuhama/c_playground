#include <stdio.h>

typedef struct {
    int id;
    int num;
    char status[64];
    /* double point; */
} Hoge;

int main() {
    Hoge hoges[100];

    printf("%d", sizeof(hoges));

    return 0;
}
