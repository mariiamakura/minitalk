/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:05:49 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/10 14:42:44 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	len_hex(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_hex(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_hex(n / 16, format);
		ft_hex(n % 16, format);
	}
	else
	{
		if (format == 'x')
			ft_printchar("0123456789abcdef"[n]);
		if (format == 'X')
			ft_printchar("0123456789ABCDEF"[n]);
	}
}

int	ft_printhex(unsigned int n, char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_hex(n, format);
	return (len_hex(n));
}

/* int main()
{
	ft_hex(4567, 'x');
}
 */