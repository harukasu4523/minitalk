#include "./minitalk.h"

t_msg g_msg;
char check_bit;

void my_handler1(int bit)
{
    
    g_msg.c += ((bit & 1) << g_msg.size);
    g_msg.size += 1;
    if (g_msg.size == 7)
    {
        write(1, &g_msg.c, 1);
        if (!g_msg.c)
            write(1, "\n", 1);
        g_msg.c = 0;
        g_msg.size = 0;
    }
}

char *ft_itoa(int pid, int digit)
{
    char *s;
    int i;

    if (digit == 0)
        return (NULL);
    s = malloc(digit + 1);
    if (!s)
        return (NULL);
    i = digit - 1;
    while (i >= 0)
    {
        s[i] = pid % 10 + '0';
        pid /= 10;
        i -=1;
    }
    s[digit] = '\0';
    return (s);
}

int digit_size(int pid)
{
    int cnt;

    cnt = 0;
    while (pid != 0)
    {
        pid /= 10;
        cnt += 1;
    }
    return (cnt);
}

int main(void)
{
    int pid;
    char *s_pid;
    int digit;

    // printf("1: %d 2: %d\n", SIGUSR1, SIGUSR2);
    g_msg.c = 0;
    check_bit = 0;
    g_msg.size = 0;
    pid = getpid();
    digit = digit_size(pid);
    s_pid = ft_itoa(pid, digit);
    if (!s_pid)
        exit (1);
    write(1, s_pid, digit);
    write(1, "\n", 1);
    free(s_pid);
    while(1)
    {
        signal(SIGUSR1, my_handler1);
        signal(SIGUSR2, my_handler1);
        pause();
    } 
    return (0);
}