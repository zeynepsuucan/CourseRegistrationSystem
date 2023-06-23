#include "Course.h"

    Course::Course(){

    }
    Course::~Course(){
        
    }
    Course::Course(int id, string title){
        this->id = id;
        this->title = title;
    }
    bool Course::operator <(const Course& c){
        return this->getId() < c.id;
    }

    int Course::getId(){
        return id;
    }
    string Course::getTitle(){
        return title;
    }