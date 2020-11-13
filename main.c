#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARGS 15 //max command line args
#define min(a, b) ((a) < (b) ? (a) :(b)) //if true a, else 

struct argList //is this necessary?
{
    int count;
    char * args[MAXARGS]; //they're being put in separately
    //ok what exactly does args contain (maxargs mihgt be a red herring)
} ArgList;

typedef struct 
{
    int count;
    char *string;
} funcParam; //for one or is this general

//do we write one for each function?
typedef void funcPtr(funcParam *); //what args go int?
typedef struct 
{
    char * description;
    funcPtr * name; //this is a functin pointer
} dtEntry;
void add(funcParam * input)
{
    printf("addd\n");
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

    //Load command line args into a struct
    argv++;
    int i;
    for(i = 0; i < aCount; i++)
    {
        ArgList.args[i] = malloc(strlen(argv[i] + 1));
        strncpy(ArgList.args[i], argv[i], strlen(argv[i])+1);
    }
    ArgList.count = i;

    //Move the functions into fdt
    int funcMax = 1;  //this needs to be tweaked whenver we add fucntions into fdt

    funcParam * fList[funcMax]; 

    //call every function in the fdt
    for(int i = 0; i < funcMax; i++)
    {
        fList[i] = (funcParam * )malloc(sizeof(funcParam));   //allocate  funcparam sized mem and cast it to that type
        fList[i]->count = i;
        printf("Invoking %d: %s\n",i, fdt[i].description);
        (*fdt[i].name)(fList[i]); 
        free (fList[i]); 
    }

    //struct contains: descriptions of the functions
    //a list number of functions
    int count = 0;
    for(int i = 0; i < funcMax; i++)
    {
        fList[i] = (funcParam * )malloc(sizeof(funcParam));
        printf("Invoking %d: %s\n",i, fdt[i].description);
        //increment count every time we pull in a function
        
        fList[i]->count = i;
    }
   
    //int userchoice;
    printmenu();
    
    return 0;
}

//prints funciton  names and count
int printmenu(struct argList l)
{
    //printf("there are %d arguements \n", l.count);
    //for(int i = 0; i < ArgList.count; i++) 
    //{
        //printf("arg[%d] == %s\n", i, ArgList.args[i]);    
    //}
    return 0;
}
