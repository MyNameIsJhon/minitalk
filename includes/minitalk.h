/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:28:02 by jriga             #+#    #+#             */
/*   Updated: 2025/07/21 01:28:41 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# define DATA_SPEED 20 

void	receipt_init(struct sigaction *sig);
void	receipt_signal(int sig, siginfo_t *info, void *context);
void	send_signal(char *message, int pid);

#endif
