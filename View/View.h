//
// Created by ubecerril on 2/20/26.
//

#ifndef LIBRARY_VIEW_H
#define LIBRARY_VIEW_H

#include <iostream>
#include <cstdlib>

class View {
public:
    void showMessage(const std::string& message);
    std::string getMessage();
    void showMainMenu();
    void showBooksMenu();
    void showUsersMenu();
    void showBooksLoanMenu();
    int getOption();
    void clear();
};

#endif //LIBRARY_VIEW_H