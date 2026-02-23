//
// Created by ubecerril on 2/20/26.
//

#ifndef LIBRARY_VIEW_H
#define LIBRARY_VIEW_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Book.h"
#include <iomanip>

class View {
public:
    void showMessage(const std::string& message);
    std::string getMessage();
    int getOption();
    void clear();

    void showMainMenu();
    void showBooksMenu();
    void showUsersMenu();
    void showBooksLoanMenu();

    Book getBook();
    void showBooks(const std::vector<const Book*>& books);
    std::string getBookName();
    std::string getBookAuthor();
    int getBookId();
    void showBook(const Book& book);
};

#endif //LIBRARY_VIEW_H