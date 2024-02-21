#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

/*
Checker takes two arguments: the divisor (argument one) and the dividend (argument two). It checks whether argument two is divisible
by argument one and then prints and return the value. These arguments will be supplied by coordinator

Whenever something is printed, it must be prefixed by whichever file printed it ("Coordinator: xxx" or "Checker: xxx").
*/


int main(int argc, char *argv[]) {
    //char *a = argv[1];
    int divisor = atoi(argv[0]);
    //char *b = argv[2];
    int dividend = atoi(argv[1]);

    int remainder = dividend % divisor;

    if (remainder) {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", getpid(), dividend, divisor);
        return 1;
    } else {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", getpid(), dividend, divisor);
        return 0;
    }
}