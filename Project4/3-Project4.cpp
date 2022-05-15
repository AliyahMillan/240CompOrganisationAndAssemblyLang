/*
Problem 3
*/
#include <iostream>
using namespace std; 

short a, good = 0, bad = 0, i = 1, counterON = 0, defectiveSprinkler,
counterOFF = 0, jumpCounter = 1, registerBaseTwo = 0x6A2F; 

void Base2() {
short x = 1 << 15, t; 
short n = a;
for (short i = 1; i <= 16; i++){
	t = n & x;
	if (t == 0)	{
		cout << 0;
	}
	else {
		cout << 1;
	}
	if (i % 4 == 0)	{
		cout << " ";
	}
	n = n << 1;
}
}
void displayJumpCounter() {
	cout << "jumpCounter = " << jumpCounter << endl;  
}
void checker() {
	cout << "The code has made it this far!" << endl; 
}
void displayON() {
	cout << "\n" << counterON << " sprinkler(s) are ON" << endl;
}
void displayOFF1() {
	cout << "Defective Sprinklers: "; 
}
void displayOFF2() {
	cout << defectiveSprinkler << " ";
}
int main() {
	_asm {
		mov ax, registerBaseTwo; // 0x6A2F
		mov a, ax; 
		call Base2; 

		mov ax, a; 
		mov bx, 0000000000000001b;

	whileLoop: 
		mov ax, a; 
		and ax, bx; 
		cmp ax, 0;

		Jg incCounter; 

		Jmp resume; 

	resume: 
		cmp jumpCounter, 17; 
		jle shiftLeft; 
		jmp leaveObjII; 

	incCounter: 
		inc counterON; 
		jmp shiftLeft; 

	shiftLeft: 
		inc jumpCounter; 
		shl bx, 1; 
		jmp whileLoop; 

	leaveObjII: 
		call displayON; 

		call displayOFF1; 
		mov ax, 6A2FH; 
		mov bx, 0000000000000001b; 
	
	whileLoop2: 
		mov ax, 6A2Fh; 
		cmp i, 17; 
		Je done; 
		and ax, bx; 
		cmp ax, 0; 
		Je isDefective; 
		shl bx, 1; 
		inc i; 
		inc good; 
		Jmp whileLoop2; 

	isDefective: 
		mov cx, i; 
		mov defectiveSprinkler, cx; 
		call displayOFF2; 
		shl bx, 1; 
		inc bad; 
		inc i; 
		Jmp whileLoop2; 

	done:
	}
	return 0; 
}
