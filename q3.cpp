#include <iostream>
#include <vector>

short counter = 1;
short d_sprinklers = 0;
short sprinklers = 0;

short one = 1;
short zero = 0;
short number = 0;

short hex_number = 0x6A2F;
std::vector<short> the_defectives;

void beginningPrint() {
	std::cout << "i. Display the AX register at base two " << std::endl;
	std::cout << "ii. How many sprinklers are on ? " << std::endl;
	std::cout << "iii. Which sprinkler are defective(off) ? " << std::endl;
}

void pushBack() {
	the_defectives.push_back(number);
}

void Display() {
	std::cout << "AX = 1001 0001 0000 1100" << std::endl;
	std::cout << sprinklers << " sprinklers are ON" << std::endl;
	std::cout << "Defective sprinklers: " << std::endl;
	for (auto index : the_defectives) {
		std::cout << index << " ";
	}
	std::cout << std::endl;
}

int main() {
	_asm {
		call beginningPrint;
		mov ax, hex_number;
		shl ax, 1;
		mov hex_number, ax;

	forLoop:
		cmp counter, 17;
		Je exitLoop;

		mov ax, hex_number;
		shr ax, 1;
		mov hex_number, ax;

		and ax, one;
		cmp ax, zero;
		Je zeroLoop;
		cmp ax, one;
		Je oneLoop;

	oneLoop:
		inc sprinklers;
		inc counter;
		Jmp forLoop;

	zeroLoop:
		inc d_sprinklers;
		mov ax, counter;
		mov number, ax;
		call pushBack;
		inc counter;
		Jmp forLoop;

	
	exitLoop:
		call Display;
	}
}
