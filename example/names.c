#include <stdio.h>
#include <string.h>
#include "../stackC.h"

// Prototypes of some functions

bool stack_push(Stack *stack, const char *name);


// Main program

int main()
{
    Stack stackNames;
    stack_init(&stackNames);

    stack_push(&stackNames,"Billi");
    stack_push(&stackNames,"John");
    stack_push(&stackNames,"Jason");

    puts("Let's show names:\n");
    while(!stack_isEmpty(&stackNames))
    {
        printf("%s\n",(char*) stack_getFirst(&stackNames));
        stack_pop(&stackNames);
    }

    stack_push(&stackNames,"Saitama");
    printf("%s\n",(char*) stack_getFirst(&stackNames));

    stack_push(&stackNames,"Garou");
    stack_push(&stackNames,"King");
    
    stack_quit(&stackNames);
    return 0;
}


// Definition of some functions

bool stack_push(Stack *stack, const char *name)
{
    char *newName = stack_createData(stack,sizeof(char),20); // Name should at most 19 characters here
    strcpy(newName,name);
    return stack_pushData(stack,newName);
}
