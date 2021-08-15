#pragma once

#include "GetShape.hpp"

GLD::Shape* GLD::getShape::Triangle(sf::Color color){
    GLD::Shape* shape = new GLD::Shape();
    shape->vertices = {
        sf::Vertex(sf::Vector2f(0.5f, 1.0f), color),
        sf::Vertex(sf::Vector2f(0.0f, 0.0f), color), 
        sf::Vertex(sf::Vector2f(1.0f, 0.0f), color)
    };
    shape->vertex_buffer.setPrimitiveType(sf::PrimitiveType::Triangles);
    shape->configVertexBuffer();
    return shape;
}

GLD::Shape* GLD::getShape::Triangle(std::array<sf::Color, 3> colors){
    GLD::Shape* shape = new GLD::Shape();
    shape->vertices = {
        sf::Vertex(sf::Vector2f(0.5f, 1.0f), colors[0]),
        sf::Vertex(sf::Vector2f(0.0f, 0.0f), colors[1]),
        sf::Vertex(sf::Vector2f(1.0f, 0.0f), colors[2])
    };
    shape->vertex_buffer.setPrimitiveType(sf::PrimitiveType::Triangles);
    shape->configVertexBuffer();
    
    return shape;
}

GLD::Shape* GLD::getShape::Rectangle(sf::Color color){
    GLD::Shape* shape = new GLD::Shape();
    shape->vertices = {
        sf::Vertex(sf::Vector2f(0.0f, 0.0f), color),
        sf::Vertex(sf::Vector2f(0.0f, 1.0f), color), 
        sf::Vertex(sf::Vector2f(1.0f, 0.0f), color),
        sf::Vertex(sf::Vector2f(1.0f, 1.0f), color)
    };
    shape->vertex_buffer.setPrimitiveType(sf::PrimitiveType::TrianglesStrip);
    shape->configVertexBuffer();
    return shape;
}

GLD::Shape* GLD::getShape::Rectangle(std::array<sf::Color, 4> colors){
    GLD::Shape* shape = new GLD::Shape();
    shape->vertices = {
        sf::Vertex(sf::Vector2f(0.0f, 0.0f), colors[0]),
        sf::Vertex(sf::Vector2f(0.0f, 1.0f), colors[1]), 
        sf::Vertex(sf::Vector2f(1.0f, 0.0f), colors[2]),
        sf::Vertex(sf::Vector2f(1.0f, 1.0f), colors[3])
    };
    shape->vertex_buffer.setPrimitiveType(sf::PrimitiveType::TrianglesStrip);
    shape->configVertexBuffer();
    return shape;
}