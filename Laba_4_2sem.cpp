#include <iostream>
using namespace std;

template <typename M>
class Matrix
{
private:
	M** Mat;
	int n;
	int m;

public:
	Matrix(int n, int m) : n(n), m(m)
	{
		Mat = new M * [n];
		for (int i = 0; i < n; i++)
		{
			Mat[i] = new M[m];
		}
	}

	// конструктор копирования
	Matrix(const Matrix& Matrix)
	{
		n = Matrix.n;
		m = Matrix.m;
		Mat = new M * [n];
		for (int i = 0; i < n; i++)
		{
			Mat[i] = new M[m];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				Mat[i][j] = Matrix.Mat[i][j];
			}
		}
	}

	// оператор присваивания
	Matrix& operator= (const Matrix& Matrix)
	{
		n = Matrix.n;
		m = Matrix.m;
		Mat = new M * [n];
		for (int i = 0; i < n; i++)
		{
			Mat[i] = new M[m];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				Mat[i][j] = Matrix.Mat[i][j];
			}
		}
		return *this;
	}

	// оператор ввода
	friend istream& operator>>(istream& in, Matrix& Matrix)
	{
		cout << "Enter the matrix elements of " << Matrix.n << " rows and " << Matrix.m << " columns:" << endl;
		for (int i = 0; i < Matrix.n; i++)
		{
			for (int j = 0; j < Matrix.m; j++)
			{
				in >> Matrix.Mat[i][j];
			}
		}
		return in;
	}

	// оператор вывода
	friend ostream& operator<<(ostream& out, Matrix& Matrix)
	{
		cout << "Matrix: " << endl;
		for (int i = 0; i < Matrix.n; i++)
		{
			for (int j = 0; j < Matrix.m; j++)
			{
				out << Matrix.Mat[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}

	// оператор +
	friend Matrix operator+(const Matrix& Mat1, const Matrix& Mat2)
	{
		if ((Mat1.n == Mat2.n) && (Mat1.m == Mat2.m))
		{
			Matrix<M> tempM(Mat1.n, Mat1.m);
			for (int i = 0; i < tempM.n; i++)
			{
				for (int j = 0; j < tempM.m; j++)
				{
					tempM.Mat[i][j] = (Mat1.Mat[i][j] + Mat2.Mat[i][j]);
				}
			}
			return tempM;
		}
		else
		{
			Matrix<M> tempM(1, 1);
			tempM.Mat[0][0] = 0;
			cout << "Error" << endl;
			return tempM;
		}
	}

	// оператор -
	friend Matrix operator-(const Matrix& Mat1, const Matrix& Mat2)
	{
		if ((Mat1.n == Mat2.n) && (Mat1.m == Mat2.m))
		{
			Matrix<M> tempM(Mat1.n, Mat1.m);
			for (int i = 0; i < tempM.n; i++)
			{
				for (int j = 0; j < tempM.m; j++)
				{
					tempM.Mat[i][j] = (Mat1.Mat[i][j] - Mat2.Mat[i][j]);
				}
			}
			return tempM;
		}
		else
		{
			Matrix<M> tempM(1, 1);
			tempM.Mat[0][0] = 0;
			cout << "Error" << endl;
			return tempM;
		}
	}

	// оператор +=
	Matrix& operator+=(const Matrix& Mat1)
	{
		if ((n == Mat1.n) && (m == Mat1.m))
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Mat[i][j] += Mat1.Mat[i][j];
				}
			}
			return *this;
		}
		else
		{
			Matrix<M> tempM(1, 1);
			tempM.Mat[0][0] = 0;
			cout << "Error" << endl;
			return tempM;
		}
	}

	// оператор *
	friend Matrix operator*(const Matrix& Mat1, const Matrix& Mat2)
	{
		if (Mat1.m == Mat2.n)
		{
			int count = Mat1.m;
			Matrix<M> tempM(Mat1.n, Mat2.m);
			for (int i = 0; i < tempM.n; i++)
			{
				for (int j = 0; j < tempM.m; j++)
				{
					int sum = 0;
					for (int k = 0; k < count; k++)
					{
						sum += Mat1.Mat[i][k] * Mat2.Mat[k][j];
					}
					tempM.Mat[i][j] = sum;
				}
			}
			return tempM;
		}
		else
		{
			Matrix tempM(1, 1);
			tempM.Mat[0][0] = false;
			cout << "Error" << endl;
			return tempM;
		}
	}

	// оператор *=
	Matrix& operator*=(const Matrix& Mat1)
	{
		if (m == Mat1.n)
		{
			Matrix<M> tempM(n, Mat1.m);
			int count = m;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < Mat1.m; j++)
				{
					int sum = 0;
					for (int k = 0; k < count; k++)
					{
						sum += Mat[i][k] * Mat1.Mat[k][j];
					}
					tempM.Mat[i][j] = sum;
				}
			}

			*this = tempM;
			return *this;
		}
		else
		{
			Matrix tempM(1, 1);
			tempM.Mat[0][0] = false;
			cout << "Error" << endl;
			return tempM;
		}
	}

	// оператор ++
	Matrix& operator++(int)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				Mat[i][j] += 1;
			}
		}
		return *this;
	}

	M determinant()
	{
		if (n == m)
		{
			if (n == 1)
			{
				return (Mat[0][0]);
			}
			if (n == 2)
			{
				return (Mat[0][0] * Mat[1][1] - Mat[0][1] * Mat[1][0]);
			}
			if (n == 3)
			{
				M A = (Mat[0][0] * Mat[1][1] * Mat[2][2]) +
					(Mat[1][0] * Mat[0][2] * Mat[2][1]) +
					(Mat[2][0] * Mat[0][1] * Mat[1][2]);
				M B = (Mat[2][0] * Mat[1][1] * Mat[0][2]) +
					(Mat[1][0] * Mat[0][1] * Mat[2][2]) +
					(Mat[0][0] * Mat[1][2] * Mat[2][1]);
				return A - B;
			}
		}
		else
		{
			cout << "Error" << endl;
			return 0;
		}
	}

	M operator()(int i, int j)
	{
		if ((0 < i <= n) && (0 < j <= m))
		{
			return Mat[i - 1][j - 1];
		}
		else
		{
			cout << "Error" << endl;
			return 0;
		}
	}

	M replaceElement(int i, int j, M element)
	{
		if ((0 < i <= n) && (0 < j <= m))
		{
			Mat[i - 1][j - 1] = element;
			return Mat[i - 1][j - 1];
		}
		else
		{
			cout << "Error" << endl;
			return 0;
		}
	}

	//деструктор
	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete Mat[i];
		}
		delete Mat;
	}

};

int main()
{
	Matrix<int> A(3, 3), B(3, 3), C(2, 3);
	cin >> A >> B >> C;
	cout << endl;

	A++;
	cout << "A++:" << endl << A;

	Matrix<int> D = A + B;
	cout << "D = A + B:" << endl << D << endl;

	Matrix<int> E = A * C;
	cout << "E = A * C:" << endl << E << endl;

	int i, j;
	cout << "Enter index i and j of Matrix A: ";
	cin >> i >> j;
	cout << "A[" << i << "][" << j << "] = " << A(i, j) << endl;

	int Z = B.determinant();
	cout << endl << "Z = " << Z << endl;

	A.replaceElement(i, j, Z);
	cout << endl << A << endl;

	A++;
	cout << "A++:" << endl << A;

	return 0;
}