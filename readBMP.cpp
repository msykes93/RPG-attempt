#include <iostream>
#include <cstdio>
#include "rgp.hpp"

std::pair<unsigned char*, int> readBMP(std::string filename) {
    unsigned char buffer[4];
    FILE *source = nullptr;
    source = fopen(filename.c_str(), "rb");
    fread(buffer, 1, 2, source);
    if(buffer[0] != 'B' || buffer[1] != 'M') {
        throw std::runtime_error("not a bitmap file");
    }
    fread(buffer, 1, 4, source);
    int filesize = *(int*)buffer;
    fseek(source, 4, SEEK_CUR);
    fread(buffer, 1, 4, source);
    int offset = *(int*)buffer;
    fseek(source, offset, SEEK_CUR);
    int datasize = filesize - ftell(source);
    unsigned char *data = (unsigned char*)malloc(datasize);
    fread(data, 1, datasize, source);
    int current = ftell(source);
    if(current != filesize) {
        printf("didn't read whole file\n");
        printf("read to %d of %d\n", current, filesize);
    }
    fclose(source);
    return std::make_pair(data, datasize);
}
