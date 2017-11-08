/*
 * Mimic bash which runs processes
*/
#include "bash.h"

int main(int argc, char *argv[])
{
    int status;
    
    command_line_parser(argc, argv);

    char user_input[MAX_BUFFER_SIZE];

    pid_t pid;

    while(1)
    {
        printf("# ");
        scanf("%s",user_input);

        if((pid = fork()) == 0) // Child block
        {
            execvp(user_input,argv);
            exit(0);
        }
        else
        {
            wait(&status);
        }

    }

    return 0;
}
