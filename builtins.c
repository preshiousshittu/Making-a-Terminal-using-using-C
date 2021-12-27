/*
Name: Precious Shittu
Course: Operationg Systems
Description: code for builtins.c. implements all relevant functions
*/

#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>


const char* BUILTIN[] = {"cd", NULL};
const void (*FCNS[])(const strvec * cmd) = {_cd, NULL};

void _cd(const strvec * cmd)
{
    if(cmd-> _size >= 3) 
    {
        printf("cd has too many arguments");
    }
    else if(cmd-> _size == 1)
    {
      chdir(getenv("HOME"));
    }
    else
    {
        if(chdir(strvec_get(*cmd, 1)) == -1)
        {
            perror("cd");
        }
    }
    
}
