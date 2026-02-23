//
// Created by ubecerril on 2/20/26.
//

#include "Book.h"

Book::Book(const int id, std::string name, std::string author):
    theId{id}, theName{std::move(name)}, theAuthor{std::move(author)}, theAvailable(true){}

void Book::setId (const int id){ theId = id; }
void Book::setName (const std::string &name){ theName = name; }
void Book::setAuthor (const std::string &author){ theAuthor = author; }
void Book::setAvailable (const bool available){ theAvailable = available; }

int Book::getId() const{ return theId; }
std::string Book::getName() const{ return theName; }
std::string Book::getAuthor() const{ return theAuthor; }
bool Book::isAvailable() const{ return theAvailable; }