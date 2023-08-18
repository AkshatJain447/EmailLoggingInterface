#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "signup.cpp"
#include "login.cpp"
//the function below is only to delay the output 
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void main_page();
void found();

int main(){
	main_page();
	found();
}

void main_page(){
	system("cls");
	printf("  QuickMail.com   \\ +\t\t\t\t\t\t\t\t\t\t\t\t   | X\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\tQ U I C K M A I L\n");
}


void found(){
	printf("\n\n\t\t\t\t\tDon't have an account? 'Sign up?'\n");
	printf("\t\t\t\t\t\t\t\t-------\n");
	printf("\t\t\t\t\t_________________________________\n");
	printf("\t\t\t\t\t|\t\t\t\t|\n");
	printf("\t\t\t\t\t|\tEnter\t  Cancel   \t|\n");
	printf("\t\t\t\t\t|\t-----\t  ------   \t|\n");
	printf("\t\t\t\t\t|\t\t\t\t|\n");
	printf("\t\t\t\t\t|  Login ID:    \t\t|\n");
	printf("\t\t\t\t\t|  Password:    \t\t|\n");
	printf("\t\t\t\t\t|\t\t\t\t|\n");
	printf("\t\t\t\t\t|_______________________________|\n\n");
	printf("\t\t\t\t\t\t  Login  (login)\n\t\t\t\t\t\t  Signup (signup)\n");
	printf("\t\t\t\t\t      Enter your choice: ");
	char option[50];
	gets(option);
	if(strcmp(option,"login")==0){
		login();
		delay(300);
		system("cls");
		found();
	}
	else if(strcmp(option,"signup")==0){
		signup_account();
		printf("\t\t\t\tYou have successfully created your account");
		printf("\n\t\t\t\tReturning back to main menu (Press any key)");
		getch();
		delay(300);
		system("cls");
		found();
	}
	else{
		system("cls");
		found();
	}
}