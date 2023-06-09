#include <iostream>
using namespace std;

class MyVectorBool
{
private:
	bool* m_vect;
	int m_size = 0;
public:
	MyVectorBool()
	{
		m_vect = nullptr;
		m_size = 0;
	}
	~MyVectorBool()
	{
		if (m_vect != nullptr)
		{
			delete[] m_vect;
		}
	}

	MyVectorBool(const MyVectorBool& vector)
	{
		m_size = vector.m_size;
		m_vect = new bool[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_vect[i] = vector.m_vect[i];
		}
	}

	MyVectorBool(int N)
	{
		int tеmp = N; m_size = 0;
		while (tеmp > 0)
		{
			tеmp = tеmp / 2;
			m_size += 1;
		}

		tеmp = N;
		m_vect = new bool[m_size];
		for (int i = m_size - 1; i >= 0; i--)
		{
			m_vect[i] = tеmp % 2;
			tеmp = tеmp / 2;
		}
	}

	MyVectorBool& operator=(const MyVectorBool& vector)
	{
		m_size = vector.m_size;
		m_vect = new bool[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_vect[i] = vector.m_vect[i];
		}
		cout << "op. =:\t" << *this << endl;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const MyVectorBool& vector)
	{
		for (int i = 0; i < vector.m_size; i++)
		{
			out << vector.m_vect[i];
		}
		return out;
	}

	void add_end(bool k)
	{
		m_size += 1;
		bool* tеmp_vect = (bool*)realloc(m_vect, m_size * sizeof(bool));

		if (tеmp_vect != NULL)
		{
			m_vect = tеmp_vect;
		}
		m_vect[m_size - 1] = k;

		cout << "a_e:\t" << *this << endl;
	}

	int size()
	{
		return m_size;
	}

	void erase(int index)
	{
		if ((index > 0) && (index <= m_size))
		{
			cout << "e:\t" << *this;

			bool* tеmp = new bool[m_size];
			for (int i = 0; i < m_size; i++)
			{
				tеmp[i] = m_vect[i];
			}

			m_size -= 1;
			bool* tеmp_vect = (bool*)realloc(m_vect, m_size * sizeof(bool));
			if (tеmp_vect != NULL)
			{
				m_vect = tеmp_vect;
			}

			for (int i = index - 1; i < m_size; i++)
			{
				m_vect[i] = tеmp[i + 1];
			}

			cout << "  -  " << *this << endl;
		}
	}

	bool& operator[](int index)
	{
		if ((index > 0) && (index <= m_size))
			return m_vect[index - 1];
	}
};

int main()
{
	MyVectorBool vecA(11);
	MyVectorBool vecB(3);
	cout << vecA << "\t" << vecB << endl;

	vecB.add_end(1); cout << "main\n";

	int index; cout << "Enter index\t"; cin >> index;

	cout << vecA << "  -  " << vecA[index] << endl;
	vecA[index] = !(vecA[index]); cout << vecA << endl;
	vecA.erase(index);

	return 0;
}