//Problem #2
#include <iostream>
using namespace std;

bool menuChoice = true;
int average, userNumber = 0, counter = 0, sum = 0;
void askdata() {
	cout << "Enter your score (-1) to stop: " << endl;
	cin >> userNumber;
}
int main() {
	cout << "Let’s compute your score’s average: " << endl;
	_asm {
	whileLoop:
		call askdata;
		cmp userNumber, -1;
		Je exitLoop;
		//checks before adding the data to the average

		inc counter;
		mov eax, userNumber;
		add sum, eax;
		Jmp whileLoop;
	exitLoop:
		//find the average
		mov eax, sum;
		cdq;
		idiv counter;
		mov average, eax;
	}
	cout << "\n The average is " << average;

	return 0;

}
