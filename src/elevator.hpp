#pragma once
#include <iostream>

class Elevator {
    public:
        static void winElevate(std::string appName);
        static int unixElevate(std::string appName);
};