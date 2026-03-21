#include "syscall.h"

int main() {
    unsigned int result;
    int number = ReadNum();
    PrintString("Hi guys welcome to nachos lab IIT Tirupati\n");
    result = Abs(number);
    PrintString("The absolute value is: ");
    PrintNum(result);
    PrintString("\n");
    Halt();
    /* not reached */
}

