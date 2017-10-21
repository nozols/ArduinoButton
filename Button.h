#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button{
  public:
    Button(int pin, int pinmode, int interval = 1000);
    void init(void (*cl)(int), void (*down)(int), void (*up)(int));   // call init in setup!!
    void loop();
    bool isDown();
  private:
    int _pin;             // pin for this button
    int _pinmode;         // pinmode, either pullup or input
    int _buttonLastDown;  // time in ms when it was last pressed down
    int _clickInterval;   // maximum interval for click to trigger
    bool _activeState;    // is active high or active low
    bool _inactiveState;  // opposite of _activeState
    bool _lastState;      // last state
    void (*_click)(int);  // click callback
    void (*_down)(int);   // down callback
    void (*_up)(int);     // up callback
};

#endif
