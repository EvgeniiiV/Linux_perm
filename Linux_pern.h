using namespace std;
#include <fstream>
#include <iostream>

class User {
	string _name;
	string _login;
	string _pass;
public:
	User(string name, string login, string pass) :_name(name), _login(login), _pass(pass) {}

	friend fstream& operator >>(fstream& is, User& obj);
	friend ostream& operator <<(ostream& os, const User& obj);
};

fstream& operator >>(fstream& is, User& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}
ostream& operator <<(ostream& os, const User& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	return os;
}

class Message {
	string _sender;
	string _receiver;
	string _text;
public:	
	Message (string text, string sender, string receiver) :_text(text), _sender(sender), _receiver(receiver) {}
	friend fstream& operator >>(fstream& is, Message& obj);		
	friend ostream& operator <<(ostream& os, const Message& obj);	
};

fstream& operator >>(fstream& is, Message& obj)
{
	is >> obj._sender;
	is >> obj._receiver;
	is >> obj._text;
	return is;
}
ostream& operator <<(ostream& os, const Message& obj)
{    
	os << obj._sender;
	os << ' ';
	os << obj._receiver;
	os << ' ';
	os << obj._text;
	return os;
}
