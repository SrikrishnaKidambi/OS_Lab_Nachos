#include "syscall.h"
#define stdin 0
#define stdout 1

int main(){
	int i,j;
	for (i = 0;i<1000;i++){
		for(j=0;j<10000;j++);
		PrintString("Child process running\n");
	}
	return 0;
}
