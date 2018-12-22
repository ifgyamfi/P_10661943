/*A c++ program for school management system*/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//class for students
class Student {
	public:	
		string fname[10];
		string lname[10];
		int id[10];
		int level[10];
		string courses[10][10];
		string gender[10];
		int numOfCourses[10];
		int credit[10][10];
		double score[10][10];
		double gpt[10][10];
		double gpa[10][10];
};

Student newStd;

class Staff {
	public:
		string lname[10];
		string fname[10];
		string gender[10];
		int id[10];
		string course[10];
		string department[10];
};

Staff newStf;


// variables
int mmoption,stdoption, stfoption, courseoption, n, x, v, i, addingStd, addingStf;
double totalGpt[10], totalCredit[10], GPA[10];
char newStudent;
string returnMenu;

// functions
void menu();
void stdMenu();
void addStudent();
void editStudent();

void stfMenu();
void addStaff();
void editStaff();


int main() {
	menu();
	
	switch(mmoption) {
		
		case 1: //Student Menu
			system("cls");
			stdMenu();
			cout<<endl;
			cout<<"\tEnter your option: ";
			cin>>stdoption;
			switch(stdoption) {
				case 1:
					addStudent();
					break;
				case 2:
					editStudent();
					break;
				case 3:
					menu();
					break;
			}
			break;
			
			
		case 2: //Staff Menu
			system("cls");
			stfMenu();
			cout<<endl;
			cout<<"\tEnter your option: ";
			cin>>stfoption;
			
			switch(stfoption) {
				case 1:
					addStaff();
					break;
				case 2:
					editStaff();
					break;
				case 3:
					menu();
					break;
			}
			break;
		
//		case 4: //Close program
			
			
			
	}
	
	
	return 0;
}

//function to display the main menu
void menu() {
	
	cout<<"______________________________________________________________\n\n";
	cout<<"\tSuccess International School Management System\n";
	cout<<"______________________________________________________________\n\n";
	cout<<"\t\t\tMain Menu\n\n";
	cout<<"\t\tEnter your option\n";
	cout<<"\t\t>>> [1] Student Data\n";
	cout<<"\t\t>>> [2] Staff Data\n";
	cout<<"\t\t>>> [3] Courses\n";
	cout<<"\t\t>>> [4] Close Program\n\n";
	
	cout<<"\tEnter your option: ";
	cin>>mmoption;
}


// function to display the student menu
void stdMenu() {
	system("cls");
	cout<<"______________________________________________________________\n\n";
	cout<<"\t\t\tStudent Menu\n";
	cout<<"______________________________________________________________\n";
	
	cout<<"\t>>> [1] Add new tudent\n";
	cout<<"\t>>> [2] Edit/Delete student\n";
	cout<<"\t>>> [3] Search student\n";
	cout<<"\t>>> [4] Return to Main menu\n";
}

//function to add new student
void addStudent() {
//	student newStd;
	system("cls");
	cout<<"______________________________________________________________\n";
	cout<<"\t\t\tAdd New Student\n";
	cout<<"______________________________________________________________\n";
	
	cout<<"\tEnter the number of students to add: ";
	cin>>addingStd;
	for(int n = 0; n < addingStd; n++) {
		cout<<"\tEnter student "<< n + 1 <<" first name: ";
		cin>>newStd.fname[n];
		cout<<endl;
		cout<<"\tEnter student "<< n + 1 <<" last name: ";
		cin>>newStd.lname[n];
		cout<<endl;
		cout<<"\tEnter student "<< n + 1 <<" gender: ";
		cin>>newStd.gender[n];
		cout<<endl;
		cout<<"\tEnter student "<< n + 1 <<" level: ";
		cin>>newStd.level[n];
		cout<<endl;
		cout<<"\tEnter student "<< n + 1 <<" ID: ";
		cin>>newStd.id[n];
		cout<<endl;
		cout<<"\tEnter student "<< n + 1 <<" number of courses: ";
		cin>>newStd.numOfCourses[n];
			
			for(v = 0; v < newStd.numOfCourses[n]; v++) {
				cout<<"Enter the course codes(press the enter key): ";		cout<<"Enter the course codes(after each course, press the enter key)\n";
			for(v = 0; v < newStd.numOfCourses[n]; v++) {
				cin>>newStd.courses[v][n];
				cout<<"Enter the credit hours for "<<newStd.courses[v][n]<<": ";
				cin>>newStd.credit[v][n];
				cout<<"Enter the exam score for "<<newStd.courses[v][n]<<": ";
				cin>>newStd.score[v][n];
				    
				    if((newStd.score[v][n]) >= 80) {
//						(newStd.gpa[v][i-1]) = "A";
					    (newStd.gpt[v][n]) = 12; 
						}
				    else if((newStd.score[v][n]) >= 75 && (newStd.score[v][n]) < 80) {
//						(newStd.gpa[v][i-1]) = "B+";
          				(newStd.gpt[v][n]) = 10.5;
						}
				    else if((newStd.score[v][n]) >= 70 && (newStd.score[v][n]) < 75) {
//						(newStd.gpa[v][i-1]) = "B";
				        (newStd.gpt[v][n]) = 9;
						}
				    else if((newStd.score[v][n]) >= 65 && (newStd.score[v][n]) < 70) {
//						(newStd.gpa[v][i-1]) = "C+";
				        (newStd.gpt[v][n]) = 7.5;
						}
				    else if((newStd.score[v][n]) >= 60 && (newStd.score[v][n]) < 65) {
//						(newStd.gpa[v][i-1]) = "C";
				        (newStd.gpt[v][n]) = 6;
						}
				    else if((newStd.score[v][n]) >= 55 && (newStd.score[v][n]) < 60) {
//						(newStd.gpa[v][i-1]) = "D";
				        (newStd.gpt[v][n]) = 3;}
				    else if((newStd.score[v][n]) >= 50 && (newStd.score[v][n]) < 55) {
//						(newStd.gpa[v][i-1]) = "E";
				        (newStd.gpt[v][n]) = 1.5;
						}
				    else if((newStd.score[v][n]) >= 45 && (newStd.score[v][n]) < 50) {
//						(newStd.gpa[v][i-1])="F";
				        (newStd.gpt[v][n]) = 0.0;
						}
						
				        totalGpt[n]+=newStd.gpt[v][n];
				        totalCredit[n]+=newStd.credit[v][n];
			}			}
				cin>>newStd.courses[v][n];
				cout<<"Enter the credit hours for "<<newStd.courses[v][n]<<": ";
				cin>>newStd.credit[v][n];
				cout<<"Enter the exam score for "<<newStd.courses[v][n]<<": ";
				cin>>newStd.score[v][n];
				    
				    if((newStd.score[v][n]) >= 80) {
//						(newStd.gpa[v][i-1]) = "A";
					    (newStd.gpt[v][n]) = 12; 
						}
				    else if((newStd.score[v][n]) >= 75 && (newStd.score[v][n]) < 80) {
//						(newStd.gpa[v][i-1]) = "B+";
          				(newStd.gpt[v][n]) = 10.5;
						}
				    else if((newStd.score[v][n]) >= 70 && (newStd.score[v][n]) < 75) {
//						(newStd.gpa[v][i-1]) = "B";
				        (newStd.gpt[v][n]) = 9;
						}
				    else if((newStd.score[v][n]) >= 65 && (newStd.score[v][n]) < 70) {
//						(newStd.gpa[v][i-1]) = "C+";
				        (newStd.gpt[v][n]) = 7.5;
						}
				    else if((newStd.score[v][n]) >= 60 && (newStd.score[v][n]) < 65) {
//						(newStd.gpa[v][i-1]) = "C";
				        (newStd.gpt[v][n]) = 6;
						}
				    else if((newStd.score[v][n]) >= 55 && (newStd.score[v][n]) < 60) {
//						(newStd.gpa[v][i-1]) = "D";
				        (newStd.gpt[v][n]) = 3;}
				    else if((newStd.score[v][n]) >= 50 && (newStd.score[v][n]) < 55) {
//						(newStd.gpa[v][i-1]) = "E";
				        (newStd.gpt[v][n]) = 1.5;
						}
				    else if((newStd.score[v][n]) >= 45 && (newStd.score[v][n]) < 50) {
//						(n
      								  GPA[n]=totalGpt[n]/totalCredit[n];
					  system("cls");
					  cout<<"\t\t\n\n";
					    cout<<newStd.fname[n]<<" record stored successfully\n\n";
					    cout<<"\t\tEnter \'p\' for printing of academic record\n";
					    cin>>newStudent;
					    if(newStudent=='p') {
						   system("cls");
						   for (int m = 0; m < addingStd; m++) {
								cout<<"\t\t\tAcademic Record\n";
								cout<<"\t\tAcademic year: 2018/2019\n";
								cout<<"\t\tSemester: 1st semester\n\n";
							    cout<<"\t\tStudent number: "<<newStd.id[n]<<endl;
								cout<<"\t\tGender: "<<newStd.gender[n]<<endl;
								cout<<"\t\tName: "<<newStd.fname[n]<<" "<<newStd.lname[n]<<endl;
								cout<<"\t\tNumber of courses: "<< newStd.numOfCourses[n]<<endl<<endl;
								
								cout<<"\t\tCourse Code\t\tCourse Credit\t\tGPT\t\t\n\n";
								for (v = 0; v < newStd.numOfCourses[n]; v++) {
									for (int n = 0; n < newStd.numOfCourses[n]; n++) {
										cout<<"\t\t"<<newStd.courses[v][n]<<"\t\t\t"<< newStd.credit[v][n] << endl;	
									}
								}
							
								for(int m = 0; m < newStd.numOfCourses[n]; m++) {
								
									cout<<"\t\t"<<newStd.courses[m][n]<<"\tGPA: "<<newStd.gpa[v][n]<<"\tGPT: "<<newStd.gpt[v][n]<<endl;
								    cout<<"\t\tEnter any key to return to student menu\n";
								    cin>>returnMenu;
								    system("cls");
								    break;
								    system("cls");
								}
						   	
						   		}
						   	}
							    else if(newStudent == 'a')
							          continue;
							    else {   
									system("cls");
							        break;
							    }
							        }
}
}

void editStudent(){
	int num;
	string edit;
	system("cls");
	cout<<"______________________________________________________________\n";
	cout<<"\t\t\tEdit Student\n";
	cout<<"______________________________________________________________\n";
	
		cout<<"\tDo you want to edit "<< newStd.fname[n]<<"? Use y or n for yes or no ";
		cin>>edit;
		
		if(edit == "Y" || edit == "y" || edit == "yes") {
			cout<<"\tEnter student "<< n + 1 <<" first name: ";
			cin>>newStd.fname[n];
			cout<<endl;
			cout<<"\tEnter student "<< n + 1 <<" last name: ";
			cin>>newStd.lname[n];
			cout<<endl;
			cout<<"\tEnter student "<< n + 1 <<" gender: ";
			cin>>newStd.gender[n];
			cout<<endl;
			cout<<"\tEnter student "<< n + 1 <<" level: ";
			cin>>newStd.level[n];
			cout<<endl;
			cout<<"\tEnter student "<< n + 1 <<" ID: ";
			cin>>newStd.id[n];
			cout<<endl;
			cout<<"Student data changed successfully!";
		}
		
		else {
			menu();
		}
	}

// function to display staff menu
void stfMenu() {
	system("cls");
	cout<<"______________________________________________________________\n\n";
	cout<<"\t\t\tStaff Menu\n";
	cout<<"______________________________________________________________\n\n";
	
	cout<<"\t>>> [1] Add new staff\n";
	cout<<"\t>>> [2] Edit/Delete staff\n";
	cout<<"\t>>> [3] Return to Main menu\n";
}

// function to add staff
void addStaff() {
	
	cout<<"______________________________________________________________\n";
	cout<<"\t\t\tAdd New Staff\n";
	cout<<"______________________________________________________________\n";
	
	cout<<"\tEnter the number of staff to add: ";
	cin>>addingStf;
		for(int n = 0; n < addingStf; n++) {
			cout<<"\tEnter staff "<< n + 1 << " first name: ";
			cin>>newStf.fname[n];
			cout<<endl;
			cout<<"\tEnter staff "<< n + 1 <<" last name: ";
			cin>>newStf.lname[n];
			cout<<endl;
			cout<<"\tEnter staff "<< n + 1 <<" gender: ";
			cin>>newStf.gender[n];
			cout<<endl;
			cout<<"\tEnter staff "<< n + 1 <<" course: ";
			cin>>newStf.course[n];
			cout<<endl;
			cout<<"\tEnter staff "<< n + 1 <<" department: ";
			cin>>newStf.department[n];
			cout<<"\tEnter staff "<< n + 1 <<" ID: ";
			cin>>newStf.id[n];
			cout<<endl;
		}
		
		system("cls");
		cout<<"\t\t\n\n";
		cout<<addingStf<<" records stored successfully\n\n";
					    
	
}

void editStaff() {
	system("cls");
	
}

//function to edit staff
			
