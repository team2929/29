#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
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
void Add_Users(char harshaa) {
	int  size, id;
	char temp1[100], temp2[100], *name, *last, password[9] = { "Ee123456" }, *mail;
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
	ofstream file1;
	file1.open("users.txt", ios::app);
	file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << harshaa;
	file1.close();
	if (harshaa=='A')
	{
		file1.open("info.txt", ios::app);
		file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << harshaa;
		file1.close();
	}
	else if (harshaa == 'B')
	{
		file1.open("secretary.txt", ios::app);
		file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << harshaa;
		file1.close();
	}
	else
	{
		file1.open("students.txt", ios::app);
		file1 << endl << name << " " << last << " " << id << " " << mail << " " << password << " " << harshaa;
		file1.close();
	}
}


void main() {

	char harshaa;
	cout << "enter  harshaa:\n A\n B\n C\n";
	cin >> harshaa;

	switch (harshaa)
	{
	case 'A':
	{
		Add_Users('A');
		cout << "The details add to file!" << endl;
		break;
	}
	case 'B':
	{
		Add_Users('B');
		cout << "The details add to file!" << endl;
		break;
	}
	case 'C':
	{
		Add_Users('C');
		cout << "The details add to file!" << endl;
		break;
	}
	default:
	{
		cout << "wrong choice!" << endl;
		break;
	}
	}
}