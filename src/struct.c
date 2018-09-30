#include "./debug_macro.h"

struct hoge {
    int age;
    int number;
    char status[64];
    double point;
};

// using typedef and define struct at the same time
typedef struct fuga_struct {
    int age;
    int number;
    char status[64];
    char name[64];
    double point;
} piyo;

int main() {
    struct hoge data;

    data.age = 10;
    DEBUG(d, data.age);

    strcpy(data.status, "ほげげ");
    DEBUG(s, data.status);

    piyo piyo_instance;

    piyo_instance.number = 1000;
    DEBUG(d, piyo_instance.number);

    return 0;
}
