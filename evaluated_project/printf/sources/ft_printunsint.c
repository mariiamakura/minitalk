/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:29:49 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/10 15:45:52 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

size_t	int_ulen(unsigned int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_upositive(char *str, unsigned int num, size_t len_int)
{
	while (num > 0)
	{
		str[len_int] = 48 + (num % 10);
		num = num / 10;
		len_int--;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	len_int;
	long	num;

	num = n;
	len_int = int_ulen(n);
	str = malloc((len_int + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len_int--] = 0;
	if (num == 0)
	{
		str[0] = 48 + num;
		return (str);
	}
	if (num > 0)
		str = ft_upositive(str, num, len_int);
	return (str);
}

int	ft_printunsint(unsigned int n)
{
	int		total;
	char	*str;

	total = 0;
	str = ft_uitoa(n);
	total += ft_printstr(str);
	free(str);
	return (total);
}

/* int main ()
{
	unsigned int a = -1;
	ft_printunsint(a);
	printf(" %u", ft_printunsint(a));
}  */
