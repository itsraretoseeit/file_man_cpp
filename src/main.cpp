#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void print_summary(const fs::path path) {
   std::cout
        << "Path summary: " << std::endl
        << "root: " << path.root_name() << std::endl
        << "root dir: " << path.root_directory() << std::endl
        << "root path: " << path.root_path() << std::endl
        << "rel path: " << path.relative_path() << std::endl
        << "parent path: " << path.parent_path() << std::endl
        << "filename: " << path.filename() << std::endl
        << "stem: " << path.stem() << std::endl
        << "extension: " << path.extension() << std::endl
        << "is absolute: " << path.is_absolute() << std::endl;
}

int main(int argc, char *argv[]) {

    if(argc == 1) {
        std::cout << "No arguments provided." << std::endl;
        return 1;
    }



    auto instruction = std::string(argv[1]);
    //FILE
    if(instruction.compare("print_summary") == 0) {
        auto path = fs::path(argv[2]);
        print_summary(path);
        return 0;
    }
    
    if(instruction.compare("copy") == 0) {
        auto original_file = fs::path(argv[2]);
        if (!fs::exists(original_file)) {
            std::cout << "Original file does not exist. Nothing to copy." << std::endl;
            return 1;
        }
        auto copied_file = fs::path(argv[3]);
        auto success = fs::copy_file(original_file, copied_file);
        if (!success) {
            std::cout << "Failed to copy." << std::endl;
            return 1;
        }
        return 0;
    }

    if(instruction.compare("move") == 0) {
        auto original_path = fs::path(argv[2]);
        if(!fs::exists(original_path)) {
            std::cout << "Original file does not exist. Nothing to move/rename." << std::endl;
            return 1;
        }
        auto desired_path = fs::path(argv[3]);
        std::error_code err;
        fs::rename(original_path, desired_path, err);
        if(err) {
            std::cout << "Error in move: " << err.message() << std::endl;
            return 1;
        }
        return 0;
    }

    if(instruction.compare("delete") == 0) {
        auto original_path = fs::path(argv[2]);
        if(!fs::exists(original_path)) {
            std::cout << "File does not exist. Nothing to delete." << std::endl;
            return 1;
        }
        auto success = fs::remove(original_path);
        if (!success) {
            std::cout << "Failed to delete." << std::endl;
            return 1;
        }
        return 0;
    }

    //DIR
    if(instruction.compare("create_dir") == 0) {
        auto path = fs::path(argv[2]);
        auto success = fs::create_directory(path);
        if (!success) {
            std::cout << "Failed to create a dir." << std::endl;
            return 1;
        }
        return 0;
    }

    if(instruction.compare("delete_dir") == 0) {
        auto path = fs::path(argv[2]);
        if(!fs::exists(path)) {
            std::cout << "Path does not exist." << std::endl;
            return 1;
        }
        auto success = fs::remove(path);
        if (!success) {
            std::cout << "Failed to delete a dir." << std::endl;
            return 1;
        }
        return 0;
    }

    if(instruction.compare("move_dir") == 0) {
        auto original_path = fs::path(argv[2]);
        if(!fs::exists(original_path)) {
            std::cout << "Path does not exist." << std::endl;
            return 1;
        } 
        auto desired_path = fs::path(argv[3]);

        std::error_code err;
        fs::rename(original_path, desired_path, err);

        if (err) {
            std::cout << "Error in rename: " << err.message() << std::endl;
            return 1;
        }
        return 0;

    }    

    std::cout << "not recognized" << std::endl;
    return 0;

}