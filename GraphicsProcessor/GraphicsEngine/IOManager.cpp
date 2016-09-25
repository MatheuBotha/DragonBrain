//
// Created by matheu on 9/7/16.
//

#include "IOManager.h"

#include <fstream>
#include <SDL2/SDL.h>
//#include <experimental/filesystem>
// Namespace alias
//namespace fs = std::experimental::filesystem;

// Namespace alias
// namespace fs = std::;

namespace GraphicsEngine {

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

//    bool IOManager::getDirectoryEntries(const char* path, std::vector<DirEntry>& rvEntries) {
//        auto dpath = fs::path(path);
//        // Must be directory
//        if (!fs::is_directory(dpath)) return false;
//
//        for (auto it = fs::directory_iterator(dpath); it != fs::directory_iterator(); ++it) {
//            rvEntries.emplace_back();
//            rvEntries.back().path = it->path().string();
//            if (is_directory(it->path())) {
//                rvEntries.back().isDirectory = true;
//            } else {
//                rvEntries.back().isDirectory = false;
//            }
//        }
//        return true;
//    }
//
//    bool IOManager::makeDirectory(const char* path) {
//        return fs::create_directory(fs::path(path));
//    }
}