#pragma once
#include<mysql.h>

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
void connect() {
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "Mahesh@09112001", "UserLoginDetails", 3306, NULL, 0);

	if (conn) {
		puts("successful Connection to database . ");
		//system("cls");
	}
	else {
		puts("connection to database has failed .");
	}

}

