#include <stdio.h>
#include <unistd.h>

int main() {

    int array[] = {1, 2, 3};
    int* ptr = array;
    ptr = 0;
    int i = 1;

    printf("pid = %d\n", getpid());
    *ptr = 4;

    return 0;
}