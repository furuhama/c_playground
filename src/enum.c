#include "./debug_macro.h"

enum {
    E_0,
    E_1,
    E_5 = 5,
    E_6,
    E_7,
    E_9 = 9,
};

int main() {
    DEBUG(d, E_0);
    DEBUG(d, E_1);
    DEBUG(d, E_5);
    DEBUG(d, E_6);
    DEBUG(d, E_7);
    DEBUG(d, E_9);

    return 0;
}
