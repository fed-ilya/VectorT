#include <iostream>
#include <stdlib.h>
#include "Vector.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	try {
		Vector<Rational> a(5), b(5), r;
		Vector<double> c(3), d(3), f;
		
		//Тест рациональных
		for (int i = 0; i < a.get_size(a); i++) {
			a[i].set_m(1);
			a[i].set_n(4);
		}
		for (int i = 0; i < b.get_size(b); i++) {
			b[i].set_m(3);
			b[i].set_n(4);
		}
		cout << "Вектор a: ";
		a.print();
		cout << endl;
		cout << "Вектор b: ";
		b.print();
		cout << endl;
		/*
		r = a + b;
		cout << "+: ";
		r.print();
		r = a - b;
		cout << "-: ";
		r.print();
		r = a;
		r += b;
		cout << "+=: ";
		r.print();
		*/
		r = a;
		r -= b;
		cout << "-=: ";
		r.print();
		cout << endl;
		cout << endl;

		//Тест double
		for (int i = 0; i < c.get_size(c); i++) {
			c[i] = 5;
		}
		for (int i = 0; i < d.get_size(d); i++) {
			d[i] = 2;
		}
		cout << "Вектор c: ";
		c.print();
		cout << endl;
		cout << "Вектор d: ";
		d.print();
		cout << endl;

		f = c + d;
		cout << "+: ";
		f.print();
		f = c - d;
		cout << "-: ";
		f.print();
		f = c;
		f += d;
		cout << "+=: ";
		f.print();
		f = c;
		f -= d;
		cout << "-=: ";
		f.print();
		cout << endl;
		cout << endl;

		cout << "Исходный вектор: ";
		c.print();
		cout << "\n";
		cout << "На 0 индекс приравнять к значению 2.5, а на 1 индекс-4.6: ";
		c[0] = 2.5;
		c[1] = 4.6;
		c.print();

		cout << "\n";
		cout << "Вставить на 2 индекс 4.9: ";
		c.Ins(2, 4.9);
		c.print();

		cout << "\n";
		cout << "Удалить на 2 индексе элемент: ";
		c.Del(2);
		c.print();
		cout << "\n";
	}
	catch (Exception& e) { //Вопрос про const
		e.print();
	}
}