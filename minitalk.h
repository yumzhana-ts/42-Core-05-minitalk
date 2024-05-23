/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:37:58 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/10/14 16:58:27 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

void	ft_setmemory_cpy(unsigned int *allocated_bytes, unsigned int count_c,
			char **string);
void	process_bit(int bit, siginfo_t *info);
size_t	ft_strlen(const char *string);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	add_bit(char c, int bit);
int		ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
