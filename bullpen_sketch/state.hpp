#ifndef __STATE__
#define __STATE__

#include "person.hpp"
#include <stdlib.h>
#include <vector>
#include <algorithm>

class State{
  //Has-a array of class Person
  std::vector<Person> people;
  static bool filterIn (Person &p);
  static bool filterOut(Person &p);
public:
  State(std::vector<Person> people):people(people){}
  std::vector<Person> getInList();
  std::vector<Person> getOutList();
  bool isIn(int personIndex);
  void togglePerson(int personIndex);//calls togglePresent on person at given index

};

#endif
