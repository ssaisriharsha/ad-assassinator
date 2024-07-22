#include <iostream>
#include "./elevator.hpp"
#include <fstream>

void Elevator::winElevate(std::string appName) {
    /*Code for windows elevation*/
}

int Elevator::unixElevate(std::string appName) {
    std::string command = "sudo " + appName + "&";
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
    }
    else {
        Elevator().unixElevate(argv[1]);
    }
}