#include "FileManagerDirectory.hpp"


namespace fs = std::filesystem;

FileManagerDirectory::FileManagerDirectory(fs::path src) : FileManager(src) {
    //constructor
};

FileManagerDirectory::FileManagerDirectory(char *path[]) : FileManager(*path) {
    //constructor
};


int FileManagerDirectory::remove() {
    if(!fs::exists(this->m_path)) {
        return 1;
    }
    auto success = fs::remove(m_path);
    if (!success) {
        return 1;
    }
    return 0;
}

int FileManagerDirectory::copy(fs::path dst) {
    if(!fs::exists(this->m_path)) {
        return 1;
    }
    auto success = fs::copy_file(m_path, dst);
    if (!success) {
        return 1;
    }
    return 0;
}

int FileManagerDirectory::move(fs::path dst) {
    if(!fs::exists(this->m_path)) {
        return 1;
    }
    std::error_code err;
    fs::rename(m_path, dst, err);
    if (err) {
        return 1;
    }
    return 0;
}

int FileManagerDirectory::create() {
    if(fs::exists(this->m_path)) {
        return 1;
    }
    auto success = fs::create_directory(this->m_path);
    if(!success) {
        return 1;
    }
    return 0;
}