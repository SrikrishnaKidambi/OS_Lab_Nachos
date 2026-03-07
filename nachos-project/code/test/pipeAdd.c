#include "syscall.h"

int main(){
        int result;
        int rd,wd;
        int res1;
        int res2;
        int child;

        result = Add(-8,-9);

        res1 = Pipe(&rd,&wd);

        res2 = WriteFFd(wd,(char *)&result,sizeof(int));

        if(res2 == -1){
                PrintString("WriteFailed\n");
                Halt();
        }

        child = ExecChild("../test/pipeAbs",15,"Child",rd);
        Join(child);

        CloseFd(rd);
        CloseFd(wd);

        Halt();
}
