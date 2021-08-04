#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

namespace GLD
{

////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Getting input from the W-S, D-A and Q-E Axis. Return a value between -1 and 1
////////////////////////////////////////////////////////////////////////////////////////////
#include "AxisImpl.cpp"

////////////////////////////////////////////////////////////
/// \brief the possible Axis to use
////////////////////////////////////////////////////////////
enum Axis { Horizontal, Vertical, Diagonal };


////////////////////////////////////////////////////////////
/// \brief return a value between -1 and 1 from some Axis
////////////////////////////////////////////////////////////
float GetAxis(Axis axis);

}