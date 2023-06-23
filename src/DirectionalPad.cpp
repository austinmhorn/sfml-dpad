#include "DirectionalPad.hpp"

#include <iostream>

DirectionalPad::DirectionalPad()
    : m_radius({100.f, 100.f})
    , m_spacing({20.f, 20.f})
    , m_position({0.f, 0.f})
    , m_directable({16.f, 16.f})
{
    computeGeometry();
}
void DirectionalPad::setRadius(const sf::Vector2f& radius)
{
    m_radius = radius;
    computeGeometry();
    arrange();
}
void DirectionalPad::setPosition(const sf::Vector2f& position)
{
    m_position = position;
    arrange();
}
void DirectionalPad::setSpacing(const sf::Vector2f& spacing)
{
    m_spacing = spacing;
    arrange();
}
void DirectionalPad::setFillColor(const sf::Color& color)
{
    m_center.setFillColor(color);
    m_left.setFillColor(color);
    m_right.setFillColor(color);
    m_up.setFillColor(color);
    m_down.setFillColor(color);
}
void DirectionalPad::setOutlineColor(const sf::Color& color)
{
    m_center.setOutlineColor(color);
    m_left.setOutlineColor(color);
    m_right.setOutlineColor(color);
    m_up.setOutlineColor(color);
    m_down.setOutlineColor(color);
}
void DirectionalPad::setOutlineThickness(float thickness)
{
    m_center.setOutlineThickness(thickness);
    m_left.setOutlineThickness(thickness);
    m_right.setOutlineThickness(thickness);
    m_up.setOutlineThickness(thickness);
    m_down.setOutlineThickness(thickness);
}
void DirectionalPad::setMouseOverFillColor(const sf::Color& color)
{
    
}
void DirectionalPad::setMouseOverOutlineColor(const sf::Color& color)
{
    
}
void DirectionalPad::handleEvent(sf::RenderWindow& window, sf::Event event, sf::Time elapsed)
{
    if (event.type == sf::Event::MouseMoved)
    {
        m_current_mouse_pos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) )  ///< Left Arrow Key PRESSED
    {
        m_left.mouseOver();
        m_directable.handleEvent(event, elapsed);
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ) ///< Right Arrow Key PRESSED
    {
        m_right.mouseOver();
        m_directable.handleEvent(event, elapsed);
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) )    ///< Up Arrow Key PRESSED
    {
        m_up.mouseOver();
        m_directable.handleEvent(event, elapsed);
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) )  ///< Down Arrow Key PRESSED
    {
        m_down.mouseOver();
        m_directable.handleEvent(event, elapsed);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Left)  ///< Left Arrow Key RELEASED
    {
        m_left.mouseLeave();
        m_directable.handleEvent(event, elapsed);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Right) ///< Right Arrow Key RELEASED
    {
        m_right.mouseLeave();
        m_directable.handleEvent(event, elapsed);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Up)    ///< Up Arrow Key RELEASED
    {
        m_up.mouseLeave();
        m_directable.handleEvent(event, elapsed);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Down)  ///< Down Arrow Key RELEASED
    {
        m_down.mouseLeave();
        m_directable.handleEvent(event, elapsed);
    }
    
    m_left.processMouseEvent(event, m_current_mouse_pos, elapsed);
    m_right.processMouseEvent(event, m_current_mouse_pos, elapsed);
    m_up.processMouseEvent(event, m_current_mouse_pos, elapsed);
    m_down.processMouseEvent(event, m_current_mouse_pos, elapsed);
}
void DirectionalPad::update(const sf::Vector2f& bounds, sf::Time elapsed)
{
    m_directable.update(bounds, elapsed);
}
void DirectionalPad::computeGeometry()
{
    m_center = sf::CircleShape(m_radius.x/3.f, 30.f);
    m_left   = Button(sf::Vector2f(m_radius.x/3.f, m_radius.y/3.f), 3.f);
    m_right  = Button(sf::Vector2f(m_radius.x/3.f, m_radius.y/3.f), 3.f);
    m_up     = Button(sf::Vector2f(m_radius.x/3.f, m_radius.y/3.f), 3.f);
    m_down   = Button(sf::Vector2f(m_radius.x/3.f, m_radius.y/3.f), 3.f);
    
    m_left.setRotation(270.f);
    m_right.setRotation(90.f);
    m_down.setRotation(180.f);
}
void DirectionalPad::arrange()
{
    m_center.setPosition(m_position.x + m_radius.x/3.f, m_position.y + m_radius.y/3.f);
    m_left.setPosition(m_position.x - m_spacing.x, m_position.y + m_radius.y);
    m_right.setPosition(m_position.x + (m_radius.x * 4.f/3.f) + m_spacing.x, m_position.y + m_radius.y/3.f);
    m_up.setPosition(m_position.x + m_radius.x/3.f, m_position.y - m_spacing.y);
    m_down.setPosition(m_position.x + m_radius.x, m_position.y + (m_radius.y * 4.f/3.f) + m_spacing.y);
}
void DirectionalPad::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_directable);
    
    target.draw(m_left);
    target.draw(m_right);
    target.draw(m_up);
    target.draw(m_down);
    target.draw(m_center);
}
