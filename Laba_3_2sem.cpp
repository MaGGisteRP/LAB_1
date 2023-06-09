#include <iostream>

using namespace std;

class D_Complex
{
private:
    double a;
    double b;
public:
    D_Complex(double a = 0.0, double b = 0.0) : a(a), b(b)
    {
        //Базовый конструктор
    }

    D_Complex(const D_Complex& z)
    {
        //Конструктор копирования
        a = z.a;
        b = z.b;
    }

    D_Complex& operator=(D_Complex z)
    {
        //Оператор присваивания копированием
        a = z.a;
        b = z.b;
        return *this;
    }

    ~D_Complex() {} //Деструктор

    D_Complex& operator+=(const D_Complex& z)
    {
        a += z.a;
        b += z.b;
        return *this;
    }

    friend D_Complex operator+(const D_Complex& z1, const D_Complex& z2)
    {
        D_Complex temp;
        temp.a = z1.a + z2.a;
        temp.b = z1.b + z2.b;
        return temp;
    }

    D_Complex& operator*=(const D_Complex& z)
    {
        D_Complex temp = (*this);
        a = temp.a * z.a - temp.b * z.b;
        b = temp.a * z.b + z.a * temp.b;
        return *this;
    }

    friend D_Complex operator*(const D_Complex& z1, const D_Complex& z2)
    {
        D_Complex temp;
        temp.a = z1.a * z2.a - z1.b * z2.b;
        temp.b = z1.a * z2.b + z2.a * z1.b;
        return temp;
    }

    //Префиксный
    D_Complex& operator++()
    {
        a += 1;
        return *this;
    }

    //Постфиксный
    D_Complex operator++(int)
    {
        D_Complex temp = *this;
        a += 1;
        return temp;
    }

    friend istream& operator>>(istream& in, D_Complex& z)
    {
        in >> z.a >> z.b;
        return in;
    }

    friend ostream& operator<<(ostream& out, const D_Complex& z)
    {
        out << z.a << " + " << z.b << "i";
        return out;
    }
};

int main()
{
    D_Complex z1, z2;
    cout << "First number: ";
    cin >> z1;
    cout << "Second number: ";
    cin >> z2;

    D_Complex z3 = z1 + z2;
    D_Complex z4 = z1 * z2;
    cout << "Sum: " << z3 << endl;
    cout << "Multiplication: " << z4 << endl;

    return 0;
}