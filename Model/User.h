//
// Created by ubecerril on 2/20/26.
//

#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H
#include <string>


class User {
private:
    int theId;
    std::string theName;
    std::string theEmail;

public:
    User();
    User(int id, std::string name, std::string email);
    User (std::string name, std::string email);

    void setId (int id);
    void setName (const std::string &name);
    void setEmail (const std::string &email);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
};


#endif //LIBRARY_USER_H