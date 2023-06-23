#ifndef HW3_REGISTRATIONSYSTEM_H
#define HW3_REGISTRATIONSYSTEM_H
#include <iostream>
#include "Student.h"
#include "LinkedListDouble.h"
#include <string>

using namespace std;

class RegistrationSystem { 
    private:
    LinkedListDouble<Student> allStudents;
    int studentNo;

    public:
    RegistrationSystem(); 
    ~RegistrationSystem();
    void addStudent( const int studentId ,const string firstName, const string lastName );
    void deleteStudent( const int studentId );
    void addCourse( const int studentId , const int courseId , const string courseName );
    void withdrawCourse( const int studentId, const int courseId ); 
    void cancelCourse( const int courseId );
    void showStudent( const int studentId );
    void showCourse( const int courseId ); 
    void showAllStudents();
};
#endif