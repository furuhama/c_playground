#include <stdio.h>
#include <string.h>

void my_strrev(char *str) {
    int len = strlen(str);
    printf("%d\n", len);
    char *ptr = str + len; // pointer to tail of string
    printf("%p\n", str);
    printf("%p\n", ptr);

    for (int i = 0; i < len / 2; ++i) {
        char t = *--ptr;
        *ptr = *str;
        *str++ = t;
    }
}

int main() {
    char str[] = "hoge sample";

    printf("%s\n", str);
    my_strrev(str);
    printf("%s\n", str);

    return 0;
}
