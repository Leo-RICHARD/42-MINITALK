/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:09:06 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/24 22:48:09 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(int pid)
{
	char	d;

	d = pid % 10 + 48;
	if (pid >= 10)
		print_pid(pid / 10);
	write(1, &d, 1);
}

void	handlesig(int sig)
{
	static int		i = -1;
	static char		c = 0;

	if (++i < 8)
		c = (c << 1) + (sig == SIGUSR1);
	if (i == 7)
	{
		write(1, &c, 1);
		i = -1;
		c = 0;
	}
}

int	main(void)
{
	print_pid(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handlesig);
	signal(SIGUSR2, handlesig);
	while (1)
		pause();
	return (0);
}
