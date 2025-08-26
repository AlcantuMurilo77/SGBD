#ifndef FILE_H
#define FILE_H


#include <stdint.h>
#include <stdio.h>

#define PAGE_SIZE_DEFAULT 4096
#define HEADER_SIZE 16

typedef struct {
	char magic[4];
	uint8_t version;
	uint32_t page_size;
} FileHeader;


int create_db_file(const char *filename);
int read_db_header(const char *filename, FileHeader *header);

#endif
