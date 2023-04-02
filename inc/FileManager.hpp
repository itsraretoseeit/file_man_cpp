#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <filesystem>

class FileManager {

public:
    virtual ~FileManager(){};

    virtual int create() = 0;
    virtual int copy(std::filesystem::path dst) = 0;
    virtual int move(std::filesystem::path dst) = 0;
    virtual int remove() = 0;

};

#endif