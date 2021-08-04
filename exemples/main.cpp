#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../GLD/GLD.hpp"

int main()
{
    GLD::Time myTime;

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    GLD::Shape triangle;
    triangle.shader.loadFromFile("shader.vert", "shader.frag");

    triangle.vertices = {
        sf::Vertex(sf::Vector2f(0.5f, 1.0f), sf::Color::White),
        sf::Vertex(sf::Vector2f(0.0f, 0.0f), sf::Color::Transparent),
        sf::Vertex(sf::Vector2f(1.0f, 0.0f), sf::Color::Transparent),
    };
    triangle.vertex_buffer.setPrimitiveType(sf::PrimitiveType::Triangles);
    triangle.vertex_buffer.setUsage        (sf::VertexBuffer::Usage::Static);
    triangle.vertex_buffer.create          ( triangle.vertices.size());
    triangle.vertex_buffer.update          (&triangle.vertices[0]);

    triangle.transformable.setOrigin(0.5f, 1.0f);
    triangle.transformable.scale    (250.0f, 250.0f);
    triangle.transformable.move     (125.0f, 125.0f);

    while (window.isOpen())
    {
        myTime.getFrameInit();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        triangle.shader.setUniform("intensity", ((float)std::sin(myTime.getTime()/ 2.0f + 1.0f)));

        float velocity  = 200.0f;
        float veloc_ang = 180.0f;
        triangle.transformable.move(  velocity  * GLD::Axis::GetAxis(GLD::Axis::Horizontal)* myTime.getDeltaTime(),
                                      velocity  * GLD::Axis::GetAxis(GLD::Axis::Vertical)  * myTime.getDeltaTime());

        triangle.transformable.rotate(veloc_ang * GLD::Axis::GetAxis(GLD::Axis::Diagonal)  * myTime.getDeltaTime());

        window.clear();
        triangle.render(window);
        window.display();
    }

    return 0;
}