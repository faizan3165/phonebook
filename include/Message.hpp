#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <iostream>
#include <string>

using namespace std;

class Message
{
public:
    Message(const string &sender, const string &content);

    const string &getSender() const;
    const string &getContent() const;

private:
    string sender;
    string content;
};

#endif
