#include <iostream>

#include "Message.hpp"

using namespace std;

Message::Message(const string &sender, const string &content)
    : sender(sender), content(content) {}

const string &Message::getSender() const
{
    return sender;
}

const string &Message::getContent() const
{
    return content;
}
