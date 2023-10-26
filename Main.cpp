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
		
		//���� ������������
		for (int i = 0; i < a.get_size(a); i++) {
			a[i].set_m(1);
			a[i].set_n(4);
		}
		for (int i = 0; i < b.get_size(b); i++) {
			b[i].set_m(3);
			b[i].set_n(4);
		}
		cout << "������ a: ";
		a.print();
		cout << endl;
		cout << "������ b: ";
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

		//���� double
		for (int i = 0; i < c.get_size(c); i++) {
			c[i] = 5;
		}
		for (int i = 0; i < d.get_size(d); i++) {
			d[i] = 2;
		}
		cout << "������ c: ";
		c.print();
		cout << endl;
		cout << "������ d: ";
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

		cout << "�������� ������: ";
		c.print();
		cout << "\n";
		cout << "�� 0 ������ ���������� � �������� 2.5, � �� 1 ������-4.6: ";
		c[0] = 2.5;
		c[1] = 4.6;
		c.print();

		cout << "\n";
		cout << "�������� �� 2 ������ 4.9: ";
		c.Ins(2, 4.9);
		c.print();

		cout << "\n";
		cout << "������� �� 2 ������� �������: ";
		c.Del(2);
		c.print();
		cout << "\n";
	}
	catch (Exception& e) { //������ ��� const
		e.print();
	}
}