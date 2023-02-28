/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:29 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/23 15:10:30 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void arguments_check (int av, char *ag[])
{
	int	i;

	i = 0;
	if (av != 3)
	{
		ft_printf("ERROR: write 2 argument next time, please\n");
		exit(1);
	}
	while (ag[1][i])
	{
		if (!ft_isdigit(ag[1][i++]))
		{
			ft_printf("ERROR: wrong PID\n");
			exit(1);
		}
	}
	if (ag[2] == 0) //do i need this?
	{
		ft_printf("ERROR: empty\n");
		exit(1);
	}
}


void send_bits(pid_t pid_server, char *message)
{

	unsigned char	c; //if it's unicode we need more than 126
	int	bits;

	while (*message)
	{
		c = *message; //the 1 byte which is 8 bits
		bits = 8;
		while (bits)
		{
			if (c & 10000000) //128 in decimal
				kill(pid_server, SIGUSR1);
			else 
				kill(pid_server, SIGUSR2);
			usleep(50);
			c<<=1; // so A = 01000001 will become 10000010
			bits--;
		}
		message++;
	}
	
}

void sig_modify(int sig_number)
{
	if (sig_number == SIGUSR2)
		ft_printf("Message has been received!\n");
}

void	config_signals(void)
{
	//creating a struck where will save new signal info
	struct sigaction	newsig; 

	// sa_handler specifies the action to be associated with signum
	// A pointer to a signal handling function.  This function
	// receives the signal number as its only argument.
	newsig.sa_handler = &sig_modify; 

	//If SA_SIGINFO is specified in sa_flags, then sa_sigaction (instead of sa_handler) 
	// specifies the signal-handling function for signum.  
	// This function receives three arguments, as described in server.c.
	newsig.sa_flags = SA_SIGINFO;


	/* sigaction() returns 0 on success; 
	on error, -1 is returned, and
	errno is set to indicate the error.*/
	if (sigaction(SIGUSR1, &newsig, NULL) < 0)
		ft_printf("Failed to change SIGUSR1");
	//ft_printf("%i\n", SIGUSR1); == 10
	if (sigaction(SIGUSR2, &newsig, NULL) < 0)
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
	pid_t	pid_server;

	arguments_check(av, ag);
	pid_server = ft_atoi(ag[1]);
	ft_printf("CLIENT PID = %d\n", getpid());
	config_signals();
	send_bits(pid_server, ag[2]); 
	while (1)
		pause();
	return (0);
}
