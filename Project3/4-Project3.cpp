// Problem 4 - Cramer's Rule
#include <iostream>
using namespace std;
int main() {
	short a, b, c, d, e, f, divisor, resultX, resultY;
	cout << "This program solves the system" << endl;
	cout << "\taX + bY = c" << endl;
	cout << "\taX + bY = c" << endl;
	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d, e, and f: ";
	cin >> d >> e >> f;
	__asm {
		//Numerator for X 
		mov ax, c;
		imul ax, e;
		mov bx, b;
		imul bx, f;
		sub ax, bx;
		mov resultX, ax;
		//Numerator for Y 
		mov ax, a;
		imul ax, f;
		mov bx, c;
		imul bx, d;
		sub ax, bx;
		mov resultY, ax;
		//Denominator 
		mov ax, a;
		imul ax, e;
		mov bx, b;
		imul bx, d;
		sub ax, bx;
		mov divisor, ax;
		//(X numerator / Denominator) 
		mov ax, resultX;
		cwd;
		idiv divisor;
		mov resultX, ax;
		//(X numerator / Denominator) 
		mov ax, resultY;
		cwd; idiv divisor;
		mov resultY, ax;
	}
	cout << "\t X = " << resultX << endl;
	cout << "\t Y = " << resultY << endl;
}
