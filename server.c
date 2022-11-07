/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:19:42 by cafriem           #+#    #+#             */
/*   Updated: 2022/11/07 17:40:52 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_value = 0;

static void	translate_char(int bin)
{
	static int	inc;

	if (!inc)
		inc = 128;
	if (bin == 1)
		g_value += inc;
	inc = inc / 2;
	if (inc == 0)
	{
		ft_putchar_fd(g_value, 1);
		inc = 128;
		g_value = 0;
	}
}

static void	recieve_char(int num)
{
	int	bin;

	bin = 1;
	if (SIGUSR1 == num)
		bin = 0;
	translate_char(bin);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd ("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal (SIGUSR1, recieve_char);
	signal (SIGUSR2, recieve_char);
	while (1)
		pause();
}
