#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

char **parse_args(char * line);

char ** parse_args(char * line){
    char **starts = calloc(5, sizeof(char *));
    char *curr = line;
    char *token;
    int i = 1;

    starts[0] = curr;
    char * last = line + sizeof(line);
    // while ( (token = strsep(&curr, " ")) != NULL && i < 5 && curr <= last ){
    //     starts[i] = curr;
    //     i++;
    //     printf("A\n");
    //     printf("%s\n", curr);
    // }
    for (i = 1; i < 5; i++){
        if ((token = strsep(&curr, " ")) != NULL){
            starts[i] = curr;
            // printf("C\n");
        }
        else {
            starts[i] = 0;
            // printf("D\n");
        }
        // printf("B\n");
    }
    return starts;
}

int main(){
    // char test[100] = "grunters humph grr"; // Test 1 DONE!
    // char test[100] = "grunters humph grr a b"; // Test 2 DONE!
    char test[100] = "ls -a -l"; // Final Test Works!
    char **things = parse_args(test);
    
    int i;
    // int count = sizeof(things) / sizeof(things[0]);
    // printf("%ld\t%ld\t%d\n", sizeof(things), sizeof(things[0]), count);
    for (i = 0; i < 5; i++){
        if (things[i] != 0){
            printf("%s\n", things[i]);
        }
    }
    execvp(things[0], things);

    return 0;
}
