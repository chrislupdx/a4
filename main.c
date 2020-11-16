#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXARGS 15 //max command line args
#define min(a, b) ((a) < (b) ? (a) :(b)) //if true a, else 
#define funCount 7

typedef struct fParam  //lol what is this for
{
    int count;
    int * params; //this is a list of command line arguements cleand out for calculator consumption
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
    "Reverse"
};

int printmenu(menu * menu); 

//FDT
typedef void funcPtr(); //what args go int?
typedef struct 
{
    char * description;
    funcPtr * name; //this is a functin pointer
} dtEntry;

void add(funcParam fp) //is a struct absolutely necessary (list of vals + arguement count)
{
    int sum = 0;
    //Decimal
    for(int i = 0; i < fp.count; i++)
    {
        printf("%d", fp.params[i]);
        if(i != (fp.count - 1))
        {
            printf(" + ");
        }
        sum = sum + fp.params[i]; 
    }
    printf(" = %d ", sum);
    printf("\n");
    return;
}

void subtract(funcParam fp)
{
    int x = fp.params[0];
    printf("%d", x);
    for(int i = 1; i < fp.count; i++)
    {
        printf(" - ");
        printf("%d", fp.params[i]);
        int res = x - fp.params[i];
        x = res;
    }
    printf(" = %d ", x);
    printf("\n");
    return;
}

void mult(funcParam fp)
{
    int x = fp.params[0];
    printf("%d", x); 
    for(int i = 1; i < fp.count; i++)
    {
        printf(" * ");
        printf("%d", fp.params[i]);
        int res = x * fp.params[i];
        x = res;
    }
    printf(" = %d ", x);
    printf("\n");
    return;
}

//only divide
void division(funcParam fp)
{
    int first = fp.params[0];
    int second = fp.params[1];
    double res =((double) first) / second; //but fractions bitch
    printf("%d / %d = %f\n", first, second, res); 
    printf("0x%x / 0x%x = 0x%f\n", first, second, res);
    return;
}

void modulo(funcParam fp)
{
    int first = fp.params[0];
    int second = fp.params[1];
    int res  = first % second;
    printf("%d %c %d = %d\n", first, 37, second, res);
    return;
}

//1. shove it into a struct :(( 2. put it into arguement
void reverse(int argc, char ** argv)
{
    for(int i = (argc - 1); i >= 1; i--)
    {
        int leng = strlen(argv[i]);
        for(int x = leng; x >= 0; x--)
        {
        printf("%c", argv[i][x]);
        }
        printf(" ");
    }
    return;
}

void eexit(funcParam fp)
{
    return;
}

dtEntry fdt[7] = 
{
    {"exit", eexit},
    {"add", add},
    {"subtract", subtract},
    {"multiplication", mult},
    {"division", division},
    {"modulo", modulo},
    {"reverse", reverse}
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
    int count = 0; 
    for(int i = 1; i < argc; i++) //starting the count here at 1
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
        fp.params[count] = value;
        count++;
        //printf("params %d is %d \n", i, fp.params[i]);
    }
    fp.count = args;

    //Generate the Menu
    menu menu;
    menu.count = funCount; 
    for (int i = 0; i < menu.count; i++) 
    {
        menu.items[i] = choices[i];
    }

    int done = 0;
    while(done == 0)
    {
        printmenu(&menu);
        //Take UserInput
        int ui;
        printf("input: ");
        int yay = scanf("%i", &ui);
        if(yay < 0)
        {
            printf("sure\n");
        }

        //pass FDT UI+Data
        printf("invoking %d: %s\n", ui, fdt[ui].description);

        //if erecerse, pass it 
        if(ui == 6)
        {
            (*fdt[ui].name)(argc, argv);
        }
        else
        {
            (*fdt[ui].name)(fp);
        }

        //if ui is 0 set done to 1
        if(ui == 0)
        {
            done = 1;
        }
    };
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
