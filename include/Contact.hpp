#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

#include "Messages.hpp"

using namespace std;

class Contact
{
public:
    Contact(const string &name, const string &phoneNumber);

    Contact *getPrev() const;
    Contact *getNext() const;
    Messages &getMessages();
    string getName() const;
    string getPhoneNumber() const;

    void setPrev(Contact *prev);
    void setNext(Contact *next);

private:
    string name;
    string phoneNumber;
    Contact *prev;
    Contact *next;
    Messages messages;
};

#endif
