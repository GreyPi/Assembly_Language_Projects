// Project 4 Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Gregory Pierot

#include <iostream>
using namespace std;
short a = 0;
void readData() {
	cout << "Enter Data: ";
	cin >> a;
}
void Base2() {
	short x = 1 << 15, t, n = a;
	cout << "AX = ";
	for (int i = 1; i <= 16; ++i) {
		t = n & x;
		if (t == 0) { cout << 0; }
		else { cout << 1; }
		if (i % 4 == 0) { cout << " "; }
		n = n << 1;
	}
	cout << "\n";
	a = n; //save the original value of a
}
void Problem1() {
	short ramSize, numFloppy, numPrinter = 0;
	_asm {
		mov ax, 1100111010011100b;
		mov bx, ax; // store original value in bx
		mov a, ax;
		call Base2;
		mov ax, bx;
	checkRam: //check the bits for ram
		shr ax, 2; // shift to ram bits
		and ax, 11b;
		cmp ax, 0b; // add ram based on result
		je addRam1;
		cmp ax, 1b;
		je addRam2;
		cmp ax, 10b;
		je addRam3;
		cmp ax, 11b;
		je addRam4;
	addRam1: //add ram then move on to floppy drives
		mov ramSize, 16;
		jmp checkFloppy;
	addRam2:
		mov ramSize, 32;
		jmp checkFloppy;
	addRam3:
		mov ramSize, 48;
		jmp checkFloppy;
	addRam4:
		mov ramSize, 64;
		checkFloppy:
		mov numFloppy, 1; // if bits == 00 , floppy drives == 1
		mov ax, bx; // get original value
		shr ax, 6; // shift right by 6 bits
		and ax, 11b; // compare
		add numFloppy, ax; // add result to number of floppy drives
	checkPrinters:
		mov ax, bx; // original value
		shr ax, 14; // shift to printer bits
		and ax, 11b; // compare
		add numPrinter, ax; // add to number of printers
	}
	cout << "Ram size = " << ramSize << "gb\n";
	cout << "Number of floppy drives = " << numFloppy << "\n";
	cout << "Number of printers = " << numPrinter << "\n";
}
short sprinklerNum = 0;
void message() { cout << "\nDefective Sprinklers: "; }
void displaySprinklers() {
	cout << sprinklerNum << " ";
}
void Problem2() {
	short sprinklers = 0;
	_asm {
		mov bx, 0x6A2F;
		mov a, bx;
		call Base2;
		call message;
		mov cx, 0;
		mov edx, 0;
	checkOn:
		inc cx; // increment cx
		cmp cx, 16; // if cx is greater than 16, jump to exit
		jg exitLoop;
		mov dx, bx; // move bx to dx
		and dx, 1b; // and dx with 0001b , dx is used to compare without
					// losing original value to 'and'
		shr bx, 1; // shift bx to the right by 1, bx holds the bits
		cmp dx, 0; // dx compared with 0 and jump to 'Defective' if equal
		je Defective;
		inc sprinklers;
		jmp checkOn;
	Defective: // display the defective sprinklers
		mov sprinklerNum, cx;
		call displaySprinklers;
		mov cx, sprinklerNum;
		jmp checkOn;
	exitLoop:
	}
	cout << "\n" << sprinklers << " sprinklers are on\n";
}
short floors;
void displayFloor() {
	cout << floors << " ";
}
void Problem3() {
	_asm {
		call readData; // get data
		mov bx, a; // backup a
		call Base2;
		mov a, bx; // get backup
	}
	cout << "Elevator will stop at floors no. ";
	_asm {
		mov cx, 0; // bit counter
	loopStart:
		inc cx;
		cmp cx, 16; // exit after 16 loops
		jg exitLoop;
		mov ax, a; // prep value for comparing
		and ax, 1b; // compare
		shr a, 1; // shift right by 1
		cmp ax, 0; // if 0 then go back to loop start;
		je loopStart;
		mov floors, cx; //display floor stopped at
		call displayFloor;
		mov cx, floors;
		jmp loopStart;
	exitLoop:
	}
}
int main() {
	std::cout << "Enter problem number or '0' for all at once (1-3) ";
	int select;
	std::cin >> select;
	switch (select) {
	default: break;
	case 0:Problem1();
		Problem2();
		Problem3();
		break;
	case 1:
		Problem1(); break;
	case 2:
		Problem2(); break;
	case 3:
		Problem3(); break;
	}
	return 0;
}


