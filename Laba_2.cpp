#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int A, B, C;
	cout << "iput числа A B C";
	cin >> A;
	cin >> B;
	cin >> C;
	if ((A + B) % C == 0 && C % B == 0)
	{
		cout << (A + B) / C - C / B << endl;
	}
	else if((A + B) % C == 0 && C % B != 0)
	{
		cout << (A + B) / C + B * C << endl;
	}
	else;
	{
		cout << A - B + C << endl;
	}

	int N;
	cout << "введите код товара (1, 2, 3, 4, 5) : ";
	cin >> N;
	switch (N)
	{
	case 1:
		cout << "bvz njdfhf";
		break;
	case 2:
		cout << "имя товара";
		break;
	case 3:
		cout << "имя товара 3";
		break;
	case 4:
		cout << "имя товара 13";
		break;
	case 5:
		cout << "имя товара 1000-7";
		break;
	default:
		cout << "нормальные же числа попросил ввести, ты че ввел?";
	}

}

