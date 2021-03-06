#include <iostream>
#include "student.hpp"

/*
 * This is a constant we'll use to simplify allocating arrays to hold student
 * grades.
 */
#define MAX_GRADES 100

/*
 * Here's the definition for the Student class's default constructor.  It
 * uses an initialization list to initialize the values of id and n_grades,
 * and it allocates a new array to hold the student's grades.
 */
Student::Student() : id(0), n_grades(0) {
  std::cout << "== Default Student constructor called." << std::endl;
  this->grades = new float[MAX_GRADES];
}

/*
 * Here's the definition for the Student class's parameterized constructor.
 * It uses an initialization list to initialize the values of name and id, with
 * the constructor's argument values and to initialize n_grades to 0.  It also
 * allocates a new array to hold the student's grades.
 */
Student::Student(std::string name, int id) : name(name), id(id), n_grades(0) {
  std::cout << "== Parameterized constructor called for student " << id
    << std::endl;
  this->grades = new float[MAX_GRADES];
}

Student::Student(const Student& s) {
  this->name = s.name;
  this->id = s.id;
  this->n_grades = s.n_grades;

  this->grades = new float[MAX_GRADES];
  for (int i = 0; i < s.n_grades; i++) {
    this->grades[i] = s.grades[i];
  }
}

Student::~Student() {
  std::cout << "== In Student destructor" << std::endl;
  delete[] this->grades;
}

/*
 * This is the definition of our method to add a new grade to a Student objecy.
 * It checks to make sure the Student still has space in its grades array.
 */
void Student::add_grade(float grade) {
  if (this->n_grades < MAX_GRADES) {
    this->grades[this->n_grades++] = grade;
  }
}

/*
 * This is our function to print info about a given student to stdout (i.e. to
 * to std::cout).  It prints the address of the student's grades array so you
 * can verify that the copy constructor and assignment operator are indeed
 * allocating new arrays.  Try commenting out the copy constructor and/or
 * the assignment operator to verify that the grades arrays of copied Student
 * objects are the same when the default copy constructor and assignment
 * operator are used.
 */
void Student::print_student() {
  std::cout << "== " << this->name << " (" << this->id << "):" << std::endl;
  std::cout << "  grades array address: " << this->grades << std::endl;
  std::cout << "  grades:" << std::endl;
  for (int i = 0; i < this->n_grades; i++) {
    std::cout << "    " << this->grades[i] << std::endl;
  }
  std::cout << std::endl;
}

void Student::operator=(const Student& s) {
  this->name = s.name;
  this->id = s.id;
  this->n_grades = s.n_grades;

  // delete[] this->grades;
  // this->grades = new float[MAX_GRADES];
  for (int i = 0; i < s.n_grades; i++) {
    this->grades[i] = s.grades[i];
  }
}
