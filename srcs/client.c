/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:11:44 by jriga             #+#    #+#             */
/*   Updated: 2025/07/26 22:40:44 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"
#include "minitalk.h"

int	main(int ac, char **av)
{
	int	pid;

	if (ac < 3)
		return (0);
	pid = ft_atoi(av[1]);
	ft_printf("[From %d to %d] sending: %s\n", getpid(), pid, av[2]);
	send_signal(av[2], pid);
	return (0);
}
