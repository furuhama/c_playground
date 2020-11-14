// testing c language with c++ compiler
#include <stdio.h>

int main() {
    // sample array program
    int a[] = { 1, 2, 3, 4, 5 };
    int i;
    for (i = 0; i < 5; i++) {
        printf("n[%d] = %d\n", i, a[i]);
    }

    // sample char program
    char s1[4] = { 'a', 'b', 'c', '\0' };
    char s2[] = "Hello, world";
    // char s3[10];
    // printf("please input literals\n");
    // scanf("%s", s3);
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    // printf("s3 = %s\n", s3);

    // sample multi dimension program
    int ma[2][4];
    int m, n;
    // set value
    for (m = 0; m < 2; m++) {
        for (n = 0; n < 4; n++) {
            ma[m][n] = m + n + m * m * n * n;
        }
    }
    // print value
    for (m = 0; m < 2; m++) {
        for (n = 0; n < 4; n++) {
            printf("a[%d][%d] = %d\n", m, n, ma[m][n]);
        }
    }
    return 0;
}
