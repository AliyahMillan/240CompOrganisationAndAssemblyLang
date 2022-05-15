//Question 1
#include <iostream>

short totalShirtNum = 0, medShirtNum = 0, blueShirtNum = 0,
loopCount = 0;
int shirtArray[4][4] = { 10, 20, 30, 40, 20, 10, 40,
30, 5, 15, 20, 25, 30, 25, 20, 15 };

void displayCounts(){
	std::cout << "a. Compute and display the total number of All shirts:  " << totalShirtNum << std::endl;
	std::cout << "b. Compute and display the total number of Medium shirts:  " << medShirtNum << std::endl;
	std::cout << "c. Compute and display the total number of Blue shirts:  " << blueShirtNum << std::endl;
}
int main(){
	
	//QUESTION 1
		_asm {
			lea esi, [shirtArray];
			mov ax, totalShirtNum;
		forLoop:
			cmp loopCount, 16;
			Jnl continuePartTwo;

			add eax, [esi];
			inc loopCount;
			add esi, 4;
			Jmp forLoop;

		continuePartTwo:
			mov totalShirtNum, ax;
			lea esi, [shirtArray];
			mov ax, medShirtNum;
			add esi, 4;
			add ax, [esi];
			add esi, 16;
			add ax, [esi];
			add esi, 16;
			add ax, [esi];
			add esi, 16;
			add ax, [esi];
			Jmp continuePartThree;

		continuePartThree:
			mov medShirtNum, ax;
			lea esi, [shirtArray];
			mov ax, blueShirtNum;
			add esi, 32;
			add ax, [esi];
			add esi, 4;
			add ax, [esi];
			add esi, 4;
			add ax, [esi];
			add esi, 4;
			add ax, [esi];
			mov blueShirtNum, ax;
			Jmp done;

		done:
			call displayCounts;
		}
}
