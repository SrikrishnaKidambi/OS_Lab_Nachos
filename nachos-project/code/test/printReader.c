#include "syscall.h"

int main(){
	char ch;
	
	PrintString("The upper case string is: \n");
	while(1){
		//PrintString("in loop");
		ch = ReadChar();
		
		if(ch=='\n'){
			//PrintString("Done");
			PrintChar('\n');
			break;
		}

		if(ch>='a' && ch<='z'){
			ch =  ch - 32;
		}
		PrintChar(ch);
	}
//	return 0;
 	//Halt()
}
