#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARGS 15 //max command line args
#define min(a, b) ((a) < (b) ? (a) :(b)) //if true a, else 
#define funCount 1

typedef struct fParam  //lol what is this for
{
    int count;
    char *string;
} funcParam; //for one or is this general

typedef struct _menu
{
    int count;
    char *items[funCount];
} menu;

char * choices[] = 
{
    "Exit", "Addition", "Subtraction",
    "Multiplication", "Division", "Modulo",
    "Reverse Input"
};

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
int printmenu(menu * menu); 

int main(int argc, char ** argv) //up to 15 args
{
    if(argc == 1)
    {
        printf("too few gtfo \n");
        return 0;
    }
   
    menu menu;
    menu.count = funCount; 
    //copy choices into menu
    for (int i = 0; i < menu.count; i++)
    {
        menu.items[i] = choices[i];
    }
    printmenu(&menu);
    

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


    return 0;
}

//prints funciton  names and count
int printmenu(menu * menu)
{
    printf("\n");
    for(int i = 0; i < menu->count; i++)
    {
    printf("%d. %s\n", i, menu->items[i]);
    }
    printf("\n");

    return 0;
}
