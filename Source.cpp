#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <iostream>

using namespace std;

Exception::Exception(const char* _file, const char* _func, int _line, const char* _desc) { //Конструктор
	size_t N1 = strlen(_file);
	file = new char[N1 + 1];
	strcpy(file, _file);

	int N2 = strlen(_func);
	func = new char[N2 + 1];
	strcpy(func, _func);

	int N3 = strlen(_desc);
	desc = new char[N3 + 1];
	strcpy(desc, _desc);

	line = _line;
}

Exception::Exception(const Exception& ex) { //Конструктор копирования
	int N1 = strlen(ex.file);
	file = new char[N1 + 1];
	strcpy(file, ex.file);

	int N2 = strlen(ex.func);
	func = new char[N2 + 1];
	strcpy(func, ex.func);

	int N3 = strlen(ex.desc);
	desc = new char[N3 + 1];
	strcpy(desc, ex.desc);

	line = ex.line;
}

void Exception::print() {
	cout << "Error " << file << " " << func << " " << "line " << line << " - " << desc;
}

void Rational::nod() {
	int p = abs(m); int q = abs(n);
	while (p > 0 && q > 0) {
		if (p > q) p %= q;
		else q %= p;
	}
	if ((p + q) != 1) {
		m /= (p + q); n /= (p + q);
	}
}

Rational Rational::operator+(Rational x) {
	Rational res;
	res.m = x.m * n + m * x.n;
	res.n = n * x.n;
	res.nod();
	return res;
}
void Rational::operator +=(Rational x) {
	m *= x.n;
	m += n * x.m;
	n *= x.n;
	this->nod();
}

Rational Rational::operator-(Rational x) {
	Rational res;
	res.m = m * x.n - x.m * n;
	res.n = n * x.n;
	res.nod();
	return res;
}

void Rational::operator -=(Rational x) {
	m *= x.n;
	m -= n * x.m;
	n *= x.n;
	this->nod();
}

Rational Rational::operator*(Rational x) {
	Rational res;
	res.m = x.m * m;
	res.n = n * x.n;
	res.nod();
	return res;
}

void Rational::operator *=(Rational x) {
	m *= x.m;
	n *= x.n;
	this->nod();
}

Rational Rational::operator /(Rational x) {
	Rational res;
	res.m = m * x.n;
	res.n = n * x.m;
	res.nod();
	return res;
}

void Rational::operator /=(Rational x) {
	m *= x.n;
	n *= x.m;
	this->nod();
}