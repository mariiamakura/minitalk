/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:23:28 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/10 15:48:20 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	len_hexprt(uintptr_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i + 2);
}

void	ft_hexptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_hexptr(n / 16);
		ft_hexptr(n % 16);
	}
	else
		ft_printchar("0123456789abcdef"[n]);
}

int	ft_printptr(uintptr_t n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		ft_printstr("0x");
		ft_hexptr(n);
	}
	return (len_hexprt(n));
}

/* int main()
{
	int a;
	int result;
	void	*ptr;

	a = 5;
	ptr = &a;
	result = ft_printptr((uintptr_t) ptr);
	printf("\n%p \n%i", ptr, result);
	ft_printptr(0);
} */

/* int main()
{
	printf("\n%p %p", 0, 0);
 	ft_printptr(0);
	ft_printptr(0);
	return(0);
}  */