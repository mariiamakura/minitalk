/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:20 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/10 14:42:47 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_printint(int n)
{
	int		total;
	char	*str;

	total = 0;
	str = ft_itoa(n);
	total += ft_printstr(str);
	free(str);
	return (total);
}

/* int main ()
{
	int a = 0;
	ft_printint(a);
} */