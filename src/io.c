#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>

char* get_file_conetents(const char* filepath) {

    char* buffer = 0;
    long length;

    FILE* fp = fopen(filepath, "rb");

    if(fp) {

        fseek(fp, 0, SEEK_END);
        length = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        buffer = calloc(length, length);

        if(buffer) {

            fread(buffer, 1, length, fp);

        }

        fclose(fp);
        return buffer;
    }

    printf("Error reading file %s\n", filepath);
    exit(2);

}