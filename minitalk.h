/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 20:17:48 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/25 22:57:26 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

void	error(char *message, char *tofree);
size_t	ft_strlen(const char *s);
void	prints(char *str);
int		ft_atoi(char *s, char *err);
char	*ft_itoa(int n);

#endif
