#include <stdio.h>
#include <stdlib.h>

int sizeLargestSubnetwork(int *subnetSize) {
  // get largest size
  subnetSize[0] = 1;
  return subnetSize[0];
}

int main(int argc, char **argv){
    int *subnetSize = malloc(sizeof(int));
    int num = 0;
    num = sizeLargestSubnetwork(subnetSize);
    printf("num is %d\n", num);
    return 0;
}

