/* A C++ program to manage the student and staff 
details for School of Physical and Mathematical Sciences */

#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct student {
	string fname, lname, gender, dob, program;
	int prgNum, level, stdID, contact;
};

struct staff {
	string fname, lname, gender, dob, program;
	int prgNum, stfID, contact;
};

/** Struct instances */

student newStd;
staff newStf;


//variables
int menuOption, adminOption, adminResponse, backOption, delOption, studentID, staffID, ch, studOption, newNumber, stafOption, stafNumber, exitOption, stafLength;
   string newProgram;

//constant variables
const int STUDENT_TOTAL = 200, STAFF_TOTAL = 150, NUM_OF_COURSES = 5; 

struct ComputerScience{
   string firstYear[NUM_OF_COURSES] = {"CSCD 101 Introduction to Computer Science I", "MATH 121 Algebra and Trigonometry",
                           "CSCD 102 Introduction to Computer Science II", "MATH 122 Calculus I", "STAT 102 Elementary Probability"};
   string secondYear[NUM_OF_COURSES] = {"CSCD 202 Programming II ( Java )", "CSCD 201 Information Systems", "CSCD 211 Computer Organization and Architecture"
                           "CSCD 216 Data Structures & Algorithms", "CSCD 205 Programming I (with C++)"};
   string thirdYear[NUM_OF_COURSES] = {"CSCD 301 Object Oriented Analysis & Design", "CSCD 315 Operating Systems", "CSCD 306 Software Engineering",
                           "CSCD 304 Design and Analysis of Algorithms", "CSCD 312 Introduction to Artificial Intelligence"};
   string fourthYear[NUM_OF_COURSES] = {"CSCD 415 Compilers", "CSCD 417 Theory and Survey of Programming Languages", "CSCD 418 Computer Systems Security",
                           "CSCD 423 Software Modeling and Simulation", "CSCD 428 Expert Systems"};

   int csCredit[NUM_OF_COURSES] = {3, 3, 3, 3, 3};
};

struct Mathematics{
   string firstYear[NUM_OF_COURSES] = {"MATH 123 Vectors and Geometry", "MATH 122 Calculus I", "MATH 124 Mechanics", "UGRC 150 Critical Thinking and Practical Reasoning",
                           "URGC 110 Academic Writing I"};
   string secondYear[NUM_OF_COURSES] = {"MATH 221 Algebra", "MATH 223 Calculus II", "MATH 224 Introductory Abstract Algebra", "MATH 226 Introductory Computational Mathematics",
                           "MATH 222 Vector Mechanics"};
   string thirdYear[NUM_OF_COURSES] = {"MATH 351 Linear Algebra", "MATH 353 Analysis I", "MATH 355 Calculus of Several Variables",
                           "MATH 354 Abstract Algebra I", "MATH 356 Analysis II"};
   string fourthYear[NUM_OF_COURSES] = {"MATH 400 Project", "MATH 447 Complex Analysis", "MATH 450 Differential equations II",
                           "MATH 441 Advanced Calculus", "MATH 453 Introduction to Quantum Mechanics"};
   int maCredit[NUM_OF_COURSES] = {3, 3, 3, 3, 3};
};

struct Statistics{
   string firstYear[NUM_OF_COURSES] = {"STAT 101 Introduction to Statistics", "PSYC 101 Elements of Psychology", "MATH 124 Mechanics",
                           "STAT 102 Elementary Probability", "UGRC 131-136 Understanding Human Society"};
   string secondYear[NUM_OF_COURSES] = {"STAT 221 Introductory Probability I", "STAT 223 Elementary Statistical Methods", "STAT 222 Data Analysis I",
                           "STAT 224 Introductory Probability II", "STAT 226 Official Statistics"};
   string thirdYear[NUM_OF_COURSES] = {"STAT 331 Probability Distributions", "STAT 333 Statistical Methods I", "STAT 335 Sample Survey Methods",
                           "STAT 332 Multivariate Distributions", "STAT 334 Statistical Methods"};
   string fourthYear[NUM_OF_COURSES] = {"STAT 443 Theory of Sampling", "STAT 445 Regression Analysis", "STAT 450 Project",
                           "STAT 442 Statistical Inference: Tests of Hypothesis", "STAT 444 Survey Organization and Management"};

   int staCredit[NUM_OF_COURSES] = {3, 3, 3, 3, 3};
};

struct InformationTechnology{
   string firstYear[NUM_OF_COURSES] = {"CSIT 101 Introduction to Information Technology", "CSIT 103 Introduction to Computings", "CSIT 105 Programming Fundamentals",
                           "CSIT 102 Introduction to IT Problem Solving", "CSIT 104 Mathematics for IT Professionals"};
   string secondYear[NUM_OF_COURSES] = {"CSIT 203 Computer Hardware Fundamentals", "CSIT 205 Object Oriented Techniques for IT Problem Solving", "CSIT 207 Database Fundamentals",
                           "CSIT 202 Introduction to Computer and Networks", "CSIT 204 Introduction to Information Security"};
   string thirdYear[NUM_OF_COURSES] = {"CSIT 301 Mobile Development", "CSIT 303 Human Computer Interaction", "CSIT 305 Operating Systems Fundamentals",
                           "CSIT 313 Programme Design and Data Structures", "CSIT 315 Event-Driven Programming"};
   string fourthYear[NUM_OF_COURSES] = {"CSIT 401 Digital Media Editing", "CSIT 403 Graphics & Information Visualization", "CSIT 409 Cloud Computing",
                           "CSIT 411 Advanced Networking Principles", "CSIT 417 Information Storage and Management Technologies"};

   int infoCredit[NUM_OF_COURSES] = {3, 3, 3, 3, 3};
};

struct GPA{
   string grade, classObtained;
   float gradePoint, gradeAverage;
   int creditTaken;
};

//Additional struct instances
student studentList[STUDENT_TOTAL];
staff staffList[STAFF_TOTAL];
ComputerScience getComputer[NUM_OF_COURSES];
Mathematics getMaths[NUM_OF_COURSES];
Statistics getStat[NUM_OF_COURSES];
InformationTechnology getInfo[NUM_OF_COURSES];
GPA gpa[NUM_OF_COURSES];

//functions

//Add student
void addStudent(newStd newStd[], int length){
   srand(time(0));

   for(int i = 0; i < length; i++){
      newStd[i].stdID = (rand() % 1000) + 10152431;

      cout << endl << "\n\n\t\t Student " << i + 1  << " ID: " << newStd[i].stdID << endl;
      cout << "\n\n\t\t Firstname: ";
      cin >> newStd[i].firstname;
      cout << "\n\n\t\t Lastname: ";
      cin >> newStd[i].lastname;
      cout << "\n\n\t\t Sex [Male or Female]: ";
      cin >> newStd[i].gender;
      cout << "\n\n\t\t Date of Birth [dd-mm-yyyy]: ";
      cin >> newStd[i].dob;
      cout << "\n\n\t\t contact Number: ";
      cin >> newStd[i].number;
      cout << "\n\n\t\t Year[1, 2, 3, && 4]: ";
      cin >> newStd[i].year;
      cout << "\n\n\t\t Programme" << endl << "\n\t\t 1. Computer Science" << endl << "\n\t\t 2. Mathematics" << endl << "\n\t\t 3. Statistics" << endl << "\n\t\t 4. Information Technology " << endl << "\n\n\t\t Option: ";
      cin  >> newStd[i].program;

      switch(newStd[i].program){
      case 1:
            newStd[i].programme = "Computer Science";
         break;

      case 2:
            newStd[i].programme = "Mathematics";
         break;

      case 3:
            newStd[i].programme = "Statistics";
         break;

      case 4:
            newStd[i].programme = "Information Technology";
         break;

      default:
            newStd[i].programme = " ";
         break;
      }
      cout << endl << endl;
   }
}

//Add Staff
void addStaff(staff newStf[], int length){
   srand(time(0));

   for(int i = 0; i < length; i++){
      newStf[i].stfID = (rand() % 1000) + 11060401;

      cout << endl << "\n\n\t\t Staff " << i + 1  << " ID: " << newStf[i].stfID << endl;
      cout << "\n\n\t\t Firstname: ";
      cin >> newStf[i].firstname;
      cout << "\n\n\t\t Lastname: ";
      cin >> newStf[i].lastname;
      cout << "\n\n\t\t Sex [Male or Female]: ";
      cin >> newStf[i].gender;
      cout << "\n\n\t\t Date of Birth [dd-mm-yyyy]: ";
      cin >> newStf[i].dob;
      cout << "\n\n\t\t Phone Number: ";
      cin >> newStf[i].number;
      cout << "\n\n\t\t Year assigned to teach [1, 2, 3, && 4]: ";
      cin >> newStf[i].year;
      cout << "\n\n\t\t Specialist Field" << endl << "\n\t\t 1. Computer Science" << endl << "\n\t\t 2. Mathematics" << endl << "\n\t\t 3. Statistics" << endl << "\n\t\t 4. Information Technology " << endl << "\n\n\t\t Option: ";
      cin  >> newStf[i].program;

      switch(newStf[i].program){
      case 1:
            newStf[i].programme = "Computer Science";
         break;

      case 2:
            newStf[i].programme = "Mathematics";
         break;

      case 3:
            newStf[i].programme = "Statistics";
         break;

      case 4:
            newStf[i].programme = "Information Technology";
         break;

      default:
            newStf[i].programme = " ";
         break;
      }
      cout << endl << endl;
   }
}

void showStudent(newStd newStd[], int length, int id){

   for(int i = 0; i < length; i++){

      if((newStd[i].stdID != id)){
         continue;
      }
      cout << endl;
      cout << "\n\n\t\t Full Name: " << newStd[i].lastname << ", " << newStd[i].firstname << endl;
      cout << "\n\n\t\t Sex: " << newStd[i].gender  << endl;
      cout << "\n\n\t\t Date of Birth: " << newStd[i].dob << endl;
      cout << "\n\n\t\t Phone number: " << newStd[i].number << endl;
      cout << "\n\n\t\t Year: " << newStd[i].year << endl;
      cout << "\n\n\t\t Programme: " << newStd[i].programme << endl;
   }
   cout << endl << endl;
}

void showStaff(staff newStf[], int length, int id){

   for(int i = 0; i < length; i++){

      if((newStf[i].stfID != id)){
         continue;
      }
      cout << endl;
      cout << "\n\n\t\t Full Name: " << newStf[i].lastname << ", " << newStf[i].firstname << endl;
      cout << "\n\n\t\t Sex: " << newStf[i].gender  << endl;
      cout << "\n\n\t\t Date of Birth: " << newStf[i].dob << endl;
      cout << "\n\n\t\t Phone number: " << newStf[i].number << endl;
      cout << "\n\n\t\t Year: " << newStf[i].year << endl;
      cout << "\n\n\t\t Programme: " << newStf[i].programme << endl;
   }
   cout << endl << endl;
}

void deleteStudent(newStd newStd[], int length, int id){

   for(int i = 0; i < length; i++){
      if(newStd[i].stdID == id){
            newStd[i].stdID = 0;
            newStd[i].firstname = "";
            newStd[i].lastname = "";
            newStd[i].gender = "";
            newStd[i].dob = "";
            newStd[i].number = 0;
            newStd[i].year = 0;
            newStd[i].program = 0;
            newStd[i].programme = "";
      }

      else if(newStd[i].stdID == 0){
         cout << endl << "\n\n\t\t ****** No Records ******" << endl;
      }

      else
         break;

   }
   cout << endl << endl;
}

void deleteStaff(staff newStf[], int length, int id){

   for(int i = 0; i < length; i++){
      if(newStf[i].stfID == id){
         newStf[i].stfID = 0;
         newStf[i].firstname = "";
         newStf[i].lastname = "";
         newStf[i].gender = "";
         newStf[i].dob = "";
         newStf[i].number = 0;
         cout << endl << "\n\n\t\t No Records" << endl;
      }

      else{
         cout << endl << "\n\n\t\t ****** No Records ******" << endl;
      }
   }
   cout << endl << endl;
}

void editStudent(newStd newStd[], int id, int contact, string pChange){
   int i;

   i = 0;
   while(i){
      if(newStd[i].stdID == id){
         newStd[i].number = 0;
         newStd[i].number = contact;
         newStd[i].programme = "";
         newStd[i].programme = pChange;
      }

      else{
         break;
      }

      i++;
   }

   cout << endl << endl;
}

void editStaff(staff newStf[], int id, int contact){
   int i;

   i = 0;
   while(i){
      if(newStf[i].stfID == id){
         newStf[i].number = 0;
         newStf[i].number = contact;
      }

      else{
         break;
      }
      i++;
   }
   cout << endl << endl;
}

void assignedCourses(newStd newStd[], int id, int length){
   int j, i;

   i = 0, length = total;
   //sub1:
   for(i = 0; i < length; i++){ // while( i < length)
      while(newStd[i].stdID == id){

         switch(newStd[i].year){

         // Year 1
         case 1:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].firstYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].firstYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].firstYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].firstYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }

            cout << endl;
            break;

            //Year 2
         case 2:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].secondYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\nsetw(18)\t " << getMaths[j].secondYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].secondYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].secondYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }
            cout << endl;
            break;


         // Year 3
         case 3:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].thirdYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].thirdYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].thirdYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].thirdYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }

            cout << endl;
            break;


         // Year 4
         case 4:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].fourthYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].fourthYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].fourthYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].fourthYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }

            cout << endl;
            break;


         default:
            cout << "\n\n\n\t\t **** You have not been assigned to any course[s] OR Check your student year status and enter again. *****" << endl;
            Sleep(5000);
            system("cls");
            //goto sub1;
            break;
         }

         i++;
         break;
      }

   }

}

void getGradePoint(){
   int j;

   for(j = 0; j < NUM_OF_COURSES; j++){
      if(gpa[j].grade == "A" || gpa[j].grade == "a")
      gpa[j].gradePoint = 4.00;

      else if(gpa[j].grade == "B+" || gpa[j].grade == "b+")
         gpa[j].gradePoint = 3.50;

      else if(gpa[j].grade == "B" || gpa[j].grade == "b")
         gpa[j].gradePoint = 3.00;

      else if(gpa[j].grade == "C+" || gpa[j].grade == "c+")
         gpa[j].gradePoint = 2.50;

      else if(gpa[j].grade == "C" || gpa[j].grade == "c")
         gpa[j].gradePoint = 2.00;

      else if(gpa[j].grade == "D+" || gpa[j].grade == "d+")
         gpa[j].gradePoint = 1.50;

      else if(gpa[j].grade == "D" || gpa[j].grade == "d")
         gpa[j].gradePoint = 1.00;

      else if(gpa[j].grade == "E" || gpa[j].grade == "e")
         gpa[j].gradePoint = 0.50;

      else if(gpa[j].grade == "F" || gpa[j].grade == "f")
         gpa[j].gradePoint = 0.00;

      else
         gpa[j].gradePoint = 0.00;
   }

}

void recordGrade(staff newStf[], int id, newStd newStd[], int length){

   int j, i, k;

   i = 0;

   while(i < TOTAL_ && i < total){

      if(newStf[i].stfID == id){

         sub1:
         switch(newStf[i].year){

         case 1:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;

                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

            }

            break;

         case 2:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }
            }

            break;

         case 3:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }
            }
            break;

         case 4:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }
            }
            break;

         default:
            cout << "\n\n\n\t\t Enter your corresponding year assingned to and specialist field to record grade for approriate student" << endl;
            break;
         }
      }

      else{
         cout << "\n\n\n\t\t\a **** Incorrect Student ID. ****" << endl << endl;
         Sleep(5000);
         system("cls");
         goto sub1;
      }

      i++;
      break;
   }

}

int TotalCredit(){
   int credit = 0, j = 0;
   newStd newStd[total];

   while(j < total){
      if(newStd[j].programme == "Computer Science"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getComputer[i].csCredit[i];
         }
      }

      else if(newStd[j].programme == "Mathematics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getMaths[i].maCredit[i];
         }
      }

      else if(newStd[j].programme == "Statistics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getStat[i].staCredit[i];
         }
      }

      else{
        for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getInfo[i].infoCredit[i];
         }
      }

      j++;
      break;
   }


   return credit;
}

float TotalGradePoint(){
  int gradepoint = 0, j = 0;
   newStd newStd[total];

   while(j < total){
      if(newStd[j].programme == "Computer Science"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getComputer[i].csCredit[i] * gpa[i].gradePoint);
         }
      }

      else if(newStd[j].programme == "Mathematics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getMaths[i].maCredit[i] * gpa[i].gradePoint);
         }
      }

      else if(newStd[j].programme == "Statistics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getStat[i].staCredit[i] * gpa[i].gradePoint);
         }
      }

      else{
        for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getInfo[i].infoCredit[i] * gpa[i].gradePoint);
         }
      }

      j++;
      break;
   }

   return gradepoint;
}

float GradePointAverage(){
   float overallPerformance = 0.0;

   overallPerformance = TotalGradePoint() / TotalCredit();

   return overallPerformance;
}

string classObtained(){
   string classDivision = "";

   if(GradePointAverage() <= 4.00 && GradePointAverage() >= 3.60)
      classDivision = "First Class Division";

   else if(GradePointAverage() <= 3.50 && GradePointAverage() >= 3.00)
      classDivision = "Second Class Upper Division";

   else if(GradePointAverage() <= 2.99 && GradePointAverage() >= 2.00)
      classDivision = "Second Class Lower Division";

   else if(GradePointAverage() <= 1.99 && GradePointAverage() >= 1.00)
      classDivision = "Third Class Division";

   else if(GradePointAverage() <= 0.99 && GradePointAverage() >= 0.00)
      classDivision = "Fail";

   else
      classDivision = "N/A";

   return classDivision;
}

void displayReport(newStd newStd[], int id){
   int i = 0;

   while(i < total){

      if(newStd[i].stdID == id){
         cout << fixed << showpoint << setprecision(2);

         cout << "\n\n\t\t Student ID: " << newStd[i].stdID << "\t Name: " << newStd[i].lastname << ", " << newStd[i].firstname << endl;
         cout << "\n\n -------------------------------------------------------------------------------------------------------------";
         cout << "\n\n Course[s]  \t\t\t\t\t\t Credit  \t\t Grade  \t Grade Point" << "\n\n -------------------------------------------------------------------------------------------------------------";

         switch(newStd[i].year){

         case 1:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].firstYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].firstYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].firstYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].firstYear[j] << "\t\t " << right << setw(1) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         case 2:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].secondYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].secondYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].secondYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].secondYear[j] << "t\t " << right << setw(4) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         case 3:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].thirdYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].thirdYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].thirdYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].thirdYear[j] << "\t\t " << right << setw(4) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         case 4:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].fourthYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].fourthYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].fourthYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].fourthYear[j] << "\t\t " << right << setw(4) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         }

         cout << endl;
         cout << "\n\n -------------------------------------------------------------------------------------------------------------";
         cout << "\n\n\t\t\t\t\t  total Credit : " << right << setw(3) << TotalCredit() << " \t\t\t     total Grade Point : " << setw(4) << TotalGradePoint() << endl;
         cout << "\n\n\n\n\n\t\t Grade Point Average : " << right << setw(4) << GradePointAverage() << endl
         << right << " \n\n\t\t Class Obtained : " << setw(4) << classObtained() << endl;
      }

      else {
         cout << "\n\n\t\t ***** No records for the student ******" << endl;
      }

      i++;
      break;
   }

}


	


int main() {
	
	start:
		cout<<"______________________________________________________________\n\n";
		cout<<"\tSuccess International School Management System\n";
		cout<<"______________________________________________________________\n\n";
		cout<<"\t\t\tMain Menu\n\n";
		cout<<"\t\tEnter your option\n";
		cout<<"\t\t>>> [1] Administrator option\n";
		cout<<"\t\t>>> [2] Student option\n";
		cout<<"\t\t>>> [3] Staff option\n";
		cout<<"\t\t>>> [4] Close Program\n\n";
		cin>>menuOption;
		system("cls");
		switch(menuOption) {
			
			case 1:
				sub:
					system("cls");
					cout<<"______________________________________________________________\n\n";
					cout<<"\t\t\tStudent Menu\n";
					cout<<"______________________________________________________________\n";
					cout << "\n\t\t >>>[1] Add New Student\n";
			        cout << "\n\t\t >>>[2] Add New Staff\n\n";
			        cout << "\n\t\t >>>[3] Delete Student or Staff\n";
			        cout << "\n\n\n\t\t >>>[4] Go back to Main Menu\n\n";
			        cout << "\n\n\t\t Enter option: ";
			        cin >> adminOption;
			         
			         switch(adminOption) {
			         	case 1:
			         		system("cls");
			         		cout<<"______________________________________________________________\n\n";
							cout<<"\t\t\tStudent Menu\n";
							cout<<"______________________________________________________________\n\n";
							cout << "\t\t Enter the number of student[s] to record: ";
			                  cin >> adminResponse;
			
			                  if(adminResponse > total){
			                     goto sub;
			                  }
			                  
			                  else{
			                     addStd(newStd, adminResponse);
			                     cout <<"\n\n\t\t Records sucessfully added \n\n" << endl;
			                     cout <<"\t\t Enter [00] to go back or [99] to main menu: ";
			                     cin >> returnOption;
			
			                     if(returnOption == 00){
			                        goto sub;
			                     }
			
			                     else
			                        system("cls");
			                        goto start;
			
			                  }
			               }
			               
			               case 2:
			               	system("cls");
			               	cout<<"______________________________________________________________\n\n";
							cout<<"\t\t\tStaff Menu\n";
							cout<<"______________________________________________________________\n\n";
							cout << "\n\n\t\t Enter the number of staff[s] to record: ";
			                  cin >> adminResponse;
			
			                  if(adminResponse > TOTAL_) {
			                     goto sub;
			                  }
			
			                  else {
			                     addStaff(stf, adminResponse);
			                     cout << "\n\n\t\t ***** Records sucessfully added *****" << endl;
			                     cout << "\n\n\t\t Enter [00] to go back or [99] to main menu: ";
			                     cin >> returnOption;
			
			                     if(returnOption == 00){
			                        goto sub;
			                     }
			
			                     else
			                        system("cls");
			                        goto start;
			
			                  }
			
			               } break;
			               
			               case 3:
			               	system("cls");
			               	cout<<"\t\t\tDelete\n\n";
			               	cout<<"\t\tTo delete student, enter 1\nTo delete staff, enter 2: ";
			               	cin>>delOption;
			               	cout<<endl<<endl;
			               	
			               	if(delOption == 1) {
			               		cout<<"\t\tEnter student ID: ";
			               		cin>>id;
			               		
			               		displayStd(stdList, adminResponse, id);
			               		
			               		cout<<endl;
			               		cout<<"\n\t\tDo you want to delete the above record?\n\n";
			               		cout<<"Y or y - Yes or N or n - No: ";
			               		cin>>delOption;
			               		
			               		if(delOption == "y" || delOption == "y") {
			               			delStud(stdList, adminRespons, id);
			               			
								   }
								   else {
								   	system("cls");
								   	goto sub;
								   	
								   }
							   }
			               	else {
			               		cout<<endl;
			               		cout<<"\t\tEnter the staff ID: ";
			               		cin>>id;
			               		
			               		display(stf, adminResponse, id);
			               		cout<<endl;
			               		cout<<"\t\tDo you want to delete the above record?\n\n";
			               		cout<<"Y or y - Yes or N or n - No: ";
			               		cin>> delOption;
			               		
			               		if(delOption == 1) {
			               			delStaff(stf, adminResponse, id);
								   }
								   else {
								   	system("cls");
								   	goto sub;
								   }
							   }
							   
							   cout<<"\t\tRecords has been successfully deleted!\n\n";
							   cout<<"Enter [00] to go back or [99] to main menu: ";
							   cin>>returnOption;
							   
									if(returnOption == 00) {
										goto sub;
									}
									
									else {
										system("cls");
										goto start;
									}
								}
								break;
								
								case 4:
									system("cls");
									goto start;
									break;
									
							break;
				// Menu option 2			
				case 2:
					sub1:
					cout<<"\t______________________________________________________________\n\n";
					cout<<"\t\t\tStudent Menu\n";
					cout<<"\t______________________________________________________________\n";
					
					cout<<"\tEnter your student ID: ";
					cin>>id;
					
					for(int n = 0; n < total; n++) {
						if(stdList[n].id == id){
		                 cout << "\n\n\n\t\t [1] View courses for "<< stdList[n].id << endl;
		                 cout << "\n\n\t\t [2] Edit personal information" << endl;
		                 cout << "\n\n\t\t [3] Academic Report" << endl;
		                 cout << "\n\n\t\t [4] Go back to Main Menu" << endl;
		                 cout << "\n\n\t\t Enter option: ";
		                 
						 cin >> stdOption;
						 
						 system("cls");
						 if(stdOption == 1) {
						 	cout<<"\t\t\tCourses Assigned to "<<stdList[n].id;
						 	cout<< left << setw(12) << "\n\n\t\t Course Code " << right << setw(18) << "\t\t\t\t\t\t Credit"
							cout<< "\n\t\t -------------------------------------------------------------------------------------------";
							
							assignedCourses(stdList, id, total);
						 }
						 else if(stdOption == 2) {
						 	cout<<"\t\t\tEdit Personal Information\n\n";
						 	displayStudent(stdList, total, id);
						 	cout<<"\n\t\tEnter new contact: ";
						 	cin>>changeNum;
						 	cout<<"\n\t\tEnter new programme: ";
						 	cin>>changePrg;
						 	
						 	editStd(stdList, id, changeNum, changePrg)
						 	cout<<"\n\n\tRecord has been successfully saved!";	
						}
						 
						 else if (stdOption == 3) {
						 	cout<<"\n\t\t\tAcademic Report";
						 	displayRpt(stdList, id);
						 }
						 else if (stdOption == 4){
						 	system("cls");
						 	goto start;
						 }
						 else {
						 	cout<<"\nWrong input, check your selection!";
						 	Sleep(3000);
						 	goto sub1;
						 }
						 
				break;
					
				case 3:
					sub2:
						cout<<"_____________________________________________";
						cout<<"\n\t\t\tStaff Menu\n\n";
						cout<<"_____________________________________________";
						cout<<"\tEnter your Staff ID: ";
						cin>>id;
						
						for (int m = 0; m < staffTotal; m++) {
							if(stdList[m].id == id) {
								cout << "\n\n\n\t\t [1] Record student grade" << endl;
				                 cout << "\n\n\t\t [2] Edit personal information" << endl;
				                 cout << "\n\n\t\t [3] Go back to Main Menu" << endl;
				                 cout << "\n\n\t\t Enter option: ";
				                 cin >> stfOption;
				                 
				                 system("cls");
				                 if(stfOption == 1) {
				                 	sub3:
				                 		cout<<"\n\t\t\tRecord Student Grade\n";
				                 		cout << "\n\n\t\t Enter the number of student[s] to record grade: ";
				                 		cin>>stfLength;
				                 		
				                 		system("cls");
						            
						                    if(stfLength >= total){
						                       cout << "\n\n\t\t\a Enter between 1 - 100" << endl;
						                       Sleep(5000);
						                       system("cls");
						                       goto sub3;
						                    }
						
						                    else{
						                       recordGrade(stfList, staffID, stdList, stfLength);
						                       cout << endl << "\n\n\t\tGrade[s] sucessfully recorded" << endl;
						                    }
						                 }
						                 
						                 else if(stafOption == 2){
							                    cout << "\n\t\t\t ----------- EDIT PERSONAL INFORMATION ----------" << endl << endl;
							                    showStaff(stfList, TOTAL_, staffID);
							                    cout << "\n\n\n\t\t Enter new contact number: ";
							                    cin >> stafNumber;
							
							                    editStaff(stfList, staffID, stafNumber);
							                    cout << endl << "\n\n\t\t ***** Records sucessfully edited *****" << endl;
							                 }
							
							                 else if(stfOption == 3){
							                    system("cls");
							                    goto START;
                 								}
								 }
							}	
						}	
			}
					
				
/** Function Definition */


//Add student
void addStudent(newStd newStd[], int length){
   srand(time(0));

   for(int i = 0; i < length; i++){
      newStd[i].stdID = (rand() % 1000) + 10152431;

      cout << endl << "\n\n\t\t Student " << i + 1  << " ID: " << newStd[i].stdID << endl;
      cout << "\n\n\t\t Firstname: ";
      cin >> newStd[i].firstname;
      cout << "\n\n\t\t Lastname: ";
      cin >> newStd[i].lastname;
      cout << "\n\n\t\t Sex [Male or Female]: ";
      cin >> newStd[i].gender;
      cout << "\n\n\t\t Date of Birth [dd-mm-yyyy]: ";
      cin >> newStd[i].dob;
      cout << "\n\n\t\t contact Number: ";
      cin >> newStd[i].number;
      cout << "\n\n\t\t Year[1, 2, 3, && 4]: ";
      cin >> newStd[i].year;
      cout << "\n\n\t\t Programme" << endl << "\n\t\t 1. Computer Science" << endl << "\n\t\t 2. Mathematics" << endl << "\n\t\t 3. Statistics" << endl << "\n\t\t 4. Information Technology " << endl << "\n\n\t\t Option: ";
      cin  >> newStd[i].program;

      switch(newStd[i].program){
      case 1:
            newStd[i].programme = "Computer Science";
         break;

      case 2:
            newStd[i].programme = "Mathematics";
         break;

      case 3:
            newStd[i].programme = "Statistics";
         break;

      case 4:
            newStd[i].programme = "Information Technology";
         break;

      default:
            newStd[i].programme = " ";
         break;
      }
      cout << endl << endl;
   }
}

//Add Staff
void addStaff(staff newStf[], int length){
   srand(time(0));

   for(int i = 0; i < length; i++){
      newStf[i].stfID = (rand() % 1000) + 11060401;

      cout << endl << "\n\n\t\t Staff " << i + 1  << " ID: " << newStf[i].stfID << endl;
      cout << "\n\n\t\t Firstname: ";
      cin >> newStf[i].firstname;
      cout << "\n\n\t\t Lastname: ";
      cin >> newStf[i].lastname;
      cout << "\n\n\t\t Sex [Male or Female]: ";
      cin >> newStf[i].gender;
      cout << "\n\n\t\t Date of Birth [dd-mm-yyyy]: ";
      cin >> newStf[i].dob;
      cout << "\n\n\t\t Phone Number: ";
      cin >> newStf[i].number;
      cout << "\n\n\t\t Year assigned to teach [1, 2, 3, && 4]: ";
      cin >> newStf[i].year;
      cout << "\n\n\t\t Specialist Field" << endl << "\n\t\t 1. Computer Science" << endl << "\n\t\t 2. Mathematics" << endl << "\n\t\t 3. Statistics" << endl << "\n\t\t 4. Information Technology " << endl << "\n\n\t\t Option: ";
      cin  >> newStf[i].program;

      switch(newStf[i].program){
      case 1:
            newStf[i].programme = "Computer Science";
         break;

      case 2:
            newStf[i].programme = "Mathematics";
         break;

      case 3:
            newStf[i].programme = "Statistics";
         break;

      case 4:
            newStf[i].programme = "Information Technology";
         break;

      default:
            newStf[i].programme = " ";
         break;
      }
      cout << endl << endl;
   }
}

void showStudent(newStd newStd[], int length, int id){

   for(int i = 0; i < length; i++){

      if((newStd[i].stdID != id)){
         continue;
      }
      cout << endl;
      cout << "\n\n\t\t Full Name: " << newStd[i].lastname << ", " << newStd[i].firstname << endl;
      cout << "\n\n\t\t Sex: " << newStd[i].gender  << endl;
      cout << "\n\n\t\t Date of Birth: " << newStd[i].dob << endl;
      cout << "\n\n\t\t Phone number: " << newStd[i].number << endl;
      cout << "\n\n\t\t Year: " << newStd[i].year << endl;
      cout << "\n\n\t\t Programme: " << newStd[i].programme << endl;
   }
   cout << endl << endl;
}

void showStaff(staff newStf[], int length, int id){

   for(int i = 0; i < length; i++){

      if((newStf[i].stfID != id)){
         continue;
      }
      cout << endl;
      cout << "\n\n\t\t Full Name: " << newStf[i].lastname << ", " << newStf[i].firstname << endl;
      cout << "\n\n\t\t Sex: " << newStf[i].gender  << endl;
      cout << "\n\n\t\t Date of Birth: " << newStf[i].dob << endl;
      cout << "\n\n\t\t Phone number: " << newStf[i].number << endl;
      cout << "\n\n\t\t Year: " << newStf[i].year << endl;
      cout << "\n\n\t\t Programme: " << newStf[i].programme << endl;
   }
   cout << endl << endl;
}

void deleteStudent(newStd newStd[], int length, int id){

   for(int i = 0; i < length; i++){
      if(newStd[i].stdID == id){
            newStd[i].stdID = 0;
            newStd[i].firstname = "";
            newStd[i].lastname = "";
            newStd[i].gender = "";
            newStd[i].dob = "";
            newStd[i].number = 0;
            newStd[i].year = 0;
            newStd[i].program = 0;
            newStd[i].programme = "";
      }

      else if(newStd[i].stdID == 0){
         cout << endl << "\n\n\t\t ****** No Records ******" << endl;
      }

      else
         break;

   }
   cout << endl << endl;
}

void deleteStaff(staff newStf[], int length, int id){

   for(int i = 0; i < length; i++){
      if(newStf[i].stfID == id){
         newStf[i].stfID = 0;
         newStf[i].firstname = "";
         newStf[i].lastname = "";
         newStf[i].gender = "";
         newStf[i].dob = "";
         newStf[i].number = 0;
         cout << endl << "\n\n\t\t No Records" << endl;
      }

      else{
         cout << endl << "\n\n\t\t ****** No Records ******" << endl;
      }
   }
   cout << endl << endl;
}

void editStudent(newStd newStd[], int id, int contact, string pChange){
   int i;

   i = 0;
   while(i){
      if(newStd[i].stdID == id){
         newStd[i].number = 0;
         newStd[i].number = contact;
         newStd[i].programme = "";
         newStd[i].programme = pChange;
      }

      else{
         break;
      }

      i++;
   }

   cout << endl << endl;
}

void editStaff(staff newStf[], int id, int contact){
   int i;

   i = 0;
   while(i){
      if(newStf[i].stfID == id){
         newStf[i].number = 0;
         newStf[i].number = contact;
      }

      else{
         break;
      }
      i++;
   }
   cout << endl << endl;
}

void assignedCourses(newStd newStd[], int id, int length){
   int j, i;

   i = 0, length = total;
   //sub1:
   for(i = 0; i < length; i++){ // while( i < length)
      while(newStd[i].stdID == id){

         switch(newStd[i].year){

         // Year 1
         case 1:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].firstYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].firstYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].firstYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].firstYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }

            cout << endl;
            break;

            //Year 2
         case 2:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].secondYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\nsetw(18)\t " << getMaths[j].secondYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].secondYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].secondYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }
            cout << endl;
            break;


         // Year 3
         case 3:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].thirdYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].thirdYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].thirdYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].thirdYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }

            cout << endl;
            break;


         // Year 4
         case 4:
            if(newStd[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].fourthYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].fourthYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(newStd[i].programme == "Statistics"){
              for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getStat[j].fourthYear[j] << right << setw(18)<< "\t " << getStat[j].staCredit[j];
               }
            }

            else{
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getInfo[j].fourthYear[j] << right << setw(18)<< "\t " << getInfo[j].infoCredit[j];
               }
            }

            cout << endl;
            break;


         default:
            cout << "\n\n\n\t\t **** You have not been assigned to any course[s] OR Check your student year status and enter again. *****" << endl;
            Sleep(5000);
            system("cls");
            //goto sub1;
            break;
         }

         i++;
         break;
      }

   }

}

void getGradePoint(){
   int j;

   for(j = 0; j < NUM_OF_COURSES; j++){
      if(gpa[j].grade == "A" || gpa[j].grade == "a")
      gpa[j].gradePoint = 4.00;

      else if(gpa[j].grade == "B+" || gpa[j].grade == "b+")
         gpa[j].gradePoint = 3.50;

      else if(gpa[j].grade == "B" || gpa[j].grade == "b")
         gpa[j].gradePoint = 3.00;

      else if(gpa[j].grade == "C+" || gpa[j].grade == "c+")
         gpa[j].gradePoint = 2.50;

      else if(gpa[j].grade == "C" || gpa[j].grade == "c")
         gpa[j].gradePoint = 2.00;

      else if(gpa[j].grade == "D+" || gpa[j].grade == "d+")
         gpa[j].gradePoint = 1.50;

      else if(gpa[j].grade == "D" || gpa[j].grade == "d")
         gpa[j].gradePoint = 1.00;

      else if(gpa[j].grade == "E" || gpa[j].grade == "e")
         gpa[j].gradePoint = 0.50;

      else if(gpa[j].grade == "F" || gpa[j].grade == "f")
         gpa[j].gradePoint = 0.00;

      else
         gpa[j].gradePoint = 0.00;
   }

}

void recordGrade(staff newStf[], int id, newStd newStd[], int length){

   int j, i, k;

   i = 0;

   while(i < TOTAL_ && i < total){

      if(newStf[i].stfID == id){

         sub1:
         switch(newStf[i].year){

         case 1:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;

                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

            }

            break;

         case 2:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }
            }

            break;

         case 3:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }
            }
            break;

         case 4:
            for(k = 0; k < length; k++){
               if((newStd[i].programme == "Computer Science") && (newStf[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Mathematics") && (newStf[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((newStd[i].programme == "Statistics") && (newStf[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << newStd[k].stdID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getInfo[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }
            }
            break;

         default:
            cout << "\n\n\n\t\t Enter your corresponding year assingned to and specialist field to record grade for approriate student" << endl;
            break;
         }
      }

      else{
         cout << "\n\n\n\t\t\a **** Incorrect Student ID. ****" << endl << endl;
         Sleep(5000);
         system("cls");
         goto sub1;
      }

      i++;
      break;
   }

}

int TotalCredit(){
   int credit = 0, j = 0;
   newStd newStd[total];

   while(j < total){
      if(newStd[j].programme == "Computer Science"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getComputer[i].csCredit[i];
         }
      }

      else if(newStd[j].programme == "Mathematics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getMaths[i].maCredit[i];
         }
      }

      else if(newStd[j].programme == "Statistics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getStat[i].staCredit[i];
         }
      }

      else{
        for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getInfo[i].infoCredit[i];
         }
      }

      j++;
      break;
   }


   return credit;
}

float TotalGradePoint(){
  int gradepoint = 0, j = 0;
   newStd newStd[total];

   while(j < total){
      if(newStd[j].programme == "Computer Science"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getComputer[i].csCredit[i] * gpa[i].gradePoint);
         }
      }

      else if(newStd[j].programme == "Mathematics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getMaths[i].maCredit[i] * gpa[i].gradePoint);
         }
      }

      else if(newStd[j].programme == "Statistics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getStat[i].staCredit[i] * gpa[i].gradePoint);
         }
      }

      else{
        for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getInfo[i].infoCredit[i] * gpa[i].gradePoint);
         }
      }

      j++;
      break;
   }

   return gradepoint;
}

float GradePointAverage(){
   float overallPerformance = 0.0;

   overallPerformance = TotalGradePoint() / TotalCredit();

   return overallPerformance;
}

string classObtained(){
   string classDivision = "";

   if(GradePointAverage() <= 4.00 && GradePointAverage() >= 3.60)
      classDivision = "First Class Division";

   else if(GradePointAverage() <= 3.50 && GradePointAverage() >= 3.00)
      classDivision = "Second Class Upper Division";

   else if(GradePointAverage() <= 2.99 && GradePointAverage() >= 2.00)
      classDivision = "Second Class Lower Division";

   else if(GradePointAverage() <= 1.99 && GradePointAverage() >= 1.00)
      classDivision = "Third Class Division";

   else if(GradePointAverage() <= 0.99 && GradePointAverage() >= 0.00)
      classDivision = "Fail";

   else
      classDivision = "N/A";

   return classDivision;
}

void displayReport(newStd newStd[], int id){
   int i = 0;

   while(i < total){

      if(newStd[i].stdID == id){
         cout << fixed << showpoint << setprecision(2);

         cout << "\n\n\t\t Student ID: " << newStd[i].stdID << "\t Name: " << newStd[i].lastname << ", " << newStd[i].firstname << endl;
         cout << "\n\n -------------------------------------------------------------------------------------------------------------";
         cout << "\n\n Course[s]  \t\t\t\t\t\t Credit  \t\t Grade  \t Grade Point" << "\n\n -------------------------------------------------------------------------------------------------------------";

         switch(newStd[i].year){

         case 1:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].firstYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].firstYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].firstYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].firstYear[j] << "\t\t " << right << setw(1) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         case 2:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].secondYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].secondYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].secondYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].secondYear[j] << "t\t " << right << setw(4) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         case 3:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].thirdYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].thirdYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].thirdYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].thirdYear[j] << "\t\t " << right << setw(4) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         case 4:
            getGradePoint();
            if(newStd[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].fourthYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].fourthYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(newStd[i].programme == "Statistics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getStat[j].fourthYear[j] << "\t\t " << right << setw(4) << getStat[j].staCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getStat[j].staCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else{
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getInfo[j].fourthYear[j] << "\t\t " << right << setw(4) << getInfo[j].infoCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getInfo[j].infoCredit[j] * gpa[j].gradePoint << " ";
               }
            }
            break;

         }

         cout << endl;
         cout << "\n\n -------------------------------------------------------------------------------------------------------------";
         cout << "\n\n\t\t\t\t\t  total Credit : " << right << setw(3) << TotalCredit() << " \t\t\t     total Grade Point : " << setw(4) << TotalGradePoint() << endl;
         cout << "\n\n\n\n\n\t\t Grade Point Average : " << right << setw(4) << GradePointAverage() << endl
         << right << " \n\n\t\t Class Obtained : " << setw(4) << classObtained() << endl;
      }

      else {
         cout << "\n\n\t\t ***** No records for the student ******" << endl;
      }

      i++;
      break;
   }

}

	
