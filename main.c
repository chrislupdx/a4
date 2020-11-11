#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARGS 15 //max command line args
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
    int argCount = 1;
    
    //copy the the command line args into the array args
    for(int i = 0; i < argCount; i++)
    {
        ArgList.args[i] = malloc(strlen(argv[i] + 1));
        strncpy(ArgList.args[i], argv[i], strlen(argv[i]+1));
    }
    
    //update count to reflect the # of args
    ArgList.count = argc - 1; //do we need to detangle this from argc




    printmenu(ArgList);
    return 0;
}

int printmenu(struct argList list)
{
    printf("there are %d arguements \n", list.count);
    return 0;
}

int add()
{
    printf("add\n");
    return 0;
}
