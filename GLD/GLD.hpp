////////////////////////////////////////////////////////////////////////////////
// MIT License
// 
// Copyright (c) 2021 !Gustavo!
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in allS
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#include "Shape.cpp"

namespace GLD{

    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Getting input from the W-S, D-A and Q-E Axis. Return a value between -1 and 1
    ////////////////////////////////////////////////////////////////////////////////////////////
    namespace Axis{

        namespace { //private namespace
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
        };

        ////////////////////////////////////////////////////////////
        /// \brief the possible Axis to use
        ////////////////////////////////////////////////////////////
        enum Axis { Horizontal, Vertical, Diagonal };
        

        ////////////////////////////////////////////////////////////
        /// \brief return a value between -1 and 1 from some Axis
        ////////////////////////////////////////////////////////////
        float GetAxis(Axis axis);
    };

    ////////////////////////////////////////////////////////////
    /// \brief to use time functions
    ////////////////////////////////////////////////////////////
    class Time {
    private:
        std::chrono::high_resolution_clock::time_point _init_time;
        std::chrono::high_resolution_clock::time_point _last_frame;
        double _delta_time;

    public:

        /////////////////////////////////////////////////////////////////
        /// \brief determining window startup time. PUT IT IN INIT TIME
        /////////////////////////////////////////////////////////////////
        Time();

        ////////////////////////////////////////////////////////////
        /// \brief  get the current time based on init time
        ////////////////////////////////////////////////////////////
        double getTime();

        ////////////////////////////////////////////////////////////
        /// \brief PUT IT IN FRAME INICIALIZATION!!!
        ////////////////////////////////////////////////////////////
        void getFrameInit();

        ////////////////////////////////////////////////////////////
        /// \brief get the time variation between the 2 last frames
        ////////////////////////////////////////////////////////////
        double getDeltaTime();
    };
};


float GLD::Axis::GetAxis(Axis axis){
    if(sf::Keyboard::isKeyPressed(_axis_array[axis].positive))
        return  1.0f;
    if(sf::Keyboard::isKeyPressed(_axis_array[axis].negative))
        return -1.0f;
}

GLD::Time::Time() {
    _init_time = std::chrono::high_resolution_clock::now();
};

double GLD::Time::getTime() {
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(now - _init_time).count();
};

void GLD::Time::getFrameInit(){
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    _delta_time = std::chrono::duration_cast<std::chrono::duration<double>>(now - _last_frame).count();
    _last_frame = std::chrono::high_resolution_clock::now();
}

double GLD::Time::getDeltaTime() {
    return _delta_time;
}
