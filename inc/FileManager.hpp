#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <filesystem>
#include <sstream>

class FileManager {

public:
    FileManager(std::filesystem::path path) : m_path(path) {};
    virtual ~FileManager(){};

    virtual int create() = 0;
    virtual int copy(std::filesystem::path dst) = 0;
    virtual int move(std::filesystem::path dst) = 0;
    virtual int remove() = 0;

    virtual std::string summary() {
        std::stringstream ss;
        ss  << "Path summary: " << "\n"
            << "root: " << m_path.root_name() << "\n"
            << "root dir: " << m_path.root_directory() << "\n"
            << "root path: " << m_path.root_path() << "\n"
            << "rel path: " << m_path.relative_path() << "\n"
            << "parent path: " << m_path.parent_path() << "\n"
            << "filename: " << m_path.filename() << "\n"
            << "stem: " << m_path.stem() << "\n"
            << "extension: " << m_path.extension() << "\n"
            << "is absolute: " << m_path.is_absolute() << "\n";
        return ss.str();
    }

private:
    std::filesystem::path m_path;
};

#endif