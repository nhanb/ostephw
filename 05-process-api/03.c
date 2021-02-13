#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child
        sleep(2);
        printf("Hello\n");
    } else {
        // parent
        wait(NULL);
        printf("Goodbye\n");
    }
    return 1;
}
