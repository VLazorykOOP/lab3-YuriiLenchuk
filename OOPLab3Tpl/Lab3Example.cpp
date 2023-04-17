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
		cout << "\n Basis = " << basis << "Height = " << height << "Side = " << side << " Color = " << color;
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
	return 1;
}


class ShortVector
{
	short* v;
	int num;   // default num=2
	int state = 0;
public:
	ShortVector() : ShortVector(2) {}
	ShortVector(int n) {
		if (n <= 0) n = 2;  // default num =2;
		num = n;
		v = new short[n];
		for (int i = 0; i < n; i++) {
			v[i] = 0;
		}
	}
	ShortVector(int n, short b) : ShortVector(n) {
		for (int i = 0; i < num; i++) v[i] = b;
	};
	ShortVector(int n, short* p) : ShortVector(n) {
		if (p != nullptr) for (int i = 0; i < num; i++) v[i] = p[i];
	};
	ShortVector(const ShortVector& s) {
		num = s.num;
		v = new short[num];
		state = s.state;
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
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
	ShortVector Add(ShortVector& b) {
		int tnum;
		tnum = num < b.num ? num : b.num;
		if (tnum >= 0) {
			ShortVector tmp(tnum);
			for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
			return tmp;
		}
		return ShortVector(1);
	};

};

int mainExample2()
{
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


