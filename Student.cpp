    #include <iostream>
    #include <string>
    #include "Student.h"

    using namespace std;

    Student::Student(){
        courseNo = 0;
        enrolledCourses.headPtr = nullptr;
    }

    Student::Student(int id, string firstName, string lastName){
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        courseNo = 0;
        enrolledCourses.headPtr = nullptr;
    }

    Student::~Student(){
        enrolledCourses.clear();
    }

    bool Student::operator <(Student s){
        return this->getId() < s.getId();
    }

    bool Student::operator ==(Student s){
        return this->getId() == s.getId();
    }

    int Student::getId(){
        return id;
    }

    string Student::getFirstName(){
        return firstName;
    }

    string Student::getLastName(){
        return lastName;
    }

    void Student::addCourseStudent(int courseId, string courseName){
        Course add2(courseId,courseName);
        enrolledCourses.insert(add2);
        courseNo++;
    }

    void Student::removeCourse(int pos){
        enrolledCourses.remove(pos);
        courseNo--;
    }

    void Student::showCourses(){
        if(courseNo!=0){
        cout << "Course id Course name" << endl;
        for(int i = 0; i < courseNo; i++){
            Course course = enrolledCourses.getNodeAt(i)->item;
            cout << course.getId() << " " << course.getTitle() << endl;
        }
        }
    }