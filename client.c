/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:14:29 by cafriem           #+#    #+#             */
/*   Updated: 2022/11/07 17:50:37 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	arg_checker(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 3)
		return (-1);
	while (!argv[1][i])
	{
		if (!(ft_strchr("0123456789", argv[1][i])))
			return (-1);
		i++;
	}
	return (0);
}

static void	send_bit(int binary, int pid)
{
	if (binary == 0)
		kill(pid, SIGUSR1);
	if (binary == 1)
		kill(pid, SIGUSR2);
	usleep(90);
}

static void	send_str(char *str, int pid)
{
	size_t	str_counter;
	int		bit_counter;
	int		binary;

	str_counter = 0;
	binary = 0;
	while (str_counter != ft_strlen(str))
	{
		bit_counter = 7;
		while (bit_counter >= 0)
		{
			binary = str[str_counter] >> bit_counter;
			binary = binary & 1;
			send_bit(binary, pid);
			bit_counter--;
		}
		str_counter++;
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		pid;

	if (arg_checker(argc, argv))
		return (-1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	str = ft_strjoin(str, "\n");
	send_str(str, pid);
}
