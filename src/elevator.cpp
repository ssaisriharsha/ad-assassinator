#include <iostream>
#include "./elevator.hpp"

void Elevator::winElevate(std::string appName) {
    /*Code for windows elevation*/
}

int Elevator::unixElevate(std::string appName) {
    std::string command = "sudo " + appName;
    int status = system(command.c_str());
    return status;
}