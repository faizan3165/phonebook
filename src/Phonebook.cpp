#include <iostream>
#include <conio.h>

#include "Phonebook.hpp"

using namespace std;

Phonebook::Phonebook() : root(NULL) {}

void Phonebook::addContact()
{
    string name, phoneNumber;
    cout << "Enter contact name: ";
    cin >> name;

    cout << "Enter contact phone number: ";
    cin >> phoneNumber;

    Contact *newContact = new Contact(name, phoneNumber);
    addContactToTree(newContact, root);

    cout << "Contact added successfully.\n";
}

void Phonebook::addContactToTree(Contact *newNode, Contact *const &currentRoot)
{
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        if (newNode->getName() < currentRoot->getName())
        {
            if (currentRoot->getPrev() == NULL)
            {
                currentRoot->setPrev(newNode);
            }
            else
            {
                addContactToTree(newNode, currentRoot->getPrev());
            }
        }
        else
        {
            if (currentRoot->getNext() == NULL)
            {
                currentRoot->setNext(newNode);
            }
            else
            {
                addContactToTree(newNode, currentRoot->getNext());
            }
        }
    }
}

void Phonebook::viewContacts() const
{
    if (root == NULL)
    {
        cout << "No contacts available.\n";
    }
    else
    {
        cout << "Contacts (Alphabetically Ordered):\n";
        inOrderTraversal(root);
    }
}

void Phonebook::inOrderTraversal(Contact *node) const
{
    if (node != NULL)
    {
        if (node->getPrev() != NULL)
        {
            inOrderTraversal(node->getPrev());
        }

        cout << "Name: " << node->getName() << "\tPhone: " << node->getPhoneNumber() << "\n";

        if (node->getNext() != NULL)
        {
            inOrderTraversal(node->getNext());
        }
    }
}

Contact *Phonebook::findContactNodeByName(const string &name, Contact *currentRoot) const
{
    if (currentRoot == NULL || currentRoot->getName() == name)
    {
        return currentRoot;
    }

    if (name < currentRoot->getName())
    {
        return findContactNodeByName(name, currentRoot->getPrev());
    }
    else
    {
        return findContactNodeByName(name, currentRoot->getNext());
    }
}

void Phonebook::sendMessage()
{

    viewContacts();

    string recipientName;
    cout << "Enter recipient name: ";
    cin >> recipientName;

    Contact *recipient = findContactNodeByName(recipientName, root);

    if (recipient == NULL)
    {
        cout << "Recipient not found.\n";
        return;
    }

    sendMessageToContact(recipient);
}

void Phonebook::sendMessageToContact(Contact *recipient)
{
    string sender, content;
    cout << "Enter your name: ";
    cin >> sender;

    cout << "Enter your message: ";
    cin.ignore();
    getline(cin, content);

    Message newMessage(sender, content);
    recipient->getMessages().push(newMessage);

    cout << "Message sent successfully.\n";
}

void Phonebook::displayMessagesWithArrows(Contact *contact) const
{
    Messages &messages = contact->getMessages();

    if (messages.empty())
    {
        cout << "No message history for this contact.\n";
        return;
    }

    int currentIndex = 0;
    int totalMessages = messages.size();

    while (true)
    {
        system("cls");

        Message currentMessage = messages.getNthMessage(currentIndex);
        cout << "Sender: " << currentMessage.getSender() << "\n";
        cout << "Message: " << currentMessage.getContent() << "\n";

        cout << "Press 'Up' to view the previous message, 'Down' for the next message, or 'Enter' to exit.\n";

        int key = _getch();

        if (key == 13)
        {

            break;
        }
        else if (key == 224)
        {

            key = _getch();
            if (key == 72)
            {

                if (currentIndex > 0)
                {
                    currentIndex--;
                }
            }
            else if (key == 80)
            {

                if (currentIndex < totalMessages - 1)
                {
                    currentIndex++;
                }
            }
        }
    }
}

void Phonebook::viewMessages() const
{
    if (root == NULL)
    {
        cout << "No contacts available.\n";
    }
    else
    {
        viewContacts();
        string contactName;
        cout << "Enter contact name to view messages: ";
        cin >> contactName;

        Contact *contact = findContactNodeByName(contactName, root);

        if (contact == NULL)
        {
            cout << "Contact not found.\n";
        }
        else
        {
            displayMessagesWithArrows(contact);
        }
    }
}
