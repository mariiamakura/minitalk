/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:35:32 by mishamakura       #+#    #+#             */
/*   Updated: 2023/02/16 22:02:32 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main()
{
	int	pid_server;

	pid_server = getpid();
	ft_printf("SERVER PID: %d\n", pid_server);
	while (1)
	{
		
	}
}

//cc -o server server.c printf/libftprintf.a compile with printf

