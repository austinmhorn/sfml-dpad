#pragma once

#include "Button.hpp"

#include "Directable.hpp"

class DirectionalPad : public sf::Drawable, public sf::Transformable
{
public:
    
    DirectionalPad();
    ~DirectionalPad() override = default;
    
    DirectionalPad(const DirectionalPad&) = default;
    class DirectionalPad& operator=(const DirectionalPad&) = delete;
    
    DirectionalPad(DirectionalPad&&) noexcept = default;
    class DirectionalPad& operator=(DirectionalPad&&) noexcept = delete;
    
    void setRadius(const sf::Vector2f& radius);
    void setPosition(const sf::Vector2f& position);
    void setSpacing(const sf::Vector2f& spacing);
    void setFillColor(const sf::Color& color);
    void setOutlineColor(const sf::Color& color);
    void setOutlineThickness(float thickness);
    void setMouseOverFillColor(const sf::Color& color);
    void setMouseOverOutlineColor(const sf::Color& color);

    void handleEvent(sf::RenderWindow& window, sf::Event event, sf::Time elapsed);
    void update(const sf::Vector2f& bounds, sf::Time elapsed);
    
protected:
    
    void computeGeometry();
    void arrange();
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
private:
    
    sf::Vector2f    m_radius;
    sf::Vector2f    m_spacing;
    sf::Vector2f    m_position;
    sf::CircleShape m_center;
    Button          m_left;
    Button          m_right;
    Button          m_up;
    Button          m_down;
    Directable      m_directable;
    sf::Vector2f    m_current_mouse_pos;
    
public:
    
    Directable& directable = m_directable;
};

typedef class DirectionalPad DPad;

