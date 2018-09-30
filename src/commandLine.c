#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        printf("Usage: ./commandline_test [some words]\n");
        return 1;
    } else {
        for (int i = 1; i < argc; i++) {
            printf("%d: %s\n", i, argv[i]);
        }
        return 0;
    }
}
