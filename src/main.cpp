#include <iostream>
#include <filesystem>
#include "FileManagerFile.hpp"
#include "FileManagerDirectory.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {

    if(argc == 1) {
        std::cout << "No arguments provided." << std::endl;
        return 1;
    }

    auto instruction = std::string(argv[1]);
    //FILE
    if(instruction.compare("print_summary") == 0) {
        FileManagerFile fmf{argv[2]};
        std::cout << fmf.summary().str();
        return 0;
    }
    
    if(instruction.compare("copy") == 0) {
        FileManagerFile fmf{argv[2]};
        return fmf.copy(argv[3]);
    }

    if(instruction.compare("move") == 0) {
        FileManagerFile fmf{argv[2]};
        return fmf.move(argv[3]);
    }

    if(instruction.compare("delete") == 0) {
        FileManagerFile fmf{argv[2]};
        return fmf.remove();
    }

    //DIR
    if(instruction.compare("create_dir") == 0) {
        FileManagerDirectory fmd{argv[2]};
        return fmd.create();
    }

    if(instruction.compare("delete_dir") == 0) {
        FileManagerDirectory fmd{argv[2]};
        return fmd.remove();
    }

    if(instruction.compare("move_dir") == 0) {
        FileManagerDirectory fmd{argv[2]};
        return fmd.move(argv[3]);
    }    

    std::cout << "not recognized" << std::endl;
    return 0;

}