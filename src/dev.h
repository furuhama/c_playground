#ifndef	_DEV_H
#define	_DEV_H

#include <stdio.h>
#include <stdlib.h>

void err_sys(const char *arg) {
    perror(arg);
    exit(1);
}

#endif
