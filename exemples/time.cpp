#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../GLD/GLD.hpp"

int main()
{
    // Put at the beginning of the application. The timing starts here
    GLD::Time myTime;

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    while (window.isOpen())
    {

        // *PUT IT AT FRAME INICIALIZATION!!!*
        myTime.getFrameInit();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear screen
        std::cout << std::string(100, '\n');

        ///////////////////////////////////////////////////////////////////////////////////////
        std::cout << "time between the last 2 frames: " << myTime.getDeltaTime() << std::endl;
        std::cout << "total application time:         " << myTime.getTime()      << std::endl;
        ///////////////////////////////////////////////////////////////////////////////////////

        window.clear();
        window.display();

    }

    return EXIT_SUCCESS;
}