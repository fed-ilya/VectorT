#pragma once

#include <iostream>
using namespace std;

class Exception {
	char* file, * func, * desc;
	int line;
public:
	Exception(const char* _file, const char* _func, int _line, const char* _desc); //Конструктор
	Exception(const Exception& ex); //Конструктор копирования
	~Exception() { delete[] file; delete[] func; delete[] desc; } //Деструктор
	void print();
};

class Rational {
	int m, n;
	void nod();
public:
	Rational operator+ (Rational x);
	void operator +=(Rational x);
	Rational operator- (Rational x);
	void operator -=(Rational x);
	Rational operator *(Rational x);
	void operator *=(Rational x);
	Rational operator/ (Rational x);
	void operator /=(Rational x);

	friend ostream& operator <<(ostream& os, Rational& a) {
		os << a.get_m() << "/" << a.get_n();
		return os;
	}

	Rational operator= (int a) {
		m = a;
		n = 1;
		return *this;
	}

	Rational(int _m, int _n) { //Конструктор инициализации
		if (_n == 0) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Zero in the denominator");
		}
		m = _m; n = _n;
		this->nod();
	}
	Rational() { m = 1; n = 1; } //Конструктор по умолчанию

	void print() { cout << get_m() << "/" << get_n() << endl; }

	double get_m() { return m; }
	double get_n() { return n; }
	void set_m(int _m) { m = _m; }
	void set_n(int _n) {
		if (_n == 0) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Zero in the denominator");
		}
		n = _n;
	}
};

template <class T>
class Vector {
private:
	int N;
	T* arr;
public:
	Vector(int _N = 10) { //Конструктор по умолчанию/инициализации
		if (_N <= 0) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrongsize on Constructor");
		}
		N = _N;
		arr = new T[N];
		for (int i = 0; i < N; i++) {
			arr[i] = 0;
		}
	} 

	Vector(const Vector& _V) { //Конструктор копирования
		N = _V.N;
		arr = new T[N];
		for (int i = 0; i < N; i++) arr[i] = _V.arr[i];
	} 

	Vector& operator =(const Vector& b) { //Оператор присваивания
		if (b.N == N)
			for (int i = 0; i < N; i++) arr[i] = b.arr[i];
		else {
			delete[] arr;
			N = b.N;
			arr = new T[N];
			for (int i = 0; i < N; i++) { arr[i] = b.arr[i]; }
		}
		return *this;
	}

	~Vector() { delete[]arr; } //Деконструктор

	T& operator[](int ind) { //Доступ к элементу по индексу
		if (ind < 0 || ind >= N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong index");
		}
		return arr[ind];
	}

	void in(int ind, double a) { //Присвоить значение a на индекс ind
		if (ind < 0 || ind >= N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong index");
		}
		arr[ind] = a;
	}

	int get_size(const Vector a) { //Вернуть размер
		return N;
	}

	void Ins(int ind, T el) { //Вставить на ind индекс значение el
		if (ind < 0 || ind >= N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong index");
		}
		Vector v(*this);
		delete[] arr;
		N = N + 1;
		arr = new T[N];
		for (int i = 0, d = 0; i < N; i++, d++) {
			if (i == ind) {
				arr[i] = el;
				d--;
			}
			else arr[i] = v.arr[d];
		}
	}

	void Del(int ind) { //Удалить элемент на индексе ind
		if (ind < 0 || ind >= N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong index");
		}
		Vector v(*this);
		delete[] arr;
		N = N - 1;
		arr = new T[N];
		for (int i = 0, d = 0; i < N; i++, d++) {
			if (d == ind) {
				i--;
			}
			else arr[i] = v.arr[d];
		}
	}

	void print() {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
	}

	Vector operator+(const Vector& V) {
		if (N != V.N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Diff size of two vectors on addition");
		}
		Vector res(N);
		for (int i = 0; i < N; i++) res.arr[i] = arr[i] + V.arr[i];
		return res;
	}
	void operator+=(const Vector& V) {
		if (N != V.N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Diff size of two vectors on addition");
		}
		for (int i = 0; i < N; i++) arr[i] += V.arr[i];
	}
	Vector operator-(const Vector& V) {
		if (N != V.N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Diff size of two vectors on subtracting");
		}
		Vector res(N);
		for (int i = 0; i < N; i++) res.arr[i] = arr[i] - V.arr[i];
		return res;
	}
	void operator-=(const Vector& V) {
		if (N != V.N) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Diff size of two vectors on subtracting");
		}
		for (int i = 0; i < N; i++) arr[i] -= V.arr[i];
	}
};