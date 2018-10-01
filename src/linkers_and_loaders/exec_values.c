#include <stdio.h>

extern char c0, c1;
extern char *cp0, *cp1;
extern char str[];
extern int i0, i1;
extern const int ci0, ci1;

int main() {
    printf("c0 = %c, c1 = %c\n", c0, c1);
    printf("cp0 = %s, cp1 = %s, str = %s\n", c0, c1, str);
    printf("i0 = %d, i1 = %d", i0, i1);
    printf("ci0 = %d, ci1 = %d", ci0, ci1);

    printf("&c0 = 0x%08x, &c1 = 0x%08x\n", &c0, &c1);
    printf("&cp0 = 0x%08x, &cp1 = 0x%08x, &str = 0x%08x\n", &c0, &c1, &str);
    printf("&i0 = 0x%08x, &i1 = 0x%08x", &i0, &i1);
    printf("&ci0 = 0x%08x, &ci1 = 0x%08x", &ci0, &ci1);

    exit(0);
}
