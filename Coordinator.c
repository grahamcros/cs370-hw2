/*
    Coordinator must use three different commands;
    -fork(), to launch another process.
    -exec(), to replace the program driving this process, while also supplying arguments
    that this new program (Checker) needs to complete execution.
    -wait(), to wait for the completion of the execution of the process.

    1. Coordinator must accept five command line arguments; the first argument being a divisor, and the next four being dividends.
        -For example: coordinator 3 8 15 21 45 creates four sepearate processes that check 8/3, 15/3, 21/3, and 45/3 in that order.
    2. Coordinator then needs to do the following for each argument: fork() to create a separate process, exec() to send the
    arguments to checker, and wait() to wait until the current process is complete before starting the next.
    3. Once coordinator uses the fork() command, it should print the process ID (PID) of the newly created process (the PID can be
    found by checking the return value of the fork() command).
    4. Immediately following the fork() command, checker will be loaded using the exec() command. This exec() command should also pass
    two arguments into checker
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    char *divisor = argv[1];
    char *dividend;

    for (int i = 2; i < argc; i++) {

        pid_t pid = fork();

        if (pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            int childPID = getpid();
            dividend = argv[i];
            printf("Checker process [%d]: Starting.\n", childPID);
            execlp("checker", divisor, dividend, NULL);
        } else {
            // Parent process
            printf("Coordinator: forked process with ID %d.\n", pid);
            printf("Coordinator: waiting for process [%d].\n", pid);
            int status;
            wait(&status);
            int result = WEXITSTATUS(status);
            printf("Checker process [%d]: Returning %d.\n", getpid(), result);
            printf("Coordinator: child process %d returned %d.\n", pid, result);
        }
    }
    printf("Coordinator: exiting.\n");
}
