#ifndef SEAHORSE
#define SEAHORSE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"
void handle_c_file(const char *file_name, const char *dir_name, FILE *rf);
void handle_h_file(const char *file_name, const char *dir_name, FILE *rf);
int is_c_file(const char *file_name);
int is_h_file(const char *filename);
void delete_args(argument_docs *args);
#endif
