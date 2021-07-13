#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

typedef struct  s_msg
{
	char	c;
	size_t	size;
}				t_msg;

#endif