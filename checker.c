#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

/*
Checker takes two arguments: the divisor (argument one) and the dividend (argument two). It checks whether argument two is divisible
by argument one and then prints and return the value. These arguments will be supplied by coordinator

Whenever something is printed, it must be prefixed by whichever file printed it ("Coordinator: xxx" or "Checker: xxx").
*/


int main(int argc, char* argv[]) {
    char *a = argv[1];
    int divisor = atoi(a);
    char *b = argv[2];
    int dividend = atoi(b);

    if (dividend % divisor == 0) {
        printf("Checker process [%d]: %s *IS* divisible by %s.\n", getpid(), argv[1], argv[2]);
        printf("Checker process [%d]: Returning 1.\n", getpid());
        return(1);
    } else {
        printf("Checker process [%d]: %s *IS NOT* divisible by %s.\n", getpid(), argv[1], argv[2]);
        printf("Checker process [%d]: Returning 0.\n", getpid());
        return(0);
    }
}