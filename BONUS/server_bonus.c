/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:48:16 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/24 22:48:11 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	print_pid(int pid)
{
	char	d;

	d = pid % 10 + 48;
	if (pid >= 10)
		print_pid(pid / 10);
	write(1, &d, 1);
}

void	confirm_reception(int cpid)
{
	usleep(234);
	if (kill(cpid, SIGUSR1))
		write(1, "Client died\n", 13);
}

void	handlesig(int sig)
{
	static int		i = -1;
	static int		cpid = 0;
	static char		c = 0;
	static char		cpid_transmission_in_progress = 1;

	if (++i < 8)
		c = (c << 1) + (sig == SIGUSR1);
	if (i == 7)
	{
		if (cpid_transmission_in_progress && c)
			cpid = cpid * 10 + c - 48;
		else if (cpid_transmission_in_progress)
			cpid_transmission_in_progress = 0;
		else if (c)
			write(1, &c, 1);
		else
		{
			write(1, "\n", 1);
			confirm_reception(cpid);
			cpid = 0;
			cpid_transmission_in_progress = 1;
		}
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
