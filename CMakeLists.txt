# 1. Version and name
cmake_minimum_required(VERSION 3.10)
project(LibraryManagement CXX)

# 2. C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Directories of files (.h)
include_directories(. Model View Controller)

# 4. List source files (.cpp)
add_executable(LibraryManagement
        main.cpp
        Controller/Controller.cpp
        Model/Library.cpp
        Model/Book.cpp
        Model/User.cpp
        View/View.cpp
)
