#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARGS 15 //max command line args
#define min(a, b) ((a) < (b) ? (a) :(b)) //if true a, else b

struct argList //is this necessary?
{
    int count;
    char * args[MAXARGS]; //they're being put in separately
} ArgList;

typedef struct {
    int count;
    char *string;
} funcParam; //for one or is this general

//do we write one for each function?
typedef void funcPtr(funcParam *); //what args go int?
typedef struct {
    char * description;
    funcPtr * name;
} dtEntry;

void
add(funcParam * input)
{
    printf("fuck you\n");
    return;
}

dtEntry fdt[4] = 
{
    {"add", add}
};
int fdtCount = sizeof(fdt) / sizeof(fdt[0]);

int printmenu(struct argList list); 

int main(int argc, char ** argv) //up to 15 args
{
    int aCount = min(argc -1, MAXARGS);
    if(argc == 1)
    {
        printf("too few gtfo \n");
        return 0;
    }
    argv++; //oh whoah
    int i;
    for(i = 0; i < aCount; i++)
    {
        ArgList.args[i] = malloc(strlen(argv[i] + 1));
        strncpy(ArgList.args[i], argv[i], strlen(argv[i])+1);
    }
    ArgList.count = i;

    //


    printmenu(ArgList);  //we could toss that into the fdt
    return 0;
}

//currently just prints the struct
int printmenu(struct argList l)
{
    printf("there are %d arguements \n", l.count);
    for(int i = 0; i < ArgList.count; i++) 
    {
        printf("arg[%d] == %s\n", i, ArgList.args[i]);    
    }
    return 0;
}
