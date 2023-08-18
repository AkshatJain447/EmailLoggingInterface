#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <time.h>
#include <string.h>

int global = 0;

void delay4(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock())
		;
}

typedef struct
{
	char login_id[50];
	char login_pass[50];
} signin;

typedef struct
{
	char chk[100];
} check1;

check1 chck1[100];
signin log_in[100];
void login();
int loading(char loadname[]);
void account(char a[]);

// int main(){
//	login();
// }

void login()
{
	system("cls");
	fflush(stdin);

	// system("color FC");//FC white red and 0C black red
	printf(" Login-QuickMail \\ +\t\t\t\t\t\t\t\t\t\t\t   | X\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("<-  ->  G | http://accounts.quickmail.com/ServiceLogin?continue\t\t\t\t\t\t\tT *|..\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n\n");

	// delay(100);
	int i = 0;
	char p[200] = "\t\t\t\t\t               \"Q U I C K M A I L\"          \n\n\n";
	while (p[i] != '\0')
	{
		printf("%c", p[i]);
		i++;
	}

	printf("\t\t\t\t\t       'Sign in to continue to QuickMail'     \n");
	printf("\t\t\t\t\t____________________________________________\n");
	printf("\t\t\t\t\t|                                          |\n");
	printf("\t\t\t\t\t|              Enter   Cancel              |\n");
	printf("\t\t\t\t\t|              -----   ------              |\n");
	printf("\t\t\t\t\t|                                          |\n");
	printf("\t\t\t\t\t|   Login ID: ");
	fflush(stdin);
	gets(log_in[i].login_id);

	// for checking username exists or not
	FILE *secret;
	secret = fopen("abc.txt", "r");
	char x = 'y';
	int line_no = 1;
	int abc = 0;

	while (x != EOF)
	{
		x = fgetc(secret);
		chck1[line_no].chk[abc] = x;
		abc++;
		if (x == '\n')
		{
			line_no++;
			abc = 0;
		}

		if (x == EOF)
			break;
	}

	int flag = 0;
	int k;

	int len1 = 0, len2 = 0;
	// printf("%s",cpy_id);
	// printf("\n%s",lencnt);
	for (k = 2; k <= line_no; k += 6)
	{
		len1 = strlen(log_in[i].login_id);
		len2 = strlen(chck1[k].chk);
		chck1[k].chk[len2 - 1] = NULL;
		if (strcmp(log_in[i].login_id, chck1[k].chk) != 0)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		char opt5[3];

		printf("\t\t\t\t\t|                                          |\n");
		printf("\t\t\t\t\t|          Sorry, quickmail doesn't          |\n");
		printf("\t\t\t\t\t|           recognize that email.          |\n");
		printf("\t\t\t\t\t|__________________________________________|\n");
		printf("\t\t\t\t\t\t     Try Again?(y/n): ");
		gets(opt5);
		if (strcmp(opt5, "y") == 0 || strcmp(opt5, "Y") == 0)
		{
			login();
		}
		else if (strcmp(opt5, "n") == 0 || strcmp(opt5, "N") == 0)
		{
			exit(1);
		}
		else
		{
			printf("\t\t\t\t\t\t  Returning to main menu\t\n\t\t\t\t\t\t     (Press any key)");
			getch();
			return;
		}

	} // for password check
	else
	{

		// for checking password matched or not
		char password[50], ch;
		// strcpy(password,log[i].login_pass);
		int x = 0;

		printf("\t\t\t\t\t|                User exits                |\n");
		printf("\t\t\t\t\t|   Password: ");
		while (1)
		{
			if (x < 0)
			{
				x = 0;
			}
			ch = getch();
			if (ch == 13)
				break;
			else if (ch == 8)
			{ 
				putch('\b');
				putch(NULL);
				putch('\b');
				x--;
				continue;
			}

			log_in[i].login_pass[x++] = ch;
			ch = '*';
			putch(ch);
		}
		log_in[i].login_pass[x] = '\0';

		char str3[50];
		int len1, len = 0, len2 = 0;
		flag = 0;
		k = k + 2;
		len1 = strlen(log_in[i].login_pass);
		len2 = strlen(chck1[k].chk);

		chck1[k].chk[len2 - 1] = NULL;
		if (strcmp(log_in[i].login_pass, chck1[k].chk) != 0)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
			//				break;
		}
		if (flag == 0)
		{ // incorrect password;
			char opt6[3];

			printf("\n\t\t\t\t\t|                                          |\n");
			printf("\t\t\t\t\t|            Password InCorrect            |\n");
			printf("\t\t\t\t\t|__________________________________________|\n");
			printf("\t\t\t\t\t\t     Try Again?(y/n): ");
			gets(opt6);
			if (strcmp(opt6, "y") == 0 || strcmp(opt6, "Y") == 0)
			{
				login();
			}
			else if (strcmp(opt6, "n") == 0 || strcmp(opt6, "N") == 0)
			{
				exit(1);
			}
			else
			{
				printf("\t\t\t\t\t\t  Returning to main menu\t\n\t\t\t\t\t\t     (Press any key)\n");
				getch();
				return;
			}
		}
		else
		{
			printf("\n\t\t\t\t\t|             Password Correct             |\n");
			printf("\t\t\t\t\t|                                          |\n");
			printf("\t\t\t\t\t|__________________________________________|");
			delay4(800);

			loading(log_in[i].login_id);
			// getch();
			account(log_in[i].login_id);
		}

		fclose(secret);
	}
}

int loading(char loadname[])
{
	system("cls");
	fflush(stdin);
	char load[100] = "*************************************************|";
	printf("  Q U I C K M A I L  \\ +\t\t\t\t\t\t\t\t\t\t\t\t   | X\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("<-  ->  G | http://mail.quickmail.com   \t\t\t\t\t\t\t\t\t\tT *|..\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	int i = 0;

	printf("\n\n");
	printf("\t\t\t\t\t     Loading  %s....", loadname);
	printf("\n\t\t\t\t   ___________________________________________________");
	printf("\n\t\t\t\t   |");
	while (load[i] != '\0')
	{
		printf("%c", load[i]);
		delay4(50);
		i++;
	}

	delay4(700);
}
void account(char a[])
{
	int opt;
	char choice1[100];
	system("cls");

	// system("color FC");//FC white red and 0C black red
	printf("     Inbox        \\ +\t\t\t\t\t\t\t\t\t\t\t\t   | X\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("<-  ->  G | http://mail.quickmail.com/mail/u/service=mail#inbox   \t\t\t\t\t\tT *|..\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\tHi!, Welcome to QuickMail mails\n\n");
	printf("\n   Mail +\t|\t\t\t\t\t\t\t\t\t\t\t\t   | *");
	printf("\n            \t|\t");
	printf("\n            \t|\t");
	printf("\n            \t|\t   What you want to Do,Sir?");
	printf("\n            \t|\t");
	printf("\n            \t|\t  __________________");
	printf("\n            \t|\t  |Compose Mails  |   To send mails to friends.   (write compose)");
	printf("\n            \t|\t  ------------------");
	printf("\n            \t|\t  ___________________");
	printf("\n            \t|\t  |Received Mails  |  To check recevied mails.    (write mails)");
	printf("\n            \t|\t  -------------------");
	printf("\n            \t|\t  ______________");
	printf("\n            \t|\t  |Email Log  |       To check email log.    (write log)");
	printf("\n            \t|\t  --------------");
	printf("\n            \t|\t  ____________");
	printf("\n            \t|\t  |*Logout  |         To logout from the account. (write logout)");
	printf("\n            \t|\t  ------------");
	printf("\n            \t|");
	printf("\n            \t|\t  Enter Your choice: ");
	gets(choice1);

	// to compose mail
	if (strcmp(choice1, "compose") == 0)
	{
		system("cls");
		printf("     Inbox        \\ +\t\t\t\t\t\t\t\t\t\t\t\t   | X\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("<-  ->  G | http://mail.quickmail.com/mail/u/service=mail&continue\t\t\t\t\t\tT *|..\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t\tHi!, Welcome to QuickMail mails\n");
		printf("\n   Mail +\t|\t\t\t\t\t\t\t\t\t\t\t\t   | *");
		printf("\n            \t|");
		printf("\n            \t|\t\t\t\t\t\t\tAccount: %s", a);
		printf("\n            \t|");
		printf("\n            \t|\t  __________________");
		printf("\n            \t|\t  |Compose Mails  >|");
		printf("\n            \t|\t  ------------------");
		printf("\n            \t|");
		printf("\n            \t|");

		FILE *secret;
		secret = fopen("abc.txt", "r");
		char x = 'y';
		int line_no = 1;
		int abc = 0;

		while (x != EOF)
		{
			x = fgetc(secret);
			chck1[line_no].chk[abc] = x;
			abc++;
			if (x == '\n')
			{
				line_no++;
				abc = 0;
			}

			if (x == EOF)
				break;
		}

		int flag = 0;
		int k;

		char mail[20];
		// sending mailsss
		char text[1000];
		printf("\n            \t|\tTo: ");
		fflush(stdin);
		gets(mail);
		int acc;
		acc = strlen(mail);
		int len = 0, len2 = 0;
		for (k = 2; k <= line_no; k += 6)
		{
			len = strlen(mail);
			len2 = strlen(chck1[k].chk);
			if (strncmp(mail, chck1[k].chk, len2 - 1) != 0)
			{
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("\t\t\t\tSorry, quickmail doesn't recognize that email.\n");
			delay4(300);
			printf("\t\t\t\tRetruning back to Your account main page :)\n");
			printf("\t\t\t\t(Press any key to continue");
			getch();
			account(a);
		}

		else
		{
			mail[acc + 0] = '.';
			mail[acc + 1] = 't';
			mail[acc + 2] = 'x';
			mail[acc + 3] = 't';
			mail[acc + 4] = '\0';

			FILE *pointer;
			pointer = fopen(mail, "a");
			FILE *logFile;
			logFile = fopen("log.txt", "a");

			if (pointer != NULL)
			{
				printf("            \t|\tUser name exits");
				printf("\n            \t|\n");
				printf("            \t|\tYour text: ");
				gets(text);

				fprintf(pointer, "From: %s\n", a);
				fprintf(pointer, "%s\n", text);
				fprintf(pointer, "--------------------------------------------------------------\n");
				fclose(pointer);

				if (logFile != NULL)
				{
					fprintf(logFile, "From: %s\n", a);
					fprintf(logFile, "To: %s\n", mail);
					fprintf(logFile, "Message: %s\n", text);
					fprintf(logFile, "--------------------------------------------------------------\n");
					fclose(logFile);
				}
				else
				{
					printf("Error opening log file.\n");
				}
				system("cls");
				printf("     Inbox        \\ +\t\t\t\t\t\t\t\t\t\t\t\t   | X\n");
				printf("----------------------------------------------------------------------------------------------------------------------\n");
				printf("<-  ->  G | http://mail.quickmail.com/mail/u/service=mail&continue\t\t\t\t\t\tT *|..\n");
				printf("----------------------------------------------------------------------------------------------------------------------\n");

				delay4(400);
				printf("\n\t\t\t\t\t   Mail has been Sent.");
				printf("\n\t\t\t\t\tPress any key to continue");
				getch();
				account(a);
			}
			else
			{
				printf("User name not exits\n");
			}
		}
	}

	// 2 choice for recived mails
	else if (strcmp(choice1, "mails") == 0)
	{
		system("cls");
		printf("     Inbox        \\ +\t\t\t\t\t\t\t\t\t\t\t\t   | X\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("<-  ->  G | http://mail.quickmail.com/mail/u/service=mail&continue\t\t\t\t\t\tT *|..\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t\tHi!, Welcome to QuickMail mails\n");
		printf("\n   Mail +\t|\t\t\t\t\t\t\t\t\t\t\t\t   | *");
		printf("\n      M     \t|");
		printf("\n      A     \t|\t\t\t    Your Account: %s", a);
		printf("\n      I     \t|");
		printf("\n      L     \t|");
		printf("\n      S      \t|");
		printf("\n________________|");
		printf("\n\t  ___________________");
		printf("\n\t  |Received Mails  >|");
		printf("\n\t  -------------------\n");

		//		char array[100];
		//		strcpy(array,a);
		FILE *usraccnt2;
		int lenght = 0;

		if (global == 0)
		{
			lenght = strlen(a);
			a[lenght + 0] = '.';
			a[lenght + 1] = 't';
			a[lenght + 2] = 'x';
			a[lenght + 3] = 't';
			a[lenght + 4] = '\0';
		}
		global++;
		usraccnt2 = fopen(a, "r");
		int k = 0;
		char xyz;
		int count;
		int line = 1;
		if (usraccnt2 != NULL)
		{

			// printf("\nhello");

			while (1)
			{
				xyz = fgetc(usraccnt2);
				if (xyz == EOF)
				{
					break;
				}
				else
				{
					if (xyz == '\n')
					{
						line++;
						// printf("\n            \t|");
					}
					if (line >= 11)
					{
						printf("%c", xyz);
					}
				}
			}
			fclose(usraccnt2);
			printf("\n\n\nPress any key to return back to mail menu");
			getch();
			account(a);
		}

		else
		{
			printf("\nend");
			getch();
		}
	}
	else if (strcmp(choice1, "log") == 0)
	{
		system("cls");
		printf("     Inbox        \\ +\t\t\t\t\t\t\t\t\t\t\t\t   | X\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("<-  ->  G | http://mail.quickmail.com/mail/u/service=mail&continue\t\t\t\t\t\tT *|..\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t\tHi!, Welcome to QuickMail mails\n");
		printf("\n   Mail +\t|\t\t\t\t\t\t\t\t\t\t\t\t   | *\n");
		printf("      M     \t|\n");
		printf("      A     \t|\n");
		printf("      I     \t|\t\t\t    Email Log  >\n");
		printf("      L     \t|\n");
		printf("      S      \t|\n");
		printf("________________|\n");
		printf("\n\n");
		char opt10[3];
		FILE *logdoc;
		logdoc = fopen("log.txt", "r");
		int k = 0;
		char xyz;
		int count;
		int line = 1;
		if (logdoc != NULL)
		{
			while (1)
			{
				xyz = fgetc(logdoc);
				if (xyz == EOF)
				{
					break;
				}
				else
				{
					if (xyz == '\n')
					{
						line++;
					}
					if (line >= 0)
					{
						printf("%c", xyz);
					}
				}
			}
		}

		printf("\n\n\nEnter 's' to search any mail\n");
		printf("Enter 'd' to delete an email\n");
		printf("Enter 'x' to return back to the mail menu\n");
		fgets(opt10, sizeof(opt10), stdin);

		if (strcmp(opt10, "x\n") == 0)
		{
			fclose(logdoc);
			account(a);
		}
		else if (strcmp(opt10, "s\n") == 0)
		{
			char search[100];
			printf("\nEnter Email Id of the sender: ");
			fgets(search, sizeof(search), stdin);
			search[strcspn(search, "\n")] = '\0';
			FILE *search1;
			search1 = fopen("log.txt", "r");
			int found = 0;
			char line[1000];
			while (fgets(line, sizeof(line), search1) != NULL)
			{
				if (strstr(line, "From:") != NULL && strstr(line, search) != NULL)
				{
					found = 1;
					printf("\n");
					printf("Email from %s", line); // Print the line containing the sender's email
					while (fgets(line, sizeof(line), search1) != NULL)
					{
						if (strstr(line, "--------------------------------------------------------------") != NULL)
						{
							break; // Reached the end of the mail
						}
						printf("%s", line); // Print the mail content
					}
					printf("--------------------------------------------------------------\n");
				}
			}
			if (!found)
			{
				printf("No mails found from %s.\n", search);
			}
			fclose(search1);
			printf("\t\t\t\t     (Press any key to continue)");
			getch();
			account(a);
		}
		else if (strcmp(opt10, "d\n") == 0)
		{
			char deleteEmail[100];
			printf("\nEnter Email ID of the sender to delete the email: ");
			fgets(deleteEmail, sizeof(deleteEmail), stdin);
			deleteEmail[strcspn(deleteEmail, "\n")] = '\0';

			FILE *temp;
			temp = fopen("temp.txt","w");

			if (temp == NULL)
			{
				printf("Error opening files.\n");
				return;
			}

			int deleteFlag = 0; // Flag to indicate if email is found and deleted

			char line[1000];
			while (fgets(line, sizeof(line), logdoc) != NULL)
			{
				if (strstr(line, "From:") != NULL && strstr(line, deleteEmail) != NULL)
				{
					deleteFlag = 1;
					while (fgets(line, sizeof(line), logdoc) != NULL)
					{
						if (strstr(line, "--------------------------------------------------------------") != NULL)
						{
							break; // Reached the end of the mail
						}
					}
				}
				else
				{
					fprintf(temp, "%s", line); // Write the line to the temporary file
				}
			}

			fclose(logdoc);
			fclose(temp);

			if (deleteFlag)
			{
				if (remove("log.txt") != 0)
				{
					printf("Error deleting the email.\n");
					return;
				}

				if (rename("temp.txt", "log.txt") != 0)
				{
					printf("Error renaming the file.\n");
					return;
				}
				printf("Email(s) from %s deleted successfully.\n", deleteEmail);
			}
			else{
				printf("No emails found from %s.\n", deleteEmail);
			}
			printf("\t\t\t\t     (Press any key to continue)");
			getch();
			account(a);
			}
		}
		else if (strcmp(choice1, "logout") == 0)
		{
			system("cls");
			// system("color FC");//FC white red and 0C black red
			printf(" Login-Quickmail \\ +\t\t\t\t\t\t\t\t\t\t\t   | X\n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("<-  ->  G | http://id.logout.quickmail.com/u/service=logout&continue\t\t\t\t\t\tT *|..\n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("\n\n\t\t\t\t\tSaving your mails......\n\t\t\t\t\tWait for a while :)\n");
			delay4(400);
			printf("\t\t\t\t     (Press any key to continue)");
			getch();
			return;
			login();
		}

		else
		{
			account(a);
		}
}