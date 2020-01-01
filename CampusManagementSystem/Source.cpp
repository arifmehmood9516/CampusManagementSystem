
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CAMPUS MANAGEMENT PROGRAM

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class Person{
public:
	Person(){
		fname = lname = address = "";
	}
	string fname;//for student first name
	string lname;//for student last name
	string address;
};

//For students
class Student : public Person
{
public:
	Student(){
		registration = degree = academicYear = attendance = course = grade = "";
	}
	string registration;//for Registration No number
	string degree;//for class info
	string academicYear;
	string attendance;
	string course;
	string grade;
};

//For teachers
class Teacher : public Person
{
public:
	Teacher(){
		qualification = pay = subj = "";
	}
	string qualification;//Qualification of teacher
	string pay;//Pay of the Teacher
	string subj;//subject whos he/she teach
};

class ClassRoom
{
	Student students[20];
	Teacher teacher[5];
};

Student allStudent[100];
Teacher allTeacher[50];

int studentIndex = 0;
int newStudentIndex = 0;

int teacherIndex = 0;
int newTeacherIndex = 0;

void preProcess(){
	ifstream f1("student.txt");
	if (f1.fail()){
		f1.close();
		ofstream outfile("student.txt");
		outfile << "NewFile";
		outfile.close();
	}
	else
	{
		for (int j = 0; (!f1.eof()); j++)
		{
			string startEndCheck = "**Start**";
			string lineRead;
			getline(f1, lineRead);

			if (startEndCheck == lineRead)
			{
				getline(f1, allStudent[studentIndex].fname);
				getline(f1, allStudent[studentIndex].lname);
				getline(f1, allStudent[studentIndex].address);
				getline(f1, allStudent[studentIndex].registration);
				getline(f1, allStudent[studentIndex].degree);
				getline(f1, allStudent[studentIndex].academicYear);
				getline(f1, allStudent[studentIndex].attendance);
				getline(f1, allStudent[studentIndex].course);
				getline(f1, allStudent[studentIndex].grade);
				studentIndex++;
			}
		}
		f1.close();
	}
	ifstream f2("teacher.txt");
	if (f2.fail()){
		f2.close();
		ofstream outfile("teacher.txt");
		outfile << "NewFile";
		outfile.close();
	}
	else{
		cout << endl;
		for (int j = 0; (!f2.eof()); j++)
		{
			string startEndCheck = "**Start**";
			string lineRead;
			getline(f2, lineRead);

			if (startEndCheck == lineRead)
			{
				getline(f2, allTeacher[teacherIndex].fname);
				getline(f2, allTeacher[teacherIndex].lname);
				getline(f2, allTeacher[teacherIndex].address);
				getline(f2, allTeacher[teacherIndex].qualification);
				getline(f2, allTeacher[teacherIndex].pay);
				getline(f2, allTeacher[teacherIndex].subj);
				teacherIndex++;
			}
		}
		f2.close();
	}

	newStudentIndex = studentIndex;
	newTeacherIndex = teacherIndex;
}

void postProcess(){

	ofstream f1("student.txt", ios::trunc);
	for (int varI = 0; varI != newStudentIndex; varI++)
	{
		if (allStudent[varI].fname != "" && allStudent[varI].lname != "" && allStudent[varI].address != "" && allStudent[varI].registration != ""){
			f1 << "**Start**" << endl << allStudent[varI].fname << endl << allStudent[varI].lname << endl << allStudent[varI].address << endl <<
				allStudent[varI].registration << endl << allStudent[varI].degree << endl << allStudent[varI].academicYear << endl << allStudent[varI].attendance << endl <<
				allStudent[varI].course << endl << allStudent[varI].grade << endl << "**End**" << endl;
		}
	}
	f1.close();

	ofstream f2("teacher.txt", ios::trunc);
	for (int varI = 0; varI != newTeacherIndex; varI++)
	{
		if (allTeacher[varI].fname != "" && allTeacher[varI].lname != "" && allTeacher[varI].address != ""){
			f2 << "**Start**" << endl << allTeacher[varI].fname << endl << allTeacher[varI].lname << endl << allTeacher[varI].address << endl <<
				allTeacher[varI].qualification << endl << allTeacher[varI].pay << endl << allTeacher[varI].subj << endl << "**End**" << endl;
		}
	}
	f2.close();
}

void createNewStudent(){
	cout << "Enter First name: ";
	cin >> allStudent[newStudentIndex].fname;
	cout << "Enter Last name: ";
	cin >> allStudent[newStudentIndex].lname;
	cout << "Enter Registration number: ";
	cin >> allStudent[newStudentIndex].registration;
	cout << "Enter Degree: ";
	cin >> allStudent[newStudentIndex].degree;
	cout << "Enter Address: ";
	cin >> allStudent[newStudentIndex].address;
	cout << "Enter Academic Year: ";
	cin >> allStudent[newStudentIndex].academicYear;
	cout << "Enter Attendance: ";
	cin >> allStudent[newStudentIndex].attendance;
	cout << "Enter Course: ";
	cin >> allStudent[newStudentIndex].course;
	cout << "Enter Grade: ";
	cin >> allStudent[newStudentIndex].grade;
	newStudentIndex++;
}

void findStudent(){
	string find;
	cout << "Enter First name to be displayed: ";
	cin >> find;
	cout << endl;
	int notFound = 0;
	for (int j = 0; j<newStudentIndex; j++)
	{
		if (allStudent[j].fname == find)
		{
			notFound = 1;
			cout << "First Name: " << allStudent[j].fname << endl;
			cout << "Last Name: " << allStudent[j].lname << endl;
			cout << "Registration No number: " << allStudent[j].registration << endl;
			cout << "Degree: " << allStudent[j].degree << endl;
			cout << "Address: " << allStudent[j].address << endl;
			cout << "Academic Year: " << allStudent[j].academicYear << endl;
			cout << "Attendance: " << allStudent[j].attendance << endl;
			cout << "Course: " << allStudent[j].course << endl;
			cout << "Grade: " << allStudent[j].grade << endl;
		}
	}

	if (notFound == 0){

		cout << "No Record Found" << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
}

void deleteStudent(){
	string find;
	cout << "Enter Student Registration no to be Deleted: ";
	cin >> find;
	cout << endl;
	int notFound = 0;
	for (int j = 0; j<newStudentIndex; j++)
	{
		if (allStudent[j].registration == find)
		{
			notFound = 1;
			cout << "First Name: " << allStudent[j].fname << endl;
			cout << "Last Name: " << allStudent[j].lname << endl;
			cout << "Registration No number: " << allStudent[j].registration << endl;
			cout << "Degree: " << allStudent[j].degree << endl;
			cout << "Address: " << allStudent[j].address << endl;
			cout << "Academic Year: " << allStudent[j].academicYear << endl;
			cout << "Attendance: " << allStudent[j].attendance << endl;
			cout << "Course: " << allStudent[j].course << endl;
			cout << "Grade: " << allStudent[j].grade << endl;
			cout << "Following record is going to be deleted....Press Y to delete....Or press N: ";
			char del;
			cin >> del;
			if (del == 'Y' || del == 'y'){
				allStudent[j].fname = "";
				allStudent[j].lname = "";
				allStudent[j].registration = "";
				allStudent[j].degree = "";
				allStudent[j].address = "";
				allStudent[j].academicYear = "";
				allStudent[j].attendance = "";
				allStudent[j].course = "";
				allStudent[j].grade = "";
			}
		}
	}

	if (notFound == 0){

		cout << "No Record Found" << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
	postProcess();
}

void editStudent(){
	string find;
	cout << "Enter Student Registration no to be edited: ";
	cin >> find;
	cout << endl;
	int notFound = 0;
	for (int j = 0; j<newStudentIndex; j++)
	{
		if (allStudent[j].registration == find)
		{
			notFound = 1;
			cout << "First Name: " << allStudent[j].fname << endl;
			cout << "Last Name: " << allStudent[j].lname << endl;
			cout << "Registration No number: " << allStudent[j].registration << endl;
			cout << "Degree: " << allStudent[j].degree << endl;
			cout << "Address: " << allStudent[j].address << endl;
			cout << "Academic Year: " << allStudent[j].academicYear << endl;
			cout << "Attendance: " << allStudent[j].attendance << endl;
			cout << "Course: " << allStudent[j].course << endl;
			cout << "Grade: " << allStudent[j].grade << endl;
			cout << "Following record is going to be Edited....Press Y to delete....Or press N: ";
			char del;
			cin >> del;
			if (del == 'Y' || del == 'y'){
				cout << "Enter First name: ";
				cin >> allStudent[j].fname;
				cout << "Enter Last name: ";
				cin >> allStudent[j].lname;
				cout << "Enter Registration number: ";
				cin >> allStudent[j].registration;
				cout << "Enter Degree: ";
				cin >> allStudent[j].degree;
				cout << "Enter Address: ";
				cin >> allStudent[j].address;
				cout << "Enter Academic Year: ";
				cin >> allStudent[j].academicYear;
				cout << "Enter Attendance: ";
				cin >> allStudent[j].attendance;
				cout << "Enter Course: ";
				cin >> allStudent[j].course;
				cout << "Enter Grade: ";
				cin >> allStudent[j].grade;
			}
		}
	}

	if (notFound == 0){

		cout << "No Record Found" << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
	postProcess();
}

void createNewTeacher(){
	cout << "Enter First name: ";
	cin >> allTeacher[newTeacherIndex].fname;
	cout << "Enter Last name: ";
	cin >> allTeacher[newTeacherIndex].lname;
	cout << "Enter Address: ";
	cin >> allTeacher[newTeacherIndex].address;
	cout << "Enter Pay: ";
	cin >> allTeacher[newTeacherIndex].pay;
	cout << "Enter Qualification: ";
	cin >> allTeacher[newTeacherIndex].qualification;
	cout << "Enter Subjects: ";
	cin >> allTeacher[newTeacherIndex].subj;
	newTeacherIndex++;
}

void findTeacher(){
	string find;
	cout << "Enter First name to be displayed: ";
	cin >> find;
	cout << endl;
	int notFound = 0;
	for (int j = 0; j<newTeacherIndex; j++)
	{
		if (allTeacher[j].fname == find)
		{
			notFound = 1;
			cout << "First Name: " << allTeacher[j].fname << endl;
			cout << "Last Name: " << allTeacher[j].lname << endl;
			cout << "Subject: " << allTeacher[j].subj << endl;
			cout << "Address: " << allTeacher[j].address << endl;
			cout << "Pay: " << allTeacher[j].pay << endl;
			cout << "Qualification: " << allTeacher[j].qualification << endl;
		}
	}

	if (notFound == 0){

		cout << "No Record Found" << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
}

void deleteTeacher(){
	string find;
	string findb;
	cout << "Enter teacher first name to be Deleted: ";
	cin >> find;
	cout << "Enter teacher last name to be Deleted: ";
	cin >> findb;
	cout << endl;
	int notFound = 0;
	for (int j = 0; j<newTeacherIndex; j++)
	{
		if (allTeacher[j].fname == find && allTeacher[j].lname == findb)
		{
			notFound = 1;
			cout << "First Name: " << allTeacher[j].fname << endl;
			cout << "Last Name: " << allTeacher[j].lname << endl;
			cout << "Subject: " << allTeacher[j].subj << endl;
			cout << "Address: " << allTeacher[j].address << endl;
			cout << "Pay: " << allTeacher[j].pay << endl;
			cout << "Qualification: " << allTeacher[j].qualification << endl;
			cout << "Following record is going to be deleted....Press Y to delete....Or press N: ";
			char del;
			cin >> del;
			if (del == 'Y' || del == 'y'){
				allTeacher[j].fname = "";
				allTeacher[j].lname = "";
				allTeacher[j].subj = "";
				allTeacher[j].address = "";
				allTeacher[j].pay = "";
				allTeacher[j].qualification = "";
			}
		}
	}

	if (notFound == 0){

		cout << "No Record Found" << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
	postProcess();
}

void editTeacher(){
	string find;
	string findb;
	cout << "Enter teacher first name to be edited: ";
	cin >> find;
	cout << "Enter teacher last name to be edited: ";
	cin >> findb;
	cout << endl;
	int notFound = 0;
	for (int j = 0; j<newTeacherIndex; j++)
	{
		if (allTeacher[j].fname == find && allTeacher[j].lname == findb)
		{
			notFound = 1;
			cout << "First Name: " << allTeacher[j].fname << endl;
			cout << "Last Name: " << allTeacher[j].lname << endl;
			cout << "Subject: " << allTeacher[j].subj << endl;
			cout << "Address: " << allTeacher[j].address << endl;
			cout << "Pay: " << allTeacher[j].pay << endl;
			cout << "Qualification: " << allTeacher[j].qualification << endl;
			cout << "Following record is going to be edited....Press Y to delete....Or press N: ";
			char del;
			cin >> del;
			if (del == 'Y' || del == 'y'){
				cout << "Enter First name: ";
				cin >> allTeacher[j].fname;
				cout << "Enter Last name: ";
				cin >> allTeacher[j].lname;
				cout << "Enter Address: ";
				cin >> allTeacher[j].address;
				cout << "Enter Pay: ";
				cin >> allTeacher[j].pay;
				cout << "Enter Qualification: ";
				cin >> allTeacher[j].qualification;
				cout << "Enter Subjects: ";
				cin >> allTeacher[j].subj;
			}
		}
	}

	if (notFound == 0){

		cout << "No Record Found" << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
	postProcess();
}

void degreeReport(string qual){
	int notFound = 0;
	for (int j = 0; j<newStudentIndex; j++)
	{
		if (allStudent[j].degree == qual)
		{
			notFound = 1;
			cout << allStudent[j].fname << " " << allStudent[j].lname << " Registration No number: " << allStudent[j].registration << " Degree Level: " << allStudent[j].degree << endl;
		}
	}
	if (notFound == 0){
		cout << "Nothing to show in this Report Degree Level: " << qual << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
}

void attendanceReport(string attendance){
	int notFound = 0;
	for (int j = 0; j<newStudentIndex; j++)
	{
		if (allStudent[j].attendance == attendance)
		{
			notFound = 1;
			cout << allStudent[j].fname << " " << allStudent[j].lname << " Registration No number: " << allStudent[j].registration << " Attendance: " << allStudent[j].attendance << endl;
		}
	}
	if (notFound == 0){
		cout << "Nothing to show in this Report Attendance: " << attendance << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
}

void facultyReport(string qual){
	int notFound = 0;
	for (int j = 0; j<newTeacherIndex; j++)
	{
		if (allTeacher[j].qualification == qual)
		{
			notFound = 1;
			cout << allTeacher[j].fname << " " << allTeacher[j].lname << " Qualification: " << allTeacher[j].qualification << endl;
		}
	}
	if (notFound == 0){
		cout << "Nothing to show in this Report Faculty Qualification: " << qual << endl;
	}
	cout << "Press any key two times to proceed";
	_getch();//To hold data on screen
	_getch();//To hold data on screen
}

void main()
{
	int i = 0, j;//for processing usage 
	char choice;//for getting choice
	string find;//for sorting
	string srch;
	preProcess();
	while (1)//outer loop
	{
		system("cls");//Clear screen

		//Level 1-Display process 
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
		cout << "\n\n\t\t\CAMPUS MANAGEMENT PROGRAM\n\n";
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
		cout << "\n\n\t\t\tMAIN SCREEN\n\n";
		cout << "Enter your choice: " << endl;
		cout << "1.Students information" << endl;
		cout << "2.Teacher information" << endl;
		cout << "3.Reports" << endl;
		cout << "4.Exit program" << endl;
		cin >> choice;

		system("cls");//Clear screen


		switch (choice)//First switch
		{

		case '1':	//Student
		{
			while (1)//inner loop-1
			{
				system("cls");//Clear screen
				cout << "\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n\n";
				cout << "Enter your choice: " << endl;
				cout << "1.Create new entry\n";
				cout << "2.Find and display entry\n";
				cout << "3.Delete entry\n";
				cout << "4.Edit entry\n";
				cout << "5.Jump to main\n";
				cin >> choice;

				switch (choice)//Second switch

				{
				case '1'://Insert data
				{
					for (i = 0; choice != 'n'; i++)
					{
						if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
						{
							createNewStudent();
							cout << "Do you want to enter data: ";
							cout << "Press Y for Continue and N to Finish:  ";
							cin >> choice;
						}
					}
					postProcess();
				}
				continue;//control back to inner loop -1

				case '2'://Display data
				{
					findStudent();
				}
				continue;//control back to inner loop -1

				case '3'://Jump to main
				{
					deleteStudent();
				}
				continue;//control back to inner loop -1

				case '4'://Jump to main
				{
					editStudent();
				}
				continue;//control back to inner loop -1

				case '5'://Jump to main
				{
					break;//inner switch breaking
				}
				}

				break;//inner loop-1 breaking
			}
			continue;//Control pass to 1st loop				
		}

		case '2'://Teachers biodata
		{
			while (1)//inner loop-2
			{
				system("cls");//Clear screen
				//Level-2 Display process
				cout << "\t\t\tTEACHERS INFORMATION AND BIODATA SECTION\n\n\n";
				cout << "Enter your choice: " << endl;
				cout << "1.Create new entry\n";
				cout << "2.Find and display\n";
				cout << "3.Delete entry\n";
				cout << "4.Edit entry\n";
				cout << "5.Jump to main\n";
				cin >> choice;

				switch (choice)//Third switch
				{
				case '1'://Insert data
				{
					for (i = 0; choice != 'n'&& choice != 'N'; i++)
					{

						if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
						{
							createNewTeacher();
							cout << "Do you want to enter data: ";
							cout << "Press Y for Continue and N to Finish:  ";
							cin >> choice;
						}//if
					}//for loop
					//for finding through name 
					system("cls");
					postProcess();
				}//case 1

				continue;//Control pass to inner loop-2

				case '2'://Display data
				{
					findTeacher();
				}//case 2

				continue;//Control pass to inner loop-2

				case '3'://Jump to main
				{
					deleteTeacher();
				}
				continue;//control back to inner loop -1

				case '4'://Jump to main
				{
					editTeacher();
				}
				continue;//control back to inner loop -1

				case '5'://Jump to main
				{
					break;//inner switch breaking
				}

				}//inner switch

				break;//inner while
			}//inner loop

			continue;//control pass to 1st loop
		}//outer case 2

		case '3'://Reporting
		{
			while (1)//inner loop-2
			{
				system("cls");//Clear screen
				cout << "\t\t\tReports Section\n\n\n";
				cout << "Enter your choice: " << endl;
				cout << "1.Student in a Degree Report\n";
				cout << "2.Student Attendance Report\n";
				cout << "3.Teacher Qualification Report\n";
				cout << "4.Jump to main\n";
				cin >> choice;

				switch (choice)
				{
				case '1':
				{
					string reportParam;
					cout << "Enter the degree Program:(Masters, Bachelors, Phd) " << endl;
					cin >> reportParam;
					degreeReport(reportParam);
					system("cls");
				}

				continue;

				case '2':
				{
					string reportParam;
					cout << "Enter the attendance level:(low, high, critical) " << endl;
					cin >> reportParam;
					attendanceReport(reportParam);
					system("cls");
				}

				continue;//Control pass to inner loop-2

				case '3'://Jump to main 
				{
					string reportParam;
					cout << "Enter the Qualification:(Masters, Bachelors, Phd) " << endl;
					cin >> reportParam;
					facultyReport(reportParam);
					system("cls");
				}

				case '4'://Jump to main 
				{
					break;//inner switch
				}

				}//inner switch

				break;//inner while
			}//inner loop

			continue;//control pass to 1st loop
		}

		case '4':
		{
			break;//outer case 3
		}//outer case 3
		}
		break;//outer loop
	}
}