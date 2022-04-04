#pragma once
#include<iostream>
#include <string.h>
#include <string>
#include "databseConnect.h"
#include "createAccount.h"


void itsMewhoIssending(std::string friendName, std::string msg);
int sendmsg(std::string friendName, std::string msg);

std::string temp;

void createAccountintoDB(std::string username, std::string password) {
	int qstate;

	std::string query;
	query="insert into userDetails(UserName, loginKey) VALUES('"+username+"', '"+password+"')";

	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		std::cout << "successful." << std::endl;
	}
	else {
		std::cout << "User Name already exists ...Error Code:" << mysql_errno(conn) << std::endl;
	}

}

int checkLoginCredentials(std::string uname,std::string passwrd) {
	std::string query = "select LoginKey from userDetails where username ='"+uname+"'";

	int qstate;
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate) {
		res = mysql_store_result(conn);
		
		while ((row = mysql_fetch_row(res))) {
			if(strcmp(*row,&(passwrd[0])) == 0) {
				temp = uname;
				return 1;
			}
			else {
				std::cout << "User Not Found.";
				return 0;
			}
		}
	}
	else {
		std::cout << "Something Went Wrong ...Error Code:" << mysql_errno(conn) << std::endl;
	}
	return 0;
}

void friendList() {
	std::string query= "select userName from userDetails";
	int qstate;
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			std::cout <<"   " << row[0] << std::endl;
		}
	}
}

int displaychat(std::string friendName) {
	system("cls");
	std::cout << "\n-----------------------------WELCOME TO MY CHAT APPLICATION----------------------------------\n\n";
	int qstate;
	std::string query = "select distinct sender,message,statuss,dt  from chatstable where myusername='" + temp + "' and friendname='" + friendName + "'";
	
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			std::cout<< row[0]<<" : " << row[1] << "      " << row[2]<<"      " << row[3] << std::endl;
		}
	}
	else {
		std::cout << "Error Occured ." << mysql_errno(conn) << std::endl;
	}

	query = "update chatstable set statuss='           ' where statuss='new message' and myusername='" + temp + "'";
	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
	}
	else {
		std::cout << "1.Error Occured ." << mysql_errno(conn) << std::endl;
	}

	std::cout << "\n\n***Press '1' to Back ";
	std::cout << "Or Message to Send\nEnter :";

	std::string input;
	std::cin>>input;

	if (strcmp(&input[0], "1") == 0) {
		return 1;
	}
	else if (strcmp(&input[0], "2") == 0) {
		return 2;
	}else {
		return sendmsg(friendName, input); 
	}

}


int sendmsg(std::string friendName, std::string msg)
{
	int qstate;
	std::string query = "insert into chatstable(myusername,friendname,sender,message,statuss,dt) values('" + friendName + "','" + temp+ "','" + temp + "','" + msg + "','new message',now())";

	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
	}
	else {
		std::cout << "coud not send message .";
	}

	itsMewhoIssending(friendName,msg);
	

	return 0;

}


void itsMewhoIssending(std::string friendName, std::string msg) {
	std::string query1 = "insert into chatstable(myusername,friendname,sender,message,statuss,dt) values('" + temp + "','" + friendName + "','" + temp + "','" + msg + "','               ',now())";
	const char* q1 = query1.c_str();
	int qstate1 = mysql_query(conn, q1);
	if (!qstate1) {
	}
	else {
		std::cout << "coud not send message .";
	}
}





