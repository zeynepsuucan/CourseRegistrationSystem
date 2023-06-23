#ifndef HW3_STUDENT_H
#define HW3_STUDENT_H
#include <iostream>
#include "LinkedList.h"
#include "Course.h"
#include <string>
using namespace std;

class Student{
    private:
    int id;
    string firstName;
    string lastName;

    public:
    LinkedList<Course> enrolledCourses;
    int courseNo;
    Student();
    Student(int id, string firstName, string lastName);
    ~Student();
    bool operator <(Student s);
    bool operator ==(Student s);

    int getId();
    string getFirstName();
    string getLastName();
    void addCourseStudent(int courseId, string courseName);
    void removeCourse(int pos);
    void showCourses();
};
#endif
