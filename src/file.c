#include "file.h"
#include <string.h>

int create_db_file(const char *filename){
	FILE *fp = fopen(filename, "wb");
	if (!fp) return -1;

	FileHeader header;
	memcpy(header.magic, "SGBD", 4);
	header.version = 1;
	header.page_size = PAGE_SIZE_DEFAULT;

	fwrite(&header, sizeof(FileHeader), 1, fp);
	fclose(fp);

	return 0;
}


int read_db_file(const char *filename, FileHeader, *header){
	FILE *fp = fopen(filename, "rb");
	if (!fp) return -1;

	fread(header, sizeof(FileHeader), 1, fp);
	fclose(fp);

	return 0;
}


