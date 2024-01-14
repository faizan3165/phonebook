#include <iostream>

#include "Messages.hpp"

using namespace std;

Messages::Node::Node(const Message &message) : data(message), next(NULL) {}

Messages::Messages() : top(NULL) {}

Messages::~Messages()
{
    while (!empty())
    {
        pop();
    }
}

bool Messages::empty() const
{
    return top == NULL;
}

void Messages::push(const Message &message)
{
    Node *newNode = new Node(message);
    newNode->next = top;
    top = newNode;
}

void Messages::pop()
{
    if (!empty())
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void Messages::viewMessages() const
{
    Node *current = top;
    while (current != NULL)
    {
        cout << "Sender: " << current->data.getSender()
             << "\tMessage: " << current->data.getContent() << "\n";
        current = current->next;
    }
}

Message Messages::getNthMessage(int n) const
{
    Node *current = top;
    int count = 0;

    while (current != NULL)
    {
        if (count == n)
        {
            return current->data;
        }
        current = current->next;
        count++;
    }

    return Message("", "");
}

int Messages::size() const
{
    int count = 0;
    Node *current = top;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

Messages::Node *Messages::getTop() const
{
    return top;
}

Messages::Node *Messages::getCurrentNode() const
{
    return currentNode;
}
