#include <iostream>

#include "Contact.hpp"

using namespace std;

Contact::Contact(const string &name, const string &phoneNumber)
    : name(name), phoneNumber(phoneNumber), prev(NULL), next(NULL) {}

string Contact::getName() const
{
    return name;
}

string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

Contact *Contact::getPrev() const
{
    return prev;
}

Contact *Contact::getNext() const
{
    return next;
}

Messages &Contact::getMessages()
{
    return messages;
}

void Contact::setPrev(Contact *prev)
{
    this->prev = prev;
}

void Contact::setNext(Contact *next)
{
    this->next = next;
}
