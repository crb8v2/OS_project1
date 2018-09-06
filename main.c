// test comment
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for perror

#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>

int main (int argc, char *argv[]) {

    pid_t childpid = 0;
    int counter1, counter2;
    int n, k, m;

    // checks for proper number of args
    if (argc != 4) {
        fprintf(stderr, "Invalid number of command line args.");
        return 1;
    }

    // get command line values
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    m = atoi(argv[3]);


    for (counter1 = 1; counter1 < n; counter1++) {
        sleep(2);
        if((childpid = fork()))
            break;
    }


    for (counter2 = 0; counter2 < k; counter2++) {

//        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", counter1,
//                (long) getpid(), (long) getppid(), (long) childpid);

        fprintf(stderr, "i:%d", counter1);
        fprintf(stderr, "process ID:%ld ", (long)getpid());
        fprintf(stderr, "parent ID:%ld ", (long)getppid());
        fprintf(stderr,"child ID:%ld\n", (long)childpid);

        sleep(m);
    }
    return 0;
}
