#include <WiFi.h>

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

char ssid[48] = "AxiomMarketsLLC";
char pwd[48] = "@xiomr001z";
const int port = 8000;
const int pinButton = 0;  
const int pinEncoder = 2; 


void check_wifi() {
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shiel-m "d not present"); 
    // don't continue:
    while(true);
  } 

  if( WiFi.firmwareVersion() != "1.1.0" ) {
    Serial.println("Please upgrade the firmware");
  }
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    WiFi.begin(ssid,pwd);
    delay(1000);
  }    
}

void wifi_handler() {
  if(WiFi.status() != WL_CONNECTED){
      check_wifi();
    }
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  std::vector<Person> p;
  p.push_back(Person("Larry", true));
  p.push_back(Person("Dipesh"));
  p.push_back(Person("Ming"));

  check_wifi();

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
  wifi_handler();
  if(v->isButtonPressed()) {
   // s->;
  }
}
