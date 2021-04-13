#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int studentID;
    int current_length = 4; 
    int *class_list = malloc(sizeof(current_length*studentID));

    printf("Enter the Student IDs for the class list, followed an empty line:\n");

    int num_item = 0;
    while(scanf("%d", &studentID) != EOF) {
        class_list[num_item] = studentID;
        num_item++;
        
        if(num_item == current_length) {
            current_length *= 2;
        }
    }
    
    printf("The IDs for the students in the class are:\n");
    for(int i=0;i<num_item;i++) {
        printf("%d", class_list[i]);
        if(i != num_item) {
            printf(", ");
        }
    }
    printf("The array contains %d items, and has a capacity of %d", num_item, current_length);
}