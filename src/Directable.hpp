#pragma once

#include <SFML/Graphics.hpp>
#include <cmath> // std::cos, std::sin

class Directable : public sf::Shape
{
public:
    
    Directable(const sf::Vector2f& radius, float pointCount = 30.f);
        
    void setRadius(const sf::Vector2f& radius);
    void setPointCount(float pointCount);
    void setVelocity(const sf::Vector2f& velocity);
    
    const sf::Vector2f&  getRadius() const;
    virtual std::size_t  getPointCount() const override;
    virtual sf::Vector2f getPoint(std::size_t index) const override;
    const sf::Vector2f&  getVelocity() const;
    
    void update(const sf::Vector2f& bounds, sf::Time elapsed);
    void handleEvent(sf::Event event, sf::Time elapsed);
    
private:
    
    void checkBounds(const sf::Vector2f& bounds, sf::Time elapsed);
    void updatePhysics(sf::Time elapsed);
    
protected:
    
    sf::Vector2f m_radius;
    std::size_t  m_pointCount;
    sf::Vector2f m_velocity;
    sf::Vector2f m_velocityMax;
    sf::Vector2f m_position;
    float        m_drag;
    float        m_acceleration;
};
