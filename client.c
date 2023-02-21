/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:29 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/21 16:26:09 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int arguments_check (int av, char *ag[])
{
	int	i;

	i = 0;
	if (av != 3)
	{
		ft_printf("ERROR: write 2 argument next time, please\n");
		return (0);
	}
	if (*ag[2] == 0) //do i need this?
	{
		ft_printf("ERROR: empty\n");
		return (0);
	}
	while (ag[1][i])
	{
		if (!ft_isdigit(ag[1][i++]))
		{
			ft_printf("ERROR: wrong PID\n");
			return (0);
		}
	}
	return (1);
}

void sig_modify(int sig_number)
{
	if (sig_number == SIGUSR2)
	{
		ft_printf("Message has been received!\n");
	}
	
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
	newsig.sa_handler = &sig_modify; 


	/* sigaction() returns 0 on success; 
	on error, -1 is returned, and
	errno is set to indicate the error.*/
	if (sigaction(SIGUSR1, &newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1");
	//ft_printf("%i\n", SIGUSR1); == 10
	if (sigaction(SIGUSR2, &newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR2");
	//ft_printf("%i\n", SIGUSR2); == 12
}

//how to send signal
/* void send_message()
{
	int pid_server = 45937;
	kill(pid_server, SIGUSR1);
} */

int	main(int av, char* ag[])
{
	int	pid_client;
	int	pid_server;
	int	arg_error;

	pid_client = getpid();
	arg_error = arguments_check(av, ag);
	if (arg_error == 0)
		return (0);
	//ft_printf("CLIENT PID: %d\n", pid_client);
	config_signals();
	send_message();
}