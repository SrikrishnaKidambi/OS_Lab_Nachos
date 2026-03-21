#include "syscall.h"

int arr[30][30];

int main(){
	int ROWS = 30;
	int COLS = 30;
	int i = 0;
	int j = 0;
	PrintString("Hello\n");
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++){
			arr[i][j]=1;
		}
	}
	PrintString("Done with dtest1\n");
	Halt();
}
