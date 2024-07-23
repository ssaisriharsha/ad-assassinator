#include <iostream>
#include <string.h>

int main(int argc, char *argv[]) {
    char a[50] = "test ";
    strcat(a, argv[1]);
    std::cout << a << std::endl;
}