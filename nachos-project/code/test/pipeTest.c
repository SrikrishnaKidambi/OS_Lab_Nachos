#include "syscall.h"

int main(){
	int result;
	int rd,wd;
	char* userbuf;
	int res1;
	int child;

	result=Pipe(&rd,&wd);
//	PrintNum(rd);
//	PrintString("\n");
//	PrintNum(wd);
//	PrintString("\n");	
        userbuf	= "hello world";
        res1 = WriteFFd(wd,userbuf,11);
	if(res1==-1){
//		PrintString("Write failed\n");
		Halt();
	}
	child = ExecChild("../test/pipeTestChild",15,"Child",rd);
	Join(child);

	CloseFd(rd);
	CloseFd(wd);
	Halt();
}
