//
// Created by matheu on 9/7/16.
//

#include "IOManager.h"

#include <fstream>
#include <SDL2/SDL.h>

bool IOManager::readFileToBuffer(const char* filePath, char* buffer) {
    SDL_RWops *rw = SDL_RWFromFile(filePath, "rb");
    if (rw == NULL) return NULL;

    Sint64 res_size = SDL_RWsize(rw);
    char* res = (char*)malloc(res_size + 1);

    Sint64 nb_read_total = 0, nb_read = 1;
    char* buf = res;
    while (nb_read_total < res_size && nb_read != 0) {
        nb_read = SDL_RWread(rw, buf, 1, (res_size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }
    SDL_RWclose(rw);
    if (nb_read_total != res_size) {
        free(res);
        return NULL;
    }

    res[nb_read_total] = '\0';

    buffer = res;

    return true;
}

bool IOManager::readFileToBuffer(std::string filePath, std::string& buffer) {
    std::ifstream file(filePath, std::ios::binary);
    if (file.fail()) {
        perror(filePath.c_str());
        return false;
    }

    //seek to the end
    file.seekg(0, std::ios::end);

    //Get the file size
    unsigned int fileSize = (unsigned int)file.tellg();
    file.seekg(0, std::ios::beg);

    //Reduce the file size by any header bytes that might be present
    fileSize -= (unsigned int)file.tellg();

    buffer.resize(fileSize);
    file.read((char *)&(buffer[0]), fileSize);
    file.close();

    return true;
}
