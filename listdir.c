/*
 *
 * File: listdir.c
 * Description: list the directory specified
 * License: MIT
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

/* Function for comparing strings by comparing every character */
int pchar_cmp_same(char* str1, char* str2)
{
	/* Check if str1's length and str2's length is not same */
	if(strlen(str1) != strlen(str2))
	{
		/* If true then return 0(which is false) */
		return 0;
	}
	/* Start comparing */
	int i = 0;
	while(i < strlen(str1))
	{
		/* check if the str1's current char is not same with str2's current char */
		if(str1[i] != str2[i])
		{
			/* If not same then return the result that it is not same */
			return 0;
		}
		++i;
	}
	/* If it reaches this code then return 1 which is true */
	return 1;
}
char* get_type(char* path)
{
	struct stat new_stat;
	stat(path, &new_stat);
	if(S_ISDIR(new_stat.st_mode))
		return "Directory";
	else
		return "File";
}


int main(int argc, char **argv)
{
    char* list_path;
    /* Check if argument count is lesser than 2 */
    if(argc < 2)
    {
	    list_path = malloc(2 * sizeof(char));
	    list_path = ".\0";
    }
    else
    {
	    strcpy(list_path, argv[1]);
    }
    /* Begin reading*/
    struct dirent* ent;
    DIR* dir = opendir(list_path);
    if(dir == NULL) /* if dir is NULL then output error */
    {
        printf("\033[31mError:\033[0m Directory(In Argument 2) does not exists or is not a file\n");
        exit(-1);
    }
    printf("-- [ Directory \"%s\" ] --\n", realpath(list_path, NULL));
    while((ent = readdir(dir)) != NULL)
    {
	if(pchar_cmp_same(ent->d_name, ".") == 0)
		if(pchar_cmp_same(ent->d_name, "..") == 0)
		{
			char* path_r = (char*)malloc((strlen(ent->d_name) + strlen(realpath(list_path, NULL)) + 2) * sizeof(char));
			sprintf(path_r, "%s/%s", realpath(list_path, NULL), ent->d_name);
			printf("%s: %s\n", get_type(path_r), ent->d_name);
		}
    }
    closedir(dir);
    free(ent);
    return 0;
}
