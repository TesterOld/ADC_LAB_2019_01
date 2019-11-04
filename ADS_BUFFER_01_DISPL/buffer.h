#include "tm1637.h"
#define BUF_SIZE_128 128
#define BUF_SIZE_64  64
#define BUF_SIZE_16  16
#define BUF_SIZE_8   8 
#define BUF_SIZE_4   4

#define BUF_MASK_128  (BUF_SIZE_128-1)
#define BUF_MASK_64   (BUF_SIZE_64-1)
#define BUF_MASK_16   (BUF_SIZE_16-1)
#define BUF_MASK_8    (BUF_SIZE_8-1)
#define BUF_MASK_4    (BUF_SIZE_4-1)

extern unsigned char rIN, rOUT;
extern unsigned int rBuffer [BUF_SIZE_8];//-!!

void buffer_add(unsigned int val);
unsigned int buffer_avg(void);
unsigned int buffer_read(void);

void test_buff_load(unsigned int load);
void test_buff_displ(unsigned int load);
