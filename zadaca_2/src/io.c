#include "io.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int read_word(int fd) {
	int retval;

	read(fd, &retval, sizeof(int));
	return retval;
}

short read_half(int fd) {
	short retval;
	read(fd, &retval, sizeof(short));
	return retval; 
}

void write_word(int fd, int word) {
	write(fd, &word, sizeof(int));
}


void write_half(int fd, short word) {
	write(fd, &word, sizeof(short));
}