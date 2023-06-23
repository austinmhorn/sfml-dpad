#include "Directable.hpp"

#include <iostream>

Directable::Directable(const sf::Vector2f& radius, float pointCount)
    : m_radius(radius)
    , m_pointCount(pointCount)
    , m_velocity({0.f, 0.f})
    , m_velocityMax({.25f, .25f})
    , m_position({0.f, 0.f})
    , m_drag(0.93f)
    , m_acceleration(0.25f)
{
    Shape::update();
}
void Directable::setRadius(const sf::Vector2f& radius)
{
    m_radius = radius;
    Shape::update();
}
void Directable::setPointCount(float pointCount)
{
    m_pointCount = pointCount;
    Shape::update();
}
void Directable::setVelocity(const sf::Vector2f& velocity)
{
    m_velocity = velocity;
}
const sf::Vector2f& Directable::getVelocity() const
{
    return m_velocity;
}
void Directable::update(const sf::Vector2f& bounds, sf::Time elapsed)
{
    checkBounds(bounds, elapsed);
    
    updatePhysics(elapsed);
}
void Directable::handleEvent(sf::Event event, sf::Time elapsed)
{
    if ( !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) )
    {
        m_velocity.x = 0.f;
    }
    if ( !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) )
    {
        m_velocity.y = 0.f;
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) )  ///< Left Arrow Key PRESSED
    {
        m_velocity.x += -1.f * m_acceleration;
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ) ///< Right Arrow Key PRESSED
    {
        m_velocity.x += 1.f * m_acceleration;
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) )    ///< Up Arrow Key PRESSED
    {
        m_velocity.y += -1.f * m_acceleration;
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) )  ///< Down Arrow Key PRESSED
    {
        m_velocity.y += 1.f * m_acceleration;
    }
}
void Directable::checkBounds(const sf::Vector2f& bounds, sf::Time elapsed)
{
    if (m_position.x < 0.f) // Left window collision
        m_position.x = 0.f;
    if (m_position.x + Shape::getGlobalBounds().width > bounds.x) // Right window collision
        m_position.x = bounds.x - Shape::getGlobalBounds().width;
    if (m_position.y < 0.f) // Top window collision
        m_position.y = 0.f;
    if (m_position.y + Shape::getGlobalBounds().height > bounds.y) // Bottom window collision
        m_position.y = bounds.y - Shape::getGlobalBounds().height;
}
void Directable::updatePhysics(sf::Time elapsed)
{
    // Apply gravity
    //this->velocity.y += 0.4f * this->gravity;
    
    // Limit Y axis velocity
    if (std::abs(m_velocity.y) > m_velocityMax.x)
        m_velocity.y = m_velocityMax.y * ((m_velocity.y < 0) ? -1.f : 1.f);
    
    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;
    
    // Move character sprite
    Shape::setPosition(m_position);
    
    // Limit X axis velocity
    if (std::abs(m_velocity.x) > m_velocityMax.x)
        m_velocity.x = m_velocityMax.x * ((m_velocity.x < 0) ? -1.f : 1.f);
}
std::size_t Directable::getPointCount() const
{
    return m_pointCount;
}
sf::Vector2f Directable::getPoint(std::size_t index) const
{
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * m_radius.x;
    float y = std::sin(angle) * m_radius.y;

    return sf::Vector2f(m_radius.x + x, m_radius.y + y);
}
