#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child;
    // create process , will return the created process id or negative in failer
    child = fork();

    // child will start executing from here with a copy of all instructions of the parent

    if (child < 0 )
        printf("child is not ray2\n");
    // if child = 0, as child process dosne't execute the fork line , so the child variable in child process = 0
    else if (child == 0)
        printf("i am child ray2\n");
    else
        printf("parent and child pid = %d \n",child);

    // wait until child is terminated
    child = wait();

    return 0;
}
