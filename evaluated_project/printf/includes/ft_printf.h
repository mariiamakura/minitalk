/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:56:01 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/10 15:32:56 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(const char c);
int		ft_printstr(char *str);
int		ft_printper(void);
int		ft_printint(int n);
int		ft_printunsint(unsigned int n);
int		ft_printhex(unsigned int n, char format);
int		ft_printptr(uintptr_t n);
void	ft_putstr(char *str);

#endif