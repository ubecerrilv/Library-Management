//
// Created by ubecerril on 2/20/26.
//

#include "View.h"

void View::showMessage(const std::string& message) {
    std::cout << message << std::endl;
}

std::string View::getMessage() {
    std::string line{};
    std::getline(std::cin, line);
    return line;
}

void View::showMainMenu() {
    std::cout << "This program is to manage the use of the library" << std::endl;
    std::cout << "Please select one of the following:" << std::endl;

    std::cout << "1. Books management" << std::endl;
    std::cout << "2. Users management" << std::endl;
    std::cout << "3. Books loan" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void View::showBooksMenu() {
    std::cout << "Please select one of the following:" << std::endl;
    std::cout << "1. Add a book" << std::endl;
    std::cout << "2. Show all the books" << std::endl;
    std::cout << "3. Search book by title" << std::endl;
    std::cout << "4. Search book by author" << std::endl;
    std::cout << "5. Delete a book" << std::endl;
    std::cout << "6. Mark book as borrowed/available" << std::endl;
    std::cout << "7. Back" << std::endl;
}

void View::showUsersMenu() {
    std::cout << "Please select one of the following:" << std::endl;
    std::cout << "1. Register user" << std::endl;
    std::cout << "2. Show all users" << std::endl;
    std::cout << "3. Delete user" << std::endl;
    std::cout << "4. Back" << std::endl;
}

void View::showBooksLoanMenu() {
    std::cout << "Please select one of the following:" << std::endl;
    std::cout << "1. Allow user to borrow a book" << std::endl;
    std::cout << "2. Register loan date" << std::endl;
    std::cout << "3. Return a book" << std::endl;
    std::cout << "4. Back" << std::endl;
}

int View::getOption() {
    int option{-1};
    return std::stoi(getMessage());
}

void View::clear() {
    system("clear");
}