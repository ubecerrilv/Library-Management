//
// Created by ubecerril on 2/20/26.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include <string>


class Book {
private:
    int theId;
    std::string theName;
    std::string theAuthor;
    bool theAvailable;

public:
    Book(int id, std::string name, std::string author);

    void setId (int id);
    void setName (const std::string &name);
    void setAuthor (const std::string &author);
    void setAvailable (bool available);

    int getId() const;
    std::string getName() const;
    std::string getAuthor() const;
    bool isAvailable() const;
};


#endif //LIBRARY_BOOK_H