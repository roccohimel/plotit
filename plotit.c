// plotit.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

// this is the main plot function
// the Y value is subtracted from the max Y value
void plot(int x, int y, char *z) {
        // debug
        printf("\033[H\033[J");

        // get max Y value
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int maxY = w.ws_row;


        // print the chars (z)
        printf("%s", z);
}

// main
int main(int argc, char *argv[]) {
        // debug args
        if (argc < 4) {
                printf("argc = %d\n", argc);
                for (int i = 0; i < argc; i++) {
                        printf("argv[%d] = \"%s\"\n", i, argv[i]);
                }
                return 1;
        }

        // get args
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        char *z = argv[3];

        // plot it
        plot(x, y, z);
}
