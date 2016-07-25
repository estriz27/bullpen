#include <Arduino.h>
#include <stdlib.h>

class Person {
	
	bool present;
	String name;
	
	public: 
	Person(String name, bool present): name(name), present(present) {}
	void togglePresent();
	void setPresent();
	bool getPresent();
};