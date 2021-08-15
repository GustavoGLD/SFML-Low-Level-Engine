#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#include "Shape.hpp"

void GLD::Shape::render(sf::RenderWindow &window){
    _render_states.shader    = &shader;
    _render_states.transform = transformable.getTransform();
    window.draw(vertex_buffer, _render_states);
}

void GLD::Shape::configVertexBuffer(){
    vertex_buffer.create( vertices.size());
    vertex_buffer.update(&vertices[0]);
}