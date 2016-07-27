#include "controller.hpp"


Controller::Controller(int pinButton,int pinEncoder, unsigned int personCount):pinButton(pinButton), pinEncoder(pinEncoder), personCount(personCount), cursorPos(0){
    pinMode(pinEncoder,INPUT);
    pinMode(pinButton,INPUT);
}
   
int Controller::isButtonPressed(){
    int state = 0;
    if(digitalRead(pinButton)){
      while(digitalRead(pinButton));
        state = 1;
      }
    return state;
}

void Controller::handleRotate(){
    while(!digitalRead(pinEncoder+1));
    if(digitalRead(pinEncoder)==HIGH){
      cursorPos++;
      if(cursorPos >= personCount) cursorPos = 0;
    } else {
      cursorPos--;
      if(cursorPos < 0) cursorPos= personCount - 1;
    } 
}
int Controller::getCursorPos(){
    return cursorPos;
}


