#include "../os-finder.hpp"

int main() {
    osDetector obj;
    std::cout << "Welcome, " << obj.getOS() << " user!" << std::endl;
}