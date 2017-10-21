#include "Button.h"
#include "Arduino.h"

Button::Button(int pin, int pinmode, int interval){
  _pin = pin;
  _pinmode = pinmode;
  pinMode(_pin, _pinmode);
  _activeState = _pinmode == INPUT_PULLUP ? LOW : HIGH;
  _inactiveState = _pinmode == INPUT_PULLUP ? HIGH : LOW;
  _lastState = _activeState == LOW ? HIGH : LOW;
  _clickInterval = interval;
  _buttonLastDown = 0;
}

void Button::init(void (*cl)(int), void (*down)(int), void (*up)(int)){
  _click = cl;
  _down = down;
  _up = up;
}

void Button::loop(){
  if(digitalRead(_pin) == _activeState){
    if(_lastState == _inactiveState){
      // DOWN
      _buttonLastDown = millis();
      _down(_pin);
    }
    _lastState = _activeState;
  }else{
    if(_lastState == _activeState){
      // UP
      if(millis() <= _buttonLastDown + _clickInterval){
        _click(_pin);
      }
      _up(_pin);
    }
    _lastState = _inactiveState;
  }
}

bool Button::isDown(){
  return digitalRead(_pin) == _activeState;
}
