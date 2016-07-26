#include <WiFi.h>
#include <WiFiServer.h>

#include <rgb_lcd.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "controller.hpp"
#include "view.hpp"
#include "state.hpp"
#include "person.hpp"

State *s;
View *v;
Controller *c;

const String ssid = "AxiomMarketsLLC";
const String pwd = "@xiomr001z";
const int port = 8000;
const int pinButton = 0;  
const int pinEncoder = 2; 

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  std::vector<Person> p;
  p.push_back(Person("Larry", true));
  p.push_back(Person("Dipesh"));
  p.push_back(Person("Ming"));
  
  s = new State(p);
  c = new Controller(pinButton, pinEncoder, p.size());
  v = new View(ssid, pwd, port, s->getInList(), s->getOutList());
  
  std::vector<Person> in = s->getInList();
  std::vector<Person> out = s->getOutList();
  
  for(int i = 0; i != in.size(); i++) {
      Serial.println(in[i].getName());
  }
  for(int i = 0; i != out.size(); i++) {
      Serial.println(out[i].getName());
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
