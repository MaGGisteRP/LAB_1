#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	/* 1.Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Если в последовательности
	нет чисел с суммой цифр, равной 12, упорядочить последовательность по возрастанию.*/

	/*int sum = 0;
	int a[] = { 293, 3298, 343, 34, 35, 65, 4, 23, 54 };
	int len = sizeof(a) / sizeof(a[0]);
	if (len > 10000)
	{
		cout << "err" << endl;
		return;
	}
	for (int j = 0; j < len; j++)
	{
		int b = a[j];
		while (b > 9)
		{
			sum += b % 10;
			b /= 10;
		}
		sum += b;
		if (sum == 12)
		{
			cout << "Сумма цифр равна 12 " << endl;
			return;
		}
		sum = 0;
	}
	cout << "Сумма цифр не равна 12 " << endl;
	for (int j = 0; j < len; j++)
	{
		for (int i = 0; i < len; i++)
		{
			if (j < i && a[j] > a[i])
			{
				swap(a[j], a[i]);
			}
		}
	}
	cout << "Итоговый массив: ";
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ", ";
	}*/

	/* 2.Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). Упорядочить последовательность
	по неубыванию произведения цифр числа, числа с одинаковыми произведениями цифр дополнительно
	упорядочить по неубыванию суммы цифр числа, числа с одинаковыми произведениями цифр и одинаковыми
	суммами цифр дополнительно упорядочить по неубыванию самого числа.*/

	/*int n;
	cout << "Введите количество элементов в массиве: ";
	cin >> n;
	if (n > 1000)
	{
		cout << "err";
		return;
	}
	int a[1000];
	cout << "Введите массив: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	int proiz_i = 1;
	int proiz_j = 1;
	int sum_i = 0;
	int sum_j = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				int I = a[i];
				if (a[i] > 9) {
					proiz_i *= I % 10;
					sum_i += I % 10;
					I /= 10;
				}
				proiz_i *= I;
				sum_i += I;

				int J = a[j];
				if (a[j] > 9) {
					proiz_j *= J % 10;
					sum_j += J % 10;
					J /= 10;
				}
				proiz_j *= J;
				sum_j += J;

				if (proiz_i > proiz_j)
					swap(a[i], a[j]);

				if ((proiz_i = proiz_j) && (sum_i > sum_j))
					swap(a[i], a[j]);

				if ((proiz_i = proiz_j) && (sum_i = sum_j) && (a[i]>a[j]))
					swap(a[i], a[j]);

				proiz_i = 1;
				proiz_j = 1;
				sum_i = 0;
				sum_j = 0;
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}*/
	
	/* 3.Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти столбец, в котором меньше
	всего чисел, заканчивающихся цифрой 3, и заменить все элементы матрицы кроме элементов этого
	столбца числом -17.*/

	/*int i, j, n, m, min, sch, a[100][100];

	cin >> n;
	cin >> m;
	min = n;

	if (n > 100 and m > 100) {
		cout << "err" << endl;
		return;
	}

	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}

	sch = 0;
	for (j = 0; j < m; j++) {
		for (i = 0;i < n;i++) {
			if (a[i][j] % 10 == 3) {
				sch += 1;
			}
		}
		if (sch < min) {
			min = sch;
		}
		sch = 0;
	}

	for (j = 0; j < m; j++) {
		for (i = 0;i < n;i++) {
			if (a[i][j] % 10 == 3) {
				sch += 1;
			}
		}
		if (sch != min) {
			for (i = 0;i < n;i++) {
				a[i][j] = -17;
			}
		}
		sch = 0;
	}

	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	*/
}