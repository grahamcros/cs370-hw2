#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid = getpid();
    printf("Checker process [%d]: Starting.\n", pid);
    //char *a = argv[1];
    int divisor = atoi(argv[1]);
    //char *b = argv[2];
    int dividend = atoi(argv[2]);

    int remainder = dividend % divisor;

    if (remainder == 0) {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", pid, dividend, divisor);
        printf("Checker process [%d]: Returning 1.\n", getpid());
        return 1;
    } else {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", pid, dividend, divisor);
        printf("Checker process [%d]: Returning 0.\n", getpid());
        return 0;
    }
}