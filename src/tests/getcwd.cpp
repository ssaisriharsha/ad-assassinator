#include <iostream>
#include <unistd.h>

int main() {
    char arr[1024];
    getcwd(arr, sizeof(arr));
    std::cout << arr << std::endl;
    return 0;
}