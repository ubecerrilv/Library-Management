//
// Created by ubecerril on 2/20/26.
//

#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

#include <unordered_map>
#include <vector>

#include "User.h"
#include "Book.h"
#include "Loan.h"

class LibraryDB {
private:
    std::string name {"Library Vasconcelos"};
    std::string address{"Eje 1 Nte. S/N, Buenavista, Cuauhtémoc, 06350 Ciudad de México, CDMX"};

    std::unordered_map<int, User> users;
    std::unordered_map<int, Book> books;
    std::unordered_map<int, Loan> loans;

public:
    LibraryDB();
    void init();

    // Logic's methods

    std::string getInfo();
    // Book management
    void addBook(const Book &b);
    std::vector<Book*> getBooks();
    Book* searchBookByName(const std::string &name);
    Book* searchBookById(int id);
    void deleteBookById(int id);
    void setBookAsBorrowed(int id);
    void setBookAsAvailable(int id);
    // User management
    void addUser(const User &user);
    std::vector<User*> getUsers();
    void deleteUserById(int id);
    //Loan management
    void createLoan(int userId, int bookId);
    // TODO: What parameters this should have
    void returnBook();

    // Methods to retrieve the information from the files
    void retrieveUsers();
    void retrieveBooks();
    void retrieveLoans();

    // Methods to save the information to the files
    void saveUsers();
    void saveBooks();
    void saveLoans();
};

#endif //LIBRARY_LIBRARY_H