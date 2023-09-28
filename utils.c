/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 20:13:51 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/25 22:57:15 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *message, char *to_free)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	free(to_free);
	to_free = 0;
	exit(0);
}

size_t	ft_strlen(const char *s)
{
	const char	*str;

	if (!s)
		return (0);
	str = s;
	while (*str)
		str++;
	return (str - s);
}

void	*nmalloc(void **var, int size)
{
	*var = malloc(sizeof(char) * size);
	if (!(*var))
		return (NULL);
	return (*var);
}

int	ft_atoi(char *nptr, char *err)
{
	int				i;
	long long int	pos;
	int				nb;

	i = 0;
	nb = 0;
	pos = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			pos *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	nb *= pos;
	if (nptr[i] || nb < 0 || nb != (int)nb)
		*err = 1;
	return (nb);
}

char	*ft_itoa(int n)
{
	int				l;
	int				nn;
	unsigned int	nb;
	char			*nbr;

	l = 0;
	nn = n;
	while (++l && nn)
		nn /= 10;
	nb = n;
	if (n < 0 || (n > 0 && l-- && 1 == 3))
		nb = n * -1;
	if (!nmalloc((void **)&nbr, l + 1))
		return (NULL);
	nbr[l] = 0;
	while (l-- > 0)
	{
		nbr[l] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
