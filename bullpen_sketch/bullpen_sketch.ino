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

char ssid[48] = "Axiom Markets LLC";
char pwd[48] = "@xiomr001z";
const int port = 8000;
const int pinButton = 0;  
const int pinEncoder = 2; 


void check_wifi() {
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
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

//ugly workaround
void rotate_handler() {
 if (c != NULL) {
    c->handleRotate();
 }
}

//display local ip
void printIP() {
  IPAddress ip = WiFi.localIP();
  char local_ip[16];
  sprintf(local_ip,"%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
  local_ip[15]= '\0';
  Serial.println(local_ip);
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  std::vector<Person> p;
  p.push_back(Person("Larry", true));
  p.push_back(Person("Dipesh"));
  p.push_back(Person("Ming"));

  check_wifi();
  printIP();
  s = new State(p);
  c = new Controller(pinButton, pinEncoder, p.size());
  v = new View(port);

  //attach encoder interrupt
  attachInterrupt(pinEncoder+1,rotate_handler,FALLING);
}


void loop() {
  wifi_handler();
  int cursorPos = c->getCursorPos();
  Person* current = s->getPerson(cursorPos);
  if(c->isButtonPressed()) {
    current->togglePresent();
  }
  v->update(current->getName(), current->getPresent(), s->getInList(), s->getOutList());
 
}
