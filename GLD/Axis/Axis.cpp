#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#include "Axis.hpp"

float GLD::GetAxis(Axis axis){
    if(sf::Keyboard::isKeyPressed(_axis_array[axis].positive))
        return  1.0f;
    if(sf::Keyboard::isKeyPressed(_axis_array[axis].negative))
        return -1.0f;
}