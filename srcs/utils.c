/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:19:14 by jriga             #+#    #+#             */
/*   Updated: 2025/07/26 22:43:09 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "unistd.h"
#include "libft.h"
#include <signal.h>
#include "vector.h"
#include <stdlib.h>

void	receipt_init(struct sigaction *sig)
{
	struct sigaction	sa;

	sa = *sig;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	conf_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR2)
	{
		ft_putstr("Message sended successfully !\n");
		exit(0);
	}
}

static void	send_chr(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(DATA_SPEED);
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		pause();
	}
}

void	send_signal(char *message, int pid)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = conf_handler;
	receipt_init(&sa);
	while (*message)
	{
		send_chr(*message, pid);
		message++;
	}
	send_chr('\0', pid);
}
