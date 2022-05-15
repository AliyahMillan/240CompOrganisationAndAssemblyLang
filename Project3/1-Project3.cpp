/*
Problem 1
*/
#include <iostream>
using namespace std;
int customers, two = 2, four = 4, three = 3, five = 5, i;
int drinknumber;
char drinkletter;
int sandwichnumber;
int sandwichsize;
int sandwichprice;
int cost, drinkprice;
void askCustomer() {
	cout << "Enter the number of customers: ";
	cin >> customers;
}
void readData() {
	cout << " How many drinks? ";
	cin >> drinknumber;
	cout << " What kind of drink(S = Soda, W = Water)? ";
	cin >> drinkletter;
	cout << " How many sandwiches? ";
	cin >> sandwichnumber;
	cout << " What size of sandwich(10/12 inches)? ";
	cin >> sandwichsize;
}
void displayCost1() {
	cout << "Cost is: " << cost << endl;
}
int main() {
	cout << "------------------ 7-11 Convenient Store ------------------" << endl;
	cout << "Drinks" << endl;
	cout << "Soda(S)..............................................$2" << endl;
	cout << "Water(W)..............................................$4" << endl;
	cout << "Sandwiches" << endl;
	cout << "10 inches...........................................$3" << endl;
	cout << "12 inches...........................................$5" << endl;
	_asm {
		call askCustomer; // calls askcustomer 
		mov eax, customers;	// eax = customers 
		mov i, 1;
		// i = 1 forLoop: 
		cmp i, eax;
		//compare i and number of customers 
		jnle done;
		// if i !<= number of customers go to done 
		inc i;
		call readData;
		cmp drinkletter, 'S';
		je Soda;
		cmp drinkletter, 'W';
		je Water;
	Soda: mov eax, drinknumber imul two;
		//eax = drinknumber*2 
		mov drinkprice, eax;
		// drinkprice = drinknumber*2 
		jmp here;
	Water: mov eax, drinknumber;
		imul four;
		mov drinkprice, eax;
	here: cmp sandwichsize, 10;
		je tenInch;
		cmp sandwichsize, 12;
		je twelveInch;
	tenInch: mov eax, sandwichnumber;
		// eax = sandwichnumber imul three;	
		// eax = sandwichnumber *3 
		mov sandwichprice, eax;
		sandwichprice = sandwichnumber * 3 jmp done;
	twelveInch: mov eax, sandwichnumber;
		// eax = sandwichnumber 
		imul five;
		// eax = sandwichnumber *5 
		mov sandwichprice, eax;
		sandwichprice = sandwichnumber * 5 done: mov eax, drinkprice;
		add eax, sandwichprice;
		// eax = drinkprice + sandwichprice mov cost, eax;	
		// cost = drinkprice + sandwichprice 
	}

	cout << "The total is : $" << cost << endl;
}

