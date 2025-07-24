/*
    Chapter 2 - Process vs threads
*/

#include <stdio.h>
#include <unistd.h> // For fork & sleep functions
#include <sys/wait.h>

int main()
{
    int x = 43;
    int pid = fork(); // fork creates a new child process
    if (pid == -1)    // -1 means the process failed to create
    {
        return -1;
    }

    if (pid == 0)
    {
        x++;
    }
    sleep(2);
    printf("Value of x: %d\n", x);
    printf("Process ID %d\n", getpid()); // Each process gets a different ID
    printf("Hello from processes\n");
    if (pid != 0)
    {
        wait(NULL);
    }
    return 0;
}

/*
    Summary
    The main difference between processes and threads is that processes can contain many threads
    But a thread cannot contain processes.

    Forking creates a copy of the process and all the resources are duplicated into the child process
    Threads do not duplicate resources. They have common shared resources.
*/