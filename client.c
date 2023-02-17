/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:29 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/17 13:20:07 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	/* sa_newsig.sa_handler = &sig_handler; */
	sa_newsig.sa_flags = SA_SIGINFO;
	/* if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior"); */
}

int	main(int av, char* ag[])
{
	int	pid_client;

	pid_client = getpid();
	if (av != 3)
	{
		write(1, "ERROR: write 2 argument next time, please\n", 43);
		return (0);
	}
	printf("CLIENT PID: %d\n", pid_client);
	config_signals();
	return (EXIT_SUCCESS);
}