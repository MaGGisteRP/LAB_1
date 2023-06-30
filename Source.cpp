#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "image.jpg"); // ������� ���� �������� 800x600

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/susin/source/repos/SSSsusaAAA/SFML Image Demo/image.jpg")) // ��������� ����������� �� ����� "image.jpg"
    {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    sf::Sprite sprite(texture); // ������� ������ � ������������ ���������

    window.clear(sf::Color::White); // ������� ����

    window.draw(sprite); // ���������� ������ � ����

    window.display(); // ��������� ����

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 3) // ����������� ��������� �� 10 ������
    {
        // ������������ ������� ����
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close(); // ��������� ���� �� ������� �� �������
            }
        }
    }

    return 0;
}
