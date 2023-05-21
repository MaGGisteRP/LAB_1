#include <iostream>
#include <cstring>


using namespace std;

int main() 
    {
    setlocale(LC_ALL, "Russian");

    char str[101];
    cout << "Введите строку: ";
    cin.getline(str, 101);

    int len = strlen(str);
    for (int i = 0; i < len; i++) 
    {
        if (ispunct(str[i]))
        {                                        // проверяем, является ли символ знаком препинания
            for (int j = i; j < len; j++)
            {
                str[j] = str[j + 1];             // сдвигаем символы влево, чтобы удалить знак препинания
            }
            len--;                               // уменьшаем длину строки на 1
            i--;                                 // уменьшаем счетчик i на 1, чтобы проверить символ на новой позиции
        }
    }

    cout << "Строка без знаков препинания: " << str << endl;
    return 0;
}