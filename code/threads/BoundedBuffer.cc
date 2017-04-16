
#include "BoundedBuffer.h"

BoundedBuffer::BoundedBuffer(int maxsize)
{
	IntoBuffer  = new Lock("into buffer lock");	
	// condition for buffer full
	con_full = new Lock(" buffer full ");
	con_empty = new Lock("buffer empty");
	// condition for buffer empty
	not_full = new Condition("buffer full cond");
	not_empty = new Condition("buffer empty cond");
	buffer = new int[maxsize];
	maxSize = maxsize;
	readFrom = 0; // read position 
	writeTo = 0; // write position 
}

BoundedBuffer::~BoundedBuffer()
{
	delete IntoBuffer;	
	delete con_full;
	delete con_empty;
	delete not_full;
	delete not_empty;
	delete[] buffer;
}

void 
BoundedBuffer::Read(void *data, int size)
{
	int *readData = (int *)data;
	while(size!=0){
		// learn from others on net
		// condition for buffer empty
		con_empty->Acquire();
		while(hasCount == 0){
			not_empty->Wait(con_empty);
		}
		IntoBuffer->Acquire();
		*readData++ = buffer[readFrom]; 
		readFrom = (readFrom + 1) % maxSize; 
		hasCount--;
		IntoBuffer->Release();
		not_full->Broadcast(con_full); 
		size--;
	}
}


void 
BoundedBuffer::Write(void *data, int size)
{
	int* writeData  = (int *)data;
	while(size != 0){
		//condition for buffer full
		con_full->Acquire();
		while(hasCount == maxSize){
			not_full->Wait(con_full);
		}
		IntoBuffer->Acquire();
		buffer[writeTo] = *writeData++;
		writeTo = (writeTo + 1) % maxSize;
		hasCount++;
		IntoBuffer->Release();
		not_empty->Broadcast(con_empty);
		size--;
	}
}







