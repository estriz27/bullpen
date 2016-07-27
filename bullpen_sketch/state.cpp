#include "state.hpp"

std::vector<Person> State::getInList(){
  std::vector<Person> inList;
  for (int i = 0; i< people.size(); i++) {
    if (people[i].getPresent()) {
      inList.push_back(people[i]);
    }
  }
  return inList;
}

std::vector<Person> State::getOutList(){
  std::vector<Person> outList;
    for (int i = 0; i< people.size(); i++) {
    if (!people[i].getPresent()) {
      outList.push_back(people[i]);
    }
  }
  return outList;
}
  
bool State::isIn(unsigned int personIndex){
  if (personIndex > people.size()) {
    return false;
  }
  return people[personIndex].getPresent();
}

void State::togglePerson(unsigned int personIndex){
  if (personIndex > people.size()) {
    return;
  }
  people[personIndex].togglePresent();
}

Person* State::getPerson(unsigned int personIndex) {
 if (personIndex > people.size()) {
  return new Person("ERROR",false);
 }
 return &(people[personIndex]);
  
}

