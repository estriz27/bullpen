#include <Arduino.h>
#include <stdlib.h>



class Controller{
  
        const int pinButton;
        const int pinEncoder1;
        int isButtonPressed()
        int cursorPos;
        
        public: 
        Controller(int pinButton, int pinEncoder, int personCount);
        void handleRotate();
        void handlePressed();
        int getCursorPos();


  
}

