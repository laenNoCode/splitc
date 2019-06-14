#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int split(
        char* toSplit,
        int toSplitLength,
        char*** returnArray, 
        int* length)
{
    *length = 0;
    *returnArray = malloc(sizeof(char*));
    int alreadyRead = 0;
    int justRead;
    char* buffer = malloc (toSplitLength * sizeof(char));
    int currentLength = 0;
    while (alreadyRead < toSplitLength){
        currentLength ++;
        char** tmp = malloc(currentLength * sizeof(char*));
        for (int i = 0; i < currentLength - 1; ++i){
            tmp[i] = (*returnArray)[i];
        }
        free(*returnArray);
        *returnArray = tmp;
        sscanf(&toSplit[alreadyRead],"%s %n", buffer, &justRead);        
        (*returnArray)[currentLength - 1] = malloc(sizeof(char) * strlen(buffer));
        strcpy((*returnArray)[currentLength - 1], buffer);
        alreadyRead += justRead;
    }
    free(buffer);
    *length = currentLength;
}
int main(){
    char tmp[200];
    gets(tmp);
    char **truc;
    int length;
    split(tmp, strlen(tmp),&truc, &length);
    for (int i = 0; i < length; ++i){
        printf("%s\n", truc[i]);
    }
}