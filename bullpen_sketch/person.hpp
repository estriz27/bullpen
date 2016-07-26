#ifndef __PERSON__
#define __PERSON__

#include <Arduino.h>
#include <stdlib.h>

class Person {

  bool present;
  String name;

  public:
  Person(String name, bool present=false): name(name), present(present) {}
  void togglePresent();
  void setPresent(bool present);
  bool getPresent();
  String getName();
};

#endif
