#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "image.jpg"); // Создаем окно размером 800x600

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/susin/source/repos/SSSsusaAAA/SFML Image Demo/image.jpg")) // Загружаем изображение из файла "image.jpg"
    {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    sf::Sprite sprite(texture); // Создаем спрайт с используемой текстурой

    window.clear(sf::Color::White); // Очищаем окно

    window.draw(sprite); // Отображаем спрайт в окне

    window.display(); // Обновляем окно

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 3) // Задерживаем программу на 10 секунд
    {
        // Обрабатываем события окна
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close(); // Закрываем окно по нажатию на крестик
            }
        }
    }

    return 0;
}
