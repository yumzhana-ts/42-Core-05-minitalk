/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:37:10 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/10/14 16:48:50 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	add_bit(char c, int bit)
{
	c <<= 1;
	if (bit)
		c += 1;
	return (c);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_setmemory_cpy(unsigned int *allocated_bytes, unsigned int count_c,
		char **string)
{
	char	*temp;

	allocated_bytes[0] += 1000;
	temp = malloc((allocated_bytes[0] + 1) * sizeof(char));
	if (temp == NULL)
	{
		free(*string);
		ft_printf("Error: malloc failed\n");
		exit(1);
	}
	if (count_c != 0)
	{
		ft_strlcpy(temp, *string, allocated_bytes[0] - 999);
		free(*string);
	}
	*string = temp;
	(*string)[count_c] = '\0';
	return ;
}

void	ft_print_send_sig(siginfo_t *info, char **string,
		unsigned int *allocated_bytes, unsigned int *count_c)
{
	kill(info->si_pid, SIGUSR2);
	ft_printf("%s\n", *string);
	free(*string);
	count_c[0] = 0;
	allocated_bytes[0] = 0;
	return ;
}

void	process_bit(int bit, siginfo_t *info)
{
	static unsigned int	count_c = 0;
	static unsigned int	allocated_bytes = 0;
	static int			i = 0;
	static char			*string = NULL;

	if (count_c == allocated_bytes)
		ft_setmemory_cpy(&allocated_bytes, count_c, &string);
	string[count_c] = add_bit(string[count_c], bit);
	if (i >= 7)
	{
		string[count_c + 1] = '\0';
		i = 0;
		if (string[count_c] == 0)
		{
			ft_print_send_sig(info, &string, &allocated_bytes, &count_c);
			return ;
		}
		count_c++;
	}
	else
		i++;
	return ;
}
