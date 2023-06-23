#include "main.hpp"

int main(int argc, const char **argv)
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "dpad test");
    const auto window_size = sf::Vector2f{ window.getSize() };
        
    DPad dpad;
    dpad.setRadius({50.f, 50.f});
    dpad.setFillColor({0, 0, 255, 150});
    dpad.setOutlineThickness(2.f);
    dpad.setOutlineColor(sf::Color::White);
    dpad.setPosition({30.f, 380.f});
    dpad.directable.setRadius({8.f, 8.f});
    
    
    
    sf::Clock clock;
    sf::Time elapsed;
    
    while ( window.isOpen() )
    {
        elapsed = clock.restart();

        for ( auto event = sf::Event{}; window.pollEvent(event); )
        {
            dpad.handleEvent(window, event, elapsed);
                        
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        dpad.update(window_size, elapsed);
        
        window.clear();
        
        window.draw(dpad);
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}
