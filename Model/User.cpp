//
// Created by ubecerril on 2/20/26.
//

#include "User.h"

User::User() =default;
User::User(const int id, std::string name, std::string email):
    theId{id}, theName{std::move(name)}, theEmail{std::move(email)}{}
User::User (std::string name, std::string email):
    theName{std::move(name)}, theEmail{std::move(email)}{}

void User::setId (const int id){ theId = id; }
void User::setName (const std::string &name){ theName = name; }
void User::setEmail (const std::string &email){ theEmail = email; }

int User::getId() const{ return theId; }
std::string User::getName() const{ return theName; }
std::string User::getEmail() const{ return theEmail; }