#ifndef __VIEWS__
#define __VIEWS__

#include <Arduino.h>
#include <vector>
#include "person.hpp"
#include "rgb_lcd.h"
#include <stdlib.h>
#include <WiFiServer.h>



class View{
  int status;
  WiFiServer server;

  rgb_lcd lcd;
  const unsigned char BLColorR[3]={0xFF, 0x00, 0x00};  //Backlight color
  const unsigned char BLColorG[3]={0x00,0xFF,0x00};

  void updateLCD(String name, bool isIn);
  void updateHTML(std::vector<Person> inList, std::vector<Person> outList);


public:
  View(const int port);
  void update(String name, bool isIn,std::vector<Person> inList, std::vector<Person> outList);


};
#endif

