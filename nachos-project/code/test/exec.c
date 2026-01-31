/* exec.c
 *	Simple program to test the exec system call.
 */

#include "syscall.h"
#define stdin 0
#define stdout 1

int main() {
    int pid;
    pid = Exec("../test/child",3);
    if (pid < 0) {
        Write("Exec failed: ", 14, stdout);
        PrintNum(pid);
    } else{
	    int i,j;
	    for(i = 0;i<1000;i++){
		    for(j=0;j<10000;j++);
		    PrintString("Parent process running\n");
	    }
	    Join(pid);
    }
}
