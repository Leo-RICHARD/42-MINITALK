/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:08:43 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/25 22:57:55 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int spid, char *str)
{
	int		i;
	int		sig;
	char	*s;

	s = str;
	while (*s)
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
				error("Transmission failed \
(incorrect PID or the process died)\n", 0);
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	int		spid;
	char	wrongpid;

	if (ac != 3)
		error("Wrong number of arguments.\nPlease submit the \
server PID and a message to transmit\n", 0);
	wrongpid = 0;
	spid = ft_atoi(av[1], &wrongpid);
	if (wrongpid)
		error("Incorrect format/value for PID (don't use letters or negative \
numbers)\n", 0);
	send(spid, av[2]);
	write(1, "Data transmitted\n", 18);
	return (0);
}
