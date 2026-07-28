#include <iostream>

#include <SFML/Graphics.hpp>
#include "Body.h"
#include "Vec2.h"

// Constants
const sf::Vector2f SCREEN_COORDS_ORIGIN{ 0.0f, 0.0f };
const float TREE_HORIZONTAL_POSITION = 810.0f;
const float TREE_VERTICAL_POSITION = 0.0f;

// Screen Resolution Settings
sf::VideoMode vm({ 1920, 1080 }); // Res. definition

int main() // Program execution start - 'main() {}' function
{
    Vec2 v1(1.0f, 2.0f);
    Vec2 v2(2.0f, 4.0f);
    v1 += v2;
    std::cout << v1.x << ", " << v1.y << std::endl;

    Vec2 v3 = v1 + v2;
    std::cout << v1.x << ", " << v1.y << "; " << v3.x << ", " << v3.y << std::endl;

    // Create and open the game window object - 'window'
    sf::RenderWindow window(vm, "Timber!", sf::Style::Default);

    // Create 'Sprite' object - 'background' 
    sf::Texture texr_background;
    if (!texr_background.loadFromFile("Graphics/background.png"))
    {
        // Handle loading error...
    }
    sf::Sprite sprt_background(texr_background);
    sprt_background.setPosition(SCREEN_COORDS_ORIGIN);
    sprt_background.setScale({ 1.0f, 1.0f });

    // Create 'Sprite' object - 'tree'
    sf::Texture texr_tree;
    if (!texr_tree.loadFromFile("Graphics/tree.png"))
    {
        // Handle loading error...
    }
    sf::Sprite sprt_tree(texr_tree);
    sprt_tree.setPosition({ TREE_HORIZONTAL_POSITION, TREE_VERTICAL_POSITION });
    sprt_tree.setScale({ 1.0f, 1.0f });

    // Create 'Sprite' object - 'bee'
    sf::Texture texr_bee;
    if (!texr_bee.loadFromFile("Graphics/bee.png"))
    {
        // Handle loading error...
    }
    sf::Sprite sprt_bee(texr_bee);
    sprt_bee.setPosition({ 1890, 539 });
    sprt_bee.setScale({ 1.0f, 1.0f });

    Body playerBody("Graphics/player.png");
    sf::Sprite sprt_player(playerBody.getTexture());

    // Get elapsed time as dt
    sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            //playerBody.MoveLeft();
            //playerBody.Update(deltaTime);

            //std::cout << playerBody.getSpeed() << std::endl;
        }

        // SFML Rendering Pipeline - Clear, Draw, Display
        window.clear();
        window.draw(sprt_background);
        window.draw(sprt_tree);
        window.draw(sprt_bee);
        window.draw(sprt_player);
        window.display();
    }

    return 0; // Program execution end - 'main() {}' function
}

// 1/1/26 - We have learned SFML's 'setPosition()' function, method of the 'Sprite' class, no longer
// no longer takes two floats as parameters, but one single 'Vector2f' object
// 1/1/26 - No longer can you type sf::Event event