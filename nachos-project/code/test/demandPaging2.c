#include "syscall.h"

int arr[30][30];

int main(){
        int ROWS = 30;
        int COLS = 30;
        int i = 0;
        int j = 0;
        for(i=0;i<COLS;i++){
                for(j=0;j<ROWS;j++){
                        arr[i][j]=1;
                }
        }
	PrintString("Done with dtest2\n");
        Halt();
}
