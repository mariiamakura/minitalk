/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:32 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/23 15:19:22 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//void sig_handel (int sig_number, siginfo_t *info, void *content)

void sig_handel (int signal,  siginfo_t *info, void *content)
{
	static int	bits = -1;
	static unsigned char	c;
	
	(void)content;
	if (bits < 0)
		bits = 7;
	if (signal == SIGUSR1)
		c |= (1 << bits);
	bits--;
	if (bits < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			write(1, "Failed to change SIGUSR1's behavior", 36);
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		write(1, "Failed to change SIGUSR1's behavior", 36);
}


void	config_signals(void)
{
	//creating a struck where will save new signal info
	struct sigaction	newsig; 
	
	// sa_signation see the end of the file 
	newsig.sa_sigaction = &sig_handel;

	//If SA_SIGINFO is specified in sa_flags, then sa_sigaction (instead of sa_handler) 
	// specifies the signal-handling function for signum.  
	// This function receives three arguments, as described below.
	newsig.sa_flags = SA_SIGINFO;


	/* sigaction() returns 0 on success; 
	on error, -1 is returned, and
	errno is set to indicate the error.*/
	if (sigaction(SIGUSR1, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR1", 25);
	//ft_printf("%i\n", SIGUSR1); == 10
	if (sigaction(SIGUSR2, &newsig, NULL) < 0)
		write(1, "Failed to change SIGUSR2", 25);
	//ft_printf("%i\n", SIGUSR2); == 12
}

int	main()
{
	pid_t	pid_server;

	pid_server = getpid();
	printf("SERVER PID: %d\n\n", pid_server);
	while (1)
	{
		config_signals();
	}
	return (0);
}

//cc -o server server.c printf/libftprintf.a compile with printf


/*  The siginfo_t argument to a SA_SIGINFO handler
       When the SA_SIGINFO flag is specified in act.sa_flags, the signal
       handler address is passed via the act.sa_sigaction field.  This
       handler takes three arguments, as follows:

           void
           handler(int sig, siginfo_t *info, void *ucontext)
           {
               ...
           }

       These three arguments are as follows

       sig    The number of the signal that caused invocation of the
              handler.

       info   A pointer to a siginfo_t, which is a structure containing
              further information about the signal, as described below.

       ucontext
              This is a pointer to a ucontext_t structure, cast to
              void *.  The structure pointed to by this field contains
              signal context information that was saved on the user-
              space stack by the kernel; for details, see sigreturn(2).
              Further information about the ucontext_t structure can be
              found in getcontext(3) and signal(7).  Commonly, the
              handler function doesn't make any use of the third
              argument. */
