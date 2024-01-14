#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
public:
    Phonebook();

    void addContact();
    void viewContacts() const;
    void viewMessages() const;
    void sendMessage();

private:
    Contact *root;
    Contact *findContactNodeByName(const std::string &name, Contact *currentRoot) const;
    void sendMessageToContact(Contact *recipient);
    void addContactToTree(Contact *newNode, Contact *const &currentRoot);
    void inOrderTraversal(Contact *node) const;
    void displayMessagesWithArrows(Contact *contact) const;
};

#endif
