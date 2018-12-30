#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdio>

typedef struct details_courses {
	char* lecture;
	char* name_course;
	details_courses* next;
};
typedef struct daysinweek {
	details_courses *courses=NULL; //head
	char* name_day;
	daysinweek* next;

};
typedef struct student {
	char* first_name;
	char* last_name;
	int ID;
	daysinweek* head = NULL;


};
typedef struct list
{
	student* data;
	list* next;
};

list *head = NULL;
void addUser();
void changePosition(char*, char*);
char login_user(char*);
void Backup(char*);
void allUsersReporte(char* filename);
char *createEmail(char* first, char*last);
void restartSystem();
void bugIinsystem();
void resetPassword(char*);
void createlist(student*);
void add_choice_courses();
void add_courses();
void create(int, char*);
void sendMessage();
void StudentRequest();
void print_timetable(int);
void add_courses();
void security();
void shareTimeTable();
void printExamTable();

void create_list_course(int id,char* day,char* nlecture, char* ncourse) {
	list* s = head;
	details_courses *temp = NULL;
	details_courses* p;
	temp = new details_courses;
	temp->lecture = new char[strlen(nlecture) + 1];
	strcpy(temp->lecture, nlecture);
	temp->name_course = new char[strlen(ncourse) + 1];
	strcpy(temp->name_course,ncourse);
	temp->next = NULL;
	while (s->data->ID != id)
	{
		s = s->next;
	}
	daysinweek* t = s->data->head;
	while (strcmp(t->name_day, day)!=0)
	{
		t = t->next;
	}
	if (t->courses == NULL) {
		t->courses = temp;
	}
	else
	{
		p = t->courses;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
}
void timeTableOption()
{
	list* s = NULL;
	int id, choise;
	char FSE[4] = { "FSE" }, PSE[4] = { "PSE" }, AFL[4] = { "AFL" }, stuct[15] = { "data structure" }, FSEp[6] = { "FSE-p" }, PSEp[6] = { "PSE-p" }, DSL[17] = { "data structure-l" }, AFLp[6] = { "AFL-p" };
	char* option1 = "\nFSE-Foundations of software engineering\nPSE-Principle of software engineering\nAFL-Automata and formal languages\n---------------------------------------------------------------------------------------------------\nSunday\t\t|Monday\t\t\t|Tuesday\t\t|Wednesday\t\t|Thursday\nFSE-practice\t|PSE-lab\t\t|Data structure\t\t|AFL\t\t\t|\n\t\t|FSE\t\t\t|PSE\t\t\t|\t\t\t|\n\t\t|Data structure-lab\t|\t\t\t|AFL-practice\t\t|\n\t\t|\t\t\t|\t\t\t|\t\t\t|\n-------------------------------------------------------------------------------------------------\n";
	char* option2 = "\nFSE-Foundations of software engineering\nPSE-Principle of software engineering\nAFL-Automata and formal languages\n---------------------------------------------------------------------------------------------------------------\nSunday\t\t\t|Monday\t\t\t|Tuesday\t\t|Wednesday\t\t|Thursday\nFSE-practice\t\t|PSE-lab\t\t|Data structure\t\t|\t\t\t|\nFSE\t\t\t|AFL\t\t\t|PSE\t\t\t|\t\t\t|\nData structure-lab\t|\t\t\t|AFL-practice\t\t|\t\t\t|\n\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n------------------------------------------------------------------------------------------------------\n";
	char* option3 = "\nFSE-Foundations of software engineering\nPSE-Principle of software engineering\nAFL-Automata and formal languages\n---------------------------------------------------------------------------------------------------------------\nSunday\t\t\t|Monday\t\t\t|Tuesday\t\t|Wednesday\t\t|Thursday\nFSE\t\t\t|AFL\t\t\t|Data structure\t\t|\t\t\t|PSE-lab\nData structure-lab\t|\t\t\t|AFL-practice\t\t|PSE\t\t\t|\n\t\t\t|FSE-practice\t\t|\t\t\t|\t\t\t|\n\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t\n------------------------------------------------------------------------------------------------------\n";

	cout << "Enter your id->\n";
	cin >> id;
	cout << "\nEnter 1 to see another option and 0 to choose the current timetable\n";
	while (true)
	{
		cout << option1;
		cin >> choise;
		while (choise != 1 && choise != 0)
		{
			cout << "Incorrect!choose 1 or 0 .";
			cin >> choise;
		}
		if (choise == 0)
		{
			cout << "0" << endl;
			create(id, "sunday");
			cout << "1" << endl;
			create_list_course(id, "sunday", "Isabel Meif", "FSE-practice");
			cout << "2" << endl;
			create(id, "monday");
			cout << "3" << endl;
			create_list_course(id, "monday", "Hadas Hasidim", "FSE");
			cout << "4" << endl;
			create_list_course(id, "monday", "Svetlana Rusin", "PSE-lab");
			cout << "5" << endl;
			create_list_course(id, "monday", "Avishai Kraif", "Data struction-lab");
			cout << "6" << endl;
			create(id, "tuesday");
			cout << "7" << endl;
			create_list_course(id, "tuesday", "Irena revayev", "Data struction");
			cout << "8" << endl;
			create_list_course(id, "tuesday", "Marina Litbak", "PSE");
			cout << "9" << endl;
			create(id, "wednesday");
			create_list_course(id, "wednesday", "Alexander Chorkin", "AFL");
			create_list_course(id, "wednesday", "Alexander Shkolnik", "AFL-lab");
			create(id, "thursday");
			create(id, "friday");
			cout << "done!" << endl;


			break;
		}
		system("cls");
		cout << option2;
		cin >> choise;
		while (choise != 1 && choise != 0)
		{
			cout << "Incorrect!choose 1 or 0 .";
			cin >> choise;
		}
		if (choise == 0)
		{
			create(id, "sunday");
			create_list_course(id, "sunday", "Isabel Meif", "FSE-practice");
			create_list_course(id, "sunday", "Hadas Hasidim", "FSE");
			create_list_course(id, "sunday", "Avishai Kraif", "Data struction-lab");
			create(id, "monday");
			create_list_course(id, "monday", "Svetlana Rusin", "PSE-lab");
			create_list_course(id, "monday", "Alexander Chorkin", "AFL");
			create(id, "tuesday");
			create_list_course(id, "tuesday", "Irena revayev", "Data struction");
			create_list_course(id, "tuesday", "Marina Litbak", "PSE");
			create_list_course(id, "tuesday", "Alexander Shkolnik", "AFL-lab");
			create(id, "wednesday");
			create(id, "thursday");
			create(id, "friday");

			break;

		}
		system("cls");
		cout << option3;
		cin >> choise;
		while (choise != 1 && choise != 0)
		{
			cout << "Incorrect!choose 1 or 0 .";
			cin >> choise;
		}
		if (choise == 0)
		{
			create(id, "sunday");
			create_list_course(id, "sunday", "Hadas Hasidim", "FSE");
			create_list_course(id, "sunday", "Avishai Kraif", "Data struction-lab");
			create(id, "monday");
			create_list_course(id, "monday", "Alexander Chorkin", "AFL");
			create_list_course(id, "monday", "Isabel Meif", "FSE-practice");
			create(id, "tuesday");
			create_list_course(id, "tuesday", "Irena revayev", "Data struction");
			create_list_course(id, "tuesday", "Alexander Shkolnik", "AFL-lab");
			create(id, "wednesday");
			create_list_course(id, "wedneday", "Marina Litbak", "PSE");
			create(id, "thursday");
			create_list_course(id, "thursday", "Svetlana Rusin", "PSE-lab");
			create(id, "friday");
			break;
		}
		system("cls");
	}


}
void create(int id, char* day) {
	list* s=head;
	daysinweek *temp = NULL;
	daysinweek* p;
	temp = new daysinweek;
	temp->name_day = new char[strlen(day)+1];
	strcpy(temp->name_day, day);
	temp->next = NULL;
	while (s->data->ID != id)
	{
		s = s->next;
	}
	if (s->data->head == NULL) {
		s->data->head = temp;
	}
	else
	{
		p = s->data->head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
}
void StudentRequest()
{
	cout << "Name:Nofar Hadad\tSubject:special exam date\nName:Nir Ben-Shimon\tSubject:exemption from course\nName:Liza Gold\tSubject:Realesed from blocking course\nName:Hadas Hasidim\tSubject:Postponing the submission of work.\n" << endl;
	cout << "Report has been sent to print\n";




}
char login_user(char* users) {
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
		return type;

	}

}
void login(char* users)
{
	int id;
	char user[30];
	char type;
	bool checking = true;
	while (checking)
	{

		type = login_user(users);
		int choice;


		switch (type)
		{
			/////////menu+cin choise//////////////
			case 'A':
			{
				do
				{
					cout << "-------------Menu--------------------\n1.To print all users\n";
					cout << "2.To change user classification\n3.To backup the system\n4.To restart the system\n";
					cout << "5.To add user\n6.To producing a computer BUGS report\n7.To reset password\n";
					cout << "8.security system suplied\n"<<"9. exit from the system" << endl;
					cin >> choice;
					switch (choice)
					{
						case 1:
						{
							system("cls");
							allUsersReporte("users.txt");//דוח כלל המשתמשים

							break;
						}
						case 2:
						{
							system("cls");
							cout << "Enter username:" << endl;
							cin >> user;
							changePosition(user, "users.txt");
							break;
						}
						case 3:
						{
							system("cls");
							Backup("users.txt");
							break;
						}
						case 4:
						{
							system("cls");
							restartSystem();
							break;
						}
						case 5:
						{
							system("cls");
							addUser();
							break;
						}
						case 6:
						{
							system("cls");
							bugIinsystem();
							break;
						}
						case 7:
						{
							system("cls");
							resetPassword(users);
							break;
						}
						case 8:
						{
							system("cls");
							security();
							break;
						}
						case 9:
						{
							system("cls");
							cout << "goodbye user!" << endl;
							break;
						}
						case 10:
						{
							system("cls");
							cout << "goodbye!" << endl;
							exit(1);
						}
						default: {
							cout << "Wrong choice!" << endl;

						}
					}//end {} of switch.
					system("cls");
				} while (choice != 9);
				break;//to end switch case
			}
			case 'B':
			{
				do
				{
				cout << "-----------------------Secratery Menu--------------------\n1.To change number of people in course\n";
				cout << "2.To add student to course\n3.To print time table\n4.To print Students Request report\n";
				cout << "5.To see number of people in course\n6.To send message about course changes\n";
				cout << "7.To cancel elective course\n8.To ading an elective course\n";
				cout << "9.To add student to exam list\n10.Exit\n";
				cin >> choice;

					switch (choice)
					{
						/*case 1:
							ChangeNumInCours();
						case 2:
							add_courses();*/
					case 3:
					{
						system("cls");
						cout << "Enter student's id:" << endl;
						cin >> id;
						print_timetable(id);
						break;
					}
					case 4:
					{
						system("cls");
						StudentRequest();
						break;
					}	/*
					case 5:
						numStudentIncourse();
						*/
					case 6:
					{
						system("cls");
						sendMessage();
						break;
					}	/*
					case 7:
						DeleteChoiseCourse();
						*/
					case 8:
					{
						system("cls");
						add_choice_courses();
						break;
					}	/*
					case 9:
						addExamList();
						*/
					case 10:
					{
						system("cls");
						cout << "goodbye!" << endl;
						break;
					}
					default:{
						cout << "Wrong choice!" << endl;
					
					}

					}
				} while (choice!=10);
				break;//to end switch case

			}
			case 'C':
			{
				do {
				cout << "-------------------------Student Menu----------------------------\n1.for a user guide\n";
				cout << "2.To see option for timetable\n3.To ading an elective course\n4.To change course in the timetable\n";
				cout << "5.To share your timetable\n6.To print grade report\n7.To print your timetable\n";
				cout << "8.To print test board\n9.To login with anothe user\n";
				cin >> choice;



					switch (choice)
					{
					case 1:
					{
						system("cls");
						cout << "User guide :\n\noption 1: the system will give you an option\n to random timetable for your choice ', and the given\n timetable will show on the screen.\nyou can approve the given timetable by saving\n data or choose to show you another random tinmeable.\nfor every Option of the system you can go back to main menu." << endl << endl;
						cout << "option 2 :the system will give you an option for Manual registration / change course as you want.\nan option will give you to add\n regular courses / add choice courses - every option will appear on the screen.\nAfter selecting the option you want - a list of courses will appear for adding or removing .\n**each step will be given an option to go back to the main menu.\nFor Additional inquiries or more information, please contact the Registrar" << endl;
						cout << "phone:08-7435612, E-mail: einavmal11@ac.sce.ac.il\ngood luck!" << endl;
						break;
					}
					case 2:
					{
						system("cls");
						timeTableOption();
						break;
					}
					case 4:
					{
						system("cls");
						add_courses();
						cout << "Enter student's id:" << endl;
						cin >> id;
						print_timetable(id);

						break;
					}
					case 5:
					{
						system("cls");
						shareTimeTable();
						break;
					}
					case 7:
					{
						system("cls");
						cout << "Enter student's id:" << endl;
						cin >> id;
						print_timetable(id);
						break;
					}
					case 8:
					{
						system("cls");
						printExamTable();
						break;
					}
					case 9:
					{
						system("cls");
						cout << "goodbye!" << endl;
						break;
					}
					default: {
						cout << "Wrong choice!" << endl;
					}
							 break;
					}
				} while (choice!=9);
				break;//to end switch case
			}
		}
	}
}
void security()
{
	cout << "Activation Security system gone successfuly " << endl;
}

void shareTimeTable()
{
	cout << "Time table has been sent to your email !" << endl;
}

void printExamTable()
{
	cout << "--------------------------------------------------------------------------------------------\nExam\t\t\t\t\tDate\t\t\tDay\t\t\tA/B|\n";
	cout << "Principles of language software\t\t16/1/2019\t\tWednesday\t\tA  |\nAutomata and formal languages\t\t22/1/2019\t\tTuesday\t\t\tA  |\n";
	cout << "Data structure\t\t\t\t5/2/2019\t\tTuesday\t\t\tA  |\nPrinciples of language software\t\t11/2/2019\t\tMonday\t\t\tB  |\n";
	cout << "Automata and formal languages\t\t14/2/2019\t\tThursday\t\tB  |\nData structure\t\t\t\t25/2/2019\t\tMonday\t\t\t\B  |\n--------------------------------------------------------------------------------------------\n";

}
void sendMessage()
{
	int choose;
	char message[100] ,*message2;
	cout << "Choose what kind of message you want to send\n1.A lesson is cancelled\n2.Change in lesson\n";
	cin >> choose;
	cout << "Enter message:"<<endl;
	cin >> message;
	message2 = new char[strlen(message) + 1];
	if(choose==1)
	cout << "The message: ''" << message << "''\non cancle lesson has been send !" << endl;
	if (choose == 2)
		cout << "The message:  ''" << message << "''\non Change in course has been send !" << endl;
}
void createlist(student* a) {
	list *temp = NULL;
	list* p;
	temp = new list;
	temp->data = a;
	temp->next = NULL;
	if (head == NULL) {

		head = temp;
	}
	else
	{
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}


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
	student *temp = new student;
	temp->first_name = new char[strlen(name)];
	strcpy(temp->first_name,name);

	temp->last_name = new char[strlen(last)];
	strcpy(temp->last_name, last);
	temp->ID = id;
	createlist(temp);

}
void add_choice_courses() {

	int choice, id;
	cout << "add choice courses:\n1. English with Roman in sunday\n2. English with Gabriel in friday\n3. Tenis with Ariel in monday\n4.frence with Yael in wednesday\n5. wine with Sapir in thursday" << endl;
	cin >> choice;
	cout << "enter id:" << endl;
	cin >> id;
	list* s = head;
	details_courses *course_choice = new details_courses;
	switch (choice)
	{
	case 1:
	{
		while (s->data->ID!=id)
		{
			s = s->next;
		}
		char name_lecture[6] = { "Roman" };
		char name_course[] = { "English" };
		char day[] = { "sunday" };
		course_choice->lecture = name_lecture;
		course_choice->name_course = name_course;
		course_choice->next = NULL;
		create(id,day);
		break;
	}
	case 2: {
		while (s->data->ID != id)
		{
			s = s->next;
		}
		char name_lecture[] = { "Gabriel" };
		char name_course[] = { "English" };
		char day[] = { "friday" };
		course_choice->lecture = name_lecture;
		course_choice->name_course = name_course;
		course_choice->next = NULL;
		create(id, day);
		break;
	}
	case 3:
	{
		while (s->data->ID != id)
		{
			s = s->next;
		}
		char name_lecture[] = { "Ariel" };
		char name_course[] = { "Tenis" };
		char day[] = { "monday" };
		course_choice->lecture = name_lecture;
		course_choice->name_course = name_course;
		course_choice->next = NULL;
		create(id, day);
		break;
	}
	case 4:
	{
		while (s->data->ID != id)
		{
			s = s->next;
		}
		char name_lecture[] = { "Yael" };
		char name_course[] = { "Frence" };
		char day[] = { "wednesday" };
		course_choice->lecture = name_lecture;
		course_choice->name_course = name_course;
		course_choice->next = NULL;
		create(id, day);
		break;
	}
	case 5:
	{
		while (s->data->ID != id)
		{
			s = s->next;
		}
		char name_lecture[] = { "Sapir" };
		char name_course[] = { "Wine" };
		char day[] = { "thursday" };
		course_choice->lecture = name_lecture;
		course_choice->name_course = name_course;
		course_choice->next = NULL;
		create(id, day);
		break;
	}

	default:
		break;
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
void changePosition(char * email, char* filename)
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
void print_timetable(int id) 
{
	int num = 0;
	list *s = head;
	while (s->data->ID!=id)
	{
		s = s->next;
	}
	daysinweek *t = s->data->head;

	while (t->next!=NULL)
	{
		cout << "-----------------------------------------------" << endl;
		cout << t->name_day << " :" << endl;
		details_courses *k = t->courses;
		num = 0;
		if (k!=NULL)
		{
			while (k!=NULL)
			{
				num++;
				cout << k->name_course << " with " << k->lecture << endl;
				k = k->next;
			}
			t = t->next;
		}
		else
		{
			cout << "Day off!" << endl;
			t = t->next;


		}

	}


}
void check(int id, char* subject) 
{
	int h = 0;
	list *s = head;

	
	while (s->data->ID != id)
	{
		s = s->next;
	}

	daysinweek *t = s->data->head; //t =יום
	while (t!=NULL)
	{
		details_courses *course = t->courses;			//מצביע לקורסים של אותו יום
		if (course != NULL)
		{
			if (course->next != NULL)
			{
				if (strcmp(course->name_course, subject) == 0)
				{
					s->data->head->courses = course->next;
					delete course->lecture;
					delete course->name_course;
					delete course;
					course = NULL;
					break;
				}
				else
				{
					details_courses *pos = course;
					details_courses *sop = course->next;			//התא הבא
					while (sop != NULL)
					{

						if (strcmp(sop->name_course, subject) == 0)
						{
							pos->next = sop->next;
							delete sop->lecture;
							delete sop->name_course;
							delete sop;

							break;
						}
						pos = pos->next;
						sop = sop->next;
					}
				}
			}
		}
		t = t->next;
	}
}
void add_courses() {
	int id,choice;
	cout << "Enter student's id: " << endl;
	cin >> id;
	cout << "Courses(Lectures):\n1.AFL- Sunday\t\t\t2.AFL-Monday\t\t\t3.AFL-Wedneaday\n4.PSE-Monday\t\t\t5.PSE-Tuesday\n6.FSE-Sunday\t\t\t7.FSE-Thursday\n8.Data structure-Tuesday\t\t\t9.Data structure-Wednesday" << endl;
	cout << "Courses(Lab/Practice):\n10.AFL- Sunday\t\t\t11.AFL-Monday\t\t\t12.AFL-Tuesday\n13.PSE-Monday\t\t14.PSE-Wednesday\n15.FSE-Sunday\t\t16.FSE-Monday\n17.Data structure-Sunday\t\t18.Data structure-Monday\t\t19.Data structure-Tuesday" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		check(id, "AFL");
		create_list_course(id, "sunday", "Alexander chorkin", "AFL");
		break;
	}
	case 2:
	{
		check(id, "AFL");
		create_list_course(id, "monday", "Alexander chorkin", "AFL");
		break;
	}
	case 3: 
	{
		check(id, "AFL");
		create_list_course(id, "wednesday", "Alexander chorkin", "AFL");
		break;
	}
	case 4: 
	{
		check(id, "PSE");
		create_list_course(id, "monday", "Marina litbak", "PSE");
		break;
	}
	case 5: 
	{
		check(id, "PSE");
		create_list_course(id, "tuesday", "Marina litbak", "PSE");
		break;
	}
	case 6: 
	{
		check(id, "FSE");
		create_list_course(id, "sunday", "Hadas hasidim", "FSE");

		break;
	}
	case 7: 
	{
		check(id, "FSE");
		create_list_course(id, "thursday", "Hadas Hasidim ", "FSE");
		break;
	}
	case 8: 
	{
		check(id, "Data structure");
		create_list_course(id, "tuesday", "Irena Revayev", "Data structure");
		break;
	}
	case 9: 
	{
		check(id, "Data structure");
		create_list_course(id, "wednesday", "Irena Revayev", "Data structure");
		break;
	}
	case 10:
	{
		check(id, "AFL-lab");
		create_list_course(id, "sunday", "Alexander Shkolnik", "AFL-lab");

		break;
	}
	case 11:
	{
		check(id, "AFL-lab");
		create_list_course(id, "monday", "Alexander Shkolnik", "AFL-lab");

		break;
	}
	case 12: 
	{
		check(id, "AFL-lab");
		create_list_course(id, "tuesday", "Alexander Shkolnik", "AFL-lab");
		break;
	}
	case 13:
	{
		check(id, "PSE-lab");
		create_list_course(id, "monday", "Svetlana Rusin", "PSE-lab");
		break;
	}
	case 14: 
	{
		check(id, "PSE-lab");
		create_list_course(id, "wednesday", "Svetlana Rusin", "PSE-lab");

		break;
	}
	case 15: 
	{
		check(id, "FSE-practice");
		create_list_course(id, "sunday", "Isabel meif", "FSE-practice");

		break;
	}
	case 16:
	{
		check(id, "FSE-practice");
		create_list_course(id, "monday", "Isabel meif", "FSE-practice");

		break;
	}
	case 17:
	{
		check(id, "Data structure-lab");
		create_list_course(id, "sunday", "Avishay Kraif", "Data structure-lab");

		break;
	}
	case 18: 
	{
		check(id, "Data structure-lab");
		create_list_course(id, "monday", "Avishay Kraif", "Data structure-lab");

		break;
	}
	case 19:
	{
		check(id, "Data structure-lab");
		create_list_course(id, "tuesday", "Avishay Kraif", "Data structure-lab");
		break;
	}

	default: {
		cout << "Wrong choice!" << endl;
	}
		break;
	}


}
int main()
{
	char* fileName = NULL;

	login("users.txt");
}