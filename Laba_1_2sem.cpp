#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;
using namespace sf;

class MyText
{
private:
    double odna;
    string text;
    Font font;
    Text krastext;
public:
    void SetText(string a)
    {
        text = a;
    }
    void SetVremya(double a)
    {
        odna = a / (text.length() - 1) * 1000;
    }
    void AnimationText()
    {
        font.loadFromFile("Decrypted.ttf");
        krastext.setFont(font);
        krastext.setCharacterSize(90);
        krastext.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        krastext.setPosition(20, 0);

        RenderWindow window(VideoMode(800, 800), "laba_1");

        string bukv;
        int a = 1;

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            for (int i = 0; i < text.length() + 1; i++)
            {
                if (a == 1)
                {

                    bukv = text.substr(0, i);
                    krastext.setString(bukv);
                    Sleep(odna);
                    krastext.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));

                    window.clear(Color::White);
                    window.draw(krastext);
                    window.display();

                    if (i == text.length())
                    {
                        a = 0;
                    }
                }
            }
        }
    }
};

int main()
{
    string text;
    cout << "Vvedite text: ";
    getline(cin, text);
    double vremya;
    cout << "Vvedite vremya: ";
    cin >> vremya;
    MyText abc;
    abc.SetText(text);
    abc.SetVremya(vremya);
    abc.AnimationText();
    return 0;
}