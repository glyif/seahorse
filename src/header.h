#ifndef SEAHORSE
#define SEAHORSE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "base_struct.h"
void handle_c_file(const char *file_name, const char *dir_name, FILE *rf);
void handle_h_file(const char *file_name, const char *dir_name, FILE *rf);
void handle_c_line(char *line, FILE *rf);
int is_c_file(const char *file_name);
int is_h_file(const char *filename);
void delete_args(argument_docs *args);
void write_function_prototype(char *line, FILE *rf);
void add_new_argument(char *line);
#endif
