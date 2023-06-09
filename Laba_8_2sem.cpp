#include <iostream>

using namespace std;

class Stack
{
private:
	int size;
	int maxsize;
	double* m_Num;
public:

	Stack(int MaxSize) : maxsize(MaxSize), size(0)
	{
		if (MaxSize > 0)
		{
			try
			{
				m_Num = new double[maxsize];
			}
			catch (const std::bad_alloc& Error)
			{
				m_Num = nullptr;
				cout << "С памятью что то не так" << endl;
			}
		}
		else
		{
			cout << "ошибка";
		}
	}
	int Size()
	{
		return size;
	}

	int MaxSize()
	{
		return maxsize;
	}

	bool Empty()
	{
		if (size > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Push(double Num)
	{
		try
		{
			if (size >= maxsize)
			{
				throw overflow_error("");
			}
			m_Num[size] = Num;
			size++;
		}
		catch (const overflow_error& Error)
		{
			cout << Error.what() << endl;
		}
	}

	double Pop()
	{
		try
		{
			if (size <= 0)
			{
				throw out_of_range("Нельзя вытащить.");
			}
			double Value = m_Num[size - 1];
			m_Num[size - 1] = NULL;
			size--;
			return Value;
		}
		catch (const out_of_range& Error)
		{
			cout << Error.what() << endl;
		}
	}

	void Top()
	{
		try
		{
			if (size <= 0)
			{
				throw logic_error("Нельзя вывести.");
			}
			cout << "Верхний элемент = " << m_Num[size - 1] << endl;
		}
		catch (const logic_error& Error)
		{
			cout << Error.what() << endl;
		}
	}

	void Info()
	{
		int Procent = size * 100 / maxsize;
		cout << "Стек заполнен на " << Procent << " процентов. Он хранит " << size << " элементов из " << maxsize << ". ";
		Top();
	}

	~Stack()
	{
		if (m_Num != nullptr)
		{
			delete[] m_Num;
		}
	}
};


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ru");
	Stack a(10);
	int p, n;
	p = rand() % 8 + 1;
	for (int i = 0; i < p; i++)
	{	
		n = 1 + rand() % 100;
		cout << n << endl;
		a.Push(n);

	}

	a.Info();

	for (int i = a.Size(); i < a.MaxSize(); i++)
	{
		a.Push(0);
	}
}
