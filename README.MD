## Arduino - Button
Simple arduino library for buttons.

### Usage
1. Create instance
```c
#require <Button.h>
Button btn(PIN_NUMBER, INPUT)
```

2. Initialize
```c
void setup()
{
  btn.init(clickCallback, downCallback, upCallback);  
}
```
All callbacks must have a return type of ``void`` and one parameter of type ``int``
```c
void clickCallback(int pinNumber)
{
  // do something
}
void downCallback(int pinNumber)
{
  // do something
}
void upCallback(int pinNumber)
{
  // do something
}
```
3. Loop
```c
void loop()
{
  btn.loop();
}
```

## functions
Constructor:
```c
Button(int pin, int pinmode, int interval = 1000);
```
- ``int pin`` the pin that the button is on
- ``int pinmode`` mode of button (``INPUT`` or ``INPUT_PULLUP``)
- ``int interval`` the maximum interval of a click in ms ``[default=1000]``

Init:
```c
void init(void (*cl)(int), void (*down)(int), void (*up)(int));
```
Call this function in your ``setup``
- ``void (*cl)(int)`` pointer to click callback
- ``void (*down)(int)`` pointer to down callback
- ``void (*up)(int)`` pointer to up callback

Loop:
```c
void loop();
```
Call this function in your ``loop``. This function checks if the button is pressed.

IsDown:
```c
bool isDown();
```
- Returns wether the button is currently pressed


### License
This project is licensed under the MIT license
