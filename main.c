
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // for perror
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>

void forkerMaster (int n, int k, int m) {

    pid_t childpid = 0;
    int counter1, counter2;

    for (counter1 = 1; counter1 < n; counter1++) {
        sleep(2);
        if((childpid = fork()))
            break;
    }

    for (counter2 = 0; counter2 < k; counter2++) {

        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", counter1,
                (long) getpid(), (long) getppid(), (long) childpid);

//        fprintf(stderr, "i:%d", counter1);
//        fprintf(stderr, "process ID:%ld ", (long)getpid());
//        fprintf(stderr, "parent ID:%ld ", (long)getppid());
//        fprintf(stderr,"child ID:%ld\n", (long)childpid);

        sleep(m);
    }

}

void helpPrint() {
    printf("\n -- HELP MENU --\n");
    printf("-n int int int    runs a forking function\n");
    printf("-h    open help menu\n");
    printf("-p    generates a test error with perror\n\n");
}

void errorPrint() {
    printf("\nwere in error\n");
}

void newPrint() {
    printf("\nwere in new\n");
}



int main (int argc, char **argv) {

    char *cvalue = NULL;
    int index;
    int n, k, m, c;

    opterr = 0;

    // get command line values
    n = atoi(argv[2]);
    k = atoi(argv[3]);
    m = atoi(argv[4]);


    while ((c = getopt (argc, argv, "hpn:")) != -1)
        switch (c)
        {
            case 'h':
                helpPrint();
                break;
            case 'p':
                errorPrint();
                break;
            case 'n':
                //get and arg checker in here!
                forkerMaster(n,k,m);
                cvalue = optarg;
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










//
//void helpPrint() {
//    printf("\nwere in help\n");
//}
//
//int main (int argc, char **argv) {
////
////    pid_t childpid = 0;
////    int counter1, counter2;
//    int n, k, m;
////
////
////
////
//    // checks for proper number of args
//    if (argc != 4) {
//        fprintf(stderr, "Invalid number of command line args.");
//        return 1;
//    }
////
//    // get command line values
//    n = atoi(argv[1]);
//    k = atoi(argv[2]);
//    m = atoi(argv[3]);
////
////
////    for (counter1 = 1; counter1 < n; counter1++) {
////        sleep(2);
////        if((childpid = fork()))
////            break;
////    }
////
////
////    for (counter2 = 0; counter2 < k; counter2++) {
////
////        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", counter1,
////                (long) getpid(), (long) getppid(), (long) childpid);
////
//////        fprintf(stderr, "i:%d", counter1);
//////        fprintf(stderr, "process ID:%ld ", (long)getpid());
//////        fprintf(stderr, "parent ID:%ld ", (long)getppid());
//////        fprintf(stderr,"child ID:%ld\n", (long)childpid);
////
////        sleep(m);
////    }
//    return 0;
//}
//
//
//
//void forkerMaster (int n, int k, int m) {
//
//    pid_t childpid = 0;
//    int counter1, counter2;
//
//
////    // get command line values
////    n = atoi(argv[1]);
////    k = atoi(argv[2]);
////    m = atoi(argv[3]);
//
//
//    for (counter1 = 1; counter1 < n; counter1++) {
//        sleep(2);
//        if((childpid = fork()))
//            break;
//    }
//
//
//    for (counter2 = 0; counter2 < k; counter2++) {
//
//        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", counter1,
//                (long) getpid(), (long) getppid(), (long) childpid);
//
////        fprintf(stderr, "i:%d", counter1);
////        fprintf(stderr, "process ID:%ld ", (long)getpid());
////        fprintf(stderr, "parent ID:%ld ", (long)getppid());
////        fprintf(stderr,"child ID:%ld\n", (long)childpid);
//
//        sleep(m);
//    }
//
//}
//
//
