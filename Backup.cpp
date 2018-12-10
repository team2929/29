#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;


void Backup(const char* filename){
	
	ofstream newFile;
	newFile.open("backup.txt", ios::trunc);
	ifstream ofs(filename,ios::in);
	newFile << ofs.rdbuf();
	newFile.close();
	ofs.close();
}



int main() {
	
	int num;
	bool flag = true;
	while (flag != false) {
		cout << "****************/Backup Menu/***************\n";
		cout << " 1 - Backup users .\n";
		cout << " 2 - Backup secretary.\n";
		cout << " 3 - Backup info.\n";
		cout << " 4 - Backup courses.\n";
		cout << " 5 - Exit.\n";
		cout << " Enter number between 1-5 and press return: ";
	    cin >> num;
	
	switch (num) {
		case 1:
			Backup("users.txt");
			rename("backup.txt", "Backup_users.txt");
			cout << "\n Backup users sucsses!\n\n";
			
			break;
		case 2:
			Backup("secretary.txt");
			rename("backup.txt", "Backup_secretary.txt");
			cout << "\n Backup users sucsses!\n\n";
			
			break;
		case 3:
			Backup("info.txt");
			rename("backup.txt", "Backup_info.txt");
			cout << "\n Backup users sucsses!\n\n";
			
			break;
		case 4:
			Backup("courses.txt");
			rename("backup.txt", "Backup_courses.txt");
			cout << "\n Backup users sucsses!\n\n";
			break;
		case 5:
			cout << "End of Backup Menu .\n";
			flag = false;
			break;
		default:
			cout << "\n Not a Valid Choice. \n Choose again\n\n";
			break;
	}

}
return 0;
}





