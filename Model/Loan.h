//
// Created by ubecerril on 2/23/26.
//

#ifndef LIBRARYMANAGEMENT_LOAN_H
#define LIBRARYMANAGEMENT_LOAN_H
#include <string>

class Loan {
private:
    int theId;
    int theUserId;
    int theBookId;
    std::string theLoanDate;
    std::string theReturnDate;

public:
    Loan(int id, int userId, int bookId);

    void setId(int id);
    void setUserId(int userId);
    void setBookId(int bookId);
    void setLoanDate(const std::string &date);
    void setReturnDate(const std::string &date);

    int getId() const;
    int getUserId() const;
    int getBookId() const;
    std::string getLoanDate() const;
    std::string getReturnDate() const;
};

#endif //LIBRARYMANAGEMENT_LOAN_H