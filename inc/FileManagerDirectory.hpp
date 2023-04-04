#ifndef FILEMANAGERDIRECTORY_H
#define FILEMANAGERDIRECTORY_H

#include "FileManager.hpp"

class FileManagerDirectory : public FileManager {

    public:
        FileManagerDirectory(std::filesystem::path path);
        FileManagerDirectory(char *path[]);
        ~FileManagerDirectory(){};

        int create() override;
        int remove() override;
        int move(std::filesystem::path dst) override;
        int copy(std::filesystem::path dst) override;

    private:
        std::filesystem::path m_path;
};

#endif