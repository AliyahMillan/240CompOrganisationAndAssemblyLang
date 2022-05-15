/*
Problem 1
*/
#include <iostream>
short printerNum, driveNum, ramSize;
using namespace std; 
void printData() {
    cout << "a.\t The number of printers connected to the computer: " << printerNum << std::endl;
    cout << "b.\t The number of floppy drives: " << driveNum << std::endl;
    cout << "c.\t The size of the RAM: " << ramSize << std::endl;
}
int main() {
    _asm {
        //Printer
    printer:
        //Move register content into register
        mov bx, 1100111010011100b;
        //Shift right 13 bits to leave 15 and 16th bits
        shr bx, 14;
        //Compare register with printer values and jump to according condition
        //printer == 00b
        cmp bx, 00b;
        je printer0;
        //printer == 01b
        cmp bx, 01b;
        je printer1;
        //printer == 10b
        cmp bx, 10b;
        je printer2;
        //printer == 11b
        cmp bx, 11b;
        je printer3;

        //Update printerNum accordingly and jump to Floppy
    printer0:
        mov printerNum, 00b;
        jmp floppy;
    printer1:
        mov printerNum, 01b;
        jmp floppy;
    printer2:
        mov printerNum, 10b;
        jmp floppy;
    printer3:
        mov printerNum, 11b;
        jmp floppy;

        //Floppy
    floppy:
        //Move register content into register
        mov bx, 1100111010011100b;
        //Shift right 6 bits to remove bits 1-6
        shr bx, 6;
        //Shift left 14 to remove bits 9 - 16
        shl bx, 14;
        //Shift right to clear and reset bit 7 and 8 in the 1 and 2 positoin 
        shr bx, 14;

        //Compare register with floppy values and jump to according condition
        //floppy = 00b
        cmp bx, 00b;
        je floppy0;
        //floppy = 01b
        cmp bx, 01b;
        je floppy1;
        //floppy = 10b
        cmp bx, 10b;
        je floppy2;
        //floppy = 11b
        cmp bx, 11b;
        je floppy3;

        //Update driveNum accordingly and jump to RAM
    floppy0:
        mov driveNum, 1;
        jmp ram;
    floppy1:
        mov driveNum, 2;
        jmp ram;
    floppy2:
        mov driveNum, 3;
        jmp ram;
    floppy3:
        mov driveNum, 4;
        jmp ram;

        //RAM
    ram:
        //Move register content into register
        mov bx, 1100111010011100b;
        //Shift to the right to remove bits 1 -2
        shr bx, 2;
        //Shift to the left to remove remaining bits
        shl bx, 14;
        //Shift right to reset bit positioning
        shr bx, 14;

        //Compare register with ram values and jump to according condition
        //ram = 00b
        cmp bx, 00b;
        je ram0;
        //ram = 01b
        cmp bx, 01b;
        je ram1;
        //ram = 10b
        cmp bx, 10b;
        je ram2;
        //ram = 11b
        cmp bx, 11b;
        je ram3;

        //Update ramSize accordingly and jump to done 
    ram0:
        mov ramSize, 16;
        jmp done;
    ram1:
        mov ramSize, 32;
        jmp done;
    ram2:
        mov ramSize, 48;
        jmp done;
    ram3:
        mov ramSize, 64;
        jmp done;

    done:
        //Print out information
        call printData;
    }
    }
