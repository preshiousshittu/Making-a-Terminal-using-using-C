/*
Name: Precious Shittu
Course: Operationg Systems
Description: code for repl.c. implements all relevant functions
*/

#include "strvec.h"
#include "repl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include"builtins.h"

void prompt()
{
	char host[50];
	gethostname(host, 50);
	printf("\033[1;32m%s@%s \033[1;36m$\033[0m ", getpwuid(getuid())->pw_name, host);
}

void read_cmd(strvec * cmd)
{
	char * buffer = calloc(256, sizeof(char*));
	size_t buffsize = 256;
	int read = getline(&buffer, &buffsize, stdin);
	// make sure it's empty
	strvec_free(cmd);
	// this will help avoid the "segfault on empty input" problem
	strvec_init(cmd);
	char * ptr = strtok(buffer, " \n");
	while (ptr)
	{
		strvec_push(cmd, ptr);
		ptr = strtok(NULL, " \n");
	}
	free(buffer);
	return;
}

void exec_cmd(const strvec * cmd)
{
	if (strcmp(cmd->_vec[0], "exit") == 0)return;
	if (strcmp(cmd->_vec[0], "exit") == 0)
	{
		FCNS[0](cmd);
		return;	
	}


	int cpid = fork();
	if (cpid == 0){
			int err = execvp(cmd->_vec[0], cmd->_vec);
			if (err == -1 )
			{
				perror(strvec_get(*cmd, 0));
				exit(errno);

			}
	}
	else if(cpid < 0)
	{
		printf("An error occured in the fork process");
	}
	else
	{
		int status;
		pid_t wpid;
		do{
			 wpid = waitpid(cpid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	
}




