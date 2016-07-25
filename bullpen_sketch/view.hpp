#ifndef __VIEWS__
#define __VIEWS__

#include <Arduino.h>
#include <vector>
#include "person.hpp"
#include "rgb_lcd.h"
#include <stdlib.h>
#include <WiFi.h>



class View{
  char SSID[48];
  char pwd[48];
  bool isSSIDReconfiged;
  int status;
  WiFiServer server;

  rgb_lcd lcd;
  const unsigned char BLColorR[3]={0xFF, 0x00, 0x00};  //Backlight color
  const unsigned char BLColorG[3]={0x00,0xFF,0x00};

  void updateLCD(String name, bool isIn);
  void updateHTML(std::vector<Person> inList, std::vector<Person> outList);


public:
  View(String SSID, String pwd, const int port,std::vector<Person> inList, std::vector<Person> outList);
  void update(String name, bool isIn,std::vector<Person> inList, std::vector<Person> outList);


};
#endif

