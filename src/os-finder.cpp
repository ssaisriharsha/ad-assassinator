#include "./os-finder.hpp"
#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

void osDetector::findOS() {
    #ifdef __linux__
    os = "linux";
    #elif _WIN32
    os = "windows";
    #elif TARGET_OS_MAC
    os = "macos";
    #endif
}

std::string osDetector::getOS() {
    if(os.empty()) {
        findOS();
        return os;
    }
    else {
        return os;
    }
}