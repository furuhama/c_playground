#include "dev.h"

void error(const char *message) {
    perror(message);
    exit(1);
}
