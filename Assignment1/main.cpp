#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <sstream>
#include "main.h"


using namespace std;

namespace CPLJER001{
    fstream myFile;
    int students;

    vector<Record> studentRecord;

    void addStudent(string fname, string sname, string ID, string grades){
        Record record;
        record.Name = fname;
        record.Surname = sname;
        record.StudentNumber = ID;
        record.ClassRecord = grades;

        studentRecord.push_back(record);

    }

    void readData(string database){
        studentRecord.clear();
        string word = "";
        string fname = "";
        string sname = "";
        string stuNum = "";
        string grades = "";
        students = 0;
        const char * c = database.c_str();
        myFile.open(c);
        if(!myFile){
            cerr << "File open failed!" << endl;
        }
        else{
            string line;
            while (!myFile.eof()){
                getline(myFile,line);

                for (int i = 0; i < line.length(); i++){
                    if (line[i] != '/'){
                        word += line[i];
                    }
                    else if (fname == ""){
                        fname = word;
                        //cout << word << endl;
                        word = "";
                    }
                    else if (fname != "" && sname == ""){
                        sname = word;
                        //cout << word << endl;
                        word = "";
                    }
                    else if (fname != "" && sname != "" && stuNum == ""){
                        stuNum = word;
                        //cout << word << endl;
                        word = "";
                    }
                    else if (fname != "" && sname != "" && stuNum != "" && grades == ""){
                        grades = word;
                        //cout << word << endl;
                        word = "";
                    }
                }
                //cout << "new line" << endl;

                Record stuRecord;
                stuRecord.Name = fname;
                stuRecord.Surname = sname;
                stuRecord.StudentNumber = stuNum;
                stuRecord.ClassRecord = grades;

                studentRecord.push_back(stuRecord);
                students++;

                word = "";
                fname = "";
                sname = "";
                stuNum = "";
                grades = "";
            }
        myFile.close();
        }
    }

    void saveData(string Database){
        const char * c = Database.c_str();
        myFile.open(c, fstream::app);

        if (studentRecord.size() == students){
            cout << "No changes were made to this database!" << endl;
        }

        else{
            for (int i = students; i < studentRecord.size(); i++){
                myFile << studentRecord[i].Name + "/" + studentRecord[i].Surname + "/" + studentRecord[i].StudentNumber + "/" + studentRecord[i].ClassRecord + "/" << endl;
            }
            cout << "Database successfully saved!" << endl;
        }

        myFile.close();
    }

    void displayData(string stuID){
        bool found = false;
        if (studentRecord.size() == 0){
            cout << "No database currently selected!" << endl;
        }
        else{
            for (int i = 0; i < studentRecord.size(); i++){
                if (stuID == studentRecord[i].StudentNumber){
                    found = true;
                    cout << "Student's First Name: " + studentRecord[i].Name << endl;
                    cout << "Student's Surname:    " + studentRecord[i].Surname << endl;
                    cout << "Student's Number:     " + studentRecord[i].StudentNumber << endl;
                    cout << "Student's grades:     " + studentRecord[i].ClassRecord << endl;
                }
            }
            if (found == false) cout << "Student not found in database!" << endl;
        }
    }

    void gradeStudent(string stuID){
        bool found = false;
        string allGrades;
        string tempGrade;
        ostringstream ss;
        int total = 0;
        int count = 0;
        if (studentRecord.size() == 0){
            cout << "No database currently selected!" << endl;
        }
        else{
            for (int i = 0; i < studentRecord.size(); i++){
                if (stuID == studentRecord[i].StudentNumber){
                    found = true;

                    allGrades = studentRecord[i].ClassRecord;
                    for (int i = 0; i < allGrades.length(); i++){
                        if (allGrades[i] != ' '){
                            tempGrade += allGrades[i];
                        }
                        if (allGrades[i] == ' '){
                            int intGrade = atoi(tempGrade.c_str());
                            total += intGrade;
                            tempGrade = "";
                            count++;
                        }
                    }
                    int intGrade = atoi(tempGrade.c_str());
                    total += intGrade;
                    tempGrade = "";
                    count++;
                }
            }
            if (found != false){
                float gradeAverage = (float)total/(float)count;
                ss << gradeAverage;
                cout << "The student's grade average is: " + ss.str() << endl;
            }
            if (found == false) cout << "Student not found in database!" << endl;
        }

    }
}


