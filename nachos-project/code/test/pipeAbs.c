#include "syscall.h"

int main(){

        unsigned int result;
        int number;
        int rd = GetChildRd();

        int res1 = ReadFFd(rd,(char*)&number,sizeof(int));

        if(res1 == -1){
                PrintString("Read failed\n");
                Halt();
        }

        result = Abs(number);

        PrintString("The absolute value of addition is: ");
        PrintNum(result);
        PrintString("\n");

        Exit(0);
}
