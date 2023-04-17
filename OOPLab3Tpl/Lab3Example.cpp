#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
#endif
using std::cout;
using std::cin;
using std::endl;

class Parallelogram {
	double basis;
	double height;
	double side;
	unsigned int color;

public:
	Parallelogram() : basis(1.0), color(0), height(1.0), side(1.0) {}
	Parallelogram(double b, double h, double s, double c) : basis(b), height(h), side(s), color(c) {}
	Parallelogram(int ic) : basis(1.0), height(1.0), side(1.0) { if (ic >= 0) color = ic; else color = 0; }
	double getBasis() const
	{
		return basis;
	}
	void setBasis(double a)
	{
		if (a < 0 || a > 1.e+100)
		{
			cout << " Error set  a \n";
			return;
		}
		this->basis = a;
	}
	double getHeight() const
	{
		return height;
	}
	void setHeight(double a)
	{
		if (a < 0 || a > 1.e+100)
		{
			cout << " Error set  a \n";
			return;
		}
		this->height = a;
	}
	double getSide() const
	{
		return side;
	}
	void setSide(double a)
	{
		if (a < 0 || a > 1.e+100)
		{
			cout << " Error set  a \n";
			return;
		}
		this->side = a;
	}
	double getColor() const
	{
		return color;
	}
	void setColor(int c)
	{
		if (c < 0 || c > 10000)
		{
			cout << " Error set  color \n";
			return;
		}
		this->color = c;
	}
	double S() {
		return basis * height;
	}
	double P() {
		return 2 * (basis + side);
	}
	void printInfo()
	{
		cout << "\n Basis = " << basis << "; Height = " << height << "; Side = " << side << "; Color = " << color << endl;
		cout << "  S = " << S() << "  P = " << P() << endl;
	}

};
int mainExample1()
{
	Parallelogram obj;
	obj.printInfo();
	double in_basis, in_height, in_side; int in_color;
	cout << " Input info: "; cin >> in_basis >> in_height >> in_side >> in_color;
	Parallelogram obj1(in_color), obj2(in_basis, in_height, in_side, in_color);
	obj1.printInfo();
	obj2.printInfo();
	obj.setBasis(in_basis);
	obj.setHeight(in_height);
	obj.setSide(in_side);
	obj.setColor(in_color);
	obj.printInfo();
	cout << " End testing \n";
	char x = cin.get();
	return 0;
}

int object_count;
class ShortVector
{
	short* v;
	int num;   // default num=2
	int state = 0;
public:
	ShortVector() : ShortVector(2) { object_count++; }
	ShortVector(int n) {
		if (n <= 0) n = 2;  // default num =2;
		num = n;
		v = new short[n];
		for (int i = 0; i < n; i++) {
			v[i] = 0;
		}
		object_count++;
	}
	ShortVector(int n, short b) : ShortVector(n) {
		for (int i = 0; i < num; i++) v[i] = b;
		object_count++;
	};
	ShortVector(int n, short* p) : ShortVector(n) {
		if (p != nullptr) for (int i = 0; i < num; i++) v[i] = p[i];
		object_count++;
	};
	ShortVector(const ShortVector& s) {
		num = s.num;
		v = new short[num];
		state = s.state;
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
		object_count++;
	};
	ShortVector operator+(ShortVector s) const {
		if (num != s.num) {
			ShortVector result;
			result.state = 1;
			return result;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
			return result;
		}
	}
	ShortVector operator-(const ShortVector s) const {
		if (num != s.num) {
			ShortVector result;
			result.state = 1;
			return result;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
			return result;
		}
	};
	ShortVector operator*(unsigned char scalar) const {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}
		return result;
	};
	bool operator>(const ShortVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] <= s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator!=(const ShortVector s) const {
		if (num != s.num) {
			return true;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return true;
				}
			}
			return false;
		}
	};
	bool operator==(const ShortVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	ShortVector operator=(ShortVector s) {

		if (num != s.num)
		{
			delete[] v;
			num = s.num;
			v = new short[num];
			state = s.state;
		}
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
		return *this;
	};
	~ShortVector() {
		delete[] v;
		object_count--;
	}
	void set(int index, short x = 0) { if (index >= 0 && index <= num) v[index] = x; else state = 1; }
	short get(int index) { if (index >= 0 && index <= num) return v[index]; else state = 1; }
	void Output() {
		if (state == 1) {
			cout << "Index error";
			return;
		}
		if (num != 0) {
			for (int i = 0; i < num; i++) {
				cout << " v [ " << i << " ]   " << v[i] << '\t';
				cout << endl;
			}
		}
	};
	void Input() {
		int in_num = 0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
		} while (in_num <= 0);
		if (num != in_num) {
			num = in_num;
			if (v) delete[] v;
			v = new short[num];
		}
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]= "; cin >> v[i];
		}
	};
};

int mainExample3()
{
	object_count = 0;
	ShortVector v1;
	cout << "Vector 1: ";
	v1.Output();
	cout << endl;

	ShortVector v2(5);
	cout << "Vector 2: ";
	v2.Output();
	cout << endl;

	ShortVector v3(3, 7);
	cout << "Vector 3: ";
	v3.Output();
	cout << endl;

	ShortVector v4(v3);
	cout << "Vector 4 (copy of Vector 3): ";
	v4.Output();
	cout << endl;

	ShortVector v5;
	v5 = v2;
	cout << "Vector 5 (assigned from Vector 2): ";
	v5.Output();
	cout << endl;

	v3.set(0, 9);
	cout << "Vector 3 (after setting first element to 9): ";
	v3.Output();
	cout << endl;

	cout << "The first element of Vector 3 is: " << v3.get(0) << endl;

	cout << "Vector 3 + Vector 4";
	v1 = v3 + v4;
	v1.Output();
	
	cout << "Vector 1 - Vector 3";
	v1 = v1 - v4;
	v1.Output();

	cout << "Vector 1 * 4";
	v1 = v1 * 4;
	v1.Output();

	cout << "Vector 1 > Vector 4: " << (v1 > v4) << endl;
	cout << "Vector 1 != Vector 4: " << (v1 != v4) << endl;
	cout << "Vector 1 == Vector 4: " << (v1 == v4) << endl;

	v3.set(5, 1);
	cout << "Vector 3 (after trying to set 6th element to 1): ";
	v3.Output();
	cout << endl;
	
	return 0;
}


class Matrix {
	short** data;
	int rows;
	int cols;
	int errorState = 0;
public:
	Matrix() : Matrix(4) {};
	Matrix(int n) {
		data = new short* [n];
		for (int i = 0; i < n; i++) data[i] = new short[n];
		rows = n;
		cols = n;
		for (int i = 0, j = 0; i < n; i++, j++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] = 0;
			}
		}
	};
	Matrix(int n, int m, short value = 0) {
		data = new short* [n];
		for (int i = 0; i < n; i++) data[i] = new short[m];
		rows = n;
		cols = m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				data[i][j] = value;
			}
		}
	};
	Matrix(const Matrix& other) : Matrix(other.rows, other.cols) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	};
	Matrix& operator=(const Matrix other) {
		if (rows != other.rows && cols != other.cols) {
			for (int i = 0; i < rows; i++) delete[] data[i];
			delete[] data;
			rows = other.rows;
			cols = other.cols;
			data = new short* [rows];
			for (int i = 0; i < cols; i++) data[i] = new short[cols];
			errorState = other.errorState;
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
		return *this;
	};
	~Matrix() {
		for (int i = 0; i < rows; i++) delete[] data[i];
		delete[] data;
	};

	void set(int i, int j, short value = 0) {
		data[i][j] = value;
	}
	short get(int i, int j) const {
		 return data[i][j];
	};


	Matrix operator+(const Matrix& other) {
		if(rows != other.rows || cols != other.cols) { Matrix result(1); errorState = 1; return result; }
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) result.data[i][j] = data[i][j] + other.data[i][j];
		return result;
	};
	Matrix operator-(const Matrix& other) {
		if (rows != other.rows || cols != other.cols) { Matrix result(1); errorState = 1; return result; }
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) result.data[i][j] = data[i][j] - other.data[i][j];
		return result;
	}
	Matrix operator*(Matrix other) {
		if (cols != other.rows) { Matrix result(1); errorState = 1; return result; }
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++){
			for (int k = 0; k < cols; k++) result.data[i][j] += data[i][k] * other.data[k][j];
		}
		return result;
	}
	Matrix operator*(short scalar) {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) result.data[i][j] = data[i][j] * scalar;
		return result;
	}

	bool operator==(const Matrix& other) const {
		if (rows != other.rows || cols != other.cols) { return false; }
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) if (data[i][j] != other.data[i][j]) return false;
		return true;
	};
	bool operator!=(const Matrix& other) const {
		if (rows != other.rows || cols != other.cols) { return true; }
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) if (data[i][j] != other.data[i][j]) return true;
		return false;
	};;
	bool operator>(const Matrix& other) const {
		if (rows != other.rows || cols != other.cols) { cout << "Size failure"; return false; }
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) if (data[i][j] <= other.data[i][j]) return false;
		return true;
	};
	bool operator>=(const Matrix& other) const {
		if (rows != other.rows || cols != other.cols) { cout << "Size failure"; return false; }
		for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) if (data[i][j] < other.data[i][j]) return false;
		return true;
	};

	void print() const {
		for (int i = 0; i < rows; i++, cout << endl) for (int j = 0; j < cols; j++) cout << data[i][j] << ' ';
	};
	void printError() const {
		if (errorState == 1)
		{
			cout << "index error";
		}
		else
		{
			cout << "memory error";
		}
	};
};



int mainExample4() {
	setlocale(LC_ALL, "ukr");
	Matrix m1;
	cout << "m1:" << endl;
	m1.print();

	Matrix m2(3);
	cout << "m2:" << endl;
	m2.print();

	Matrix m3(2, 5, 10);
	cout << "m3:" << endl;
	m3.print();

	Matrix m4(m3);
	cout << "m4 (копія m3):" << endl;
	m4.print();

	m1.set(3, 2, 7);
	cout << "m1 (змінений елемент [3,2]):" << endl;
	m1.print();

	short element = m3.get(1, 3);
	cout << "Елемент [1,3] матриці m3: " << element << endl; // повинно вивести 10

	Matrix m5(3, 3, 3);
	Matrix m6(3, 3, 5);
	Matrix m7 = m5 + m6;
	cout << "m7 (сума m5 та m6):" << endl;
	m7.print(); // повинно вивести матрицю розміром 2x5, заповнену значеннями 8

	Matrix m8 = m6 - m5; 
	cout << "m8 (різниця m6 та m5):" << endl;
	m8.print(); // повинно вивести матрицю розміром 2x5, заповнену значеннями 2

	Matrix m9 = m5 * m6; 
	cout << "m9(добуток m5 та m6)" << endl;
	m9.print(); // повинно вивести матрицю розміром 3x3, заповнену значеннями 45

	cout << "m9(добуток m5 на 5)" << endl;
	m9 = m9 * ((short) 5);
	m9.print(); // повинно вивести матрицю розміром 3x3, заповнену значеннями 225

	cout << "m7 == m8: " << (m7 == m8) << endl;
	cout << "m7 != m8: " << (m7 != m8) << endl;
	cout << "m7 > m8: " << (m7 > m8) << endl;
	cout << "m7 >= m8: " << (m7 >= m8) << endl;

	return 0;
}