/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:35:31 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/10/14 16:52:29 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "minitalk.h"
#include "ft_printf/ft_printf.h"

int	g_confirmation_flag = 0;

void	convert_to_bin(char c, char *pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_confirmation_flag = 1;
		usleep(10);
		if (c & (1 << i))
			kill(ft_atoi(pid), SIGUSR2);
		else
			kill(ft_atoi(pid), SIGUSR1);
		i--;
		while (g_confirmation_flag)
			usleep(1);
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_confirmation_flag = 0;
	if (sig == SIGUSR2)
	{
		ft_printf("\nServer has just received your message!");
	}
	return ;
}

int	main(int argc, char **argv)
{
	unsigned long long	i;

	ft_printf("\nProcessing your message and sending to server...");
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	i = 0;
	if (argc != 3)
	{
		return (ft_printf("\nHey, dude! Fix number of arguments!Meh.."));
	}
	while (argv[2][i])
	{
		convert_to_bin(argv[2][i], argv[1]);
		i++;
	}
	convert_to_bin('\0', argv[1]);
	return (0);
}
