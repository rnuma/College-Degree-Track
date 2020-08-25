/************************************************************************************************
* Project: College Degree Tracker
* Description: A program that helps track the progress of a Purdue undergraduate student in any
* major by storing their progress for each semester in a binary file to view and modify. 
* Author: Roan Numa
* Languages: C / C++
************************************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;


// Classes and function declarations //

class studentInfo
{
    char studentName[60];
    int PUID;
    int semeNum;
    char studentClassification[30];
    char college[60];
    char studentMajor[60];
    char seasonAndYear[30];

    char class1[15];
    int creditHour1;
    char grade1[10];

    char class2[15];
    int creditHour2;
    char grade2[10];

    char class3[15];
    int creditHour3;
    char grade3[10];

    char class4[15];
    int creditHour4;
    char grade4[10];

    char class5[15];
    int creditHour5;
    char grade5[10];

    char class6[15];
    int creditHour6;
    char grade6[10];

    char class7[15]; 
    int creditHour7;
    char grade7[10];

    char class8[15];
    int creditHour8;
    char grade8[10];

    int currentCH;
    double currentQP;

    const char* academicStanding;
    const char* additionalStanding;

    int calcSemesterCH() const;
    int calcTotalCH() const;

    double calcQP1() const; 
    double calcQP2() const; 
    double calcQP3() const; 
    double calcQP4() const; 
    double calcQP5() const; 
    double calcQP6() const; 
    double calcQP7() const; 
    double calcQP8() const;

    double calcSemesterQP() const;
    double calcTotalQP() const;

    double calcSemesterGPA() const;
    double calcCumGPA() const;

    void academicST();
    void addST();


public:
    void userInput();
    void displayInfo() const;
    int PUIDnum() const;
    int semesterNum() const;
};


// Function to calculate semester credit hours //

int studentInfo::calcSemesterCH() const
{
    int semesterCH;


    semesterCH = creditHour1 + creditHour2 + creditHour3 + creditHour4 + creditHour5 + creditHour6 + creditHour7 + creditHour8;

    return semesterCH;
}


// Function to calculate total credit hours //

int studentInfo::calcTotalCH() const
{
    double totalCH;


    totalCH = currentCH + creditHour1 + creditHour2 + creditHour3 + creditHour4 + creditHour5 + creditHour6 + creditHour7 + creditHour8;

    return totalCH;
}


// Function to calculate quality points earned in class #1 //

double studentInfo::calcQP1() const
{
    double qp1;


    if (strcmp(grade1,"A+")==0 || strcmp(grade1,"A")==0)
       qp1 = 4.0 * creditHour1;
    else if(strcmp(grade1,"A-")==0)
        qp1 = 3.7 * creditHour1;
    else if(strcmp(grade1,"B+")==0)
        qp1 = 3.3 * creditHour1;
    else if (strcmp(grade1,"B")==0)
        qp1 = 3.0 * creditHour1;
    else if(strcmp(grade1,"B-")==0)                                     
        qp1 = 2.7 * creditHour1;
    else if(strcmp(grade1,"C+")==0)
        qp1 = 2.3 * creditHour1;
    else if(strcmp(grade1,"C")==0)
        qp1 = 2.0 * creditHour1;
    else if(strcmp(grade1,"C-")==0)
        qp1 = 1.7 * creditHour1;
    else if(strcmp(grade1,"D+")==0)
        qp1 = 1.3 * creditHour1;
    else if(strcmp(grade1,"D")==0)
        qp1 = 1.0 * creditHour1;
    else if(strcmp(grade1,"D-")==0)
        qp1 = 0.7 * creditHour1;
    else if(strcmp(grade1,"F")==0)
        qp1 = 0.0 * creditHour1;
    else if(strcmp(grade1,"N/A")==0 || strcmp(grade1,"None")==0)
        qp1 = 0.0;
    else
        qp1 = 0.0 * creditHour1;

    return qp1;
}


// Function to calculate quality points earned in class #2 //

double studentInfo::calcQP2() const
{
    double qp2;


    if (strcmp(grade2,"A+")==0 || strcmp(grade2,"A")==0)
        qp2 = 4.0 * creditHour2;
    else if (strcmp(grade2,"A-")==0)
        qp2 = 3.7 * creditHour2;
    else if(strcmp(grade2,"B+")==0)
        qp2 = 3.3 * creditHour2;
    else if(strcmp(grade2,"B")==0)
        qp2 = 3.0 * creditHour2;
    else if(strcmp(grade2,"B-")==0)
        qp2 = 2.7 * creditHour2;
    else if(strcmp(grade2,"C+")==0)
        qp2 = 2.3 * creditHour2;
    else if(strcmp(grade2,"C")==0)
        qp2 = 2.0 * creditHour2;
    else if(strcmp(grade2,"C-")==0)
        qp2 = 1.7 * creditHour2;
    else if(strcmp(grade2,"D+")==0)
        qp2 = 1.3 * creditHour2;
    else if(strcmp(grade2,"D")==0)
        qp2 = 1.0 * creditHour2;
    else if(strcmp(grade2,"D-")==0)
        qp2 = 0.7 * creditHour2;
    else if(strcmp(grade2,"F")==0)
        qp2 = 0.0 * creditHour2;
    else if(strcmp(grade2,"N/A")==0 || strcmp(grade2,"None")==0)
        qp2 = 0.0;
    else
        qp2 = 0.0 * creditHour2;

    return qp2; 
}


// Function to calculate quality points earned in class #3 //

double studentInfo::calcQP3() const
{
    double qp3;


    if (strcmp(grade3,"A+")==0 || strcmp(grade3,"A")==0)
        qp3 = 4.0 * creditHour3;
    else if(strcmp(grade3,"A-")==0)
        qp3 = 3.7 * creditHour3;
    else if(strcmp(grade3,"B+")==0)
        qp3 = 3.3 * creditHour3;
    else if(strcmp(grade3,"B")==0)
        qp3 = 3.0 * creditHour3;
    else if(strcmp(grade3,"B-")==0)
        qp3 = 2.7 * creditHour3;
    else if(strcmp(grade3,"C+")==0)
        qp3 = 2.3 * creditHour3;
    else if(strcmp(grade3,"C")==0)
        qp3 = 2.0 * creditHour3;
    else if(strcmp(grade3,"C-")==0)
        qp3 = 1.7 * creditHour3;
    else if(strcmp(grade3,"D+")==0)
        qp3 = 1.3 * creditHour3;
    else if(strcmp(grade3,"D")==0)
        qp3 = 1.0 * creditHour3;
    else if(strcmp(grade3,"D-")==0)
        qp3 = 0.7 * creditHour3;
    else if(strcmp(grade3,"F")==0)
        qp3 = 0.0 * creditHour3;
    else if(strcmp(grade3,"N/A")==0 || strcmp(grade3,"None")==0)
        qp3 = 0.0;
    else
        qp3 = 0.0 * creditHour3;

    return qp3; 
}


// Function to calculate quality points earned in class #4 //

double studentInfo::calcQP4() const
{
    double qp4;


    if (strcmp(grade4,"A+")==0 || strcmp(grade4,"A")==0)
        qp4 = 4.0 * creditHour4;
    else if(strcmp(grade4,"A-")==0)
        qp4 = 3.7 * creditHour4;
    else if(strcmp(grade4,"B+")==0)
        qp4 = 3.3 * creditHour4;
    else if(strcmp(grade4,"B")==0)
        qp4 = 3.0 * creditHour4;
    else if(strcmp(grade4,"B-")==0)
        qp4 = 2.7 * creditHour4;
    else if(strcmp(grade4,"C+")==0)
        qp4 = 2.3 * creditHour4;
    else if(strcmp(grade4,"C")==0)
        qp4 = 2.0 * creditHour4;
    else if(strcmp(grade4,"C-")==0)
        qp4 = 1.7 * creditHour4;
    else if(strcmp(grade4,"D+")==0)
        qp4 = 1.3 * creditHour4;
    else if(strcmp(grade4,"D")==0)
        qp4 = 1.0 * creditHour4;
    else if(strcmp(grade4,"D-")==0)
        qp4 = 0.7 * creditHour4;
    else if(strcmp(grade4,"F")==0)
        qp4 = 0.0 * creditHour4;
    else if(strcmp(grade4,"N/A")==0 || strcmp(grade4,"None")==0)
        qp4 = 0.0;
    else
        qp4 = 0.0 * creditHour4;
    
    return qp4;  
}


// Function to calculate quality points earned in class #5 //

double studentInfo::calcQP5() const
{
    double qp5;

    if (strcmp(grade5,"A+")==0 || strcmp(grade5,"A")==0)
        qp5 = 4.0 * creditHour5;
    else if(strcmp(grade5,"A-")==0)
        qp5 = 3.7 * creditHour5;
    else if(strcmp(grade5,"B+")==0)
        qp5 = 3.3 * creditHour5;
    else if(strcmp(grade5,"B") == 0)
        qp5 = 3.0 * creditHour5;
    else if(strcmp(grade5,"B-")==0)
        qp5 = 2.7 * creditHour5;
    else if(strcmp(grade5,"C+")==0)
        qp5 = 2.3 * creditHour5;
    else if(strcmp(grade5,"C")==0)
        qp5 = 2.0 * creditHour5;
    else if(strcmp(grade5,"C-")==0)
        qp5 = 1.7 * creditHour5;
    else if(strcmp(grade5,"D+")==0)
        qp5 = 1.3 * creditHour5;
    else if(strcmp(grade5,"D")==0)
        qp5 = 1.0 * creditHour5;
    else if(strcmp(grade5,"D-")==0)
        qp5 = 0.7 * creditHour5;
    else if(strcmp(grade5,"F")==0)
        qp5 = 0.0 * creditHour5;
    else if(strcmp(grade5,"N/A")==0 || strcmp(grade5,"None")==0)
        qp5 = 0.0;
    else
        qp5 = 0.0 * creditHour5;

    return qp5;  
}


// Function to calculate quality points earned in class #6 //

double studentInfo::calcQP6() const
{
    double qp6;


    if (strcmp(grade6,"A+")==0 || strcmp(grade6,"A")==0)
        qp6 = 4.0 * creditHour6;
    else if(strcmp(grade6,"A-")==0)
        qp6 = 3.7 * creditHour6;
    else if(strcmp(grade6,"B+")==0)
        qp6 = 3.3 * creditHour6;
    else if(strcmp(grade6,"B") == 0)
        qp6 = 3.0 * creditHour6;
    else if(strcmp(grade6,"B-")==0)
        qp6 = 2.7 * creditHour6;
    else if(strcmp(grade6,"C+")==0)
        qp6 = 2.3 * creditHour6;
    else if(strcmp(grade6,"C")==0)
        qp6 = 2.0 * creditHour6;
    else if(strcmp(grade6,"C-")==0)
        qp6 = 1.7 * creditHour6;
    else if(strcmp(grade6,"D+")==0)
        qp6 = 1.3 * creditHour6;
    else if(strcmp(grade6,"D")==0)
        qp6 = 1.0 * creditHour6;
    else if(strcmp(grade6,"D-")==0)
        qp6 = 0.7 * creditHour6;
    else if(strcmp(grade6,"F")==0)
        qp6 = 0.0 * creditHour6;
    else if(strcmp(grade6,"N/A")==0 || strcmp(grade6,"None")==0)
        qp6 = 0.0;
    else
        qp6 = 0.0 * creditHour6;

    return qp6;    
}


// Function to calculate quality points earned in class #7 //

double studentInfo::calcQP7() const
{
    double qp7;


    if (strcmp(grade7,"A+")==0 || strcmp(grade7,"A")==0)
        qp7 = 4.0 * creditHour7;
    else if(strcmp(grade7,"A-")==0)
        qp7 = 3.7 * creditHour7;
    else if(strcmp(grade7,"B+")==0)
        qp7 = 3.3 * creditHour7;
    else if(strcmp(grade7,"B") == 0)
        qp7 = 3.0 * creditHour7;
    else if(strcmp(grade7,"B-")==0)
        qp7 = 2.7 * creditHour7;
    else if(strcmp(grade7,"C+")==0)
        qp7 = 2.3 * creditHour7;
    else if(strcmp(grade7,"C")==0)
        qp7 = 2.0 * creditHour7;
    else if(strcmp(grade7,"C-")==0)
        qp7 = 1.7 * creditHour7;
    else if(strcmp(grade7,"D+")==0)
        qp7 = 1.3 * creditHour7;
    else if(strcmp(grade7,"D")==0)
        qp7 = 1.0 * creditHour7;
    else if(strcmp(grade7,"D-")==0)
        qp7 = 0.7 * creditHour7;
    else if(strcmp(grade7,"F")==0)
        qp7 = 0.0 * creditHour7;
    else if(strcmp(grade7,"N/A")==0 || strcmp(grade7,"None")==0)
        qp7 = 0.0;
    else
        qp7 = 0.0 * creditHour7;
    
    return qp7;   
}


// Function to calculate quality points earned in class #8 //

double studentInfo::calcQP8() const
{
    double qp8;


    if (strcmp(grade8,"A+")==0 || strcmp(grade8,"A")==0)
        qp8 = 4.0 * creditHour8;
    else if(strcmp(grade8,"A-")==0)
        qp8 = 3.7 * creditHour8;
    else if(strcmp(grade8,"B+")==0)
        qp8 = 3.3 * creditHour8;
    else if(strcmp(grade8,"B") == 0)
        qp8 = 3.0 * creditHour8;
    else if(strcmp(grade8,"B-")==0)
        qp8 = 2.7 * creditHour8;
    else if(strcmp(grade8,"C+")==0)
        qp8 = 2.3 * creditHour8;
    else if(strcmp(grade8,"C")==0)
        qp8 = 2.0 * creditHour8;
    else if(strcmp(grade8,"C-")==0)
        qp8 = 1.7 * creditHour8;
    else if(strcmp(grade8,"D+")==0)
        qp8 = 1.3 * creditHour8;
    else if(strcmp(grade8,"D")==0)
        qp8 = 1.0 * creditHour8;
    else if(strcmp(grade8,"D-")==0)
        qp8 = 0.7 * creditHour8;
    else if(strcmp(grade8,"F")==0)
        qp8 = 0.0 * creditHour8;
    else if(strcmp(grade8,"N/A")==0 || strcmp(grade8,"None")==0)
        qp8 = 0.0;
    else
        qp8 = 0.0 * creditHour8;
    
    return qp8;   
}


// Function to calculate semester quality points earned //

double studentInfo::calcSemesterQP() const
{
    double qp1;
    double qp2; 
    double qp3; 
    double qp4; 
    double qp5; 
    double qp6; 
    double qp7; 
    double qp8; 
    double semesterQP;


    qp1 = calcQP1();
    qp2 = calcQP2();
    qp3 = calcQP3();
    qp4 = calcQP4();
    qp5 = calcQP5();
    qp6 = calcQP6();
    qp7 = calcQP7();
    qp8 = calcQP8();
   
    semesterQP = qp1 + qp2 + qp3 + qp4 + qp5 + qp6 + qp7 + qp8;

    return semesterQP;
}


// Function to calculate total quality points earned //

double studentInfo::calcTotalQP() const
{
    double qp1;
    double qp2; 
    double qp3; 
    double qp4; 
    double qp5; 
    double qp6; 
    double qp7; 
    double qp8; 
    double totalQP;


    qp1 = calcQP1(); 
    qp2 = calcQP2();
    qp3 = calcQP3(); 
    qp4 = calcQP4(); 
    qp5 = calcQP5();
    qp6 = calcQP6();
    qp7 = calcQP7();
    qp8 = calcQP8();
   
    totalQP = currentQP + qp1 + qp2 + qp3 + qp4 + qp5 + qp6 + qp7 + qp8;

    return totalQP;
}


// Function to calculate semester GPA //

double studentInfo::calcSemesterGPA() const
{
    int semesterCH;
    double semesterGPA;
    double semesterQP;

    
    semesterQP = calcSemesterQP();
    semesterCH = calcSemesterCH();

    semesterGPA = semesterQP / (double)semesterCH;
   
    return semesterGPA;
}


// Function to calculate cumulative GPA //

double studentInfo::calcCumGPA() const
{
    int totalCH;
    double totalGPA;
    double totalQP;


    totalQP = calcTotalQP();
    totalCH = calcTotalCH();

    totalGPA = totalQP / (double)totalCH;
    
    return totalGPA;
}


// Function to calculate academic standing //

void studentInfo::academicST()
{
    double cumuGPA;
    double semesterGPA;


    cumuGPA = calcCumGPA();
    semesterGPA = calcSemesterGPA();

    if (cumuGPA >= 2.0 && semesterGPA >= 2.0)
        academicStanding = "Good Standing";
    else if (cumuGPA < 2.0 || semesterGPA < 2.0)
        academicStanding = "Academic Probation";
    else
        academicStanding = "None";
}


// Function to calculate additional standing //

void studentInfo::addST()
{
    double totalCH;
    double semesterCH;
    double cumGPA;
    double semesterGPA;


    totalCH = calcTotalCH();
    semesterCH = calcSemesterCH();
    cumGPA = calcCumGPA();
    semesterGPA = calcSemesterGPA();

    if(totalCH >= 12 && semesterCH >= 6 && cumGPA >= 3.5 && semesterGPA >= 3.0)
        additionalStanding = "Dean's List";
    else if(semesterCH >= 6 && semesterGPA >= 3.5 && cumGPA >= 2.0)
        additionalStanding = "Semester Honors";
    else
        additionalStanding = "None";    
}


// Function to collect user input and initiate calculations //

void studentInfo::userInput()
{
	cout<<"\n\nEnter your name: ";
	cin.ignore();
	cin.getline(studentName,60);
    cout<<"\nEnter your PUID: ";
	cin>>PUID;
	cout<<"\nEnter your grade (for ex: Junior): ";
	cin.ignore();
    cin.getline(studentClassification,30);
    cout<<"\nEnter your college (For ex: College of Science): ";
	cin.getline(college,60);
	cout<<"\nEnter your major: ";
	cin.getline(studentMajor,60);
    cout<<"\nEnter the semester #: ";
    cin>>semeNum;
	cout<<"\nEnter current period (for ex: Fall 2020): ";
    cin.ignore();
	cin.getline(seasonAndYear,30);

	cout<<"\n\nEnter class #1 (for ex: ECE 20001): ";
    cin.getline(class1,15);
    cout<<"\nEnter # of credit hours for class #1: ";
	cin>>creditHour1;
    cout<<"\nEnter final grade for class #1 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade1,10);

    cout<<"\n\nEnter class #2 (for ex: ECE 20001): ";
    cin.getline(class2,15);
    cout<<"\nEnter # of credit hours for class #2: ";
	cin>>creditHour2;
    cout<<"\nEnter final grade for class #2 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade2,10);

    cout<<"\n\nEnter class #3 (for ex: ECE 20001): ";
    cin.getline(class3,15);
    cout<<"\nEnter # of credit hours for class #3: ";
	cin>>creditHour3;
    cout<<"\nEnter final grade for class #3 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade3,10);

    cout<<"\n\nEnter class #4 (for ex: ECE 20001): ";
    cin.getline(class4,15);
    cout<<"\nEnter # of credit hours for class #4: ";
	cin>>creditHour4;
    cout<<"\nEnter final grade for class #4 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade4,10);

    cout<<"\n\nEnter class #5 (for ex: ECE 20001): ";
    cin.getline(class5,15);
    cout<<"\nEnter # of credit hours for class #5: ";
	cin>>creditHour5;
    cout<<"\nEnter final grade for class #5 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade5,10);

    cout<<"\n\nEnter class #6 (for ex: ECE 20001): ";
    cin.getline(class6,15);
    cout<<"\nEnter # of credit hours for class #6: ";
	cin>>creditHour6;
    cout<<"\nEnter final grade for class #6 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade6,10);

    cout<<"\n\nEnter class #7 (for ex: ECE 20001): ";
    cin.getline(class7,15);
    cout<<"\nEnter # of credit hours for class #7: ";
	cin>>creditHour7;
    cout<<"\nEnter final grade for class #7 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade7,10);

    cout<<"\n\nEnter class #8 (for ex: ECE 20001): ";
    cin.getline(class8,15);
    cout<<"\nEnter # of credit hours for class #8: ";
	cin>>creditHour8;
    cout<<"\nEnter final grade for class #8 (for ex: A+, B, C-, etc.): ";
	cin.ignore();
	cin.getline(grade8,10);

	cout<<"\n\nEnter total # of credit hours (from PAST semesters): ";
	cin>>currentCH;
    cout<<"\nEnter total # of quality points (from PAST semesters): ";
	cin>>currentQP;

	calcSemesterCH();
    calcTotalCH();

    calcQP1();
    calcQP2();
    calcQP3();
    calcQP4();
    calcQP5();
    calcQP6();
    calcQP7();
    calcQP8();

    calcSemesterQP();
    calcTotalQP();

    calcSemesterGPA();
    calcCumGPA();

    academicST();
    addST();
}


// Function to display student college record (by semester) //

void studentInfo::displayInfo() const
{
	cout<<"\nName: "<<studentName;
	cout<<"\nPUID: "<<PUID;
	cout<<"\nClassification: "<<studentClassification;
    cout<<"\nCollege: "<<college;
	cout<<"\nMajor: "<<studentMajor;
	cout<<"\nSemester #: "<<semeNum;
	cout<<"\nCurrent period: "<<seasonAndYear;

	cout<<"\n\nClass #1: "<<class1;
	cout<<"\nCredit hours: "<<creditHour1;
	cout<<"\nFinal grade: "<<grade1;

    cout<<"\n\nClass #2: "<<class2;
	cout<<"\nCredit hours: "<<creditHour2;
	cout<<"\nFinal grade: "<<grade2;

    cout<<"\n\nClass #3: "<<class3;
	cout<<"\nCredit hours: "<<creditHour3;
	cout<<"\nFinal grade: "<<grade3;

    cout<<"\n\nClass #4: "<<class4;
	cout<<"\nCredit hours: "<<creditHour4;
	cout<<"\nFinal grade: "<<grade4;

    cout<<"\n\nClass #5: "<<class5;
	cout<<"\nCredit hours: "<<creditHour5;
	cout<<"\nFinal grade: "<<grade5;

    cout<<"\n\nClass #6: "<<class6;
	cout<<"\nCredit hours: "<<creditHour6;
	cout<<"\nFinal grade: "<<grade6;

    cout<<"\n\nClass #7: "<<class7;
	cout<<"\nCredit hours: "<<creditHour7;
	cout<<"\nFinal grade: "<<grade7;

    cout<<"\n\nClass #8: "<<class8;
	cout<<"\nCredit hours: "<<creditHour8;
	cout<<"\nFinal grade: "<<grade8;

    cout<<"\n\nSemester quality points: "<<calcSemesterQP();
	cout<<"\nTotal quality points: "<<calcTotalQP();

	cout<<"\n\nSemester GPA: "<<calcSemesterGPA();
    cout<<"\nCumulative GPA: "<<calcCumGPA();

    cout<<"\n\nAcademic Standing: "<<academicStanding;
    cout<<"\nAdditional Standing: "<<additionalStanding;
}


// Function to prevent student PUID # from being modified //

int studentInfo::PUIDnum() const
{
    return PUID;
}


// Function to prevent student semester # from being modified //

int studentInfo::semesterNum() const
{
    return semeNum;
}


// Function Declarations //

void create_studentInfo();
void show_AllStudentInfo(int);
void access_studentInfo(int,int);
void edit_studentInfo(int,int);
void erase_studentInfo(int);
void show_studentInfo();
void welcome_menu();
void show_menu();


// Function to display main menu and allow user access to different menu options //

int main()
{
	char number;


	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	welcome_menu();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMain Menu";
		cout<<"\n\n\t1. View student college record";
		cout<<"\n\n\t2. Create, modify or erase student college record";
		cout<<"\n\n\t3. Exit menu";
		cout<<"\n\n\tSelect an option (1-3) and press enter: ";
		cin>>number;

		switch(number)
		{
			case '1': show_studentInfo();
				break;
			case '2': show_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}
    }while(number!='3');
	return 0;
}


// Function to create and store student college record (by semester) into a binary file //

void create_studentInfo()
{
	studentInfo createST;
	ofstream outStudentFile;


	outStudentFile.open("Student.Data",ios::binary|ios::app);
	createST.userInput();
	outStudentFile.write(reinterpret_cast<char *> (&createST), sizeof(studentInfo));
	outStudentFile.close();
    	cout<<"\n\nA new student college record has been successfully created. ";
	cin.ignore();
	cin.get();
}


// Function to display student college record (all) according to student PUID # //

void show_AllStudentInfo(int n)
{
	studentInfo showST;
	ifstream inStudentFile;


	inStudentFile.open("student.Data",ios::binary);
	if(!inStudentFile)
	{
		cout<<"This student's college record could not be opened, please try again. Press enter to continue.";
		cin.ignore();
		cin.get();
		return;
	}

    bool flag=false;
	cout<<"\n\n\n\t\tCurrent college degree progress\n\n";
	while(inStudentFile.read(reinterpret_cast<char *> (&showST), sizeof(studentInfo)))
	{
        if(showST.PUIDnum()==n)
        {
		     showST.displayInfo();
		     cout<<"\n\n----------------------------------------------------------------------\n";
             flag=true;
        }
	}

	inStudentFile.close();
    if(flag==false)
        cout<<"\n\nThis student's college record does not exist, please try again. Press enter to continue.";
	cin.ignore();
	cin.get();
}


// Function to display student college record (by semester) according to student PUID # and semester # //

void access_studentInfo(int x, int y)
{
	studentInfo accessST;
	ifstream inStudentFile;


	inStudentFile.open("student.Data",ios::binary);
	if(!inStudentFile)
	{
		cout<<"This student's college record could not be opened, please try again. Press enter to continue.";
		cin.ignore();
		cin.get();
		return;
	}

	bool num=false;
	while(inStudentFile.read(reinterpret_cast<char *> (&accessST), sizeof(studentInfo)))
	{
		if(accessST.PUIDnum()==x && accessST.semesterNum()==y)
		{
	  		 accessST.displayInfo();
			cout<<"\n\n---------------------------------------------------------------------------------\n";
			 num=true;
		}
	}

	inStudentFile.close();
	if(num==false)
		cout<<"\n\nThis student's college record does not exist, please try again. Press enter to continue.";
	cin.ignore();
	cin.get();
}


// Function to enable user to modify student college record (by semester) according to student PUID # and semester # //

void edit_studentInfo(int x, int y)
{
	bool num=false;
	studentInfo editST;
	fstream studentFile;


	studentFile.open("student.Data",ios::binary|ios::in|ios::out);
	if(!studentFile)
	{
		cout<<"This student's college record could not be opened, please try again. Press enter to continue.";
		cin.ignore();
		cin.get();
		return;
	}
    	while(!studentFile.eof() && num==false)
	{

		studentFile.read(reinterpret_cast<char *> (&editST), sizeof(studentInfo));
		if(editST.PUIDnum()==x && editST.semesterNum()==y)
		{
			editST.displayInfo();
			cout<<"\n\nPlease enter the new semester data for the student:"<<endl;
			editST.userInput();
		    	int position=(-1)*static_cast<int>(sizeof(editST));
		    	studentFile.seekp(position,ios::cur);
		    	studentFile.write(reinterpret_cast<char *> (&editST), sizeof(studentInfo));
		    	cout<<"\n\n\t Your student record has been updated. Press enter to continue.";
		    	num=true;
		}
	}
	studentFile.close();
	if(num==false)
		cout<<"\n\nThis student's college record was not found, please try again. Press enter to continue.";
	cin.ignore();
	cin.get();
}


// Function to delete student college record (by semester) according to student PUID # and semester # //

void erase_studentInfo(int n)
{
	studentInfo eraseST;
	ifstream inStudentFile;


	inStudentFile.open("student.Data",ios::binary);
	if(!inStudentFile)
	{
		cout<<"This student's college record could not be opened, please try again. Press enter to continue.";
		cin.ignore();
		cin.get();
		return;
	}

	ofstream outStudentFile;


	outStudentFile.open("TemporayStudent.Data",ios::out);
	inStudentFile.seekg(0,ios::beg);
	while(inStudentFile.read(reinterpret_cast<char *> (&eraseST), sizeof(studentInfo)))
	{
		if(eraseST.PUIDnum()!=n)
		{
			outStudentFile.write(reinterpret_cast<char *> (&eraseST), sizeof(studentInfo));
		}
	}
	outStudentFile.close();
	inStudentFile.close();
	remove("student.Data");
	rename("TemporaryStudent.Data","student.Data");
	cout<<"\n\n\tThe student's college record has been successfully deleted.";
	cin.ignore();
	cin.get();
}


// Function to display menu with user access to view student college records //

void show_studentInfo()
{
	char number;
	int PUID;
    int semeNum;


	system("cls");
	cout<<"\n\n\n\tStudent College Records";
	cout<<"\n\n\t1. View student college record (all)";
    cout<<"\n\n\t2. View student college record (by semester)";
	cout<<"\n\n\t3. Back to main menu";
	cout<<"\n\n\n\tSelect an option (1-3) and press enter: ";
	cin>>number;
	system("cls");

	switch(number)
	{
    case '1' :	cout<<"\n\n\tEnter your PUID: "; cin>>PUID;
				show_AllStudentInfo(PUID); break;
    case '2':	cout<<"\n\n\tPlease enter your PUID: "; cin>>PUID;
                cout<<"\n\n\tPlease enter the semster #: "; cin>>semeNum;
			access_studentInfo(PUID,semeNum); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}


// Function to display welcome menu //

void welcome_menu()
{
	cout<<"\n\n\n\t College Degree Tracker";
	cout<<"\n\n\t Programmed by: Roan Numa";
	cout<<"\n\n\t Press enter to Continue ";
	cin.get();
}


// Function to display menu with user access to create, modify or delete student college records //

void show_menu()
{
	char num;
	int PUID;
    int semeNum;


	system("cls");
	cout<<"\n\n\n\tWelcome!";
	cout<<"\n\n\t1. Create new student college record";
	cout<<"\n\n\t2. Edit current student college record";
	cout<<"\n\n\t3. Erase current student college record";
	cout<<"\n\n\t4. Return to main menu";
	cout<<"\n\n\tSelect an option (1-4) and press enter: ";
	cin>>num;
	system("cls");

	switch(num)
	{
	case '1':	create_studentInfo(); break;
	case '2':	cout<<"\n\n\tPlease enter your PUID: "; cin>>PUID;
                cout<<"\n\n\tPlease enter the semster #: "; cin>>semeNum;
			edit_studentInfo(PUID,semeNum);break;
	case '3':	cout<<"\n\n\tPlease enter your PUID: "; cin>>PUID;
                cout<<"\n\n\tPlease enter the semster #: "; cin>>semeNum;
			erase_studentInfo(PUID);break;
	case '4':	break;
	default:	cout<<"\a"; show_menu();
	}
}


