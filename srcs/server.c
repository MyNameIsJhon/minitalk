/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:52:10 by jriga             #+#    #+#             */
/*   Updated: 2025/07/24 02:45:06 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_sigaction = receipt_signal;
	receipt_init(&sa);
	ft_printf("[PID]: %d\n", pid);
	ft_putstr("[SERVER]: Now listening..\n");
	while (1)
		pause();
	return (0);
}
