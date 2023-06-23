#include <iostream>
#include "RegistrationSystem.h"

using namespace std;


RegistrationSystem::RegistrationSystem(){
    studentNo = 0;
}

RegistrationSystem::~RegistrationSystem(){
    allStudents.clear();
}

void RegistrationSystem::addStudent( const int studentId ,const string firstName, const string lastName ){
    bool found = false;
    for(int i = 0; i < allStudents.itemCount; i++){
        if(allStudents.getEntry(i).getId() == studentId){
            found = true;
            break;
        }
    }
    if(found){
        cout << "Student " << studentId << " already exists" << endl;
        return;
    }
    Student newStudent(studentId,firstName,lastName);
    allStudents.insert(newStudent);
    cout << "Student " << studentId << " has been added" << endl;
}

void RegistrationSystem::deleteStudent(const int studentId ){
    int pos = 0;
    bool found = false;

    for(int i = 0; i < allStudents.itemCount; i++){
        if(allStudents.getEntry(i).getId() == studentId){
            found = true;
            break;
        }
        else  
        pos++;
    }

    if(!found){
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }

    allStudents.remove(pos);
    cout << "Student " << studentId << " has been deleted" << endl;
}

void RegistrationSystem::addCourse(const int studentId , const int courseId , const string courseName){
    bool found = false;
    NodeDouble<Student>* studentHead = allStudents.headPtr;
    while (studentHead)
    {
       if(studentHead->item.getId() == studentId){
        found = true;
        break;
       }
       else{
        studentHead=studentHead->next;
       }
    }
    if(!found){
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    bool checkId = false;
    NodeDouble<Student>* studentTraverse = allStudents.headPtr;
    while(studentTraverse){
        Node<Course>* courseTraverse = studentTraverse->item.enrolledCourses.headPtr;
        while(courseTraverse){
            if(courseTraverse->item.getId()==courseId && courseTraverse->item.getTitle()!=courseName){
                cout << "Course " << courseId << " already exists with another name" << endl;
                return;
            }
            courseTraverse = courseTraverse->next;
        }
        studentTraverse = studentTraverse->next;

    }
    Node<Course>* courseHead = studentHead->item.enrolledCourses.headPtr;
    bool courseFound = false;
    while (courseHead)
    {
       if(courseHead->item.getId() == courseId){
        courseFound = true;
        break;
       }
       else{
        courseHead = courseHead->next;
       }
    }
    if(courseFound){
        cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
        return;
    }

    studentHead->item.addCourseStudent(courseId,courseName);
    cout << "Course " << courseId << " has been added to student " << studentId << endl;

}

void RegistrationSystem::withdrawCourse( const int studentId, const int courseId ){
    bool found = false;
    NodeDouble<Student>* studentHead = allStudents.headPtr;
    while (studentHead)
    {
       if(studentHead->item.getId() == studentId){
        found = true;
        break;
       }
       else{
        studentHead=studentHead->next;
       }
    }
    if(!found){
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    
    Node<Course>* courseHead = studentHead->item.enrolledCourses.headPtr;
    bool courseFound = false;
    int pos = 0;
    while (courseHead)
    {
       if(courseHead->item.getId() == courseId){
        courseFound = true;
        break;
       }
       else{
        courseHead = courseHead->next;
        pos++;
       }
    }
    if(!courseFound){
        cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
        return;
    }
    studentHead->item.removeCourse(pos);
    cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
}
void RegistrationSystem::cancelCourse( const int courseId ){
    bool found = false;
    NodeDouble<Student>* studentHead = allStudents.headPtr;
    while (studentHead)
    {
        int pos = 0;
        Node<Course>* courseHead = studentHead->item.enrolledCourses.headPtr;
        while(courseHead){
            if(courseHead->item.id == courseId){
                found = true;
                studentHead->item.removeCourse(pos);
                break;
            }
            else{
                pos++;
                courseHead = courseHead->next;
            }
        }
        studentHead = studentHead->next;
    }
    if(!found){
        cout << "Course " << courseId << " does not exist" << endl;
        return;
    }
    cout << "Course " << courseId << " has been cancelled" << endl;

}

void RegistrationSystem::showStudent( const int studentId ){
    int pos = 0;
    bool found = false;

    for(int i = 0; i < allStudents.itemCount; i++){
        if(allStudents.getEntry(i).getId() == studentId){
            found = true;
            break;
        }
        else  
        pos++;
    }

    if(!found){
        cout << "Student " << studentId << " does not exist" << endl;
        return; 
    }

    Student printStudent = allStudents.getEntry(pos);

    cout << "Student id First name Last name" << endl;
    cout << printStudent.getId() << " " << printStudent.getFirstName() << " " << printStudent.getLastName() << endl;
    printStudent.showCourses();
}

void RegistrationSystem::showCourse( const int courseId ){
    bool found = false;
    NodeDouble<Student>* studentHead = allStudents.headPtr;
    Node<Course>* courseHead;
    Course print;
    while (studentHead)
    {
        courseHead = studentHead->item.enrolledCourses.headPtr;
        while(courseHead){
            if(courseHead->item.id == courseId){
                found = true;
                print = Course(courseHead->item.getId(), courseHead->item.getTitle());
                break;
            }
            else{
                courseHead = courseHead->next;
            }
        }
        studentHead = studentHead->next;
    }
    if(!found){
        cout << "Course " << courseId << " does not exist" << endl;
        return;
    }
    cout << "Course id Course name" << endl;
    cout << print.getId() << " " << print.getTitle() << endl;
    cout << "Student id First name Last name" << endl;
    studentHead = allStudents.headPtr;
    while (studentHead)
    {
        courseHead = studentHead->item.enrolledCourses.headPtr;
        while(courseHead){
            if(courseHead->item.id == courseId){
                cout << studentHead->item.getId() << " "<< studentHead->item.getFirstName() << " "<< studentHead->item.getLastName() << endl;
                break;
            }
            else{
                courseHead = courseHead->next;
            }
        }
        studentHead = studentHead->next;
    }
} 
void RegistrationSystem::showAllStudents(){
    if(allStudents.itemCount!=0){
    cout << "Student id First name Last name" << endl;
    for(int i=0; i < allStudents.itemCount; i++){
        Student student = allStudents.getEntry(i);
        cout << student.getId() << " " << student.getFirstName() << " " << student.getLastName() << endl;
        if(student.courseNo!=0){
            student.showCourses();
        }
    }
    }
    else
    cout << "There are no students in the system" << endl;
}