#include <iostream>
#include <unistd.h>

int main() {
    uid_t uid = getuid();
    std::cout << uid << std::endl;
    return 0;
}