#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../GLD/GLD.hpp"

int main()
{
    GLD::Time myTime;

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");


    GLD::Shape* quad;
    quad = GLD::getShape::Rectangle({sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::White});

    quad->transformable.setOrigin(0.5f, 0.5);
    quad->transformable.scale    (250.0f, 250.0f);
    quad->transformable.move     (125.0f, 125.0f);

    while (window.isOpen())
    {
        myTime.getFrameInit();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //triangle.shader.setUniform("intensity", ((float)std::sin(myTime.getTime()/ 2.0f + 1.0f)));

        float velocity  = 200.0f;
        float veloc_ang = 180.0f;
        quad->transformable.move(  velocity  * GLD::GetAxis(GLD::Axis::Horizontal)* myTime.getDeltaTime(),
                                      velocity  * GLD::GetAxis(GLD::Axis::Vertical)  * myTime.getDeltaTime());

        quad->transformable.rotate(veloc_ang * GLD::GetAxis(GLD::Axis::Diagonal)  * myTime.getDeltaTime());
        window.clear();
        quad->render(window);
        window.display();
    }

    return 0;
}