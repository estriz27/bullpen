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
  
bool isIn(int personIndex){return true;}
void togglePerson(int personIndex){return;}


bool State::filterIn (Person &p) {
  return p.getPresent();
}
bool State::filterOut(Person &p){
  return !p.getPresent();
}
