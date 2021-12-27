/*
Name: Precious Shittu
Course: Operationg Systems
Description: code for simnia.c. implements all relevant functions
*/

#include <string.h>
#include "strvec.h"
#include "repl.h"
int main(int argc, char* argv[])
{
	strvec cmd;
	strvec_init(&cmd);
	do {
		prompt();
		read_cmd(&cmd);
		exec_cmd(&cmd);
	} while (strcmp(strvec_get(cmd, 0), "exit") != 0);
	strvec_free(&cmd);
	return 0;
}
