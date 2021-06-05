/*
 *
 * File: crtfl.c
 * Description: Utility for create files
 * License: MIT
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>

/* Main Program */
int main(int argc, char **argv)
{
	/* Do argument checking */
	if(argc < 2)
	{
		printf("\033[31mError:\033[0m Argument 2 Missing(File name)\n");
		exit(-1);
	}
	/* Check if file exists */
	if(access(argv[1], F_OK) == 0)
	{
		printf("\033[31mError:\033[0m \"%s\" Does Exists Already\n", basename(argv[1]));
		exit(-1);
	}
	/* Create the file */
	FILE* new_file = fopen(argv[1], "wb");
	if(new_file == NULL)
	{
		printf("\033[31mError:\033[0m Cant create file\n");
		exit(-1);
	}
	fclose(new_file);
	/* Exit program */
	return 0;
}
