#include <stdio.h>
#include <stdlib.h>
int main(int b, char** a) {
  
    char* filename = a[1];
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL) //if this file doesn't exist
    { 
        printf("Cannot open file \n"); 
        return 1;
    } 
    int charcount = 0;
    int wordcount = 1;
    int linecount = 1;
    int linecharcount = 0;
    char c = 'a';
    int wasSpace;
    int linesize = 5;
    char * line = malloc(linesize*sizeof(char));
    while(1){
        c = fgetc(fptr);
        if(c == EOF){
            break;
        }
        if(wasSpace == 1 && c != ' '){
            wordcount++;
            wasSpace = 0;
        }
        if(c == '\n'){
            printf("%s", line);
            memset(line,0,linesize);
            linecharcount = 0;
            linecount++;
        }
        if(c == ' '){
            wasSpace = 1;
        }
        if(linecharcount < linesize){
            line[linecharcount] = c;
        }else{
            
            linesize += 5;
            printf("\n allocating more %i mem \n", linesize);
            char * failcheck = (char *)realloc(line,linesize);
            if(failcheck == NULL){
                return 1;
            }
            line = failcheck;

        }

        linecharcount++;
        charcount++;


    }

    printf("word %i \n",wordcount);
    printf("char %i \n",charcount);
    printf("line %i \n",linecount);

}