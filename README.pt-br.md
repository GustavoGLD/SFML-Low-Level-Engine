# ⚙️ SFML-Low-Level-Engine ⚙️
Uma biblioteca header-only que tenta usar SFML em um nível mais profundo

# 🗣️ Languages

[(pt_br)](https://github.com/GustavoGLD/SFML-Low-Level-Engine/blob/main/README.pt-br.md) Português Brasileiro

[(en)](https://github.com/GustavoGLD/SFML-Low-Level-Engine/blob/main/README.md) Inglês

# 💾 Instalação
[Baixe o repositório](https://github.com/GustavoGLD/SFML-Low-Level-Engine/archive/refs/heads/main.zip) e coloque a pasta `GLD/` na pasta de seu projeto.

### 🖲️ Axis
> Com a classe Axis, podemos obter um eixo do teclado de um modo mais fácil. Ex.:
> ```cpp
> if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
>   return  1;
> if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
>   return -1;
> else
>   return  0;
> ```
> Para somente:
> ```cpp
> return GLD::GetAxis(GLD::Axis::Horizontal);
> 
Função baseada no método [Input.GetAxisRaw](https://docs.unity3d.com/ScriptReference/Input.GetAxisRaw.html) da Unity


```cpp
// to get A (positive) and D (negative) axis.
float horiz = GLD::GetAxis(GLD::Axis::Horizontal);

// to get W (positive) and S (negative) axis.
float vert  = GLD::GetAxis(GLD::Axis::Vertical); 
 
// to get E (positive) and Q (negative) axis.
float diag  = GLD::GetAxis(GLD::Axis::Diagonal); 
```

Em [GLD/Axis/Axis.hpp](https://github.com/GustavoGLD/SFML-Low-Level-Engine/blob/main/GLD/Axis/AxisImpl.cpp) temos a lista de Eixos:

```cpp
std::vector<_Axle> _axis_array = {
    //positive             //negative
    {sf::Keyboard::Key::D, sf::Keyboard::Key::A}, //horizontal
    {sf::Keyboard::Key::S, sf::Keyboard::Key::W}, //vertical
    {sf::Keyboard::Key::E, sf::Keyboard::Key::Q}  //diagonal
};

enum Axis { Horizontal, Vertical, Diagonal };
```
Você pode adicionar mais eixos, se assim quiser!

### ⏰ Time

> Com a classe Time, podemos obter o tempo total da aplicação e obter a variação do tempo entre os 2 últimos frames

Devemos declarar nosso objeto Time no início da aplicação, onde vai começar a contagem do tempo:
```cpp
GLD::Time myTime;
```

Para a biblioteca entender onde e quando um quadro começa, devemos usar o método getFrameInit():
```cpp
while (window.isOpen()) {
  myTime.getFrameInit();
  ...
```

Podemos obter o tempo entre os últimos frames com o método getDeltaTime(), o qual é baseado método getFrameInit() anteriormente mencionado.
```cpp
double currentTime = myTime.getDeltaTime();
```

Podemomos obter o tempo total da aplicação com o método getTime(), o qual é baseado no instante que o objeto foi declarado
```cpp
double currentTime = myTime.getTime();
```

> **_Exemplo_**
```cpp
#include <SFML/Graphics.hpp>
#include "../GLD/GLD.hpp"

int main()
{
    // Coloque no início da aplicação. A contagem começa aqui!
    GLD::Time myTime;
    
    ...
    
    while (window.isOpen()) {
    
          // Coloquei no ínicio do render loop
          myTime.getFrameInit();
          
          ...
          
          // obtendo a variação do tempo entre os últimos 2 frames
          double deltaTime = myTime.getDeltaTime();
           
          // obtendo o tempo total da aplicação
          double currentTime = myTime.getTime();
          
          ...
    }
    
    return 0;
}
```
⚙️ [Código fonte completo do exemplo aqui!](https://github.com/GustavoGLD/SFML-Low-Level-Engine/blob/main/exemples/time.cpp)
