//
// Created by ubecerril on 2/20/26.
//

#include "Controller.h"
#include <utility>

Controller::Controller(Library library, View view) :theLibrary(std::move(library)), theView(std::move(view)){}

void Controller::init(){ MainMenu(); }

void Controller::MainMenu(){
	theView.showMainMenu();
	const int o = theView.getOption();

	theView.clear();

	switch (o) {
		case 1:
			booksMenu();
			break;
		case 2:
			usersMenu();
		case 3:
			booksLoanMenu();
		case 4:
			break;
		default:
			MainMenu();
	}
}

void Controller::booksMenu() {
	theView.showBooksMenu();
	const int o = theView.getOption();
}

void Controller::usersMenu() {
	theView.showUsersMenu();
	const int o = theView.getOption();
}

void Controller::booksLoanMenu() {
	theView.showBooksLoanMenu();
	const int o = theView.getOption();
}
