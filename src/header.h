#ifndef SEAHORSE
#define SEAHORSE
#include <dirent.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void handle_file(const char *file_name, const char *dir_name, FILE *rf);
int is_c_file(const char *file_name);
int is_h_file(const char *filename);
#endif
