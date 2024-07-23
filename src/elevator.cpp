#include <iostream>
#include "./elevator.hpp"
#include <fstream>
#include <sys/wait.h>

void Elevator::winElevate(std::string appName) {
    /*Code for windows elevation*/
}

int Elevator::unixElevate(std::string appName) {
    std::string command = "sudo " + appName;
    int status = system(command.c_str());
    return status;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::fstream help;
        help.open("./elevator.helpfile", std::ios::in);
        std::string helpline;
        while (!help.eof()) {
            std::getline(help, helpline);
            std::cout << helpline << std::endl;
        }
        help.close();
        return 1;
    }
    else {
        int status = Elevator().unixElevate(argv[1]);
        std::cout << WIFEXITED(status) << std::endl;
        if(WIFEXITED(status)) {
            return 1;
        }
    }
    return 0;
}