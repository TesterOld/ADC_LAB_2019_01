#ifndef CB_H
#define CB_H

typedef struct
{
     int *buffer;		//start of the buffer of int
     int *bufferEnd;	//end of the buffer
     int *head;			//start of data
     int *tail;			//end of data
     int count;			//number elements currently hold in the CB
     int size;         	//the size of the int circular buffer
 } circularBuffer_t;

int createCircularBuffer ( circularBuffer_t *CBPtr, int size);

int freeCircularBuffer (circularBuffer_t *CBPtr);

int put (circularBuffer_t *CBPtr, int value);

int get (circularBuffer_t *CBPtr);

int getCircularBufferCount (circularBuffer_t  *CBPtr);

#endif