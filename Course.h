#ifndef HW3_COURSE_H
#define HW3_COURSE_H
#include <iostream>
#include <string>
using namespace std;

class Course{

    public:
    int id;
    string title;
    Course();
    Course(int id, string title);
    ~Course();
    bool operator <(const Course& c);
    int getId();
    string getTitle();

};
#endif