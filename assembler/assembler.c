#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int instr_opcode(char *instr)
{
    return 1;
}

int main() 
{
    FILE* ptr;
    char ch;
 
    // Opening file in reading mode
    ptr = fopen("./programs/add1_sub1_loop.s", "r");
 
    if (NULL == ptr) 
    {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    // Printing what is written in file
    // character by character using loop.
    do 
    {
        ch = fgetc(ptr);
        printf("%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } 
    while (ch != EOF);
 
    // Closing the file
    fclose(ptr);
    return 0;
}