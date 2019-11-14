#include <string.h>
#include <stdlib.h>
#include "CircularBuffer.h"

int createCircularBuffer ( circularBuffer_t *CBPtr, int size) {
	if (CBPtr != 0) {
		CBPtr->buffer = malloc (sizeof (int)* size);
		
		if (CBPtr->buffer != 0) {
			memset (CBPtr->buffer, 0, size * sizeof(int)); //clear the buffer
			CBPtr->bufferEnd = CBPtr->buffer + size;
			CBPtr->head = CBPtr->buffer;
			CBPtr->tail = CBPtr->buffer;
			CBPtr->count = 0;
			CBPtr->size = size;
		
		
		} else {
		
			return -1;
		}
	} else {
	
		return -1;
	}
	
	return 0;
}


/*
	Free the buffer of the pass-in circularBuffer_t pointer
*/
int freeCircularBuffer (circularBuffer_t *CBPtr) {
	if (CBPtr == 0) {
		return -1;
	} else {
		free (CBPtr->buffer);
		return 0;
	}
}

/* 
	put an int to the circular buffer tail pointer, if the buffer is full,
	ignore the put and return -1, otherwise add to tail, return 0;
*/
int buffer_add (circularBuffer_t *CBPtr, int value) {
	if (CBPtr == 0) {
	
		return -1;
	}
	//insert the value to tail
	*CBPtr->tail++ = value;
	//if reach the end of the buffer, move tail to buffer start
    if(CBPtr->tail == CBPtr->bufferEnd) {
       CBPtr->tail = CBPtr->buffer;
    }
    CBPtr->count++;
    
    return 0;

}

int buffer_read (circularBuffer_t *CBPtr) {
	if (CBPtr == 0) {
		
		return -1;
	}	
	if (CBPtr->count == 0) {
		
		return -1;
	}
	
	//get value from head
	// *value = *CBPtr->head++;
	
	//if reach the end of the buffer, move head to buffer start
    if(CBPtr->head == CBPtr->bufferEnd) {
       CBPtr->head = CBPtr->buffer;
    }
    return *CBPtr->head++;
}


int getCircularBufferCount (circularBuffer_t  *CBPtr) {
	if (CBPtr == 0) {

		return -1;
	} else {	
		return CBPtr->count;
	}
}