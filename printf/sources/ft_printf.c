/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:58:57 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/10 15:46:01 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_format(va_list ap, const char c)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += ft_printchar(va_arg(ap, int));
	else if (c == 's')
		total += ft_printstr(va_arg(ap, char *));
	else if (c == '%')
		total += ft_printper();
	else if (c == 'i' || c == 'd')
		total += ft_printint(va_arg(ap, int));
	else if (c == 'u')
		total += ft_printunsint(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		total += ft_printhex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
		total += ft_printptr(va_arg(ap, uintptr_t));
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			total += ft_format(ap, str[i + 1]);
			i++;
		}
		else
			total += ft_printchar(str[i]);
		i++;
	}
	va_end(ap);
	return (total);
}

/* int main()
{
	char a = 'Z';
	char b[] = "Masha";
	int num = 4567;
	int total;
	void *ptr;
	ptr = &num;
	printf("\n%i\n", ft_printf("Hello how %c you 
	%s %% %i with hex %x and pointer %p", a, b, num, num, (uintptr_t)ptr));
} */