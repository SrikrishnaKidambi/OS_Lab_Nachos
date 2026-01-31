#include "syscall.h"
#define stdin 0
#define stdout 1

int main(){
	int p1 = Exec("../test/priority1",12);
	int p2 = Exec("../test/priority2",17);
	int p3 = Exec("../test/priority3",2);
	
	//int p1 = Exec("../test/abs",8);
	//int p2 = Exec("../test/add",10);

	Join(p1);
	Join(p2);
	Join(p3);

	Halt();
}
