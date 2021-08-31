/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiwata <hiwata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:41:16 by hiwata            #+#    #+#             */
/*   Updated: 2021/07/25 21:50:45 by hiwata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_atoi(char *s)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i ++;
	return (i);
}

void	send_bit(char *str, int pid, int len)
{
	int	i;
	int	shift;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	len;

	if (argc != 3)
		return (0);
	len = 0;
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	send_bit(argv[2], pid, len);
	return (0);
}
