
# 📖 Wiki
### ⏰ Time

> With the Time class, we can get the total application time and get the variation of the last 2 game frames.

We must declare our Time object at the beginning of the application, there it will start counting the time:
```cpp
GLD::Time myTime;
```

For the library to understand where and when a frame starts, we need to use the getFrameInit() method.
```cpp
while (window.isOpen()) {
  myTime.getFrameInit();
  ...
```

we can get the time between the last 2 frames with the getDeltaTime() method, which is based on the getFrameInit() method mentioned above.
```cpp
double currentTime = myTime.getDeltaTime();
```

We can get the total application time with the getTime() method, which is based on the instant the time object was started.
```cpp
double currentTime = myTime.getTime();
```
> **_Exemple_**
```cpp
#include <SFML/Graphics.hpp>
#include "../GLD/GLD.hpp"

int main()
{
    // Put at the beginning of the application. The timing starts here
    GLD::Time myTime;
    
    ...
    
    while (window.isOpen()) {
    
          // *PUT IT AT FRAME INICIALIZATION!!!*
          myTime.getFrameInit();
          
          ...
          
          // get the time variation between the 2 last frames
          double deltaTime = myTime.getDeltaTime();
           
          // get the current time based on init time
          double currentTime = myTime.getTime();
          
          ...
    }
    
    return 0;
}
```
 ⚙️ [Full Source Code of the Example here](https://github.com/GustavoGLD/SFML-Low-Level-Engine/blob/main/exemples/time.cpp)
