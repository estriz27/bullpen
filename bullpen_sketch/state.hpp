#include "person.hpp"
#include <stdlib.h>

class State{
  //Has-a array of class Person
  Person[] people;

public:
  State(Person[] people): people(people){}
  Person[] getInList();
  Person[] getOutList();
  bool isIn(int personIndex);
  void togglePerson(int personIndex);//calls togglePresent on person at given index

}
