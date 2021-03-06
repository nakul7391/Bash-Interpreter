/*
 * Mimic bash which runs processes
 * Arguments to command are added
*/
#include "bash.h"

pid_t pid;
// signal handler
void handler(int arg)
{
    if(pid != 0)
    {
        if(arg == SIGINT)
        kill(pid,SIGTERM);
        else if(arg == SIGTSTP)
        kill(pid,SIGKILL);
    }
}

int main(int argc, char *argv[])
{
    int status;

    // register signal cntrl + C
    signal(SIGINT,handler);
    signal(SIGTSTP,handler);

    command_line_parser(argc, argv);

    interpreter();

    return 0;
}

int interpreter(void)
{
    int status, pipes, process;

    char *args[MAX_BUFFER_SIZE];

    while(1)
    {
        // get number of pipes
        pipes = get_input(args);

        process = pipes + 1;
        // Check exit condition
        if(args[0] && strcmp(args[0],"quit") == 0)
        exit(0);

        // depends on pipe create processes
        if(pipes == 0)  // single process
        {
            if((pid = fork()) == 0) // Child block
            {
                execvp(args[0],args);
            }
        }
        else
        {
            // Handle arguments
            pipe_arguments(char *args[]);
        }

        // Parent will wait for the child
        if(pipes == 0)    // Wait for one child
        wait(&status);
        else              // wait for multiple childs
        {

        }

    }
}

int single_child(char *args[])
{

}

int pipe_arguments(char *args[])
{

}

// get string input and make it a 2D pointer
int get_input(char *args[])
{
    int i = 0, procCount = 0;
    char *ptr;
    char user_input[MAX_BUFFER_SIZE] = "\0";
    char buffer[MAX_BUFFER_SIZE];

    args[0] = NULL;

    printf("# ");
    scanf("%[^\n]",user_input);

    __fpurge(stdin);
    ptr = strtok(user_input," ");

    // Parse input string
    while(ptr)
    {
        args[i] = strdup(ptr);

        if(strcmp(args[i],"|") == 0)
        procCount++;

        ptr = strtok(NULL," ");
        i++;
    }

    args[i] = NULL;   // Make it null terminated

    return procCount;
}
