#include "fileDescriptor.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

static int hashSeed = 0;
//FDTable functions

//Initialize the file descriptor table
void fdtable_init(FDTable* fdt){
	for(int i=0;i<MAX_FD;i++){
		fdt->table[i].type=FD_EMPTY;
		fdt->table[i].perm=PERM_NONE;
		fdt->table[i].buffer=NULL;
	}
}

//Allocate a new free FD
static int allocate_fd(FDTable* fdt){
	for(int i=0;i<MAX_FD;i++){
		int index = (hashSeed + i) % MAX_FD;

		if(fdt->table[index].type== FD_EMPTY){
			hashSeed=index + 1;
			return index;
		}
	}
	return -1;
}

//pipe
int fdtable_pipe(FDTable* fdt, int* rd, int* wd){
	PipeBuffer* buf = (PipeBuffer *)malloc(sizeof(PipeBuffer));
	if(!buf)return -1;

	buf->head=0;
	buf->tail=0;
	buf->count=0;

	int fdRead = allocate_fd(fdt);
	int fdWrite = allocate_fd(fdt);

	if(fdRead == -1 || fdWrite == -1){
		free(buf);
		return -1;
	}

	fdt->table[fdRead].type = FD_PIPE;
	fdt->table[fdRead].perm = PERM_READ;
	fdt->table[fdRead].buffer = buf;

	fdt->table[fdWrite].type = FD_PIPE;
        fdt->table[fdWrite].perm = PERM_WRITE;
        fdt->table[fdWrite].buffer = buf;

	*rd = fdRead;
	*wd = fdWrite;

	return 0;
}

int fdtable_write(FDTable* fdt,int fd,const char* userBuf,int n){
	if(fd < 0 || fd >= MAX_FD) return -1;
	FileDescriptor* f = &fdt->table[fd];
//	cout<<f->type<<endl;
//	cout<<f->perm<<endl;
	if(f->type != FD_PIPE ||!(f->perm & PERM_WRITE)) return -1;

	PipeBuffer* buf = f->buffer;
	int written=0;
	for(int i=0;i<n;i++){
		if(buf->count==BUFFER_SIZE) break; //full buffer
		buf->data[buf->tail] = userBuf[i];
		buf->tail = (buf->tail + 1) % BUFFER_SIZE;
		buf->count++;
		written++;
	}
	return written;
}

int fdtable_read(FDTable* fdt, int fd, char* userbuf, int n){
	if(fd < 0 || fd >= MAX_FD) return -1;
	FileDescriptor* f = &fdt->table[fd];
	if(f->type != FD_PIPE || !(f->perm & PERM_READ)) return -1;

	PipeBuffer* buf = f->buffer;
	int readBytes = 0;
	for(int i=0;i<n;i++){
		if(buf->count==0)break;
		userbuf[i] = buf->data[buf->head];
		buf->head = (buf->head+1) % BUFFER_SIZE;
		buf->count--;
		readBytes++;
	}
	return readBytes;
}

void fdtable_close(FDTable* fdt,int fd){
	if(fd < 0 || fd >= MAX_FD) return;
	FileDescriptor* f = &fdt->table[fd];
	if(f->type == FD_EMPTY)return;

	if(f->type == FD_PIPE) {
		int inUse = 0;
		for(int i=0;i<MAX_FD;i++){
			if(i != fd && fdt->table[i].buffer == f->buffer) {
				inUse = 1;
				break;
			}
		}
		if(!inUse) free(f->buffer);
	}

	f->type = FD_EMPTY;
	f->perm = PERM_NONE;
	f->buffer = NULL;
}

