#include "syscall.h"

int main() {
    unsigned int result;
    int number = ReadNum();
    result = Abs(number);
    PrintString("The absolute value of addition is: ");
    PrintNum(result);
    PrintString("\n");
    //Halt();
    /* not reached */
}

