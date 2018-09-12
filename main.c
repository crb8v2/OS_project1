//comment
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for perror
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>

void forkerMaster (int n, int k, int m, int nchars) {
    pid_t childpid = 0;
    int counter1, counter2;

    int i = 0, j = 0;
    char a, *mybuf;
    mybuf = (char *) malloc(sizeof(char));


    // creates a chain of 'n' processes
    for (counter1 = 1; counter1 < n; counter1++) {
        sleep(2);
        if((childpid = fork()))
            break;
    }



    // for loop that spins of 'k' work to do for this fork
    for (counter2 = 0; counter2 < k; counter2++) {

        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", counter1,
                (long) getpid(), (long) getppid(), (long) childpid);


//        // step 7 from the book
//        fprintf(stderr, "i:%d ", counter1);
//        fprintf(stderr, "process ID:%ld ", (long) getpid());
//        fprintf(stderr, "parent ID:%ld", (long) getppid());
//        fprintf(stderr, "child ID:%ld\n", (long) childpid);
        }

        printf("Input a string, press enter when done: ");

        while((a = getchar()) != '\n') {
            realloc(mybuf, (sizeof(char)));
            mybuf[i++] = a;
        }
        mybuf[i] = '\0';


        printf("\nYou entered the string: ");
        for(; j < nchars; j++){
            printf("%c", mybuf[j]);
            printf("%c", mybuf[j]);
        }

        printf("\n\n");

        sleep(m);
    }


void helpMenu() {
    printf("\n -- HELP MENU --\n");
    printf("-n int int int    runs a forking function\n");
    printf("-h    open help menu\n");
    printf("-p    generates a test error with perror\n\n");
}

int main (int argc, char **argv) {

    int n, k, m, nchars;
    char c;


    char mybuf[100];

    // get command line values
    n = atoi(argv[2]);
    k = atoi(argv[3]);
    m = atoi(argv[4]);
    nchars = atoi(argv[5]);

    while ((c = getopt (argc, argv, "hpn:")) != -1)
        switch (c)
        {
            case 'h':
                helpMenu();
                break;
            case 'p':
                break;
            case 'n':
                    // checks for proper number of args
                    if (argc != 6) {
                        fprintf(stderr, "Invalid number of command line args.");
                        return 1;
                    }



                forkerMaster(n,k,m, nchars);
                break;

            case '?':
                if (optopt == 'n')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                             "Unknown option character `\\x%x'.\n",
                             optopt);
                return 1;
            default:
                abort ();
        }
    return 0;
}
