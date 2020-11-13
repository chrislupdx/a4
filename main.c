#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXARGS 15 //max command line args
#define min(a, b) ((a) < (b) ? (a) :(b)) //if true a, else 
#define funCount 2

typedef struct fParam  //lol what is this for
{
    int count;
    int * params;
} funcParam; //for one or is this general

//MENU
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
int printmenu(menu * menu); 


//FDT
typedef void funcPtr(funcParam fp); //what args go int?
typedef struct 
{
    char * description;
    funcPtr * name; //this is a functin pointer
} dtEntry;
void add(funcParam fp) //is a struct absolutely necessary (list of vals + arguement count)
{
    printf("addd\n");
    return;
}
void eexit(funcParam fp)
{
    printf("goodbye\n");
    return;
}
dtEntry fdt[4] = 
{
    {"exit", eexit},
    {"add", add},
};
int fdtCount = sizeof(fdt) / sizeof(fdt[0]);


int main(int argc, char ** argv) //up to 15 args
{
    //Guard for no command line args
    if(argc == 1)
    {
        printf("too few gtfo \n");
        return 0;
    }

    //Process Command Line Argsa
    funcParam fp;
    int args = argc -1;
    fp.params = (int*) malloc(argc * sizeof(args));



    //int args[argc];
    for(int i = 1; i < argc; i++)
    {
        char * hexStr = argv[i];
        int base = 10; //if we need to tweak

        if(hexStr[0] == '0')
        {
            if((hexStr[1] == 'x') || (hexStr[1] == 'X'))
            {
                base = 16; 
            } 
        }
        int value = strtol(hexStr, NULL, base); 
        
        //args[i] = value;
        fp.params[i] = value;
        printf("params %d is %d \n", i, fp.params[i]);
        //printf("args %d is %d \n", i, args[i]);
    }
    //printf("%d: %d\n", i, list[i]);

    //Generate the Menu
    menu menu;
    menu.count = funCount; 
    for (int i = 0; i < menu.count; i++) //wtf is this
    {
        menu.items[i] = choices[i];
    }
    
    //Loop through this shit
    
    printmenu(&menu);
    //Take UserInput
    int ui;
    printf("input: ");
    int fuck = scanf("%i", &ui);
    if(fuck < 0)
    {
        printf("sure\n");
    }

    //pass FDT UI+Data
    printf("invoking %d: %s\n", ui, fdt[ui].description);
    (*fdt[ui].name)(fp);


    //allocate an int array the argc size
    //int * list = (int*) malloc(argc * sizeof(int));


    //FIGURE OUT HOW TO PROPOERTLY CONSUM 69-80 
    //int funcMax = 1;  //this needs to be tweaked whenver we add fucntions into fdt
    //funcParam * fList[funcMax]; 

    //call every function in the fdt
    //for(int i = 0; i < funcMax; i++)
    //{
    //    fList[i] = (funcParam * )malloc(sizeof(funcParam));   //allocate  funcparam sized mem and cast it to that type
    //    fList[i]->count = i;
    //    printf("Invoking %d: %s\n",i, fdt[i].description);
    //    (*fdt[i].name)(fList[i]); 
    //    free (fList[i]); 
    //}

    return 0;
}

//prints funciton  names and count
int printmenu(menu * menu)
{
    printf("\n");
    for(int i = 0; i < menu->count; i++) //menu count is currently set to 1 
    {
        printf("%d. %s\n", i, menu->items[i]);
    }
    printf("\n");
    return 0;
}
