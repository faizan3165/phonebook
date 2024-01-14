# Term Project Report

## Abstract

The Phonebook application is a comprehensive tool implemented in C++ for managing contacts and facilitating communication. This report provides an in-depth exploration of the project's design, implementation, and functionalities. The program leverages object-oriented programming principles, focusing on modularity, encapsulation, and abstraction. The report covers the project's objectives, the role of each module, and the intricacies of implementation.

## Introduction

The Phonebook application serves as an efficient solution for contact management and communication. Implemented in C++, the project aims to provide a detailed examination of its structure and functioning. The application is designed with a focus on object-oriented principles such as modularity, encapsulation, and abstraction. The core functionalities include adding contacts, viewing contacts, sending messages, and viewing message histories.

## Project UML

### Class Diagram

#### Phonebook Class

- **Attributes:**
  - `root: Contact*` - Represents the root of the binary search tree.

- **Methods:**
  - `addContact()` - Facilitates the addition of a new contact.
  - `addContactToTree()` - Adds a contact to the binary search tree.
  - `viewContacts()` - Displays contacts in alphabetical order.
  - `inOrderTraversal()` - Implements in-order traversal for contact display.
  - `findContactNodeByName()` - Searches for a contact node by name.
  - `sendMessage()` - Initiates the process of sending a message.
  - `sendMessageToContact()` - Sends a message to a specific contact.
  - `displayMessagesWithArrows()` - Displays messages with navigation options.
  - `viewMessages()` - Allows users to view messages for a specific contact.

#### Contact Class

- **Attributes:**
  - `name: std::string` - Represents the name of the contact.
  - `phoneNumber: std::string` - Stores the phone number of the contact.
  - `prev: Contact*` - Points to the previous contact in the binary search tree.
  - `next: Contact*` - Points to the next contact in the binary search tree.
  - `messages: Messages` - Represents the linked list of messages associated with the contact.

- **Methods:**
  - `getters` - Provides access to private attributes.
  - `setPrev()` - Sets the previous pointer.
  - `setNext()` - Sets the next pointer.

#### Messages Class

- **Attributes:**
  - `top: Node*` - Represents the top of the linked list.

- **Methods:**
  - `push()` - Adds a new message to the linked list.
  - `viewMessages()` - Displays the messages associated with a contact.
  - `pop()` - Removes the top message from the linked list.
  - `getNthMessage()` - Retrieves the nth message in the linked list.
  - `size()` - Returns the size of the linked list.

#### Node **Struct** (inside Messages)

- **Attributes:**
  - `data: Message` - Holds the data of a message.
  - `next: Node*` - Points to the next node in the linked list.

#### Message Class

- **Attributes:**
  - `sender: std::string` - Represents the sender's name.
  - `content: std::string` - Stores the content of the message.

- **Methods:**
  - `getSender()` - Retrieves the sender's name.
  - `getContent()` - Retrieves the content of the message.

### Sequence Diagram (Sending a Message)

1. **User -> Phonebook:**
   - `selectSendMessage()`
2. **Phonebook -> User:**
   - `displayContactList()`
3. **User -> Phonebook:**
   - `chooseContact()`
4. **Phonebook -> User:**
   - `composeMessagePrompt()`
5. **User -> Phonebook:**
   - `enterMessageDetails(sender, content)`
6. **Phonebook -> Contact:**
   - `sendMessageToContact(recipient)`
7. **Contact -> Messages:**
   - `push(newMessage)`
8. **Phonebook -> User:**
   - `confirmationMessage()`

## Workflow Diagrams

### Adding a Contact Workflow

1. **User Interaction:**
   - User selects "Add Contact."
2. **Input Gathering:**
   - Phonebook prompts for name and phone number.
3. **Contact Creation:**
   - New Contact instance is created.
4. **Adding to Phonebook:**
   - Contact is added to Phonebook.
5. **Confirmation:**
   - Successful addition message.
6. **Return to Menu:**
   - Application returns to the main menu.

### Sending a Message Workflow

1. **User

 Interaction:**
   - User selects "Send Message."
2. **Contact Selection:**
   - Phonebook displays the contact list.
3. **Recipient Choice:**
   - User selects a contact as the recipient.
4. **Message Composition:**
   - User enters sender's name and message content.
5. **Message Sending:**
   - Message is sent to the chosen contact.
6. **Confirmation:**
   - Successful message sent message.
7. **Return to Menu:**
   - Application returns to the main menu.

## Conclusion

In conclusion, the Phonebook application encapsulates the principles of object-oriented programming, utilizing a binary search tree for contact management and a linked list for message tracking. The detailed UML diagrams and workflow discussions provide a comprehensive understanding of the application's architecture and functionality.
