#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <time.h>
#include <cstdio>
#include <cmath>



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
	int count =0;
	daysinweek* head = NULL;


};
typedef struct list
{
	student* data;
	list* next;
};

list *head = NULL;
int CountFSE = 10;
int CountFSEP = 10;
int CountPSE = 10;
int CountPSEL = 10;
int CountAFL = 10;
int CountAFLL = 10;
int CountDatastruc = 10;
int CountDatastrucL = 10;
int CountEnglishR = 5;
int CountEnglishG = 5;
int CountTenis = 5;
int CountFrench = 5;
int CountWine = 5;

bool checkID_adduser(int);
void timeTableOption(int);
void addUser();
void check(int, char*, int&);
void changePosition(char*, char*);
char login_user(char*);
void Backup(char*);
void allUsersReporte(char* filename);
char *createEmail(char* first, char*last);
void restartSystem();
void bugIinsystem();
void resetPassword(char*);
void createlist(student*);
void add_choice_courses(int id);
void add_courses();
void create(int, char*);
void sendMessage();
void StudentRequest();
void print_timetable(int);
void add_courses();
void security();
void shareTimeTable();
void printExamTable(int id,char* = NULL , char* = NULL, char* = NULL, char* = NULL);
int DeleteChoiseCourse(int,char*);
void numStudentIncourse();
void ReportusersLogin(char*);
void printReportUS(char *);
void Changecountplaces(int, int, int&);
void Change_num_place();
bool check_place(int);
void create_list_course(int, char*, char* , char* , int&);
void Gradeprint(int);
bool CheckID(int);
bool exist_in_file(char*);
char* convert_to_char(int);

bool exist_in_file(char* id)
{
	char val[30], *s2;
	ifstream file("students.txt");
	if (!file)//if file couldnt open, throws an exception
		throw runtime_error("file is empty");
	file.close();//close the file
	file.open("students.txt");
	while (file >> val)
	{
		s2 = new char[strlen(val) + 1];
		strcpy(s2, val);
		if (strcmp(id, s2) == 0)			//אם הת.ז קיימת בקובץ של הסטודנטים
		{
	
			return false;
		}
	}
	return true;
}
char* convert_to_char(int id) {
	char Id[10] = {};
	for (int i = 8; i >= 0; i--)
	{

		Id[i] = (id % 10) + '0';
		id = id / 10;
	}

	Id[9] = '\0';
	return Id;
}
void Gradeprint(int id) {
	char*ID = new char[10];
	strcpy(ID, convert_to_char(id));
	string Id;
	Id = ID;
	ofstream Gfile(string(Id + "Grade.txt").c_str(), ios::app);
	srand((unsigned)time(NULL));
	cout << "FSE-Foundations of software engineering" << endl;
	cout <<"PSE - Principle of software engineering" << endl;
	cout << "AFL - Automata and formal languages" << endl;
	Gfile << "------------------------------------------------------------------------------------------------ - " << endl;
	Gfile << "COURSE\t\t | LECTURE\t\t | GRADE" << endl;
	Gfile<<"------------------------------------------------------------------------------------------------ - "<<endl;
	Gfile << "Data structure\t|Irena revayev\t\t|" << rand() % (101 - 20) + 20 << endl;
	Gfile << "AFL\t\t|Alexander Chorkin\t\t|" << rand() % (101 - 20) + 20 << endl;
	Gfile << "FSE\t\t|Hadas Hasidim\t\t|" << rand() % (101 - 20) + 20 << endl;
	Gfile << "PSE\t\t|Marina Litbak\t\t|" << rand() % (101 - 20) + 20 << endl;
	Gfile << "\t\t|\t\t\t|\t" << endl;
	Gfile.close();
	cout << "do you want to print the report?\n(y-yes,n-no)" << endl;
	char cha;
	cin >> cha;
	if (cha='y')
	{
		ifstream e(string(Id + "Grade.txt").c_str());
		string f;
		while (getline(e, f))
		{
			cout << f;
		}
		e.close();
	}
	
}

void Change_num_place() {
	int choice, num, dori;
	cout << "please enter number to Increase or decrease the number of students in the course" << endl;
	cin >> num;
	cout << "enter 1-to Increase \n 2-to decrease" << endl;
	cin >> dori;
	cout << "please enter your menu choise(1-9)" << endl;
	do
	{
		cout << "-------------course Menu-----------------\n1.FSE\n";
		cout << "2.FSE-practice\n3.PSE\n4.PSE-lab\n";
		cout << "5.AFL\n6.AFL-lab\n7.Data struction\n";
		cout << "8.Data struction-lab\n" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			Changecountplaces(num, dori, CountFSE);
			cout << CountFSE << endl;
			exit(1);
			break;
		}
		case 2:
		{
			system("cls");
			Changecountplaces(num, dori, CountFSEP);
			exit(1);
			break;
		}
		case 3:
		{
			system("cls");
			Changecountplaces(num, dori, CountPSE);
			exit(1);
			break;
		}
		case 4:
		{
			system("cls");
			Changecountplaces(num, dori, CountPSEL);
			exit(1);
			break;
		}
		case 5:
		{
			system("cls");
			Changecountplaces(num, dori, CountAFL);
			exit(1);
			break;
		}
		case 6:
		{
			system("cls");
			Changecountplaces(num, dori, CountAFLL);
			exit(1);
			break;
		}
		case 7:
		{
			system("cls");
			Changecountplaces(num, dori, CountDatastruc);
			exit(1);
			break;
		}
		case 8:
		{
			system("cls");
			Changecountplaces(num, dori, CountDatastrucL);
			exit(1);
			break;
		}

		default: {
			cout << "Wrong choice!" << endl;
		}
		}
		system("cls");
	} while (choice != 8);
}
void Changecountplaces(int num, int dori, int& count) {
	if (dori == 2)
		count = abs(num - count);
	else
		count = num + count;
}
void numStudentIncourse() {
	char*subj,str[100];
	int k = 0;
	cout << "Enter a course name to view participants:" << endl;
	cout << "\nFSE-Foundations of software engineering\nPSE-Principle of software engineering\nAFL-Automata and formal languages\nDS-Data structure\n";
	cout << "ER-english with roman\nEG-english with gabriel\nTENIS\nFRENCH\nWINE\n";
	cin >> str;
	subj = new char[strlen(str)+1];
	strcpy(subj,str);
	
	string a;
	a = subj;
	ifstream e(string(a + ".txt").c_str());
	string f;
	while (getline(e, f))
	{
		cout << f;
	}

			
	}

void create_list_course(int id,char* day,char* nlecture, char* ncourse, int& num) {
	if (check_place(num) == true) {
		list* s = head;
		details_courses *temp = NULL;
		details_courses* p;
		temp = new details_courses;
		temp->lecture = new char[strlen(nlecture) + 1];
		strcpy(temp->lecture, nlecture);
		temp->name_course = new char[strlen(ncourse) + 1];
		strcpy(temp->name_course, ncourse);
		temp->next = NULL;
		while (s->data->ID != id)
		{
			s = s->next;
		}
		daysinweek* t = s->data->head;
		while (strcmp(t->name_day, day) != 0)
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
		num--;
	}
	else
	{
		cout << "There is no places in this course" << endl;
	}
}
void timeTableOption(int id)
{
	char*ID = new char[10];
	strcpy(ID, convert_to_char(id));
	///////////////
	ofstream ofile, Efile,Gfile;
	string Id;
	Id = ID;
	ofile.open(string(Id + "Courses.txt").c_str());
	Efile.open(string(Id + "Exam.txt").c_str());
	Gfile.open(string(Id + "Grade.txt").c_str());
	ofstream Afile("AFL.txt", ios::app);
	ofstream Dfile("DS.txt", ios::app);
	ofstream Ffile("FSE.txt", ios::app);
	ofstream Pfile("PSE.txt", ios::app);

	list* s = NULL;
	int  choise = 0;
	char FSE[4] = { "FSE" }, PSE[4] = { "PSE" }, AFL[4] = { "AFL" }, stuct[15] = { "data structure" }, FSEp[6] = { "FSE-p" }, PSEp[6] = { "PSE-p" }, DSL[17] = { "data structure-l" }, AFLp[6] = { "AFL-p" };
	char* option1 = "\nFSE-Foundations of software engineering\nPSE-Principle of software engineering\nAFL-Automata and formal languages\n---------------------------------------------------------------------------------------------------\nSunday\t\t|Monday\t\t\t|Tuesday\t\t|Wednesday\t\t|Thursday\nFSE-practice\t|PSE-lab\t\t|Data structure\t\t|AFL\t\t\t|\n\t\t|FSE\t\t\t|PSE\t\t\t|\t\t\t|\n\t\t|Data structure-lab\t|\t\t\t|AFL-practice\t\t|\n\t\t|\t\t\t|\t\t\t|\t\t\t|\n-------------------------------------------------------------------------------------------------\n";
	char* option2 = "\nFSE-Foundations of software engineering\nPSE-Principle of software engineering\nAFL-Automata and formal languages\n---------------------------------------------------------------------------------------------------------------\nSunday\t\t\t|Monday\t\t\t|Tuesday\t\t|Wednesday\t\t|Thursday\nFSE-practice\t\t|PSE-lab\t\t|Data structure\t\t|\t\t\t|\nFSE\t\t\t|AFL\t\t\t|PSE\t\t\t|\t\t\t|\nData structure-lab\t|\t\t\t|AFL-practice\t\t|\t\t\t|\n\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n------------------------------------------------------------------------------------------------------\n";
	char* option3 = "\nFSE-Foundations of software engineering\nPSE-Principle of software engineering\nAFL-Automata and formal languages\n---------------------------------------------------------------------------------------------------------------\nSunday\t\t\t|Monday\t\t\t|Tuesday\t\t|Wednesday\t\t|Thursday\nFSE\t\t\t|AFL\t\t\t|Data structure\t\t|\t\t\t|PSE-lab\nData structure-lab\t|\t\t\t|AFL-practice\t\t|PSE\t\t\t|\n\t\t\t|FSE-practice\t\t|\t\t\t|\t\t\t|\n\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t\n------------------------------------------------------------------------------------------------------\n";

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
			create(id, "sunday");
			create_list_course(id, "sunday", "Isabel Meif", "FSE-practice", CountFSEP);

			create(id, "monday");
			create_list_course(id, "monday", "Hadas Hasidim", "FSE", CountFSE);

			create_list_course(id, "monday", "Svetlana Rusin", "PSE-lab", CountPSEL);

			create_list_course(id, "monday", "Avishai Kraif", "Data struction-lab", CountDatastrucL);
			create(id, "tuesday");

			create_list_course(id, "tuesday", "Irena revayev", "Data struction", CountDatastruc);

			create_list_course(id, "tuesday", "Marina Litbak", "PSE", CountPSE);

			create(id, "wednesday");
			create_list_course(id, "wednesday", "Alexander Chorkin", "AFL", CountAFL);

			create_list_course(id, "wednesday", "Alexander Shkolnik", "AFL-lab", CountAFLL);
			create(id, "thursday");
			create(id, "friday");


			ofile << "PSE\t\t" << "Marina Litbak" << endl;
			ofile << "Data structur\t" << "Irena revayev" << endl;
			ofile << "FSE\t\t" << "Hadas Hasidim" << endl;
			ofile << "AFL\t\t" << "Alexander Chorkin" << endl << endl;
			ofile << "Data struction-lab\t" << "Avishai Kraif" << endl;
			ofile << "FSE - practice\t" << "Isabel Meif" << endl;
			ofile << "AFL-lab\t\t" << "Alexander Shkolnik" << endl;
			ofile << "PSE-lab\t\t" << "Svetlana Rusin" << endl;
			Efile << "--------------------------------------------------------------------------------------------" << endl;
			Efile << "Exam\t\t\t\t\tDate\t\t\tDay\t\t\tA/B | " << endl;
			Efile << "Principles of language software\t\t16/1/2019\t\tWednesday\t\tA |" << endl;
			Efile << "Automata and formal languages\t\t22/1/2019\t\tTuesday\t\t\tA| " << endl;
			Efile << "Data structure\t\t\t\t5/2/2019\t\tTuesday\t\t\tA|" << endl;
			Efile << "Principles of language software\t\t11/2/2019\t\tMonday\t\t\tB| " << endl;
			Efile << "Automata and formal languages\t\t14/2/2019\t\tThursday\t\tB|" << endl;
			Efile << "Data structure\t\t\t\t25/2/2019\t\tMonday\t\t\tB| " << endl;
			list* s = head;
			while (s != NULL){
				if (s->data->ID == id)
					break;
			s = s->next;
		}
			Afile <<s->data->first_name<<"  "<<s->data->last_name <<endl;
			Dfile << s->data->first_name << "  " << s->data->last_name << endl;
			Ffile << s->data->first_name << "  " << s->data->last_name << endl;
			Pfile << s->data->first_name << "  " << s->data->last_name << endl;
			Afile.close();
			Dfile.close();
			Ffile.close();
			Pfile.close();
			ofile.close();
			Efile.close();

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
			create_list_course(id, "sunday", "Isabel Meif", "FSE-practice", CountFSEP);

			create_list_course(id, "sunday", "Hadas Hasidim", "FSE", CountFSE);

			create_list_course(id, "sunday", "Avishai Kraif", "Data struction-lab", CountDatastrucL);

			create(id, "monday");
			create_list_course(id, "monday", "Svetlana Rusin", "PSE-lab", CountPSEL);

			create_list_course(id, "monday", "Alexander Chorkin", "AFL", CountAFL);


			create(id, "tuesday");
			create_list_course(id, "tuesday", "Irena revayev", "Data structur", CountDatastruc);


			create_list_course(id, "tuesday", "Marina Litbak", "PSE", CountPSE);

			create_list_course(id, "tuesday", "Alexander Shkolnik", "AFL-lab", CountAFLL);

			create(id, "wednesday");
			create(id, "thursday");
			create(id, "friday");

			ofile << "PSE\t\t" << "Marina Litbak" << endl;
			ofile << "Data structur\t" << "Irena revayev" << endl;
			ofile << "FSE\t\t" << "Hadas Hasidim" << endl;
			ofile << "AFL\t\t" << "Alexander Chorkin" << endl << endl;
			ofile << "Data struction-lab\t" << "Avishai Kraif" << endl;
			ofile << "FSE - practice\t" << "Isabel Meif" << endl;
			ofile << "AFL-lab\t\t" << "Alexander Shkolnik" << endl;
			ofile << "PSE-lab\t\t" << "Svetlana Rusin" << endl;
			Efile << "--------------------------------------------------------------------------------------------" << endl;
			Efile << "Exam\t\t\t\t\tDate\t\t\tDay\t\t\tA / B | " << endl;
			Efile << "Principles of language software\t\t16/1/2019\t\tWednesday\t\tA  |" << endl;
			Efile << "Automata and formal languages\t\t22/1/2019\t\tTuesday\t\t\tA | " << endl;
			Efile << "Data structure\t\t\t\t5/2/2019\t\tTuesday\t\t\tA  |" << endl;
			Efile << "Principles of language software\t\t11/2/2019\t\tMonday\t\t\tB | " << endl;
			Efile << "Automata and formal languages\t\t14/2/2019\t\tThursday\t\tB  |" << endl;
			Efile << "Data structure\t\t\t\t25/2/2019\t\tMonday\t\t\tB | " << endl;
			list* s = head;
			while (s != NULL) {
				if (s->data->ID == id)
					break;
				s = s->next;
			}
			Afile << s->data->first_name << "  " << s->data->last_name << endl;
			Dfile << s->data->first_name << "  " << s->data->last_name << endl;
			Ffile << s->data->first_name << "  " << s->data->last_name << endl;
			Pfile << s->data->first_name << "  " << s->data->last_name << endl;
			Afile.close();
			Dfile.close();
			Ffile.close();
			Pfile.close();
			ofile.close();
			Efile.close();
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
			create_list_course(id, "sunday", "Hadas Hasidim", "FSE", CountFSE);


			create_list_course(id, "sunday", "Avishai Kraif", "Data struction-lab", CountDatastrucL);

			create(id, "monday");
			create_list_course(id, "monday", "Alexander Chorkin", "AFL", CountAFL);


			create_list_course(id, "monday", "Isabel Meif", "FSE-practice", CountFSEP);

			create(id, "tuesday");
			create_list_course(id, "tuesday", "Irena revayev", "Data struction", CountDatastruc);


			create_list_course(id, "tuesday", "Alexander Shkolnik", "AFL-lab", CountAFLL);

			create(id, "wednesday");
			create_list_course(id, "wednesday", "Marina Litbak", "PSE", CountPSE);

			create(id, "thursday");
			create_list_course(id, "thursday", "Svetlana Rusin", "PSE-lab", CountPSEL);
			create(id, "friday");

			ofile << "PSE\t\t" << "Marina Litbak" << endl;
			ofile << "Data structur\t" << "Irena revayev" << endl;
			ofile << "FSE\t\t" << "Hadas Hasidim" << endl;
			ofile << "AFL\t\t" << "Alexander Chorkin" << endl << endl;
			ofile << "Data struction-lab\t" << "Avishai Kraif" << endl;
			ofile << "FSE - practice\t" << "Isabel Meif" << endl;
			ofile << "AFL-lab\t\t" << "Alexander Shkolnik" << endl;
			ofile << "PSE-lab\t\t" << "Svetlana Rusin" << endl;
			Efile << "--------------------------------------------------------------------------------------------" << endl;
			Efile << "Exam\t\t\t\t\tDate\t\t\tDay\t\t\tA / B | " << endl;
			Efile << "Principles of language software\t\t16/1/2019\t\tWednesday\t\tA  |" << endl;
			Efile << "Automata and formal languages\t\t22/1/2019\t\tTuesday\t\t\tA | " << endl;
			Efile << "Data structure\t\t\t\t5/2/2019\t\tTuesday\t\t\tA  |" << endl;
			Efile << "Principles of language software\t\t11/2/2019\t\tMonday\t\t\tB | " << endl;
			Efile << "Automata and formal languages\t\t14/2/2019\t\tThursday\t\tB  |" << endl;
			Efile << "Data structure\t\t\t\t25/2/2019\t\tMonday\t\t\tB | " << endl;
			list* s = head;
			while (s != NULL) {
				if (s->data->ID == id)
					break;
				s = s->next;
			}
			Afile << s->data->first_name << "  " << s->data->last_name << endl;
			Dfile << s->data->first_name << "  " << s->data->last_name << endl;
			Ffile << s->data->first_name << "  " << s->data->last_name << endl;
			Pfile << s->data->first_name << "  " << s->data->last_name << endl;
			Afile.close();
			Dfile.close();
			Ffile.close();
			Pfile.close();
			ofile.close();
			Efile.close();
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
	int Request;
	char name[10], lname[10];
	char* name1, *lname1, *Request1;
	ofstream Cfile("StudentRequest.txt", ios::app);
	cout << "Enter name: ";
	cin >> name;
	name1 = new char[strlen(name)+1];
	strcpy(name1,name);
	cout << "Enter last name: ";
	cin >> lname;
	lname1 = new char[strlen(lname) + 1];
	strcpy(lname1, lname);
	cout << "Choose Request:\n1.special exam date\n2.exemption from course\n3.:Realesed from blocking course ";
	cin >> Request;
	while (Request != 1 && Request != 2 && Request != 3){
		cout << "Choose only 1/2/3  !" << endl;
		cin >> Request;
		}
	if(Request==1)
	Cfile << "Name:" << name1 << " " << lname1 << "\tTopic: special exam date " << endl;
	if (Request == 2)
		Cfile << "Name:" << name1 << " " << lname1 << "\tTopic: exemption from course "<< endl;
	if (Request == 3)
		Cfile << "Name:" << name1 << " " << lname1 << "\tTopic: Realesed from blocking course" << endl;
	cout << "Report has been sent to print\n";
	Cfile.close();


	ifstream e("StudentRequest.txt");
	string f;
	while (getline(e, f))
	{
		cout << f;
	}


}

int DeleteChoiseCourse(int id,char* subject) {
	int h = 0, k = 0;
	list *s = head;


	while (s->data->ID != id)
	{
		s = s->next;
	}

	daysinweek *t = s->data->head; //t =יום
	while (t != NULL)
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
					k++;
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
						k++;
					}
				}
			}
		}
		t = t->next;
	}

	return k;
}

void printReportUS(char* filename) {
	char val;
	ifstream file(filename);
	if (!file)//if file couldnt open, throws an exception
		throw runtime_error("file is empty");
	file.close();//close the file
	file.open(filename);
	cout << "************************The users Login Report:************************" << endl;
	while (!file.eof()) {
		if (filename) {

			string val;
			getline(file, val);
			cout << val;
		}
		cout << endl;
	}

}
void ReportusersLogin(char* name)
{
	char line[30];
	int flag = 0;
	 ifstream newFile;
	 newFile.open("Reportusers.txt");
	if (newFile.is_open())
	{
		while (newFile >> line)
		{
			if (strcmp(line, name) == 0)
			{
				flag = 1;
			}
		}
		if (flag == 1)
			newFile.close();
		else
		{
			ofstream newFile;
			newFile.open("Reportusers.txt", ios::app);
			newFile << name << endl;
			newFile.close();
		}

	}
	else
		cout << "Unable to open file";

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
					if (pass[0] == 'A') {
						type = 'A';
						ReportusersLogin(s1);
					}
					else if (pass[0] == 'B') {
						type = 'B';
						ReportusersLogin(s1);
					}
					else if (pass[0] == 'C') {
						type = 'C';
						ReportusersLogin(s1);
					}
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
bool CheckID(int id) {
	int k = 0;
	if (100000000<=id<=999999999)
	{
		k++;
	}
	list* s = head;
	while (s!=NULL)
	{
		if (s->data->ID==id)
		{
			k++;
		}
		s = s->next;
	}
	if (k==2)
	{
		return true;
	}
	return false;


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
					cout << "\n------------------------Info menu--------------------\n1.To print all users\n";
					cout << "2.To change user classification\n3.To backup the system\n4.To restart the system\n";
					cout << "5.To add user\n6.To producing a computer BUGS report\n7.To reset password\n";
					cout << "8.security system suplied\n"<< "9.User Login Report\n"<<"10. exit from the system" << endl;
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
							printReportUS("Reportusers.txt");
							break;
						}
						case 10:
						{
							system("cls");
							cout << "goodbye!" << endl;
							break;
						}
						default: {
							cout << "Wrong choice!" << endl;

						}
					}//end {} of switch.
				} while (choice !=10);
				break;//to end switch case
			}
			case 'B':
			{
				do
				{
				cout << "\n-----------------------Secratery Menu--------------------\n1.To change number of people in course\n";
				cout << "2.To add student to course\n3.To print time table\n4.To print Students Request report\n";
				cout << "5.To see number of people in course\n6.To send message about course changes\n";
				cout << "7.To cancel elective course\n8.To ading an elective course\n";
				cout << "9.To add student to exam list\n10.Exit\n";
				cin >> choice;

					switch (choice)
					{
						/*case 1:
							ChangeNumInCours();*/
					case 2: 
					{
						system("cls");
						add_courses();
						break;
					}
							
					case 3:
					{
						char* ID;
						ID = new char[10];
						cout << "Enter student's id:" << endl;
						cin >> id;
						while (id < 100000000 || id > 999999999)
						{
							cout << "Id must contain 9 digit. enter again:" << endl;
							cin >> id;
						}

						strcpy(ID, convert_to_char(id));
						if (exist_in_file(ID) == false)
						{

							print_timetable(id);
						}
						else {
							cout << "Student not exist !" << endl;
						}
						break;
					}
					case 4:
					{
						system("cls");
						StudentRequest();
						break;
					}	
					case 5:
					{
						system("cls");
						numStudentIncourse();
						break;
					}
					case 6:
					{
						system("cls");
						sendMessage();
						break;
					}	
					case 7: 
					{
						char str[100], *subject;
						char* ID;
						ID = new char[10];
						cout << "Enter student's id:" << endl;
						cin >> id;
						while (id < 100000000 || id > 999999999)
						{
							cout << "Id must contain 9 digit. enter again:" << endl;
							cin >> id;
						}

						strcpy(ID, convert_to_char(id));
						if (exist_in_file(ID) == false)
						{
							cout << "Enter subject:" << endl;
							cin >> str;
							subject = new char[strlen(str) + 1];
							strcpy(subject, str);
							if (DeleteChoiseCourse(id, subject) == 0)
								cout << "This course does not exist . \n";
							else
								cout << "Course successfully removed!\n";
						}
						else
						{
							cout << "Student not exist !" << endl;
						}
						break;
					}
					case 8:
					{
						system("cls");
						char* ID;
						ID = new char[10];
						cout << "Enter student's id:" << endl;
						cin >> id;
						while (id < 100000000 || id > 999999999)
						{
							cout << "Id must contain 9 digit. enter again:" << endl;
							cin >> id;
						}

						strcpy(ID, convert_to_char(id));
						if (exist_in_file(ID) == false)
						{
							add_choice_courses(id);
						}
						else {
							cout<< "Inccorect id" << endl;
						}
						break;
					}
					
				case 9: 
					{
					char* ID;
					ID = new char[10];
					cout << "Enter student's id:" << endl;
					cin >> id;
					while (id < 100000000 || id > 999999999)
					{
						cout << "Id must contain 9 digit. enter again:" << endl;
						cin >> id;
					}

					strcpy(ID, convert_to_char(id));
					if (exist_in_file(ID) == false)
					{
						char* t2 = NULL, *t4 = NULL, *t6 = NULL, *t8 = NULL;
						char t1[15] = {}, t3[15] = {}, t5[15] = {}, t7[15] = {};
						cout << "Enter name of course:" << endl;
						cin >> t1;
						t2 = new char[strlen(t1) + 1];
						strcpy(t2, t1);
						cout << "Enter date of exam:" << endl;
						cin >> t3;
						t4 = new char[strlen(t3) + 1];
						strcpy(t4, t3);
						cout << "Enter day of exam:" << endl;
						cin >> t5;
						t6 = new char[strlen(t5) + 1];
						strcpy(t6, t5);
						cout << "Enter moed exam:" << endl;
						cin >> t7;
						t8 = new char[strlen(t7) + 1];
						strcpy(t8, t7);
						cout << "****************NEW EXAM TABLE********************" << endl;
						printExamTable(id,t2, t4, t6, t8);
					}
					else
					{
						cout << "Student not exist !" << endl;
					}
						break;
					}
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
				cout << "\n-------------------------Student Menu----------------------------\n1.for a user guide\n";
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

						char* ID;
						ID = new char[10];
						cout << "Enter student's id:" << endl;
						cin >> id;
						while (id < 100000000 || id > 999999999)
						{
							cout << "Id must contain 9 digit. enter again:" << endl;
							cin >> id;
						}

						strcpy(ID, convert_to_char(id));
						if (exist_in_file(ID) == false)
						{
							timeTableOption(id);

						}
						else {
							cout << "Student not exist !"<<endl;
						}
						break;
					}
					case 3:
					{
						
							system("cls");
							char* ID;
							ID = new char[10];
							cout << "Enter student's id:" << endl;
							cin >> id;
							while (id < 100000000 || id > 999999999)
							{
								cout << "Id must contain 9 digit. enter again:" << endl;
								cin >> id;
							}

							strcpy(ID, convert_to_char(id));
							if (exist_in_file(ID) == false)
							{
								add_choice_courses(id);
							}
							else {
								cout << "Inccorect id" << endl;
							}
							break;
						
					}
					case 4:
					{
						system("cls");
						add_courses();
						break;
					}
					case 5:
					{
						system("cls");
						shareTimeTable();
						break;
					}
					case 6:
					{
						system("cls");
						char* ID;
						ID = new char[10];
						cout << "Enter student's id:" << endl;
						cin >> id;
						while (id < 100000000 || id > 999999999)
						{
							cout << "Id must contain 9 digit. enter again:" << endl;
							cin >> id;
						}

						strcpy(ID, convert_to_char(id));
						list *s = head;
						while (s->data->ID != id)
						{
							s = s->next;
						}
						if ((exist_in_file(ID) == false) && (s->data->count != 1))
						{
							Gradeprint(id);
						}
						else { cout << "inccorect id!" << endl; }
						break;
					}
					case 7:
					{
						char* ID;
						ID = new char[10];
						cout << "Enter student's id:" << endl;
						cin >> id;
						while (id < 100000000 || id > 999999999)
						{
							cout << "Id must contain 9 digit. enter again:" << endl;
							cin >> id;
						}

						strcpy(ID, convert_to_char(id));
						list *s = head;
						while (s->data->ID != id)
						{
							s = s->next;
						}
						if ((exist_in_file(ID) == false)&&(s->data->count!=1))
						{
							print_timetable(id);
						}
						else
						{
							cout << "Student not exist / yor already build your timetable" << endl;
						}
						break;
					}
					case 8:
					{
						system("cls");
						char* ID;
						ID = new char[10];
						cout << "Enter student's id:" << endl;
						cin >> id;
						while (id < 100000000 || id > 999999999)
						{
							cout << "Id must contain 9 digit. enter again:" << endl;
							cin >> id;
						}

						strcpy(ID, convert_to_char(id));
						if (exist_in_file(ID) == false)
						{
							printExamTable(id);
						}
						else {
							cout << "Id not found" << endl;
						}
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

void printExamTable(int id,char* sub, char* date,char* day ,char* moed )
{
	char*ID = new char[10];
	strcpy(ID, convert_to_char(id));
	string Id;
	Id= ID;
	ofstream Efile(string(Id + "Exam.txt").c_str(), ios::app);
		if (sub != NULL)
	{
		Efile <<endl<< sub << "\t\t" << date << "\t\t" << day << "\t\t" << moed << endl;
	}
	Efile.close();
	ifstream e(string(Id + "Exam.txt").c_str());
	string f;
	while (getline(e,f))
	{
		cout << f;
	}
	
	
	
	Efile.close();
}
bool checkID_adduser(int id)
{
	int k = 0,p=0;
	if (100000000 <= id && id<= 999999999)
	{
		k++;
	}
	list* s = head;
	while (s != NULL)
	{
		if (s->data->ID == id)
		{
			p++;
		}
		s = s->next;
	}
	if ((k == 1)&&(p==0))
	{
		return true;
	}
	return false;

	
}
void sendMessage()
{
	int choose1, choose2;
	char message[100] ,*message2;
	cout << "Choose what kind of message you want to send\n1.A lesson is cancelled\n2.Change in lesson\n";
	cin >> choose1;
	cout << "1.send message to all student\nsend message to student in course\n";
	cin >> choose2;
	cout << "Enter message:"<<endl;
	cin >> message;
	message2 = new char[strlen(message) + 1];
	if(choose1==1)
	cout << "The message: ''" << message << "''\non cancle lesson has been send !" << endl;
	if (choose1 == 2)
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
	int  size, id=0;
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
	char* ID;
	ID=new char[10];
	cout << "Enter id:" << endl;
	cin >> id;
	while(id < 100000000 || id > 999999999)
	{
		cout << "Id must contain 9 digit. enter again:" << endl;
		cin >> id;
	}

	strcpy(ID , convert_to_char(id));
	if (exist_in_file(ID) == true)
	{


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
		strcpy(temp->first_name, name);

		temp->last_name = new char[strlen(last)];
		strcpy(temp->last_name, last);
		temp->ID = id;
		createlist(temp);
	}
	else 
	{ 
		cout << "Id alrrady exist!" << endl; 
	}

}
void add_choice_courses(int id) {
	char*ID = new char[10];
	strcpy(ID, convert_to_char(id));
	string Id;
	Id = ID;
	ofstream Cfile(string(Id + "Courses.txt").c_str(), ios::app);
	ofstream Efile(string(Id + "Exam.txt").c_str(), ios::app);
	int choice;
	cout << "add choice courses:\n1. English with Roman in sunday\n2. English with Gabriel in friday\n3. Tenis with Ariel in monday\n4.french with Yael in wednesday\n5. wine with Sapir in thursday" << endl;
	cin >> choice;
		list* s = head;
		details_courses *course_choice = new details_courses;
		switch (choice)
		{
		case 1:
		{
			ofstream file("ER.txt", ios::app);

			while (s->data->ID != id)
			{
				s = s->next;
			}
			if (check_place(CountEnglishR) == true) {
				char name_lecture[6] = { "Roman" };
				char name_course[] = { "English" };
				char day[] = { "sunday" };
				course_choice->lecture = name_lecture;
				course_choice->name_course = name_course;
				course_choice->next = NULL;
				create_list_course(id, "sunday", "Roman Michaelan", "English", CountEnglishR);
				Cfile << "English\t\t" << "Roman Michaelan" << endl;
				Efile << "English\t\t\t15/1/2019\t\tWednesday\t\tA  |" << endl;
				file << s->data->first_name << "  " << s->data->last_name << endl;
				Cfile.close();
				Efile.close();
				file.close();
			}
			else
			{
				cout << "There is no places in this course" << endl;
			}
			break;
		}
		case 2: {
			ofstream file("EG.txt", ios::app);
			while (s->data->ID != id)
			{
				s = s->next;
			}
			if (check_place(CountEnglishG) == true) {
				char name_lecture[] = { "Gabriel" };
				char name_course[] = { "English" };
				char day[] = { "friday" };
				course_choice->lecture = name_lecture;
				course_choice->name_course = name_course;
				course_choice->next = NULL;
				create_list_course(id, "friday", "Gabriel Ben Ami", "English", CountEnglishG);
				Cfile << "English\t\t" << "Gabriel Ben Ami" << endl;
				Efile << "English\t\t\t15/1/2019\t\tWednesday\t\tA  |" << endl;
				file << s->data->first_name << "  " << s->data->last_name << endl;
				file.close();
				Cfile.close();
				Efile.close();
			}
			else
			{
				cout << "There is no places in this course" << endl;
			}
			break;
		}
		case 3:
		{
			ofstream file("TENIS.txt", ios::app);
			while (s->data->ID != id)
			{
				s = s->next;
			}
			if (check_place(CountTenis) == true) {
				char name_lecture[] = { "Ariel" };
				char name_course[] = { "Tenis" };
				char day[] = { "monday" };
				course_choice->lecture = name_lecture;
				course_choice->name_course = name_course;
				course_choice->next = NULL;
				create_list_course(id, "monday", "Ariel peretz", "Tenis", CountTenis);
				Cfile << "Tenis\t\t" << "Ariel peretz" << endl;
				Efile << "English\t\t\t22/1/2019\t\tWednesday\t\tA  |" << endl;
				file << s->data->first_name << "  " << s->data->last_name << endl;
				file.close();
				Cfile.close();
				Efile.close();

			}
			else
			{
				cout << "There is no places in this course" << endl;
			}
			break;
		}
		case 4:
		{
			ofstream file("FRENCH.txt", ios::app);
			while (s->data->ID != id)
			{
				s = s->next;
			}
			if (check_place(CountFrench) == true) {
				char name_lecture[] = { "Yael" };
				char name_course[] = { "French" };
				char day[] = { "wednesday" };
				course_choice->lecture = name_lecture;
				course_choice->name_course = name_course;
				course_choice->next = NULL;
				create_list_course(id, "wednesday", "Yael Yaakov", "French", CountFrench);
				Cfile << "French\t\t" << "Yael Yaakov" << endl;
				Efile << "French\t\t\t31/1/2019\t\tWednesday\t\tA  |" << endl;
				file << s->data->first_name << "  " << s->data->last_name << endl;
				file.close();
				Cfile.close();
				Efile.close();

			}
			else
			{
				cout << "There is no places in this course" << endl;
			}
			break;
		}
		case 5:
		{
			ofstream file("WINE.txt", ios::app);
			while (s->data->ID != id)
			{
				s = s->next;
			}
			if (check_place(CountWine) == true) {
				char name_lecture[] = { "Sapir" };
				char name_course[] = { "Wine" };
				char day[] = { "thursday" };
				course_choice->lecture = name_lecture;
				course_choice->name_course = name_course;
				course_choice->next = NULL;
				create_list_course(id, "thursday", "Sapir Dayan", "Wine", CountWine);
				Cfile << "Winet\t\t\t" << "Sapir Dayan" << endl;
				Efile << "Wine\t\t3/1/2019\t\tWednesday\t\tA  |" << endl;
				file << s->data->first_name << "  " << s->data->last_name << endl;
				file.close();
				Cfile.close();
				Efile.close();
			}
			else
			{
				cout << "There is no places in this course" << endl;
			}
			break;
		}

		default: {
			cout << "Wrong choice!" << endl;
		}
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
	char cha;
	cout << "are you sure?(y=yes , n=no)" << endl;
	cin >> cha;
	if (cha=='y')
	{
	Backup("users.txt");
	fstream restart("users.txt", ios::out | ios::trunc);
	restart.close();
	}

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


	
	ofstream bug;
	bug.open("bug.txt");
	bug << "\nAccording to report:"<< numberRepot <<" , in month[" << month << "], " << "4 bugs were detected.\na detailed report was sent for printing.\n";
	bug.close();
	ifstream e("bug.txt");
	string f;
	while (getline(e, f))
	{
		cout << f;
	}

	

}
void resetPassword(char* filename)
{
	char user[30], val[30], *s2 = NULL, NewPass[9], a[2] = "A", b[2] = "B", c[2] = "C";
	int check = 0, j = 0;
	cout << "Enter user name to reset the password:\n";
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
	cout << "password changed successfully" << endl;



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
void check(int id, char* subject, int& num) 
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
							num++;
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
	char* ID;
	ID = new char[10];
	cout << "Enter student's id:" << endl;
	cin >> id;
	while (id < 100000000 || id > 999999999)
	{
		cout << "Id must contain 9 digit. enter again:" << endl;
		cin >> id;
	}

	strcpy(ID, convert_to_char(id));
	if (exist_in_file(ID) == false)
	{


		cout << "Courses(Lectures):\n1.AFL- Sunday\t\t\t2.AFL-Monday\t\t\t3.AFL-Wedneaday\n4.PSE-Monday\t\t\t5.PSE-Tuesday\n6.FSE-Sunday\t\t\t7.FSE-Thursday\n8.Data structure-Tuesday\t9.Data structure-Wednesday" << endl;
		cout << "Courses(Lab/Practice):\n10.AFL- Sunday\t\t\t11.AFL-Monday\t\t\t12.AFL-Tuesday\n13.PSE-Monday\t\t\t14.PSE-Wednesday\n15.FSE-Sunday\t\t\t16.FSE-Monday\n17.Data structure-Sunday\t18.Data structure-Monday\t19.Data structure-Tuesday" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			check(id, "AFL", CountAFL);
			create_list_course(id, "sunday", "Alexander chorkin", "AFL", CountAFL);

			break;
		}
		case 2:
		{
			check(id, "AFL", CountAFL);
			create_list_course(id, "monday", "Alexander chorkin", "AFL", CountAFL);

			break;
		}
		case 3:
		{
			check(id, "AFL", CountAFL);
			create_list_course(id, "wednesday", "Alexander chorkin", "AFL", CountAFL);
			break;
		}
		case 4:
		{
			check(id, "PSE", CountPSE);
			create_list_course(id, "monday", "Marina litbak", "PSE", CountPSE);

			break;
		}
		case 5:
		{
			check(id, "PSE", CountPSE);
			create_list_course(id, "tuesday", "Marina litbak", "PSE", CountPSE);

			break;
		}
		case 6:
		{
			check(id, "FSE", CountFSE);
			create_list_course(id, "sunday", "Hadas hasidim", "FSE", CountFSE);

			break;
		}
		case 7:
		{
			check(id, "FSE", CountFSE);
			create_list_course(id, "thursday", "Hadas Hasidim ", "FSE", CountFSE);

			break;
		}
		case 8:
		{
			check(id, "Data structure", CountDatastruc);
			create_list_course(id, "tuesday", "Irena Revayev", "Data structure", CountDatastruc);

			break;
		}
		case 9:
		{
			check(id, "Data structure", CountDatastruc);
			create_list_course(id, "wednesday", "Irena Revayev", "Data structure", CountDatastruc);


			break;
		}
		case 10:
		{
			check(id, "AFL-lab", CountAFLL);
			create_list_course(id, "sunday", "Alexander Shkolnik", "AFL-lab", CountAFLL);
			break;
		}
		case 11:
		{
			check(id, "AFL-lab", CountAFLL);
			create_list_course(id, "monday", "Alexander Shkolnik", "AFL-lab", CountAFLL);


			break;
		}
		case 12:
		{
			check(id, "AFL-lab", CountAFLL);
			create_list_course(id, "tuesday", "Alexander Shkolnik", "AFL-lab", CountAFLL);
			break;
		}
		case 13:
		{
			check(id, "PSE-lab", CountPSEL);
			create_list_course(id, "monday", "Svetlana Rusin", "PSE-lab", CountPSEL);


			break;
		}
		case 14:
		{
			check(id, "PSE-lab", CountPSEL);
			create_list_course(id, "wednesday", "Svetlana Rusin", "PSE-lab", CountPSEL);
			break;
		}
		case 15:
		{
			check(id, "FSE-practice", CountFSEP);
			create_list_course(id, "sunday", "Isabel meif", "FSE-practice", CountFSEP);

			break;
		}
		case 16:
		{
			check(id, "FSE-practice", CountFSEP);
			create_list_course(id, "monday", "Isabel meif", "FSE-practice", CountFSEP);


			break;
		}
		case 17:
		{
			check(id, "Data structure-lab", CountDatastrucL);
			create_list_course(id, "sunday", "Avishay Kraif", "Data structure-lab", CountDatastrucL);


			break;
		}
		case 18:
		{
			check(id, "Data structure-lab", CountDatastrucL);
			create_list_course(id, "monday", "Avishay Kraif", "Data structure-lab", CountDatastrucL);



			break;
		}
		case 19:
		{
			check(id, "Data structure-lab", CountDatastrucL);
			create_list_course(id, "tuesday", "Avishay Kraif", "Data structure-lab", CountDatastrucL);


			break;
		}

		default: {
			cout << "Wrong choice!" << endl;
		}
				 break;
		}
	}
	else
	{
		cout << "Student not exist!" << endl;
	}
	
}
bool check_place(int num) {
	if (num != 0) {
		return true;
	}
	return false;
}
int main()
{
	ofstream P;
	P.open("PSE.txt");
	ofstream F;
	F.open("FSE.txt");
	ofstream A;
	A.open("AFL.txt");
	ofstream D;
	D.open("DS.txt");
	ofstream ER;
	ER.open("ER.txt");
	ofstream EG;
	EG.open("EG.txt");
	ofstream W;
	W.open("WINE.txt");
	ofstream Fr;
	Fr.open("FRENCH.txt");
	ofstream T;
	T.open("TENIS.txt");
	ofstream Req;
	Req.open(".txt");
	ofstream report;
	report.open("StudentRequest.txt");
	char* fileName = NULL;
	login("users.txt");
	ofstream reportNew;
	reportNew.open("Reportusers.txt");

}