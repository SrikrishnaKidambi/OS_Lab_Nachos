#include "syscall.h"

int main(){
	
	int rd = GetChildRd();
	char* userbuf;
	int res1 = ReadFFd(rd,userbuf,11);
	int i;
	if(res1==-1){
		PrintString("Read failed\n");
		Halt();
	}
	for(i=0;i<11;i++){
		if(userbuf[i]>='a' && userbuf[i]<='z'){
			userbuf[i]= userbuf[i] - 32;
		}
	}
	//PrintString(userbuf);
	//PrintString("\n");

	Exit(0);
}
