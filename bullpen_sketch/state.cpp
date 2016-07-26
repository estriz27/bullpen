#include "state.hpp"


std::vector<Person> State::getInList(){
  std::vector<Person> inList;
  std::remove_copy_if(people.begin(), people.end(), inList.begin(), filterOut);
  return inList;
}

std::vector<Person> State::getOutList(){
  std::vector<Person> outList;
  std::remove_copy_if(people.begin(), people.end(), outList.begin(), filterIn);
  return outList;
  }
  
bool isIn(unsigned int personIndex){
  if (personIndex > people.size()) {
    return false;
  }
  return people[personIndex].getPresent();
}

void togglePerson(unsigned int personIndex){
  if (personIndex > people.size()) {
    return;
  }
  people[personIndex].togglePresent();
}

bool State::filterIn (Person &p) {
  return p.getPresent();
}
bool State::filterOut(Person &p){
  return !p.getPresent();
}
