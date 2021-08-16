# ⚙️ SFML-Low-Level-Engine ⚙️
A header-only library that tries to use SFML at a deeper level


# 💾 Instalation
Download the source code and put the GLD folder in your project folder


# 📖 Wiki

### 🖲️ Axis
> With the Axis class, we can get "Axis" from keyboard in a easy way. Ex.:
> ```cpp
> if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
>   return  1;
> if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
>   return -1;
> else
>   return  0;
> ```
> to only:
> ```cpp
> return GLD::GetAxis(GLD::Axis::Horizontal);
> 

Function based on Unity's [Input.GetAxisRaw](https://docs.unity3d.com/ScriptReference/Input.GetAxisRaw.html)

```cpp
// to get A (positive) and D (negative) axis.
float horiz = GLD::GetAxis(GLD::Axis::Horizontal);

// to get W (positive) and S (negative) axis.
float vert  = GLD::GetAxis(GLD::Axis::Vertical); 
 
// to get E (positive) and Q (negative) axis.
float diag  = GLD::GetAxis(GLD::Axis::Diagonal); 
```

In [GLD/Axis/Axis.hpp](https://github.com/GustavoGLD/SFML-Low-Level-Engine/blob/main/GLD/Axis/AxisImpl.cpp) we have the axis list:

```cpp
std::vector<_Axle> _axis_array = {
    //positive             //negative
    {sf::Keyboard::Key::D, sf::Keyboard::Key::A}, //horizontal
    {sf::Keyboard::Key::S, sf::Keyboard::Key::W}, //vertical
    {sf::Keyboard::Key::E, sf::Keyboard::Key::Q}  //diagonal
};

enum Axis { Horizontal, Vertical, Diagonal };
```
You can add more axes if you like.

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
