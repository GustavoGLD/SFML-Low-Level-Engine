#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

namespace GLD 
{

////////////////////////////////////////////////////////////
/// \brief Making a new Shape with your VBO and Shader
////////////////////////////////////////////////////////////
class Shape {
private:
    sf::RenderStates          _render_states;

public:
    std::vector<sf::Vertex>   vertices;
    sf::VertexBuffer          vertex_buffer;
    sf::Shader                shader;
    sf::Transformable         transformable;

    ////////////////////////////////////////////////////////////
    /// \brief render the Shape
    /// \param window the current window
    ////////////////////////////////////////////////////////////
    void render(sf::RenderWindow &window);
};

};
