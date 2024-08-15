cmake_minimum_required(VERSION 3.30.2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_TOOLCHAIN_FILE /home/sai/Desktop/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "")

project(Ad-Assassinator)

add_executable(elevator elevator.cpp)

target_include_directories(elevator PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# add_executable(test tests/test.cpp)

# target_include_directories(test PRIVATE /home/sai/Desktop/vcpkg/installed/x64-linux/include)

add_library(unix-sudo-mode-check SHARED unix-sudo-mode-check.cpp)

target_include_directories(unix-sudo-mode-check PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_library(os-finder SHARED os-finder.cpp)

target_include_directories(os-finder PRIVATE ${CMAKE_SOURCE_DIR}/include)

install(TARGETS os-finder unix-sudo-mode-check DESTINATION lib)

# target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/build)

target_link_libraries(${PROJECT_NAME} PRIVATE os-finder unix-sudo-mode-check)

# target_link_libraries(test PRIVATE libpqxx::pqxx)

# find_package(libpqxx REQUIRED)


