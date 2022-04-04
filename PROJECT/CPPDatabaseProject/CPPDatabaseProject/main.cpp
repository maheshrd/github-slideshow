#include<iostream>

#include "databseConnect.h"
#include  "createAccount.h"
#include "screens.h"


enum screens { MAINSCREEN, CREATEACCOUNTSCREEN, LOGINSCREEN, FRIENDLISTSCREEN, CHATSCREEN, EXIT };

int main() {
	int myChoice;
	connect();

	screens screen ;
	screen=MAINSCREEN;
	
	while (screen != EXIT)
	{

		switch (screen)
		{
		case MAINSCREEN:
			myChoice= mainScreen();
			if (myChoice == 1) screen = CREATEACCOUNTSCREEN;
			if (myChoice == 2) screen = LOGINSCREEN;
			if (myChoice == 3) screen = EXIT;
			break;

		case CREATEACCOUNTSCREEN:
			myChoice = createAccountScreen();
			if (myChoice == 1) screen = LOGINSCREEN;
			if (myChoice == 2) screen = MAINSCREEN;
			if (myChoice == 3) screen = EXIT;
			break;

		case LOGINSCREEN:
			myChoice = loginAccountScreen();
			if (myChoice == 1) screen = FRIENDLISTSCREEN;
			if (myChoice == 2) screen = MAINSCREEN;

			break;

		case FRIENDLISTSCREEN:
			myChoice = friendListScreen();
			if (myChoice == 1) screen = FRIENDLISTSCREEN;			
			if (myChoice == 2) screen = MAINSCREEN;			
			break;
		case EXIT:
			exit(0);
			break;
		default:
			screen = MAINSCREEN;
			break;
		}

	}









	return 0;


} 