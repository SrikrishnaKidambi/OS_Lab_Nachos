#include "syscall.h"

int main() {
    unsigned int result;

    result = Abs(-8);
    PrintString("The absolute value is: ");
    PrintNum(result);
    PrintString("\n");
    //Halt();
    /* not reached */
}

