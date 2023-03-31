#ifndef FILEMANAGERFILE_H
#define FILEMANAGERFILE_H

#include <FileManager.h>
#include <filesystem>
#include <string>

class FileManagerFile : public FileManager {
    public:
        FileManagerFile(std::filesystem::path path);
        FileManagerFile(char *path[]);
        ~FileManagerFile(){};

        int create() override;
        int remove() override;
        int move(std::filesystem::path dst) override;
        int copy(std::filesystem::path dst) override;


    private:
        std::filesystem::path m_path;
};


#endif