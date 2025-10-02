/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receipt_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:38:36 by jriga             #+#    #+#             */
/*   Updated: 2025/07/26 22:39:58 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "signal.h"
#include <unistd.h>
#include "minitalk.h"

static void	init_receiver(t_vector **str, t_bool *ready)
{
	*str = vector_init(sizeof(char), 50);
	*ready = 1;
}

static void	finish_message(t_vector **str, pid_t pid, int *i, t_bool *ready)
{
	ft_printf("[PID: %d]: %s\n",
		pid,
		(*str)->content,
		ft_strlen((*str)->content));
	vec_free(*str);
	*i = 0;
	*ready = 0;
	usleep(DATA_SPEED);
	kill(pid, SIGUSR2);
}

static void	append_and_ack(t_vector **str, char c, pid_t pid, int *i)
{
	vec_strappend_char(*str, c);
	*i = 0;
	usleep(DATA_SPEED);
	kill(pid, SIGUSR1);
}

void	receipt_signal(int sig, siginfo_t *info, void *context)
{
	static int		i;
	static char		c;
	static t_bool	ready;
	static t_vector	*str;

	(void)context;
	if (ready == 0)
		init_receiver(&str, &ready);
	if (sig == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			finish_message(&str, info->si_pid, &i, &ready);
		else
			append_and_ack(&str, c, info->si_pid, &i);
		c = 0;
		return ;
	}
	usleep(DATA_SPEED);
	kill(info->si_pid, SIGUSR1);
}
