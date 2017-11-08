/*
 * All header files
*/

#ifndef BASH_H
#define BASH_H

// Libc headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


// Custom headers
#include "extra.h"


#define MAX_BUFFER_SIZE 100

// Main function
int interpreter(void);

// Spawnable child process
int single_child(char *args[]);

// Get user input
int get_input(char *args[]);

void handler(int arg);

int pipe_arguments(char *args[]);

#endif
