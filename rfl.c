/*
 *
 * File: rfl.c
 * Description: Utility for reading files
 * License: MIT
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/* Definitions */
#define CHUNK_SIZE 1

/* Main Program */
int main(int argc, char **argv)
{
    /* Check if the user provided the file name(in argument 2) */
    if(argc < 2)
    {
        printf("\033[31mError:\033[0m Missing Argument 2(File name)\n");
        exit(-1);
    }
    /* Try to open the file */
    FILE* file = fopen(argv[1], "rb");
    /* Check if file does not exists */
    if(file == NULL)
    {
	/* if it does output an error */
        printf("\033[31mError:\033[0m File not found or Cannot be opened\n");
        exit(-1);
    }
    char* con = malloc(1);
    int res = 2;
    int zeros = 0;
    /* Start reading the file */
    while(1)
    {
        if(res == 0)
        {
            zeros += 1;
        }
        res = fread(con, sizeof(con), CHUNK_SIZE, file);
        if(zeros >= 1)
        {
            free(con);
            printf("\n");
            break;
        }
        printf("%s", con);
        fflush(stdout);
        memset(con, 0, sizeof(con));
    }
    /* Exit program */
    return 0;
}
