#include "syscall.h"
#define stdin 0
#define stdout 1

int main(){
        int i,j;
        for(j=0;j<10;j++){
        	for(i=0;i<10000;i++);
		if(j==5)Sleep(4); // you can remove this sleep to test priority scheduler properly and to test sleep keep it back
        	PrintString("prgrm 2\n");
	}
        return 0;
}
