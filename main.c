/*
Name: Precious Shittu
Course: Operationg Systems
Description: code for main.c. implements all relevant functions
*/

#include <stdio.h>
#include "strvec.h"
#include "simnia.h"
#include <string.h>
#include <stdlib.h>
int main() {
	strvec cmd;
	strvec_init(&cmd);

	do {
		prompt();
		read_cmd(&cmd);
		exec_cmd(&cmd);
	}
	while (strcmp(strvec_get(cmd, 0), "exit") != 0);
}
