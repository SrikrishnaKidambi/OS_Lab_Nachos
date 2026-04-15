#include "syscall.h"
#include "malloc.h"

void alloc(int** a){
	*a = Malloc(4);
	**a = 10;
	PrintNum(**a);
	//PrintString("\n");
	//PrintString("SIF\n");
	return ;
}

int main(){
	int* a = NULL;
	alloc(&a);
	if(a==NULL){
		PrintString("a is null\n");
		return 0;
	}
	PrintNum(*a);
	//PrintString("\n");
	//PrintString("SOF\n");
	Halt();
}
