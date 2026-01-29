#include "syscall.h"

int main() {
    unsigned int result;

    result = Abs(-8);
    PrintNum(result);
    Halt();
    /* not reached */
}

