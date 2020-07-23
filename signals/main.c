#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void handler(int signum) {
    write(1, "The signal is detected!\n", 24);
    abort();
}

int main() {
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while (1) {
        printf ("I am working (%d)\n", getpid());
        sleep(1);
    }
/* 
    $ kill -TERM *PID* */
}