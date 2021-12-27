/*
Name: Precious Shittu
Course: Operationg Systems
Description: code for builtins.c. implements all relevant functions
*/

#ifndef BUILTIN_H
#define BUILTIN_H

#include"strvec.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern const char* BUILTIN[];
void _cd(const strvec * cmd);
extern void (*FCNS[])(const strvec * cmd);
#endif
