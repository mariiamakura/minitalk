/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:29 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/16 21:44:46 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int av, char* ag[])
{
	int	pid_client;

	pid_client = getpid();
	if (av != 3)
	{
		write(1, "ERROR: write 1 argument next time, please\n", 43);
		return (0);
	}
	printf("CLIENT PID: %d\n", pid_client);
	
	//
}