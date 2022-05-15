//Question 2 
#include <iostream>

int i, j, a[5] = { 9, 3, 22, 8, 1 };

void display() {
	std::cout << "Swap" << std::endl;
}

int main(){
	//QUESTION 2 
	std::cout << "Original array a: 9, 3, 22, 8, 1" << std::endl;
	_asm {
		mov i, 0;
	forloop:
		cmp i, 4;
		jnl done;

		mov j, 0;
		inc i;
		lea esi, [a];
		Jmp forloop2;

		//Bubble sort
	forloop2:
		cmp j, 4;
		jnl forloop;

		mov eax, [esi];
		mov ebx, [esi + 4];
		cmp eax, ebx;
		jg swap_nodes;

		add esi, 4;
		inc j;

		jmp forloop2;

		//Swap
	swap_nodes:
		mov eax, [esi];
		mov ebx, eax;
		xchg eax, [esi + 4];
		mov[esi], eax;

		inc j;
		add esi, 4;
		jmp forloop2;//done2


	done:
	}
	std::cout << "Sorted array a: ";

	for (int y = 0; y < 5; y++)
	{
		std::cout << a[y] << ", ";
	}
}
//intmainend
