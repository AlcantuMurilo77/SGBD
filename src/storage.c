#include "storage.h"
#include <stdlib.h>

Status storage_open(Storage *st, const char *filename){

    st->fp = fopen(filename, "rb+");

    if (!st->fp) {
        st->fp = fopen(filename, "wb+");
        if (!st->fp){
            return STATUS_ERR_IO;
        }
    }

    return STATUS_OK;
}

Status storage_close(Storage *st){
    if (st->fp) {
        fclose(st->fp);
        st->fp = NULL;
    }
    return STATUS_OK;
}