#include "syscall.h"
#include "malloc.h"

Blk_Metadata* heapTop = NULL;
Blk_Metadata* heapStart = NULL;

void* Malloc(int bytes){
	Blk_Metadata* block = NULL;
	Blk_Metadata* curr = heapStart;
	//Blk_Metadata* prev = NULL;
	int heapAddr;
	//if no memory needed bytes = 0 then return
	if(bytes == 0) return NULL;
	//check if we can get a block from free list
	while(curr!=NULL){
		if(curr->in_use == 0 && curr->blk_size >= bytes){
			curr->in_use = 1;
			//if(prev == NULL){
			//	freeList = curr->n_fblk;
			//}
			//else{
			//	prev->n_fblk = curr->n_fblk;
			//}
			//curr->n_fblk = NULL;
			return (void*)(curr + 1);
		}
		//prev = curr;
		curr = curr->n_blk;
	}

	//if no free available then call sbrk
	heapAddr = Sbrk(bytes + sizeof(Blk_Metadata));
	if(heapAddr == -1){
		return NULL;
	}
	block = (Blk_Metadata*)heapAddr;
	block->p_blk = heapTop;
	block->n_blk = NULL;
	block->blk_size = bytes;
	block->in_use = 1;

	if(heapTop != NULL){
		block->p_blk->n_blk = block;
	}
	if(heapStart == NULL){
		heapStart = block;
	}
	heapTop = block;
	return (void*)(block + 1); //returning starting addr of data
}

void Free(void* ptr){
	Blk_Metadata* f_blk = NULL;
	if(ptr == NULL) return;
	f_blk = (Blk_Metadata*)((char*)ptr - sizeof(Blk_Metadata));
	//Blk_Metadata* curr = freeList;
	f_blk->in_use = 0;
	//f_blk->n_fblk = NULL;
	//if(freeList == NULL){
	//	freeList = f_blk;
	//	return;
	//}
	
	//while(curr->n_fblk != NULL){
	//	curr = curr->n_fblk;
	//}
	
	//curr->n_fblk = f_blk;
	//f_blk->n_fblk = NULL;
	return;
}

