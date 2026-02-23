//
// Created by ubecerril on 2/20/26.
//

#include "LibraryDB.h"
#include <fstream>
#include <sstream>

LibraryDB::LibraryDB() {
    init();
}
void LibraryDB::init() {
    retrieveBooks();
    // TODO: Call retrieve users and loans
}

std::string LibraryDB::getInfo() const {
    return name + "\n" + address;
}

void LibraryDB::addBook(Book &b) {
    b.setId(nextBookId);
    books[nextBookId++] = b;
}
std::vector<const Book *> LibraryDB::getBooks() const {
    std::vector<const Book *> booksV;
    booksV.reserve(books.size());

    for (const auto &book : books) {
        booksV.push_back(&book.second);
    }

    return booksV;
}
Book LibraryDB::searchBookByName(const std::string &bookName) {
    for (const auto& [id, book] : books) {
        if (book.getName() == bookName) {
            return book;
        }
    }
    return Book();
}
std::vector<const Book*> LibraryDB::searchBookByAuthor(const std::string &bookAuthor) const {
    std::vector<const Book*> booksV;
    for (const auto& book : books) {
        if (book.second.getAuthor() == bookAuthor) {
            booksV.push_back(&book.second);
        }
    }
    return booksV;
}
void LibraryDB::deleteBookById(const int id) {
    books.erase(id);
    if (id == nextBookId-1) {
        nextBookId --;
    }
}
void LibraryDB::setBookAsBorrowedAvailable(const int id) {
    if (books.find(id) != books.end()) {
        books[id].changeState();
    }
}

void LibraryDB::retrieveBooks() {
    std::ifstream booksFile("../Data/books.csv");
    std::string booksLine;
    int maxId {1};

    while (std::getline(booksFile, booksLine)) {
        std::stringstream ss (booksLine);

        std::string idString;
        getline(ss, idString, ',');
        int id = std::stoi(idString);

        std::string bookName;
        getline(ss, bookName, ',');

        std::string bookAuthor;
        getline(ss, bookAuthor, ',');

        std::string availableString;
        getline(ss, availableString, '\n');
        bool available = (availableString == "1");

        Book b{id, bookName, bookAuthor, available};
        books[id] = b;

        if (id > maxId) maxId = id;
    }
    nextBookId = maxId + 1;
    booksFile.close();
}

void LibraryDB::saveAll() const {
    //TODO: save users and loans
    saveBooks();
}

void LibraryDB::saveBooks() const {
    std::ofstream booksFile("../Data/books.csv");
    for (const auto &book : books) {
        booksFile << book.first << "," << book.second.getName() << "," << book.second.getAuthor() << "," << book.second.isAvailable() << std::endl;
    }
    booksFile.close();
}
