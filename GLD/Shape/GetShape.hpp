#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "Shape.hpp"

namespace GLD 
{


class getShape {
public:

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Creating a Triangle with a solid color
    /// \param color pass the shape color. Ex.:
    ///
    /// \code
    /// GLD::getShape::Triangle(sf::Color::Red);  //predefined;
    /// GLD::getShape::Triangle({255, 0, 0, 255}) //RGBA;
    /// \endcode
    ///
    /// \return a pointer to the new GLD::Shape object
    ////////////////////////////////////////////////////////////////////////////
    static GLD::Shape* Triangle(sf::Color color = sf::Color::White);

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Creating a Triangle with diferent colors by the 
    /// \param color pass the 3 colors in a std::array. Ex.:
    ///
    /// \code
    ///  GLD::getShape::Triangle({sf::Color::Blue, sf::Color::Green, sf::Color::Red});
    ///  GLD::getShape::Triangle({sf::Color(255, 0, 0, 255), sf::Color(0, 255, 0, 255), sf::Color(0, 0, 255, 255)});
    /// \endcode
    ///
    /// \return a pointer to the new GLD::Shape object
    ////////////////////////////////////////////////////////////////////////////
    static GLD::Shape* Triangle(std::array<sf::Color, 3> colors);

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Creating a Rectangle with a solid color
    /// \param color pass the shape color. Ex.:
    ///
    /// \code
    /// GLD::getShape::Rectangle(sf::Color::Red);  //predefined;
    /// GLD::getShape::Rectangle({255, 0, 0, 255}) //RGBA;
    /// \endcode
    ///
    /// \return a pointer to the new GLD::Shape object
    ////////////////////////////////////////////////////////////////////////////
    static GLD::Shape* Rectangle(sf::Color color = sf::Color::White);

    ////////////////////////////////////////////////////////////////////////////
    /// \brief Creating a Rectangle with diferent colors by the vertices
    /// \param color pass the 4 colors in a std::array. Ex.:
    ///
    /// \code
    ///  GLD::getShape::Rectangle({sf::Color::Blue, sf::Color::Green, sf::Color::Red});
    ///  GLD::getShape::Rectangle({sf::Color(255, 0, 0, 255), sf::Color(0, 255, 0, 255), sf::Color(0, 0, 255, 255), sf::Color(255, 255, 255, 255)});
    /// \endcode
    ///
    /// \return a pointer to the new GLD::Shape object
    ////////////////////////////////////////////////////////////////////////////
    static GLD::Shape* Rectangle(std::array<sf::Color, 4> colors);
};

};