/*
 * LOGIC_EXTRACTION.c
 *
 * Created: 11/28/2023 12:42:48 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "LOGIC_BL.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <windows.h>
#include <windef.h>
#include <winnt.h>
#include <winbase.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	FILE *fd;
	long filesize;
	char *buffer, *it;

	if ((fd = fopen(argv[1], 'rb')) == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	fseek(fd, 0, SEEK_END);
	filesize = ftell(fd);
	rewind(fd);

	buffer = (char *) malloc(sizeof(char) * filesize+1);

	if (fread(buffer, sizeof(char), filesize, fd) != filesize) {
		fprintf(stderr, "Error reading file\n");
		return EXIT_FAILURE;
	}

	buffer[filesize] = '\0';

	for (it = buffer; *it != '\0'; it++)
	printf("%02X ", *it);

	free(buffer);

    /* Replace with your application code */
    while (1) 
    {
    }
}

