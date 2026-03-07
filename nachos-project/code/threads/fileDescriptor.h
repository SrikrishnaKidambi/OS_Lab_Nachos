#ifndef FILE_DESCRIPTOR_H
#define FILE_DESCRIPTOR_H

#include <stddef.h>
#include "sysdep.h"

#define MAX_FD 256 //this is the size of the file descriptor table
#define BUFFER_SIZE 128 //this is the size of the buffer that stores data

typedef enum { FD_EMPTY, FD_PIPE, FD_FILE} FDType;
//indicate the file descriptor types

typedef enum { PERM_NONE=0, PERM_READ=1, PERM_WRITE=2 } FDPerm;
//indicate the permission for file descriptor

typedef struct PipeBuffer PipeBuffer;
//pre declaration of PipeBuffer

typedef struct {
	FDType type;	//descriptor type
	FDPerm perm;	//permissions
	PipeBuffer* buffer; //pointer to shared buffer (for pipe)
} FileDescriptor;
//this is the entry type of FD table

struct PipeBuffer{
	char data[BUFFER_SIZE]; //data stored here
	int head; //read index
	int tail; //write index
	int count; //number of elements
};
//this is the PipeBuffer datastructure

typedef struct {
	FileDescriptor table[MAX_FD];
} FDTable;
//this is the main table

//-------------Functions are going below ----------

//Initialize the FD table probably put in kernel
void fdtable_init(FDTable* fdt);
//put this in kernel to initialize the table

int fdtable_pipe(FDTable* fdt,int* rd,int* wd); //returns 0 on success and fills rd and wd

int fdtable_read(FDTable* fdt,int fd,char* usrBuf,int n);
// reads n bytes into the usrBuf using fd

int fdtable_write(FDTable* fdt,int fd,const char* userBuf, int n);
// writes n bytes into the buffer from user buffer

void fdtable_close(FDTable* fdt,int fd);

#endif
