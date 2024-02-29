#include <iostream>
#include <vector>
using namespace std;

short counter = 1;
short no_stop = 0;
short yes_stop = 0;

short one = 1;
short zero = 0;
short number = 0;

short hex_number = 0;
std::vector<short> the_stops;

void beginningPrint() {
    std::cout << "Write a program to (i) display the content of AX at base 2 " << std::endl;
    std::cout << "(ii) use AX register to determine at what floors the elevator will stop" << std::endl;
}

void pushBack() {
    the_stops.push_back(number);
}

void Display() {
    std::cout << "Elevator will stop at floors no. ";
    for (auto index : the_stops) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
}


short a, t;            // at base 2
void Base2()
{
    cout << "AX= ";
    short x = 1 << 15;
    short y = a;
    for (int i = 1; i <= 16; ++i) {
        t = y & x;
        if (t == 0) {
            cout << 0;
        }
        else {
            cout << 1;
        }
        if (i % 4 == 0) {
            cout << " ";
        }
        y = y << 1;
    }
    a = y; //save the original value of a
    cout << endl;
}


int main()
{
    __asm {
        call beginningPrint;
        mov a, 37132;
        call Base2;

        mov ax, 1001000100001100b;
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

    zeroLoop:
        inc no_stop;
        inc counter;
        Jmp forLoop;

    oneLoop:
        inc yes_stop;
        mov ax, counter;
        mov number, ax;
        call pushBack;
        inc counter;
        Jmp forLoop;


    exitLoop:
        call Display;
    }

    return 0;
}
