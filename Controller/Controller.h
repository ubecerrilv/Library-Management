//
// Created by ubecerril on 2/20/26.
//

#ifndef LIBRARY_CONTROLLER_H
#define LIBRARY_CONTROLLER_H

#include "../Model/Library.h"
#include "../View/View.h"

class Controller {
private:
    Library theLibrary;
	View theView;

public:
    Controller(Library library, View view);

    void init();
    void MainMenu();
    void booksMenu();
    void usersMenu();
    void booksLoanMenu();
};

#endif //LIBRARY_CONTROLLER_H