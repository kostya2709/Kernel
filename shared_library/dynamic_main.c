#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    void *lib_ptr = dlopen ("libprint.so", RTLD_LAZY);
    if (!lib_ptr) {
        fprintf (stderr, "dlopen() error: %s\n", dlerror());
        exit (1);
    }

    void (*func_ptr)(const char* str);
    func_ptr = dlsym(lib_ptr, "print");
    func_ptr("Hello world!");

    dlclose(lib_ptr);
}