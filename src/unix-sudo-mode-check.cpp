#include <iostream>
#ifndef _UNIX_SUDO_MODE_CHECK_HPP_
#include "./unix-sudo-mode-check.hpp"
#endif
bool SudoModeChecker::checkSudo() {
    bool root_user;
    if(!getuid()) {
        root_user = true;
    }
    else {
        root_user = false;
    }
    return root_user;
}