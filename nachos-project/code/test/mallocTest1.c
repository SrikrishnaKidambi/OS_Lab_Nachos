#include "syscall.h"
#include "malloc.h"

int main(){
	int* a = NULL;
	int* b = NULL;
	int* c = NULL;
	a = (int*)Malloc(4);
	*a = 5;
	PrintNum(*a);
	//PrintString("\n");
	//PrintString("Succes\n");

	Free(a);
	//PrintString("Free OK\n");

	b = (int*)Malloc(4);
	*b = 10;
	PrintNum(*b);
	//PrintString("\n");
	//PrintString("Success\n");

	//if(a==b){
	//	PrintString("Same Alloction\n");
	//}else{
	//	PrintString("Wrong \n");
	//}

	Free(b);
	//freeing b
	c = (int*)Malloc(5000);
	PrintNum((int)c);
	Halt();
}
