#include <stdio.h>
#include <assert.h>

int main(int argc, char **argv) {
    assert(argv[2]);
    printf("%s", argv[0]);
    printf("%s", argv[1]);
    printf("%s", argv[2]);
    return 0;
}