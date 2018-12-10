#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdio>

void changePosition(char*, char*);
void Backup(char*);
void restartSystem();
void allUsersReporte(char*);
char *createEmail(char* first, char*last);
void bugIinsystem();
void resetPassword(char*);
void addUser();


void Login(char*users)
{
	int numberOfpeople = 0, j = 0, i = 0;
	char pass[9], password[9], type = NULL;
	int choice = 0;
	while (j != 1)
	{
		ifstream file(users);
		if (!file)
			throw runtime_error("file is empty");
		file.close();
		file.open(users);
		char name[30], val[30], *s1 = NULL, *s2 = NULL;
		cout << "Enter username\n";
		cin >> name;
		s1 = new char[strlen(name) + 1];
		strcpy(s1, name);
		cout << "Enter password:\n";
		cin >> password;
		while (file >> val)
		{

			s2 = new char[strlen(val) + 1];
			strcpy(s2, val);
			if (strcmp(s1, s2) == 0)
			{

				file >> pass;
				if (strcmp(pass, password) == 0)
				{
					j = 1;
					file >> pass;
					if (pass[0] == 'A')
						type = 'A';
					else if (pass[0] == 'B')
						type = 'B';
					else if (pass[0] == 'C')
						type = 'C';
					break;
				}
				cout << "incorrect password!" << endl;
			}
		}
		delete s1;
		delete s2;

		file.close();//close the file
		switch (type)
		{
			/////////menu+cin choise//////////////
		case 'A':
		 do {
			cout << "-------------Menu--------------------\n1.To print all users\n";
			cout << "2.To change user classification\n3.To backup the system\n4.To restart the system\n";
			cout << "6.To producing a computer BUGS report\n7.To reset password\n";
			cin >> choice;
			switch (choice)
			{
			case 1:break; allUsersReporte("users.txt"); break;
			case 2:changePosition("yaelbu11@ac.sce.ac.il", "users.txt"); break;
			case 3:Backup("users.txt"); break;
			case 4:restartSystem(); break;
			case 5:addUser(); break;
					//createEmail("sapir", "sabahat");
			case 6:bugIinsystem();break;
					//bugIinsystem();
			case 7: resetPassword("users.txt");break;
					//resetPassword("users.txt");
			/*case 8:repot(); break;*/
			case 9:exit;
			}
		 } while (choice != 9);

		case 'B':
			do {
				cout << "-----------------------Secratery Menu--------------------\n1.To change number of people in course\n";
				cout << "2.To add student to course\n3.To print time table\n4.To print Students Request report\n";
				cout << "5.To see number of people in course\n6.To send message about course changes\n";
				cout << "7.To cancel elective course\n8.To ading an elective course\n";
				cout << "9.To add student to exam list\n10.Exit\n";
				cin >> choice;
				/*
				switch (choice)
				{
				case 1:
				changePlaceNumber();
				break;
				case 2:
				addStudent();
				break;
				case 3:
				TimeTableReport2();
				break;
				case 4:
				StudentsRequest();
				break;
				case 5:
				MembersInCourse();
				break;
				case 6:
				MessageChangment();
				break;
				case 7:
				choiceCourseCancelled();
				break;
				case 8:
				addChoiceCourse2();
				break;
				case 9:
				addToExam();
				break;
				case 10:
				exit();
				}*/
			} while (choice != 10);
		}
			}while (choice != 9 || choice != 10);
}

int main()
{
	char* fileName = NULL;
	Login("users.txt");
}


void changePosition(char*email, char*filename)
{
	cout << "Enter the new position to user:\n";
	char n, val[30], *s2 = NULL, type, a[2] = "A", b[2] = "B", c[2] = "C";
	cin >> n;
	ofstream newFile;
	newFile.open("new.txt");
	fstream ofs(filename, ios::in | ios::out);
	if (!filename)//if file couldnt open, throws an exception
		throw runtime_error("file is empty");

	while (ofs >> val)
	{
		newFile << val << ' ';
		if (strcmp(val, email) == 0)
		{
			ofs >> val;
			newFile << val << ' ';
			ofs >> val;
			newFile << n << ' ' << endl;

		}
		else if (strcmp(val, a) == 0 || strcmp(val, b) == 0 || strcmp(val, c) == 0)
		{
			ofs >> val;
			newFile << endl << val << ' ';

		}
	}
	newFile.close();
	ofs.close();
	remove("users.txt");
	rename("new.txt", "users.txt");
}

void Backup(char* filename)
{
	ofstream backup;
	backup.open("BackUpUsers.txt");
	fstream usresOriginal(filename);
	char val[30], a[2] = "A", b[2] = "B", c[2] = "C";
	if (backup)
	{
		fstream backup("BackUpUsers.txt", ios::out | ios::trunc);
		while (usresOriginal >> val)
		{
			backup << val << ' ';
			if (strcmp(val, a) == 0 || strcmp(val, b) == 0 || strcmp(val, c) == 0)
			{
				usresOriginal >> val;
				backup << endl << val << ' ';

			}
		}

		backup.close();
		usresOriginal.close();
	}
	else
	{
		while (usresOriginal >> val)
		{
			backup << val << ' ';
			if (strcmp(val, a) == 0 || strcmp(val, b) == 0 || strcmp(val, c) == 0)
			{
				usresOriginal >> val;
				backup << endl << val << ' ';

			}
		}

		backup.close();
		usresOriginal.close();


	}
}

void restartSystem()
{
	Backup("users.txt");
	fstream restart("users.txt", ios::out | ios::trunc);
	restart.close();
}


void allUsersReporte(char* filename)
{
	char val;
	ifstream file(filename);
	if (!file)//if file couldnt open, throws an exception
		throw runtime_error("file is empty");
	file.close();//close the file
	file.open(filename);

	while (!file.eof()) {
		if (filename) {

			string val;
			getline(file, val);
			cout << val;
		}
		cout << endl;
	}
}


char* createEmail(char* first, char*last)
{

	char temp[14] = "@ac.sce.ac.il";
	int sizeF = strlen(first), i = 0;
	char* arry = new char[sizeF + 19];
	for (i = 0; i < sizeF; i++)
		arry[i] = first[i];
	for (int j = 0; j < 2; j++)
		arry[i++] = last[j];
	for (int j = 0; j < 2; j++)
	{
		arry[i++] = (rand() % 9) + '0';
	}
	for (int j = 0; j < strlen(temp); j++)
		arry[i++] = temp[j];
	arry[i] = '\0';
	return arry;
}

void bugIinsystem()
{
	int month = 0;
	char numberRepot[6];
	cout << "Enter the month in which you want to see the bug report\n";
	cin >> month;
	while (month <= 0 || month > 12)
	{
		cout << "Incorrect input. enter again: ";
		cin >> month;
	}
	cout << "Select the report number\n";
	cout << "1001A- Processes data\n1003A- Produces output\n9991B- System virus\n9992B- Security breaches\n-->";
	cin >> numberRepot;

	while (strcmp(numberRepot, "1001A") == 1 && (strcmp(numberRepot, "1003A")) == 1 && (strcmp(numberRepot, "9991B")) == 1 && (strcmp(numberRepot, "9992B")) == 1)
	{
		cout << "This report does not exist Please enter an existing report from the list\n";
		cin >> numberRepot;
	}


	cout << "\nIn month[" << month << "], " << "4 bugs were detected.\na detailed report was sent for printing.\n";

}

void resetPassword(char* filename)
{
	char user[30], val[30], *s2 = NULL, NewPass[9], a[2] = "A", b[2] = "B", c[2] = "C";
	int check = 0, j = 0;
	cout << "Enter the user name to reset the password:\n";
	cin >> user;
	cout << "Enter the new password:\n(start with capital letter,contain at least 1 digit and 1 small letter)";
	cin >> NewPass;
	ofstream newFile;
	newFile.open("new.txt");
	fstream ofs(filename, ios::in | ios::out);
	if (!filename)//if file couldnt open, throws an exception
		throw runtime_error("file is empty");
	do {
		j = 1;
		while (strlen(NewPass) < 8)
		{
			cout << "A password must have 8 characters\nEnter again: ";
			cin >> NewPass;
			j = 0;
		}
		while (NewPass[0]<'A' || NewPass[0]>'Z')
		{
			cout << "Password must begin with a capital letter\nEnter again: ";
			cin >> NewPass;
			j = 0;
		}

		while ((NewPass[0]<'A' || NewPass[0]>'Z') && (NewPass[1]<'A' || NewPass[1]>'Z') && (NewPass[2]<'A' || NewPass[2]>'Z') && (NewPass[3]<'A' || NewPass[3]>'Z') && (NewPass[4]<'A' || NewPass[4]>'Z') && (NewPass[5]<'A' || NewPass[5]>'Z') && (NewPass[6]<'A' || NewPass[6]>'Z') && (NewPass[7]<'A' || NewPass[7]>'Z'))
		{
			cout << "A password must contain a small letter\nEnter again: ";
			cin >> NewPass;
			j = 0;
		}

	} while (j == 0);
	while (ofs >> val)
	{
		newFile << val << ' ';
		if (strcmp(val, user) == 0)
		{
			ofs >> val;
			newFile << NewPass << ' ';

		}
		else if (strcmp(val, a) == 0 || strcmp(val, b) == 0 || strcmp(val, c) == 0)
		{
			newFile << endl;

		}
	}
	newFile.close();
	ofs.close();
	remove("users.txt");
	rename("new.txt", "users.txt");
}

void addUser() {
	int  size, id;
	char temp1[100], temp2[100], *name, *last, password[9] = { "Ee123456" }, *mail, position;
	cout << "enter first name:" << endl;
	cin >> temp1;
	size = strlen(temp1);
	name = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		name[i] = temp1[i];
	}
	cout << "enter last name:" << endl;
	cin >> temp2;
	size = strlen(temp2);
	last = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		last[i] = temp2[i];
	}
	cout << "enter id:" << endl;
	cin >> id;
	mail = createEmail(name, last);
	cout << "enter position\n";
	cin >> position;
	//write in user's data-base.
	ofstream file1;
	file1.open("users.txt", ios::app);
	file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << position;
	file1.close();
	//write in the data-base matches him.
	if (position == 'A')
	{
		file1.open("info.txt", ios::app);
		file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << position;
		file1.close();
	}
	else if (position == 'B')
	{
		file1.open("secretary.txt", ios::app);
		file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << position;
		file1.close();
	}
	else
	{
		file1.open("students.txt", ios::app);
		file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << position;
		file1.close();
	}
}