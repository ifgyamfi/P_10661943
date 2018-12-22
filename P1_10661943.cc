//End of semester project
//
//Build a school management system with the following features
//1. Add, edit or delete courses
//2. Add, edit or delete students
//3. Add, edit or delete staff
//4. Assign students to courses
//5. Record student grade
//6. Print academic record of students

//Note: The program has the courses added in an array for a given programmes in the Sciences.
//Students have options in Computer Science, Information Technology, Statistics and Mathematics

#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

/** Global variable */
const int STUDENT_TOTAL = 150, STAFF_TOTAL = 50, NUM_OF_COURSES = 5;

struct student{
   string fname, lname, gender, dob, programme;
   int number, program, year, studID;
};

struct staffData{
   string fname, lname, gender, dob, programme;
   int number, program, staff_ID, year;
};

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

/** Struct instances */
student studentList[STUDENT_TOTAL];
staffData stafID[STAFF_TOTAL];
ComputerScience getComputer[NUM_OF_COURSES];
Mathematics getMaths[NUM_OF_COURSES];
Statistics getStat[NUM_OF_COURSES];
InformationTechnology getInfo[NUM_OF_COURSES];
GPA gpa[NUM_OF_COURSES];



/** Functions Definition */


//Function to Add student
void addStudent(student student[], int length){
   srand(time(0));

   for(int i = 0; i < length; i++){
      student[i].studID = (rand() % 1000) + 10152431;

      cout << endl << "\n\n\t\t Student " << i + 1  << " ID: " << student[i].studID << endl;
      cout << "\n\n\t\t Firstname: ";
      cin >> student[i].fname;
      cout << "\n\n\t\t Lastname: ";
      cin >> student[i].lname;
      cout << "\n\n\t\t Sex [Male or Female]: ";
      cin >> student[i].gender;
      cout << "\n\n\t\t Date of Birth [dd-mm-yyyy]: ";
      cin >> student[i].dob;
      cout << "\n\n\t\t Phone Number: ";
      cin >> student[i].number;
      cout << "\n\n\t\t Year[1, 2, 3, && 4]: ";
      cin >> student[i].year;
      cout << "\n\n\t\t Programme" << endl << "\n\t\t 1. Computer Science" << endl << "\n\t\t 2. Mathematics" << endl << "\n\t\t 3. Statistics" << endl << "\n\t\t 4. Information Technology " << endl << "\n\n\t\t Option: ";
      cin  >> student[i].program;

      switch(student[i].program){
      case 1:
            student[i].programme = "Computer Science";
         break;

      case 2:
            student[i].programme = "Mathematics";
         break;

      case 3:
            student[i].programme = "Statistics";
         break;

      case 4:
            student[i].programme = "Information Technology";
         break;

      default:
            student[i].programme = " ";
         break;
      }
      cout << endl << endl;
   }
}

//Function Add Staff
void addStaff(staffData staffdata[], int length){
   srand(time(0));

   for(int i = 0; i < length; i++){
      staffdata[i].staff_ID = (rand() % 1000) + 11060401;

      cout << endl << "\n\n\t\t Staff " << i + 1  << " ID: " << staffdata[i].staff_ID << endl;
      cout << "\n\n\t\t Firstname: ";
      cin >> staffdata[i].fname;
      cout << "\n\n\t\t Lastname: ";
      cin >> staffdata[i].lname;
      cout << "\n\n\t\t Sex [Male or Female]: ";
      cin >> staffdata[i].gender;
      cout << "\n\n\t\t Date of Birth [dd-mm-yyyy]: ";
      cin >> staffdata[i].dob;
      cout << "\n\n\t\t Phone Number: ";
      cin >> staffdata[i].number;
      cout << "\n\n\t\t Year assigned to teach [1, 2, 3, && 4]: ";
      cin >> staffdata[i].year;
      cout << "\n\n\t\t Specialist Field" << endl << "\n\t\t 1. Computer Science" << endl << "\n\t\t 2. Mathematics" << endl << "\n\t\t 3. Statistics" << endl << "\n\t\t 4. Information Technology " << endl << "\n\n\t\t Option: ";
      cin  >> staffdata[i].program;

      switch(staffdata[i].program){
      case 1:
            staffdata[i].programme = "Computer Science";
         break;

      case 2:
            staffdata[i].programme = "Mathematics";
         break;

      case 3:
            staffdata[i].programme = "Statistics";
         break;

      case 4:
            staffdata[i].programme = "Information Technology";
         break;

      default:
            staffdata[i].programme = " ";
         break;
      }
      cout << endl << endl;
   }
}

void showStudent(student student[], int length, int id){

   for(int i = 0; i < length; i++){

      if((student[i].studID != id)){
         continue;
      }
      cout << endl;
      cout << "\n\n\t\t Full Name: " << student[i].lname << ", " << student[i].fname << endl;
      cout << "\n\n\t\t Sex: " << student[i].gender  << endl;
      cout << "\n\n\t\t Date of Birth: " << student[i].dob << endl;
      cout << "\n\n\t\t Phone number: " << student[i].number << endl;
      cout << "\n\n\t\t Year: " << student[i].year << endl;
      cout << "\n\n\t\t Programme: " << student[i].programme << endl;
   }
   cout << endl << endl;
}

void showStaff(staffData staffdata[], int length, int id){

   for(int i = 0; i < length; i++){

      if((staffdata[i].staff_ID != id)){
         continue;
      }
      cout << endl;
      cout << "\n\n\t\t Full Name: " << staffdata[i].lname << ", " << staffdata[i].fname << endl;
      cout << "\n\n\t\t Sex: " << staffdata[i].gender  << endl;
      cout << "\n\n\t\t Date of Birth: " << staffdata[i].dob << endl;
      cout << "\n\n\t\t Phone number: " << staffdata[i].number << endl;
      cout << "\n\n\t\t Year: " << staffdata[i].year << endl;
      cout << "\n\n\t\t Programme: " << staffdata[i].programme << endl;
   }
   cout << endl << endl;
}

//function to delete students
void deleteStudent(student student[], int length, int id){

   for(int i = 0; i < length; i++){
      if(student[i].studID == id){
            student[i].studID = 0;
            student[i].fname = "";
            student[i].lname = "";
            student[i].gender = "";
            student[i].dob = "";
            student[i].number = 0;
            student[i].year = 0;
            student[i].program = 0;
            student[i].programme = "";
      }

      else if(student[i].studID == 0){
         cout << endl << "\n\n\t\t ****** No Records ******" << endl;
      }

      else
         break;

   }
   cout << endl << endl;
}

//function to delete staff
void deleteStaff(staffData staffdata[], int length, int id){

   for(int i = 0; i < length; i++){
      if(staffdata[i].staff_ID == id){
         staffdata[i].staff_ID = 0;
         staffdata[i].fname = "";
         staffdata[i].lname = "";
         staffdata[i].gender = "";
         staffdata[i].dob = "";
         staffdata[i].number = 0;
         cout << endl << "\n\n\t\t No Records" << endl;
      }

      else{
         cout << endl << "\n\n\t\t ****** No Records ******" << endl;
      }
   }
   cout << endl << endl;
}

//Function to edit student
void editStudent(student student[], int id, int phone, string pChange){
   int i;

   i = 0;
   while(i){
      if(student[i].studID == id){
         student[i].number = 0;
         student[i].number = phone;
         student[i].programme = "";
         student[i].programme = pChange;
      }

      else{
         break;
      }

      i++;
   }

   cout << endl << endl;
}
//function to edit staff
void editStaff(staffData staffdata[], int id, int phone){
   int i;

   i = 0;
   while(i){
      if(staffdata[i].staff_ID == id){
         staffdata[i].number = 0;
         staffdata[i].number = phone;
      }

      else{
         break;
      }
      i++;
   }
   cout << endl << endl;
}

void assignedCourses(student student[], int id, int length){
   int j, i;

   i = 0, length = STUDENT_TOTAL;
   //sub1:
   for(i = 0; i < length; i++){ // while( i < length)
      while(student[i].studID == id){

         switch(student[i].year){

         // Year 1
         case 1:
            if(student[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].firstYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].firstYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(student[i].programme == "Statistics"){
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
            if(student[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].secondYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\nsetw(18)\t " << getMaths[j].secondYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(student[i].programme == "Statistics"){
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
            if(student[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].thirdYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].thirdYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(student[i].programme == "Statistics"){
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
            if(student[i].programme == "Computer Science"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getComputer[j].fourthYear[j] << right << setw(18)<< "\t " << getComputer[j].csCredit[j];
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(j = 0; j < NUM_OF_COURSES; j++){
                  cout << left << setw(12) << "\n\n\t " << getMaths[j].fourthYear[j] << right << setw(18)<< "\t " << getMaths[j].maCredit[j];
               }
            }

            else if(student[i].programme == "Statistics"){
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

//function to get GPT
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
//function to record grade
void recordGrade(staffData staffdata[], int id, student student[], int length){

   int j, i, k;

   i = 0;

   while(i < STAFF_TOTAL && i < STUDENT_TOTAL){

      if(staffdata[i].staff_ID == id){

         sub1:
         switch(staffdata[i].year){

         case 1:
            for(k = 0; k < length; k++){
               if((student[i].programme == "Computer Science") && (staffdata[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;

                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Mathematics") && (staffdata[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Statistics") && (staffdata[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].firstYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
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
               if((student[i].programme == "Computer Science") && (staffdata[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Mathematics") && (staffdata[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Statistics") && (staffdata[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].secondYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
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
               if((student[i].programme == "Computer Science") && (staffdata[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Mathematics") && (staffdata[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Statistics") && (staffdata[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].thirdYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
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
               if((student[i].programme == "Computer Science") && (staffdata[i].programme == "Computer Science")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getComputer[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Mathematics") && (staffdata[i].programme == "Mathematics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getMaths[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else if((student[i].programme == "Statistics") && (staffdata[i].programme == "Statistics")){
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
                  for(j = 0; j < NUM_OF_COURSES; j++){
                     cout << "\n\t\t " << getStat[j].fourthYear[j] << ": ";
                     cin >> gpa[j].grade;
                     getGradePoint();
                  }
               }

               else {
                  cout << "\n\n\n\t\t Student " << k + 1 << " ID: " << student[k].studID << endl;
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
   student student[STUDENT_TOTAL];

   while(j < STUDENT_TOTAL){
      if(student[j].programme == "Computer Science"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getComputer[i].csCredit[i];
         }
      }

      else if(student[j].programme == "Mathematics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            credit += getMaths[i].maCredit[i];
         }
      }

      else if(student[j].programme == "Statistics"){
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
   student student[STUDENT_TOTAL];

   while(j < STUDENT_TOTAL){
      if(student[j].programme == "Computer Science"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getComputer[i].csCredit[i] * gpa[i].gradePoint);
         }
      }

      else if(student[j].programme == "Mathematics"){
         for(int i = 0; i < NUM_OF_COURSES; i++){
            getGradePoint();
            gradepoint += (getMaths[i].maCredit[i] * gpa[i].gradePoint);
         }
      }

      else if(student[j].programme == "Statistics"){
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

void displayReport(student student[], int id){
   int i = 0;

   while(i < STUDENT_TOTAL){

      if(student[i].studID == id){
         cout << fixed << showpoint << setprecision(2);

         cout << "\n\n\t\t Student ID: " << student[i].studID << "\t Name: " << student[i].lname << ", " << student[i].fname << endl;
         cout << "\n\n -------------------------------------------------------------------------------------------------------------";
         cout << "\n\n Course[s]  \t\t\t\t\t\t Credit  \t\t Grade  \t Grade Point" << "\n\n -------------------------------------------------------------------------------------------------------------";

         switch(student[i].year){

         case 1:
            getGradePoint();
            if(student[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].firstYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].firstYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Statistics"){
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
            if(student[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].secondYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].secondYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Statistics"){
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
            if(student[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].thirdYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].thirdYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Statistics"){
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
            if(student[i].programme == "Computer Science"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getComputer[j].fourthYear[j] << "\t\t " << right << setw(4) << getComputer[j].csCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getComputer[j].csCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Mathematics"){
               for(int j = 0; j < NUM_OF_COURSES; j++){
                  cout << "\n\n\n " << left << setw(2) << getMaths[j].fourthYear[j] << "\t\t " << right << setw(4) << getMaths[j].maCredit[j] << "\t\t " << setw(6) << gpa[j].grade << "\t "
                  << setw(12) << getMaths[j].maCredit[j] * gpa[j].gradePoint << " ";
               }
            }

            else if(student[i].programme == "Statistics"){
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
         cout << "\n\n\t\t\t\t\t  Total Credit : " << right << setw(3) << TotalCredit() << " \t\t\t     Total Grade Point : " << setw(4) << TotalGradePoint() << endl;
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






int main(){

   int option, adminOption, adminResponse, backOption, delOption, studentID, staffID, ch, studOption, newNumber, stafOption, stafNumber, exitOption, stafLength;
   string newProgram;

   START:
      cout << "\n\t\t\t --------------- SCHOOL MANAGEMENT SYSTEM ---------------" << "\n\t\t\t ________________________________________________________" << endl << endl;
      cout << "\n\n\t\t ----------- MAIN MENU ----------" << endl;
      cout << endl << "\n\t\t 1. Administrator" << endl;
      cout << "\n\t\t 2. Student" << endl;
      cout << "\n\t\t 3. Staff" << endl;
      cout << "\n\t\t 4. Exit Application" << endl;
      cout << endl << "\n\t\t Select option: ";
      cin >> option;

      system("cls");
      switch(option){

      // Admin Menu Option
      case 1:
         sub:
         system("cls");
         cout << "\n\t\t\t\t\t ADMINISTRATOR MENU " << endl << endl;
         cout << endl << "\n\t\t\t\t\t ADD OPTION " << endl;
         cout << "\n\t\t 1. New Student" << endl;
         cout << "\n\t\t 2. New Staff" << endl << endl;
         cout << endl << "\n\t\t\t\t\tDELETE OPTION" << endl;
         cout << "\n\t\t 3. Delete Student or Staff" << endl;
         cout << "\n\n\n\t\t 4. Go to Main Menu" << endl;
         cout << endl << "\n\n\t\t Enter option: ";
         cin >> adminOption;

            while(adminOption >= 1 && adminOption <= 4){

               if(adminOption == 1){
                  system("cls");
                  cout << endl << "\n\t\t\t\tADD OPTION" << endl;
                  cout << "\n\n\t\t Enter the number of student[s] to record: ";
                  cin >> adminResponse;

                  if(adminResponse > STUDENT_TOTAL){
                     goto sub;
                  }

                  else{
                     addStudent(studentList, adminResponse);
                     cout << endl << "\n\n\t\t ***** Records sucessfully added *****" << endl;
                     cout << endl << "\n\n\t\t Enter [00] to go back or [99] to main menu: ";
                     cin >> backOption;

                     if(backOption == 00){
                        goto sub;
                     }

                     else
                        system("cls");
                        goto START;

                  }
               }

               if(adminOption == 2){
                  system("cls");
                  cout << endl << "\n\t\t\t ----------- ADD OPTION ----------" << endl;
                  cout << "\n\n\t\t Enter the number of staff[s] to record: ";
                  cin >> adminResponse;

                  if(adminResponse > STAFF_TOTAL){
                     goto sub;
                  }

                  else{
                     addStaff(stafID, adminResponse);
                     cout << endl << "\n\n\t\t ***** Records sucessfully added *****" << endl;
                     cout << endl << "\n\n\t\t Enter [00] to go back or [99] to main menu: ";
                     cin >> backOption;

                     if(backOption == 00){
                        goto sub;
                     }

                     else
                        system("cls");
                        goto START;

                  }

               }

               if(adminOption == 3){
                  system("cls");
                  cout << endl << "\n\t\t\t ----------- DELETE OPTION ----------" << endl;
                  cout << endl << "\n\n\t\t Enter [1] - Student OR [2] - Staff: ";
                  cin >> delOption;

                  if(delOption == 1) {
                     cout << endl << "\n\n\t\t Enter Student ID: ";
                     cin >> studentID;

                     showStudent(studentList, adminResponse, studentID);
                     cout << endl << "\n\n\t\t Do you delete the above record[s]?" << endl;
                     cout << "\n\n\t\t [1] - Yes OR [2] - No: ";
                     cin >> delOption;

                     if(delOption == 1){
                        deleteStudent(studentList, adminResponse, studentID);
                     }

                     else{
                        system("cls");
                        goto sub;
                     }

                  }

                  else {
                     cout << endl << "\n\n\t\t Enter Staff ID: ";
                     cin >> staffID;

                     showStaff(stafID, adminResponse, staffID);
                     cout << endl << "\n\n\t\t Do you delete the above record[s]?" << endl;
                     cout << "\n\n\t\t [1] - Yes OR [2] - No: ";
                     cin >> delOption;

                     if(delOption == 1)
                        deleteStaff(stafID, adminResponse, staffID);

                     else{
                       system("cls");
                       goto sub;
                     }


                  }

                  cout << endl << endl << "\n\t\t ***** Records sucessfully deleted *****" << endl;
                  cout << endl << "\n\t\t Enter [00] to go back or [99] to main menu: ";
                  cin >> backOption;

                     if(backOption == 00){
                        goto sub;
                     }

                     else{
                       system("cls");
                        goto START;
                     }

               }

               if(adminOption == 4){
                  system("cls");
                  goto START;
               }


            }

         break;

      // Student Menu Option
      case 2:
         sub1:
         cout << "\n\t\t\t\t ----------- STUDENT MENU ----------" << endl << endl;
         cout << endl << "\n\n\t\t Enter your Student ID: ";
         cin >> studentID;

            ch = 0;
            while(ch < STUDENT_TOTAL){

               if(studentList[ch].studID == studentID){
                 cout << "\n\n\n\t\t 1. View assigned course[s]" << endl;
                 cout << "\n\n\t\t 2. Edit personal information" << endl;
                 cout << "\n\n\t\t 3. Academic Report" << endl;
                 cout << "\n\n\t\t 4. Go back to Main Menu" << endl;
                 cout << "\n\n\t\t Enter option: ";
                 cin >> studOption;

                 system("cls");
                 if(studOption == 1){
                    cout << "\n\t\t\t ----------- COURSES ASSIGNED ----------" << endl << endl;
                    cout << left << setw(12) << "\n\n\t\t Course Code " << right << setw(18) << "\t\t\t\t\t\t Credit"
                    << "\n\t\t -------------------------------------------------------------------------------------------";

                    assignedCourses(studentList, studentID, STUDENT_TOTAL);
                 }

                 else if(studOption == 2){
                    cout << "\n\t\t\t ----------- EDIT PERSONAL INFORMATION ----------" << endl << endl;
                    showStudent(studentList, STUDENT_TOTAL, studentID);
                    cout << "\n\n\n\t\t Enter new phone number: ";
                    cin >> newNumber;
                    cout << "\n\n\t\t Enter new programme: ";
                    cin >> newProgram;

                    editStudent(studentList, studentID, newNumber, newProgram);
                    cout << endl << "\n\n\n\t\t ***** Records sucessfully edited *****" << endl;
                 }

                 else if(studOption == 3){
                    cout << "\n\t\t\t ----------- ACADEMIC REPORT ----------" << endl << endl;
                    displayReport(studentList, studentID);
                 }

                 else if (studOption == 4) {
                    system("cls");
                    goto START;
                 }

                 else{
                    cout << endl << "\n\n\t\t Incorrect option, enter the above number selection" << endl;
                    Sleep(5000);
                    goto sub1;
                 }

                 cout << endl << "\n\n\n\t\t Enter [00] to go back or [99] to main menu: ";
                 cin >> backOption;

                 if(backOption == 00){
                    system("cls");
                    goto sub1;
                 }

                 else{
                   system("cls");
                   goto START;
                 }

               }


               else{
                  cout << "\a\n\n\t\t Incorrect Student ID, check and enter again." << endl;
                  Sleep(5000);
                  system("cls");
                  goto sub1;
               }

               ch++;
               //break;
            }

         break;

      // Staff Menu Option
      case 3:
         sub2:
         cout << "\n\t\t\t ----------- STAFF MENU ----------" << endl << endl;
         cout << endl << "\n\n\t\t Enter your Staff ID: ";
         cin >> staffID;

            ch = 0;
            while(ch < STAFF_TOTAL){

               if(stafID[ch].staff_ID == staffID){
                 cout << "\n\n\n\t\t 1. Record student grade" << endl;
                 cout << "\n\n\t\t 2. Edit personal information" << endl;
                 cout << "\n\n\t\t 3. Go back to Main Menu" << endl;
                 cout << "\n\n\t\t Enter option: ";
                 cin >> stafOption;

                 system("cls");
                 if(stafOption == 1){
                    sub3:
                    cout << "\n\t\t\t ----------- RECORD STUDENT GRADE ----------" << endl << endl;
                    cout << "\n\n\t\t Enter the number of student[s] to record grade: ";
                    cin >> stafLength;

                    if(stafLength >= STUDENT_TOTAL){
                       cout << "\n\n\t\t\a Enter between 1 - 100" << endl;
                       Sleep(5000);
                       system("cls");
                       goto sub3;
                    }

                    else{
                       recordGrade(stafID, staffID, studentList, stafLength);
                       cout << endl << "\n\n\t\t ***** Grade[s] sucessfully recorded *****" << endl;
                    }
                 }

                 else if(stafOption == 2){
                    cout << "\n\t\t\t ----------- EDIT PERSONAL INFORMATION ----------" << endl << endl;
                    showStaff(stafID, STAFF_TOTAL, staffID);
                    cout << "\n\n\n\t\t Enter new phone number: ";
                    cin >> stafNumber;

                    editStaff(stafID, staffID, stafNumber);
                    cout << endl << "\n\n\t\t ***** Records sucessfully edited *****" << endl;
                 }

                 else if(stafOption == 3){
                    system("cls");
                    goto START;
                 }

                 else{
                    cout << endl << "\n\n\t\t Incorrect option, enter the above number selection" << endl;
                    Sleep(5000);
                    system("cls");
                    goto sub2;
                 }

                 cout << endl << "\n\n\t\t Enter [00] to go back or [99] to main menu: ";
                 cin >> backOption;

                 if(backOption == 00){
                    system("cls");
                    goto sub2;
                 }

                 else{
                   system("cls");
                   goto START;
                 }

               }


               else{
                  cout << "\a\n\n\t\t Incorrect Staff ID, check and enter again." << endl;
                  Sleep(5000);
                  system("cls");
                  goto sub2;
               }

               ch++;
               break;
            }

         break;

      case 4:
         cout << "\n\t\t\t ----------- EXIT APPLICATION ----------" << endl << endl;
         cout << "\n\n\t\t Do you want to exit the system [1] - YES OR [2] - NO? : ";
         cin >> exitOption;

         if(exitOption == 1){
            cout << endl << endl << endl;
            return 0;
         }

         else{
            system("cls");
            goto START;
         }

         break;

      default:
         cout << endl << "\n\n\t\t Invalid option, enter the following number option below" << endl;
         Sleep(5000);
         system("cls");
         goto START;

         break;
      }
}

