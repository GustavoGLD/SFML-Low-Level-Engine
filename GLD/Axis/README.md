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
