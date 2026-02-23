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
int View::getOption() {
    int option{-1};
    return std::stoi(getMessage());
}
void View::clear() {
    system("clear");
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

Book View::getBook() {
    std::cout << "Type the name of the book: " << std::endl;
    std::string name{};
    std::getline(std::cin, name);

    std::cout << "Type the author of the book: " << std::endl;
    std::string author{};
    std::getline(std::cin, author);

    return {name, author};
}
void View::showBooks(const std::vector<const Book*>& books) {
    if (books.empty()) {
        std::cout << "No books found" << std::endl;
        return;
    }

    constexpr int idWidth = 5;
    constexpr int nameWidth = 35;
    constexpr int authorWidth = 35;
    constexpr int availWidth = 10;

    std::cout << std::left
        << std::setw(idWidth)         << "ID"         << " | "
        << std::setw(nameWidth)   << "Name"       << " | "
        << std::setw(authorWidth) << "Author"     << " | "
        << std::setw(availWidth)    << "Available"  << std::endl;

    std::cout << std::string(idWidth + nameWidth + authorWidth + availWidth + 9, '-') << std::endl;

    for (const auto& book : books) {
        std::cout << std::left
            << std::setw(idWidth)     << book->getId()     << " | "
            << std::setw(nameWidth)   << (book->getName().substr(0, nameWidth - 1))   << " | "
            << std::setw(authorWidth) << (book->getAuthor().substr(0, authorWidth - 1)) << " | "
            << std::setw(availWidth)  << (book->isAvailable() ? "Yes" : "No")
            << std::endl;
    }
}

std::string View::getBookName() {
    std::cout << "Type the name of the book:" << std::endl;
    std::string name{};
    std::getline(std::cin, name);
    return name;
}
std::string View::getBookAuthor() {
    std::cout << "Type the author of the book:" << std::endl;
    std::string author{};
    std::getline(std::cin, author);
    return author;
}
int View::getBookId() {
    std::cout << "Type the ID of the book:" << std::endl;
    std::string id{};
    std::getline(std::cin, id);
    return std::stoi(id);
}
void View::showBook(const Book &book) {
    if (book.getName() == "") {
        std::cout << "The book not found" << std::endl;
    }else {
        std::cout << "The book found, ID: " << book.getId() << "; " << book.getName() << " by " << book.getAuthor()<< std::endl;
    }
}
