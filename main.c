#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARGS 15 //max command line args
#define min(a, b) ((a) < (b) ? (a) :(b)) //if true a, else b

struct argList
{
    int count;
    char * args[MAXARGS];
} ArgList;

int printmenu(struct argList list); 
int add();
//virtual function array

int main(int argc, char ** argv) //up to 15 args
{
    int aCount = min(argc -1, MAXARGS);

    printf("aCount is %d\n", aCount);
    if(argc == 1)
    {
        printf("too few gtfo \n");
        return 0;
    }
    argv++; //oh whoah
    int i;
    for(i = 0; i < aCount; i++)
    {
        printf("%s\n", argv[i]);
        ArgList.args[i] = malloc(strlen(argv[i] + 1));
        strncpy(ArgList.args[i], argv[i], strlen(argv[i])+1);
    }
    ArgList.count = i;

    //lol trying to print the args array
    for(int i = 0; i < ArgList.count; i++) 
    {
        printf("arg[%d] == %s\n", i, ArgList.args[i]);    
    }
    return 0;
}

int printmenu(struct argList l)
{
    printf("there are %d arguements \n", l.count);
    return 0;
}
int add()
{
    printf("add\n");
    return 0;
}
