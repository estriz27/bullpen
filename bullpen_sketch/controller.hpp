#ifndef __CONTRLR__
#define __CONTRLR__

#include <Arduino.h>
#include <stdlib.h>



class Controller{
  
        const int pinButton;
        const int pinEncoder;
        unsigned int personCount;
        int cursorPos;
        
        public: 
        Controller(int pinButton, int pinEncoder, unsigned int personCount);
        void handleRotate();
        int isButtonPressed();
        int getCursorPos();
  
};

#endif
