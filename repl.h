/*
Name: Precious Shittu
Course: Operationg Systems
Description: code for repl.h. implements all relevant functions
*/

#ifndef REPL_H
#define REPL_H

#include "strvec.h"

void prompt();

void read_cmd(strvec * cmd);

void exec_cmd(const strvec * cmd);
#endif
