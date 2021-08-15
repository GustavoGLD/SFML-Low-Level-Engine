#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

struct _Axle {
    sf::Keyboard::Key positive;
    sf::Keyboard::Key negative;
};
std::vector<_Axle> _axis_array = {
    //positive             //negative
    {sf::Keyboard::Key::D, sf::Keyboard::Key::A}, //horizontal
    {sf::Keyboard::Key::S, sf::Keyboard::Key::W}, //vertical
    {sf::Keyboard::Key::E, sf::Keyboard::Key::Q}  //diagonal
};