#pragma once

#include <SFML/Graphics.hpp> // sf::RenderTarget, sf::Event
#include <cmath>             // std::cos, std::sin

class Button : public sf::Shape
{
public: ///< Main
    
    explicit Button(const sf::Vector2f& radius = {0.f, 0.f}, float pointCount = 30.f);
    
    void setRadius(const sf::Vector2f& radius);
    void setRadius(float width, float height);
    void setPointCount(float pointCount);
    void setClicked(bool clicked);
    
    const sf::Vector2f&  getRadius() const;
    const bool           getClicked() const;
    const bool           contains(const sf::Vector2f& mousePos) const;

    void mouseOver();
    void mouseLeave();
    
    void processMouseEvent(sf::Event event, const sf::Vector2f& mousePos, sf::Time elapsed);
    
public: ///< sf::Shape pure virtual functions
    
    virtual std::size_t  getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;
    
private: ///< Private data members

    sf::Vector2f m_radius;
    std::size_t  m_pointCount;
    bool         m_clicked;
};
