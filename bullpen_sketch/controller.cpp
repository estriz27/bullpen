#include "controller.hpp"


      
  Controller::Controller :pinButton(pinButton), pinEncoder(pinEncoder), personCount(personCount) {}
  int cursorPos =0;
   
  int Controller::isButtonPressed(){
    int state = 0;
    if(digitalRead(pinButton)){
      while(digitalRead(pinButton));
        state = 1;
      }
    return state;
    }

  pinMode(pinEncoder,INPUT);
  

  void handleRotate(){
    if(digitalRead(pinEncoder1)==HIGH){
      cursorPos++;
      if(cursorPos >= personCount) cursorPos = 0;
    } else {
      cursorPos--;
      if(cursorPos < 0) cursorPos= personCount - 1;
    } 

  int getCursorPos(){
    return cursorPos;
  }


