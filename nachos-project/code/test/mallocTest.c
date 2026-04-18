#include "syscall.h"
#include "malloc.h"

int main(){
    void* ptr1;
    void* ptr2;
    void* a;
    void* b;
    void* c;
    void* big;
    int* arr;
    void* newPtr;

    // Test 1: basic malloc
    ptr1 = Malloc(100);
    if(ptr1 != 0){
	    PrintString("T1:OK\n");
    }
    else PrintString("T1:NO\n");

  //  Test 2: read/write
    arr = (int*)Malloc(10 * sizeof(int));
    arr[0] = 42;
    arr[9] = 34;
    if(arr[0] == 42 && arr[9] == 34) PrintString("T2:OK\n");
    else PrintString("T2:NO\n");

    // Test 3: free and reuse
    Free(ptr1);
    ptr2 = Malloc(100);
    if(ptr1 == ptr2) PrintString("T3:OK\n");
    else PrintString("T3:NO\n");

    // Test 4: unique addresses
    a = Malloc(50);
    b = Malloc(50);
    c = Malloc(50);
    if(a != b && b != c && a != c) PrintString("T4:OK\n");
    else PrintString("T4:NO\n");

    // Test 5: overflow
    big = Malloc(5000);
    if(big == 0) PrintString("T5:OK\n");
    else PrintString("T5:NO\n");

    // Test 6: free last block
    Free(c);
    newPtr = Malloc(50);
    if(newPtr == c) PrintString("T6:OK\n");
    else PrintString("T6:NO\n");
    Halt();
    //return 0;
}
