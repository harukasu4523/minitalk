#include "./minitalk.h"

int ft_atoi(char *s)
{
	int res;
	int size;
	int i;

	i = 0;
	res = 0;
	while(s[i])
	{
		res = res * 10  + (s[i] - '0');
		i ++;
	}
	return (res);
}

int ft_strlen(char* s)
{
	int i;
	
	i = 0;
	while(*s++)
		i += 1;
	return (i);
}


void send_bit(char *str, int pid)
{
	int i;
	int len;
	int shift;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			// printf("%d : %d\n", shift, (str[i] >> shift) & 1);
			if ((str[i] >> shift) & 1)
			{
				// printf("SIGUSR2\n");
				kill(pid, SIGUSR2);
			}
			else
			{
				// printf("SIGUSR1\n");
				kill(pid, SIGUSR1);
			}
			shift += 1;
			usleep(100);
		}
		i += 1;
	}
}

int main (int argc, char** argv)
{
	int pid;

	if (argc <= 2)
		return (0);
	pid = ft_atoi(argv[1]);
	send_bit(argv[2], pid);
	// for(int i = 0; i < 62; i++)
	// kill(pid, SIGUSR1);
	// kill(pid, SIGUSR2);
	return (0);
}