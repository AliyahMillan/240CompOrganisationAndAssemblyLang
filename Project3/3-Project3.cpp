/* 
Problem 3
*/
#include <iostream>
using namespace std;

char c;
int average, userNumber = 0, counterL = 0, counterU = 0;

//functions
void askForSentence() {
	cout << "Enter a sentence: " << endl;
}
void readChar() {
	c = cin.get();
}

void determineUorL() {
	if ((c == 'a') || (c == 'b') || (c == 'c') || (c == 'd') || (c == 'e') || (c == 'f') || (c == 'g') || (c == 'h') || (c == 'i') || (c == 'j') || (c == 'k') || (c == 'l') || (c == 'm') || (c == 'n') || (c == 'o') || (c == 'p') || (c == 'q') || (c == 'r') || (c == 's') || (c == 't') || (c == 'u') || (c == 'v') || (c == 'w') || (c == 'x') || (c == 'y') || (c == 'z'))	{
		++counterL;
	}
	else {
		++counterU;
	}
}

int main() {
	
	_asm	{
		call askForSentence;
	whileLoop:
		call readChar;

		//exit loop
		cmp c, '\n';
		Je exitLoop;

		cmp c, ' ';
		Je whileLoop;
		//checks for lowercase

		call determineUorL;
		jmp whileLoop;
		

	exitLoop:
		
	}
	cout << "\n The amount of uppercases are: " << counterU << endl;
	cout << " The amount of lowercases are: " << counterL << endl;

	return 0;

}
