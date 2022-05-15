/*
Problem 4
*/

#include <iostream>
#include <stdlib.h>     /* srand, rand /
#include <time.h>       / time */
using namespace std;
short RandomNum, a, good = 0, bad = 0, i;
int counter = 1;
string WriteString;
void message(){
    cout << "Displaying floors that are chosen ";
}
void displayDefective(){
    cout << bad << " ";
}
void randNum() {
    srand(time(NULL));

    RandomNum = rand() % 16 + 2;
    a = RandomNum;
}
void Base2() {
    short   x = 1 << 15, t, n = a;
    for (int i = 1; i <= 16; ++i) {
        t = n & x;
        if (t == 0) {
            cout << 0;
        }
        else {
            cout << 1;
        }
        if (i % 4 == 0) {
            cout << " ";
        }
        n = n << 1;
    }
    a = n; //save the original value of a 
    cout << endl;
}

void thatFloor(){
    cout << i - 1 << " ";
}
int main() {
    //cout << "\n The floors that have been chosen " << endl;
    _asm {
        mov a, 6A2Fh;
        call Base2;
        mov ax, 6A2Fh;
        mov i, 1;
        mov bx, 0000000000000001b;
        call message;
    floop:
        cmp i, 16;
        je done;
        mov ax, 6A2Fh;
        and ax, bx;
        cmp ax, 0;
        je defective;
        jmp working;
    defective:
        inc bad;
        inc i;
        mov cx, i;
        mov bad, cx;
        //  call displayDefective;
        shl bx, 1;
        jmp floop;
    working:
        inc good;
        inc i;
        call thatFloor;
        shl bx, 1;
        jmp floop;
    done:

    }

    return 0;
}
