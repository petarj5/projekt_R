#include "io.h"
#include <unistd.h>
#include <string.h>

#define WORD_SIZE_IN_BITS 32
#define HALF_WORD_SIZE_IN_BITS 16


int read_word(int fd) {
	int retval;
	char buf[WORD_SIZE_IN_BITS];

	read(fd, buf, WORD_SIZE_IN_BITS);
	memcpy(&retval, buf, sizeof(short));
	
	return retval;
}

short read_half(int fd) {
	short retval;
	char buf[HALF_WORD_SIZE_IN_BITS];

	read(fd, buf, HALF_WORD_SIZE_IN_BITS);
	memcpy(&retval, buf, sizeof(short));

	return retval; 
}

void write_word(int fd, int word) {
	char buf[WORD_SIZE_IN_BITS];

	memcpy(&word, buf, sizeof(int));
	write(fd, buf, WORD_SIZE_IN_BITS);
}


void write_half(int fd, short word) {
	char buf[HALF_WORD_SIZE_IN_BITS];

	memcpy(&word, buf, sizeof(short));
	write(fd, buf, HALF_WORD_SIZE_IN_BITS);
}