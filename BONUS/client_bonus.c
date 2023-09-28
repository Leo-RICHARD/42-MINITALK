/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:47:07 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/25 22:55:50 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	check_reception(int sig)
{
	(void)sig;
	write(1, "Data received\n", 15);
	exit(0);
}

int	send(int spid, char *str)
{
	int		i;
	int		sig;
	char	*s;

	s = str;
	while (((s - str) && *(s - 1)) || (s == str))
	{
		i = -1;
		while (++i < 8)
		{
			if ((*s >> (7 - i)) & 1)
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			if (!kill(spid, sig))
				usleep(101);
			else
				return (0);
		}
		s++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int					spid;
	char				wrongpid;
	char				*cpid;

	if (ac != 3)
		error("Wrong number of arguments.\nPlease submit the \
server PID and a message to transmit\n", 0);
	wrongpid = 0;
	spid = ft_atoi(av[1], &wrongpid);
	if (wrongpid)
		error("Incorrect format/value for PID (don't use letters or negative \
numbers)\n", 0);
	cpid = ft_itoa(getpid());
	if (!cpid)
		error("Memory allocation failed\n", 0);
	if (!send(spid, cpid))
		error("Transmission failed \
(incorrect PID or the process died)\n", cpid);
	free(cpid);
	send(spid, av[2]);
	write(1, "Data transmitted\n", 18);
	signal(SIGUSR1, check_reception);
	while (1)
		pause();
	return (0);
}
