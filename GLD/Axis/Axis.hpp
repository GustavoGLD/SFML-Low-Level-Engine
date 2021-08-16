#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

namespace GLD
{

////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Getting input from the W-S, D-A and Q-E Axis. Return a value between -1 and 1
////////////////////////////////////////////////////////////////////////////////////////////
  
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

////////////////////////////////////////////////////////////
/// \brief the possible Axis to use
////////////////////////////////////////////////////////////
enum Axis { Horizontal, Vertical, Diagonal };


////////////////////////////////////////////////////////////
/// \brief return a value between -1 and 1 from some Axis
////////////////////////////////////////////////////////////
float GetAxis(Axis axis);

}
