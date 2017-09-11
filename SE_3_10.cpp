//============================================================================
// Name        : cpp11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <memory>


struct student {
  int student_ID;
  double grade;

  student (int ID, double course_grade) {
    student_ID = ID;
    grade = course_grade;
  }
};

class grades {

 private:
  std::vector<student> students;

 public:

  void add_student(int ID, double course_grade){
    student person(ID, course_grade);
    students.push_back(person);
  }

  const double average() {
    size_t amount = students.size();
    unsigned int sum = 0;
    for (auto &x : students) {
      sum += x.grade;
    }
    return sum/amount;
  }

  void change(int ID, double new_score) {
    for (auto &x : students) {
      if (x.student_ID == ID)
        x.grade = new_score;
    }
  }

  void print() {
    for (auto &x : students) {
      std::cout<< x.student_ID <<"*******"<<x.grade<<"\n";
    }
  }

};

int main()
{


}
