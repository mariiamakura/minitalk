/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:32 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/28 16:01:33 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handel(int signal, siginfo_t *info, void *content)
{
	static int				bits;
	static unsigned char	c;

	(void)info;
	(void)content;
	if (signal == SIGUSR1)
		c |= 1 << (7 - bits);
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		c = 0;
		bits = 0;
	}
}

void	config_signals(void)
{
	struct sigaction	newsig;

	newsig.sa_sigaction = &sig_handel;
	newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR1", 25);
	if (sigaction(SIGUSR2, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR2", 25);
}

int	main(void)
{
	pid_t	pid_server;

	pid_server = getpid();
	ft_printf("SERVER PID: %d\n\n", pid_server);
	while (1)
	{
		config_signals();
	}
	return (0);
}
//cc -o server server.c printf/libftprintf.a compile with printf