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
    retrieveUsers();
    retrieveLoans();
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

void LibraryDB::addUser(User &user) {
    user.setId(nextUserId);
    users[nextUserId++] = user;
}
std::vector<const User *> LibraryDB::getUsers() const {
    std::vector<const User*> usersV;
    usersV.reserve(users.size());
    for (const auto &user : users) {
        usersV.push_back(&user.second);
    }
    return usersV;
}
void LibraryDB::deleteUserById(const int id) {
    users.erase(id);
    if (id == nextUserId-1) {
        nextUserId --;
    }
}

bool LibraryDB::addLoan(const int userId, const int bookId) {
    if (!users.count(userId) || !books.count(bookId)) {
        return false;
    }
    loans[nextLoanId++] = {nextLoanId, userId, bookId};
    books[bookId].setAvailable(false);
    return true;
}
bool LibraryDB::returnBook(const int bookId) {
    if (!books.count(bookId)) {
        return false;
    }

    for (auto& loan :loans) {
        if (bookId == loan.second.getBookId()) {
            // Set return date to today
            loan.second.returnBook();
            books[bookId].setAvailable(true);
            return true;
        }
    }
    return false;
}
std::vector<const Loan*> LibraryDB::getLoans() const {
    std::vector<const Loan*> loansV;
    loansV.reserve(loans.size());
    for (const auto& loan : loans) {
        loansV.push_back(&loan.second);
    }
    return loansV;
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
    nextBookId = maxId != 1? maxId + 1: 1;
    booksFile.close();
}
void LibraryDB::retrieveUsers() {
    std::ifstream usersFile("../Data/users.csv");
    std::string usersLine;

    int maxId {1};
    while (std::getline(usersFile, usersLine)) {
        std::stringstream ss (usersLine);

        std::string idString;
        getline(ss, idString, ',');
        int id = std::stoi(idString);

        std::string userName;
        getline(ss, userName, ',');

        std::string userEmail;
        getline(ss, userEmail, '\n');

        User u {id, userName, userEmail};
        users[id] = u;

        if (id > maxId) maxId = id;
    }
    nextUserId = maxId != 1? maxId + 1: 1;
    usersFile.close();
}
void LibraryDB::retrieveLoans() {
    std::ifstream loansFile("../Data/loans.csv");
    std::string loansLine;
    int maxId {1};

    while (getline(loansFile, loansLine)) {
        std::stringstream ss (loansLine);

        std::string idString;
        getline(ss, idString, ',');
        int id = std::stoi(idString);

        std::string userIdString;
        getline(ss, userIdString, ',');
        int userId = std::stoi(userIdString);

        std::string bookIdString;
        getline(ss, bookIdString, ',');
        int bookId = std::stoi(bookIdString);

        std::string loanDate;
        getline(ss, loanDate, ',');

        std::string returnDate;
        getline(ss, returnDate, '\n');

        Loan l {id, userId, bookId, loanDate, returnDate};
        loans[id] = l;

        if (id > maxId) maxId = id;
    }
    nextLoanId = maxId != 1? maxId + 1: 1;
    loansFile.close();
}

void LibraryDB::saveAll() const {
    //TODO: save users and loans
    saveBooks();
    saveUsers();
}
void LibraryDB::saveBooks() const {
    std::ofstream booksFile("../Data/books.csv");
    for (const auto &book : books) {
        booksFile << book.first << "," << book.second.getName() << "," << book.second.getAuthor() << "," << book.second.isAvailable() << std::endl;
    }
    booksFile.close();
}
void LibraryDB::saveUsers() const {
    std::ofstream usersFile("../Data/users.csv");
    for (const auto &user : users) {
        usersFile << user.first << "," << user.second.getName() << "," << user.second.getEmail() << std::endl;
    }
    usersFile.close();
}
void LibraryDB::saveLoans() const {
    std::ofstream loansFile("../Data/loans.csv");
    for (const auto &loan : loans) {
        loansFile << loan.first << "," << loan.second.getUserId() << "," << loan.second.getBookId() << "," <<   loan.second.getLoanDate() << "," << loan.second.getReturnDate() << std::endl;
    }
    loansFile.close();
}
