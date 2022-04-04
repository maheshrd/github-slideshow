#pragma once
#include<iostream>
#include "DatabaseCommands.h"

class User
{
public:
	User();
	User(std::string username, std::string passwd);
	std::string getusername() { return userName; }
	std::string getpassword() { return password; }
	~User();

private:
	std::string userName;
	std::string password;
};

User::User(std::string username, std::string passwd) {
	this->userName = username;
	this->password = passwd;
	this->password = passwd;

};

User::User()
{
	std::cout << "Enter Username :";
	std::cin >> this->userName;
	std::cout << "Enter Password :";
	std::cin >> this->password;

}

User::~User()
{
}

//User* currentUser;