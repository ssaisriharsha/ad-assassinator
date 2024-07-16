#include <iostream>
#include "./elevator.hpp"
#include "./os-finder.hpp"
#include <sys/wait.h>
#include <cstdlib>
#ifdef __unix__
#include "./unix-sudo-mode-check.hpp"
#endif

int main(int argc, char *argv[])
{
    std::cout << "[info] Checking OS." << std::endl;
    osDetector detector;
    std::string os = detector.getOS();
    if (os == "linux" || os == "macos")
    {
        std::cout << "[info] Unix-based OS" << std::endl;
        std::cout << "[info] Checking sudo mode." << std::endl;
        bool sudo_mode = SudoModeChecker::checkSudo();
        if (sudo_mode)
        {
            std::cout << "[info] All set, running in sudo mode!" << std::endl;     
        }
        else
        {
            std::cout << "[warning] Not running in sudo mode!" << std::endl;
            std::cout << "[info] Trying to switch to sudo mode." << std::endl;
            int status = Elevator::unixElevate(argv[0]);
            std::cout << status << std::endl;
            if(WIFEXITED(status)) {
                int exit_code = WEXITSTATUS(status);
                std::cout << exit_code << std::endl;
                if(exit_code) {
                    std::cout << "Unable to switch to sudo mode. Try running the program using sudo." << std::endl;
                    exit(1);
                }
            }
        }
    }
    return 0;
}