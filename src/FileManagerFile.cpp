#include "FileManagerFile.hpp"


namespace fs = std::filesystem;

FileManagerFile::FileManagerFile(fs::path src) : FileManager(src) {
    //constructor
};

FileManagerFile::FileManagerFile(char *path[]) : FileManager(*path) {
    //constructor
};


int FileManagerFile::remove() {
    if(!fs::exists(this->m_path)) {
        return 1;
    }
    auto success = fs::remove(m_path);
    if (!success) {
        return 1;
    }
    return 0;
}

int FileManagerFile::copy(fs::path dst) {
    if(!fs::exists(this->m_path)) {
        return 1;
    }
    auto success = fs::copy_file(m_path, dst);
    if (!success) {
        return 1;
    }
    return 0;
}

int FileManagerFile::move(fs::path dst) {
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

int FileManagerFile::create() {
    std::ofstream outfile{m_path};
    outfile.close();
    if(!fs::exists(m_path)) {
        return 1;
    }
    return 0;
}