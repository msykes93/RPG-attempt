#include <iostream>
#include <cstdio>

#include "rgp.hpp"

int main(int argc, char *argv[]) {
    if(argc > 1) {
        std::pair<unsigned char*, int> data = readBMP(std::string(argv[1]));
        for(int i = 0; i < data.second; i += 3) {
            if(data.first[i]) {
                printf("X");
            } else {
                printf(" ");
            }
            if(i % 10 == 0) {
                printf("\n");
            }
        }
    }
    return 0;
}
