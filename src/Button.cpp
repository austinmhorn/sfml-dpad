#include "Button.hpp"

Button::Button(const sf::Vector2f& radius, float pointCount)
    : m_radius(radius)
    , m_pointCount(pointCount)
    , m_clicked(false)
{
    Shape::update();
}
void Button::setRadius(const sf::Vector2f& radius)
{
    m_radius = radius;
    Shape::update();
}
void Button::setRadius(float width, float height)
{
    m_radius = sf::Vector2f(width, height);
    Shape::update();
}
void Button::setPointCount(float pointCount)
{
    m_pointCount = pointCount;
    Shape::update();
}
void Button::setClicked(bool clicked)
{
    m_clicked = clicked;
}
const sf::Vector2f& Button::getRadius() const
{
    return m_radius;
}
const bool Button::getClicked() const
{
    return m_clicked;
}
const bool Button::contains(const sf::Vector2f& mousePos) const
{
    return Shape::getGlobalBounds().contains(mousePos);
}
std::size_t Button::getPointCount() const
{
    return m_pointCount; 
}
sf::Vector2f Button::getPoint(std::size_t index) const
{
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * m_radius.x;
    float y = std::sin(angle) * m_radius.y;

    return sf::Vector2f(m_radius.x + x, m_radius.y + y);
}
void Button::mouseOver()
{
    Shape::setFillColor({Shape::getFillColor().r, Shape::getFillColor().g, Shape::getFillColor().b, 100});
}
void Button::mouseLeave()
{
    Shape::setFillColor({Shape::getFillColor().r, Shape::getFillColor().g, Shape::getFillColor().b, 255});
}
void Button::processMouseEvent(sf::Event event, const sf::Vector2f& mousePos, sf::Time elapsed)
{
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (this->contains(mousePos))
            m_clicked = !m_clicked;
    }
}
