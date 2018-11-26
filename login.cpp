#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdio>

void changePosition(char*,char*);
void Backup(char*);
void allUsersReporte(char* filename);
char *createEmail(char* first, char*last);
void login(char* users)
{
	///////////students/////////////
	int numberOfpeople = 0, j = 0, i = 0;
	char pass[9], password[9], type = NULL;
	while (j != 1)
	{
		ifstream file(users);
		if (!file)//if file couldnt open, throws an exception
			throw runtime_error("file is empty");
		file.close();//close the file
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

	}
	int choice;
	switch (type)
	{
		/////////menu+cin choise//////////////
	case 'A':
		cout << "-------------Menu--------------------\n1.To print all users\n";
		cout << "2.To change user classification\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			allUsersReporte("users.txt");//דוח כלל המשתמשים
		case 2:
			changePosition("yaelbu11@ac.sce.ac.il", "users.txt");
		case 3:
			createEmail("sapir", "sabahat");
		/*case 4:
			Backup();
		/*case 4:
			restartSystem();
		case 5:
			addUser();
		case 6:
			bugIinsystem();
		case 7:
			securitySystem();
		case 8:
			repot();
		case 9:
			exit;
		}
	case 'C':
		switch (choice)
		{
		case 1:
			explanationTostudent("explanation.txt");
		case 2:
			showOption();
		case 3:
			addChoiceCourse(name);
		case 4:
			changeCourse();
		case 5:
			shareTimeTable();
		case 6:
			gradeReport();
		case 7:
			TimeTableReport(name);
		}
	case 'B':
		switch (choice)
		{
		case 1:
			changePlaceNumber();
		case 2:
			addStudent();
		case 3:
			TimeTableReport2();
		case 4:
			StudentsRequest();
		case 5:
			MembersInCourse();
		case 6:
			MessageChangment();
		case 7:
			choiceCourseCancelled();
		case 8:
			addChoiceCourse2();
		case 9:
			addToExam();
		}
	}*/
		
	

		}

	}

}

char* createEmail(char* first,char*last)
{
	
	char temp[14] =  "@ac.sce.ac.il";
	int sizeF = strlen(first),i=0;
	char* arry = new char[sizeF + 19];
	for ( i = 0; i < sizeF; i++)
		arry[i] = first[i];
	for (int j = 0; j < 2; j++)
		arry[i++] = last[j];
	for (int j = 0; j < 2; j++)
	{
		arry[i++] = (rand() % 9)+'0';
	}
	for (int j = 0; j < strlen(temp); j++)
		arry[i++] = temp[j];
	arry[i] = '\0';
	return arry;
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

void changePosition(char * email,char* filename)
{
	cout << "Enter the new position to user:\n";
	char n,val[30],*s2=NULL,type,a[2]="A",b[2]="B",c[2]="C";
	cin >> n;
	ofstream newFile;
	newFile.open("new.txt");
	fstream ofs(filename,ios::in|ios::out);


	while (ofs >> val)
	{		
		newFile << val<<' ';
		if (strcmp(val, email) == 0)
		{
			ofs >> val;
			newFile << val<<' ';
			ofs >> val;
			newFile << n << ' ' << endl;

		}
		else if (strcmp(val, a)==0 || strcmp(val, b)==0 || strcmp(val, c)==0)
		{
			ofs >> val;
			newFile << endl << val<< ' ' ;
			
		}
	}
	newFile.close();
	ofs.close();
	//newFile.open("new.txt");
	
	//fstream users("users.txt", ios::out | ios::trunc);


	remove("users.txt");
	rename("new.txt", "users.txt");
	


		/*
		ifstream file(filename);
		if (!file)//if file couldnt open, throws an exception
			throw runtime_error("file is empty");
		file.close();//close the file
		file.open(filename);
		while (file >> val)
		{
			s2 = new char[strlen(val) + 1];
			strcpy(s2 ,val);
			if (strcmp(email, s2) == 0)
			{
				file >> val;
				file >> val;
				strcpy(val, n);


			}


		}*/
	
}



int main()
{
	char* fileName = NULL;

	login("users.txt");
}