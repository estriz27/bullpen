#include "person.hpp"

bool Person::getPresent() {
  return present;
}


void Person::togglePresent(){
  this->present = !present;
}

void Person::setPresent(bool present){
  this->present = present;

}



