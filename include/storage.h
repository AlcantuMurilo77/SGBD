#ifndef STORAGE_H
#define STORAGE_H

#include "types.h"
#include <stdio.h>

typedef struct {
    FILE *fp;
} Storage;


Status storage_open(Storage *st, const char *filename);


Status storage_close(Storage *st);
#endif