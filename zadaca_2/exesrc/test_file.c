#include <stdio.h>
#include "io.h"
#include <fcntl.h>  

int main(void) {
	const char *inputFilePath = "../resources/input.txt"; 
	const char *outputFilePath = "../resources/output.txt";

	int fd = open(inputFilePath, O_RDONLY | O_EXCL);

	printf("%d\n", fd);



}