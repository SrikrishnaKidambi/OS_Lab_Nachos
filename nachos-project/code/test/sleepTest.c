#include "syscall.h"
#define stdin 0
#define stdout 1

int main(){
	int p1 = Exec("../test/priority1",12);
	int i;

	for(i=0;i<1;i++){
		PrintString("Parent before sleep\n");
	}
	PrintString("Parent Slept\n");
	Sleep(3);
	for(i=0;i<1;i++){
		PrintString("Parent after sleep\n");
	}
	Join(p1);

	Halt();
}
