//Question 3

#include <iostream>

short totalShirtNum3d = 0, medShirtNum3d = 0, shortSleeveShirtNum3d = 0, redShirtNum3d = 0, loopCount3d = 0;
int shirtArray3d[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16, 17, 18 };

void displayCounts3d() {
	std::cout << "a. Total number of All shirts: " << totalShirtNum3d << std::endl;
	std::cout << "a. Total number of Medium size shirts: " << medShirtNum3d << std::endl;
	std::cout << "a. Total number of Short Sleeve shirts: " << shortSleeveShirtNum3d << std::endl;
	std::cout << "a. Total number of Red shirts: " << redShirtNum3d << std::endl;
}

int main(){
//QUESTION 3
		
		_asm {
			lea esi, [shirtArray3d];
			mov ax, totalShirtNum3d;
		forLoop:
			cmp loopCount3d, 18;
			Jnl continuePartTwo3d;

			add eax, [esi];
			inc loopCount3d;
			add esi, 4;
			Jmp forLoop;

		continuePartTwo3d:
			mov totalShirtNum3d, ax;

			lea esi, [shirtArray3d];
			mov ax, medShirtNum3d;
			add esi, 4;
			add ax, [esi];
			add esi, 12;
			add ax, [esi];
			add esi, 12;
			add ax, [esi];
			add esi, 12;
			add ax, [esi];
			add esi, 12;
			add ax, [esi];
			add esi, 12;
			add ax, [esi];
			mov medShirtNum3d, ax;
			Jmp continePartThree3d;

		continePartThree3d:
			lea esi, [shirtArray3d];
			mov ax, shortSleeveShirtNum3d;
			mov loopCount3d, 0;

		forLoop2:
			cmp loopCount3d, 9;
			Jnl continuePartFour3d;

			add ax, [esi];
			inc loopCount3d;
			add esi, 4;
			Jmp forLoop2;

		continuePartFour3d:
			mov shortSleeveShirtNum3d, ax;

			lea esi, [shirtArray3d];
			mov ax, redShirtNum3d;

			add ax, [esi];
			add esi, 4;
			add ax, [esi];
			add esi, 4;
			add ax, [esi];
			add esi, 28;
			add ax, [esi];
			add esi, 4;
			add ax, [esi];
			add esi, 4;
			add ax, [esi];

			mov redShirtNum3d, ax;

		done:
			call displayCounts3d;

}
}
