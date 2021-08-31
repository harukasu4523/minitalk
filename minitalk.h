#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_msg
{
	unsigned char	c1;
	unsigned char	c2;
	// char	*s;
	size_t	size;
}				t_msg;

#endif