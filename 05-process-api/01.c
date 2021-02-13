#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int a = 1;
    printf("> a = %d\n", a);
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child
        printf("> Child: a = %d\n", a);
        a = 2;
        printf("> Child: a = %d\n", a);
    } else {
        // parent
        printf("> Parent: a = %d\n", a);
        a = 3;
        printf("> Parent: a = %d\n", a);
    }
    return 1;
}
