/*
Jeremy Coupland
Header File
Assignment 1
March 1st, 2015
*/

#ifndef main_h
#define main_h

namespace CPLJER001{
    struct Record{
        std::string Name, Surname, StudentNumber, ClassRecord;
    };
    
    void addStudent(std::string fname, std::string sname, std::string ID, std::string grades);
    void readData(std::string database);
    void saveData(std::string Database);
    void displayData(std::string stuID);
    void gradeStudent(std::string stuID);
    
}

#endif
