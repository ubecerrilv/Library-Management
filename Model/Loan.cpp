//
// Created by ubecerril on 2/23/26.
//

#include "Loan.h"

#include <chrono>
#include <iomanip>
#include <sstream>

Loan::Loan() =default;
Loan::Loan(const int id, const int userId, const int bookId):
    theId{id}, theUserId{userId}, theBookId{bookId}, theReturnDate{""} {
    // Set the loan date as today
    const auto now = std::chrono::system_clock::now();
    const std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%d-%m-%Y");

    theLoanDate = ss.str();
}
Loan::Loan(const int id, const int userId, const int bookId, std::string loanDate, std::string returnDate):
    theId{id}, theUserId{userId}, theBookId{bookId}, theLoanDate{std::move(loanDate)}, theReturnDate{std::move(returnDate)}{}

void Loan::setId(const int id){ theId = id; }
void Loan::setUserId(const int userId){ theUserId = userId; }
void Loan::setBookId(const int bookId){ theBookId = bookId; }
void Loan::setLoanDate(const std::string &date){ theLoanDate = date; }
void Loan::setReturnDate(const std::string &date){ theReturnDate = date; }
void Loan::returnBook() {
    const auto now = std::chrono::system_clock::now();
    const std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%d-%m-%Y");

    setReturnDate(ss.str());
}

int Loan::getId() const{ return theId; }
int Loan::getUserId() const{ return theUserId; }
int Loan::getBookId() const{ return theBookId; }
std::string Loan::getLoanDate() const{ return theLoanDate; }
std::string Loan::getReturnDate() const{ return theReturnDate; }