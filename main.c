//comment
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for perror
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>

// performs forking and work to be done
void forkerMaster (int n, int nchars) {
    pid_t childpid = 0;
    int counter1;
    int counter2 = 0;
    int i = 0, j = 0;
    //buffer size for getting stdin chars
    char *mybuf;
    // allocate that memory
    mybuf = (char *) malloc(sizeof(char));

    // create forks
    for (counter1 = 1; counter1 < n; counter1++) {
        if ((childpid = fork()))
            break;
    }

    printf("Input a string, press enter when done: ");

    // accepts nchar characters in the buff size
    for (counter2 = 0; counter2 < nchars; counter2++) {
        mybuf[counter2 + 1] = getchar();
    }

    mybuf[i] = '\0';

    // prints the buff
    printf("\n %ldYou entered the string: ", (long) childpid);
    for (; j < nchars; j++) {
        printf("%c", mybuf[j]);
    }
}

void helpMenu() {
    printf("\n -- HELP MENU --\n");
    printf("-n int int int    runs a forking function\n");
    printf("-h    open help menu\n");
    printf("-p    generates a test error with perror\n\n");
}

int main (int argc, char **argv) {

    int n = 0, nchars = 0;
    int c;
    char errorString[256];

    // for options
    while ((c = getopt (argc, argv, "hpn:")) != -1)
        switch (c)
        {
            case 'h':
                helpMenu();
                break;

            case 'p':
                snprintf( errorString, sizeof errorString,
                        "This, my friend, is an error");

                perror(errorString);
                break;

            case 'n':
                    // checks for proper number of args
                    if (argc != 4) {
                        fprintf(stderr, "Invalid number of command line args.");
                        return 1;
                    }

                    //get command line values
                    n = atoi(argv[2]);
                    nchars = atoi(argv[3]);

                    forkerMaster(n, nchars);
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



































//void forkerMaster (int n, int nchars) {
//    pid_t childpid = 0;
//    int counter1;
//    //int counter2 = 0;
//
//    int status = 0;
//
//    int i = 0, j = 0;
//    char a, *mybuf;
//    mybuf = (char *) malloc(sizeof(char));
//
//    // creates a chain of 'n' processes
//    for (counter1 = 1; counter1 < n; counter1++) {
////       //number 4
////        sleep(2);
//        if((childpid = fork()))
//            break;
//    }
//
////    fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", counter1,
////            (long) getpid(), (long) getppid(), (long) childpid);
//
////    // for loop that spins of 'k' work to do for this fork
////    for (counter2 = 0; counter2 < k; counter2++) {
////        // step 7 from the book
////        fprintf(stderr, "i:%d ", counter1);
////        fprintf(stderr, "process ID:%ld ", (long) getpid());
////        fprintf(stderr, "parent ID:%ld", (long) getppid());
////        fprintf(stderr, "child ID:%ld\n", (long) childpid);
////        }
//
//        printf("Input a string, press enter when done: ");
//
//        while((a = getchar()) != '\n') {
//            mybuf[i++] = a;
//        }
//        mybuf[i] = '\0';
//
//
//        printf("\n %ldYou entered the string: ", (long) childpid);
//        for(; j < nchars; j++){
//            printf("%c", mybuf[j]);
//            printf("%c", mybuf[j]);
//        }
//
//        printf("\n\n");
////        //nummber 5
////        sleep(m);
//    }




