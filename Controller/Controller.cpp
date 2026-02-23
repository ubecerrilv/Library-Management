//
// Created by ubecerril on 2/20/26.
//

#include "Controller.h"
#include <utility>

Controller::Controller(LibraryDB library, View view) :theLibrary(std::move(library)), theView(std::move(view)){}

void Controller::init(){ MainMenu(); }

void Controller::MainMenu(){
	theView.showMessage(theLibrary.getInfo());
	int o = 0;
	while (o != 4) {
		theView.showMainMenu();
		o = theView.getOption();

		theView.clear();

		switch (o) {
			case 1:
				booksMenu();
				break;
			case 2:
				usersMenu();
				break;
			case 3:
				booksLoanMenu();
			default:
				break;
		}
	}
	theLibrary.saveAll();
}

void Controller::booksMenu() {
	int o = 0;

	while (o != 7) {
		theView.showBooksMenu();
		o = theView.getOption();

		// TODO:  Show confirmation messages
		switch (o) {
			case 1: {
				Book b = theView.getBook();
				theLibrary.addBook(b);
				theLibrary.saveBooks();
				break;
			}
			case 2: {
				theView.showBooks(theLibrary.getBooks());
				break;
			}
			case 3: {
				std::string bookName = theView.getBookName();
				Book b = theLibrary.searchBookByName(bookName);
				theView.showBook(b);
				break;
			}
			case 4: {
				std::string author = theView.getBookAuthor();
				auto booksV = theLibrary.searchBookByAuthor(author);
				theView.showBooks(booksV);
				break;
			}
			case 5: {
				const int id = theView.getBookId();
				theLibrary.deleteBookById(id);
				theLibrary.saveBooks();
				break;
			}
			case 6: {
				const int id = theView.getBookId();
				theLibrary.setBookAsBorrowedAvailable(id);
				theLibrary.saveBooks();
				break;
			}
			default:
				break;
		}
	}
}

void Controller::usersMenu() {
	int o{0};

	// TODO: Show confirmation messages
	while (o != 4) {
		theView.showUsersMenu();
		o = theView.getOption();

		switch (o) {
			case 1: {
				User u = theView.getUser();
				theLibrary.addUser(u);
				theLibrary.saveUsers();
				break;
			}
			case 2: {
				theView.showUsers(theLibrary.getUsers());
				break;
			}
			case 3: {
				const int id = theView.getUserId();
				theLibrary.deleteUserById(id);
				theLibrary.saveUsers();
				break;
			}
			default: {
				break;
			}
		}
	}

}

void Controller::booksLoanMenu() {
	int o {0};

	while (o != 4) {
		theView.showBooksLoanMenu();
		o = theView.getOption();

		switch (o) {
			case 1: {
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			default: {
				break;
			}
		}
	}
}
