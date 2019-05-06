#include<stdio.h>

struct s {
    char a;
    int b;
};

struct t {
    char a;
};

struct u {
    char a;
    long b;
};

int main(int argc, char const* argv[])
{
    printf("sizeof s: %ld\n", sizeof(struct s));
    printf("sizeof t: %ld\n", sizeof(struct t));
    printf("sizeof t: %ld\n", sizeof(struct u));
    long l;
    printf("sizeof long: %ld\n", sizeof(l));
    return 0;
}
