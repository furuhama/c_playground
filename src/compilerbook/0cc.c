#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    TK_NUM = 256, // Integer token
    TK_EOF, // End of File token
};

typedef struct {
    int type; // type of token
    int value; // value of TK_NUM type token
    char *input; // string of token to display error messages
} Token;

// Take an array for tokens (max: 100)
Token tokens[100];

void tokenize(char *p) {
    int i = 0;
    while (*p) {
        if (isspace(*p)) {
            p++;
            continue;
        }

        if (*p == '+' || *p == '-') {
            tokens[i].type = *p;
            tokens[i].input = p;
            i++;
            p++;
            continue;
        }

        if (isdigit(*p)) {
            tokens[i].type = TK_NUM;
            tokens[i].input = p;
            tokens[i].value = strtol(p, &p, 10);
            i++;
            continue;
        }

        fprintf(stderr, "Can't tokenize: %s\n", p);
        exit(1);
    }

    tokens[i].type = TK_EOF;
    tokens[i].input = p;
}

void error(int i) {
    fprintf(stderr, "Unexpected token: %s\n", tokens[i].input);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments.\n");
        return 1;
    }

    tokenize(argv[1]);

    printf(".intel_syntax noprefix\n");
    printf(".global _main\n");
    printf("_main:\n");

    // First token of expression should be TK_NUM
    if (tokens[0].type != TK_NUM) {
        error(0);
    }

    // `strtol` returns `long` type value and get it by `%ld`
    printf("    mov rax, %d\n", tokens[0].value);

    // take `+ <TK_NUM>` or `- <TK_NUM>` and generate assembly
    int i = 1;
    while (tokens[i].type != TK_EOF) {
        if (tokens[i].type == '+') {
            i++;
            if (tokens[i].type != TK_NUM) {
                error(i);
            }
            printf("    add rax, %d\n", tokens[i].value);
            i++;
            continue;
        }

        if (tokens[i].type == '-') {
            i++;
            if (tokens[i].type != TK_NUM) {
                error(i);
            }
            printf("    sub rax, %d\n", tokens[i].value);
            i++;
            continue;
        }

        error(i);
    }

    printf("    ret\n");
    return 0;
}
