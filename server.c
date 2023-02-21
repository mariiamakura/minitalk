/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:32 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/21 16:25:08 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//void sig_handel (int sig_number, siginfo_t *info, void *content)

void sig_handel (int signal)
{
	if (signal == SIGUSR1)
		write(1, "Got SIGUSR1", 11);
}


void	config_signals(void)
{
	//creating a struck where will save new signal info
	struct sigaction	newsig; 

	//If SA_SIGINFO is specified in sa_flags, then sa_sigaction (instead of sa_handler) 
	// specifies the signal-handling function for signum.  
	// This function receives three arguments, as described below.
	newsig.sa_flags = SA_SIGINFO;
	
	// sa_handler specifies the action to be associated with signum
	// A pointer to a signal handling function.  This function
	// receives the signal number as its only argument.
	newsig.sa_handler = &sig_handel; 


	/* sigaction() returns 0 on success; 
	on error, -1 is returned, and
	errno is set to indicate the error.*/
	if (sigaction(SIGUSR1, &newsig, NULL) == -1)
		write(1, "Failed to change SIGUSR1", 25);
	//ft_printf("%i\n", SIGUSR1); == 10
	if (sigaction(SIGUSR2, &newsig, NULL) == -1)
		write(1, "Failed to change SIGUSR2", 25);
	//ft_printf("%i\n", SIGUSR2); == 12
}

int	main()
{
	int	pid_server;

	pid_server = getpid();
	printf("SERVER PID: %d\n", pid_server);
	while (1)
	{
		config_signals();
	}
}

//cc -o server server.c printf/libftprintf.a compile with printf

