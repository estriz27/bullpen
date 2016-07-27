#ifndef __STATE__
#define __STATE__

#include "person.hpp"
#include <stdlib.h>
#include <vector>
#include <algorithm>

class State{
  //Has a vector of class Person
  std::vector<Person> people;
public:
  State(std::vector<Person> people):people(people){}
  std::vector<Person> getInList();
  std::vector<Person> getOutList();
  Person* getPerson(unsigned int personIndex);
  bool isIn(unsigned int personIndex);
  void togglePerson(unsigned int personIndex);//calls togglePresent on person at given index

};

#endif

