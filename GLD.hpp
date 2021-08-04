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

namespace GLD{
    class Shape {
    private:
        sf::RenderStates          _render_states;

    public:
        std::vector<sf::Vertex>   vertices;
        sf::VertexBuffer          vertex_buffer;
        sf::Shader                shader;
        sf::Transformable         transformable;

        void render(sf::RenderWindow &window){
            _render_states.shader    = &shader;
            _render_states.transform = transformable.getTransform();
            window.draw(vertex_buffer, _render_states);
        }
    };


    namespace Axis{

        namespace { //private namespace
            struct _Axi {
                sf::Keyboard::Key positive;
                sf::Keyboard::Key negative;
            };
            std::vector<_Axi> _axis_array = {
                //positive             //negative
                {sf::Keyboard::Key::D, sf::Keyboard::Key::A}, //horizontal
                {sf::Keyboard::Key::S, sf::Keyboard::Key::W}, //vertical
                {sf::Keyboard::Key::E, sf::Keyboard::Key::Q}  //diagonal
            };
        };

        enum Axis { Horizontal, Vertical, Diagonal };
        
        float GetAxis(Axis axis){
            if(sf::Keyboard::isKeyPressed(_axis_array[axis].positive))
                return  1.0f;
            if(sf::Keyboard::isKeyPressed(_axis_array[axis].negative))
                return -1.0f;
        }
    };

    class Time {
    private:
        std::chrono::high_resolution_clock::time_point _init_time;
        std::chrono::high_resolution_clock::time_point _last_frame;
                                                double _delta_time;

    public:
        Time() {
            _init_time = std::chrono::high_resolution_clock::now();
        };

        double getTime() {
            std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
            return std::chrono::duration_cast<std::chrono::duration<double>>(now - _init_time).count();
        };

        void getFrameInit(){
            std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
            _delta_time = std::chrono::duration_cast<std::chrono::duration<double>>(now - _last_frame).count();
            _last_frame = std::chrono::high_resolution_clock::now();
        }

        double getDeltaTime() {
            return _delta_time;
        }
    };
};