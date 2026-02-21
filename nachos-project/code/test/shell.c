#include "syscall.h"

int main() {
    SpaceId newProc;
    OpenFileId input = _ConsoleInput;
    OpenFileId output = _ConsoleOutput;
    char prompt[3],  buffer[60],buffer1[60],buffer2[60];
    int i;
    int j;
    int k;
    int hasPipe = 0;
    int fd;
    char* pos;
    char* fname;

    prompt[0] = '-';
    prompt[1] = '-';
    prompt[2] = '$';

    while (1) {
	//PrintString("Ready for next execution\n");
        Write(prompt, 3, output);
	hasPipe=0;
        i = 0;
	buffer[0] = '\0';
	buffer1[0]= '\0';
	buffer2[0]= '\0';
        do {
            //PrintString("Yes\n");
	    //PrintNum(i);
            Read(&buffer[i], 1, input);
	    //PrintChar(buffer[i]);
	    //PrintNum((int)buffer[i]);
	    if(buffer[i]=='|')hasPipe=1;
        } while (buffer[i++] != '\n');
	
        buffer[--i] = '\0';
	//PrintString(buffer);
	//PrintString("\n");
        if (i > 0) {
	    //PrintNum(hasPipe);
	    if (hasPipe == 1){
		    j=0;
		    k=0;
		    while(buffer[j]!='|'){
			    buffer1[k++]=buffer[j++];
		    }
		    j++;
		    buffer1[--k]='\0';
		    //PrintNum(j);
		    k=0;
		    j++;
		    while(buffer[j]!='\0'){
			    buffer2[k++]=buffer[j++];
		    }
		    //PrintNum(j);
		    //PrintString(buffer1);
		    //PrintString(buffer2);
		    fname = "pipe_temp_file";
		    fd = CreateFile(fname);
		    if(fd == -1){
			    PrintString("Cannot create file for pipe");
			    continue;
		    }
		    //PrintNum(fd);
		    //PrintString(buffer1);
		    //PrintString("\n");
		    pos = "Left";
		    newProc = ExecPV(buffer1,-1,pos,fname);
		    if(newProc==-1){
			    PrintString("Exec failed for left\n");
			    continue;
		    }
               	    Join(newProc);
		    //PrintString(buffer2);
		    //PrintString("\n");
		    pos = "Right";
                    newProc = ExecPV(buffer2,-1,pos,fname);
		    if(newProc==-1){
			    PrintString("Exec failed for right\n");
			    continue;
		    }
                    Join(newProc);
		    Remove(fname);
	    }
            else{
		//PrintString(buffer);
            	newProc = Exec(buffer,-1);
		Join(newProc);
	    }
        }
    }
}
