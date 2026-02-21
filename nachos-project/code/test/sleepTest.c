#include "syscall.h"
#define stdin 0
#define stdout 1

int main(){
	int p1 = Exec("../test/priority1",12);
	int p2 = Exec("../test/priority2",15);
	int i;

	for(i=0;i<10;i++){
		PrintString("Parent before sleep\n");
	}
	PrintString("Parent Slept\n");
	Sleep(4);
	for(i=0;i<10;i++){
		PrintString("Parent after sleep\n");
	}
	Join(p1);
	Join(p2);
	Halt();
}
