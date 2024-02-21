#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    char *divisor = argv[1];
    char *dividend;

    for (int i = 0; i < argc; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            int childPID = getpid();
            dividend = argv[i + 2];
            return execl("checker", "checker", divisor, dividend, NULL);
        } else {
            // Parent process
            printf("Coordinator: forked process with ID %d.\n", pid);
            printf("Coordinator: waiting for process [%d].\n", pid);
            int status;
            wait(&status);
            int result = WEXITSTATUS(status);
            printf("Coordinator: child process %d returned %d.\n", pid, result);
        }
    }
    printf("Coordinator: exiting.\n");
}
