#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "Message.hpp"

class Messages
{
public:
    Messages();
    ~Messages();

    Message getNthMessage(int n) const;
    void push(const Message &message);
    void viewMessages() const;
    void pop();
    bool empty() const;
    int size() const;

    struct Node
    {
        Message data;
        Node *next;
        Node *prev;
        Node(const Message &message);
    };

    Node *getTop() const;
    Node *getCurrentNode() const;

private:
    Node *top;
    Node *currentNode;
};

#endif
