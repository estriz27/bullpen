#ifndef __STATE__
#define __STATE__

#include "person.hpp"
#include <stdlib.h>
//#include <StandardCplusplus.h>
#include <vector>

class State{
  //Has-a array of class Person
  std::vector<Person> people; 

public:
  State(std::vector<Person> people){}
  std::vector<Person> getInList();
  std::vector<Person> getOutList();
  bool isIn(int personIndex);
  void togglePerson(int personIndex);//calls togglePresent on person at given index

};

#endif
