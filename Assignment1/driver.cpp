#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <sstream>
#include "main.h"


using namespace std;

int main()
{
    string input;
    string database;
    string fname, sname, stuID, grades;
    cout << "Welcome to the student database." << endl;
    for (;;){
        if (database == "") cout << "No database currently selected" << endl;
        else cout << "Currently selected database: " + database << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Read database" << endl;
        cout << "3. Save database" << endl;
        cout << "4. display given student data" << endl;
        cout << "5. grade student" << endl;
        cout << "0. quit" << endl;
        cout << "Please enter a corresponding number: ";
        getline(cin, input);
        cout << "" << endl;

        //system("clear"); Doesn't seem to work with this OS, according to internet searches

        if (input == "1"){
            //string fname, sname, stuID, grades;
            //cout << "Function 'addStudent()' called." << endl;
            if (database == ""){
                cout << "You must first read a database before you can add a student to it!" << endl;
            }
            else{
                cout << "Enter the student's first name: ";
                getline(cin, fname);
                cout << "Enter the student's surname: ";
                getline(cin, sname);
                cout << "Enter the student's student ID: ";
                getline(cin, stuID);
                cout << "Enter the student's grades, all on one line and separated by one space: ";
                getline(cin, grades);

                cout << "\nStudent " + fname + " " + sname + " (" + stuID + ") added to database." << endl;
                cout << "Student grades: " + grades << endl;
                CPLJER001::addStudent(fname, sname, stuID, grades);
            }
        }

        else if (input == "2"){
            cout << "Enter the full path directory of the existing database (eg. /home/documents/database.txt): ";
            getline (cin, database);
            cout << "\nSelected database: " + database << endl;
            CPLJER001::readData(database);
        }
        else if (input == "3"){
            if (database == "") cout << "No database currently selected!" << endl;
            else CPLJER001::saveData(database);
        }

        else if (input == "4"){
            if (database == "") cout << "No database selected to read student data from!" << endl;
            else{
                cout << "Enter the student's ID: ";
                getline(cin, stuID);
                CPLJER001::displayData(stuID);
            }
        }

        else if (input == "5"){
            if (database == "") cout << "No database selected to read student data from!" << endl;
            else{
                cout << "Enter the student's ID: ";
                getline(cin, stuID);
                CPLJER001::gradeStudent(stuID);
            }
        }

        else if (input == "0") return 0;
        else cout << "Invalid option, try again" << endl;

        cout << " \n" << endl;
    }

    return 0;
}
