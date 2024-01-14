#include <iostream>

#include "../include/Phonebook.hpp"

using namespace std;

int main()
{
    Phonebook phonebook;

    while (true)
    {
        cout << "Phonebook Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. View Messages\n";
        cout << "4. Send Message\n";
        cout << "5. Exit\n";

        int choice;
        
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            phonebook.addContact();
            break;

        case 2:
            phonebook.viewContacts();
            break;

        case 3:
            phonebook.viewMessages();
            break;

        case 4:
            phonebook.sendMessage();
            break;

        case 5:
            cout << "Exiting Phonebook. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
