cmake_minimum_required(VERSION 3.24)
project(my_minitalk C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(printf/includes)
include_directories(printf/libft)

add_executable(my_minitalk
        printf/includes/ft_printf.h
        printf/libft/ft_atoi.c
        printf/libft/ft_bzero.c
        printf/libft/ft_calloc.c
        printf/libft/ft_isalnum.c
        printf/libft/ft_isalpha.c
        printf/libft/ft_isascii.c
        printf/libft/ft_isdigit.c
        printf/libft/ft_isprint.c
        printf/libft/ft_itoa.c
        printf/libft/ft_lstadd_back.c
        printf/libft/ft_lstadd_front.c
        printf/libft/ft_lstclear.c
        printf/libft/ft_lstdelone.c
        printf/libft/ft_lstiter.c
        printf/libft/ft_lstlast.c
        printf/libft/ft_lstnew.c
        printf/libft/ft_lstsize.c
        printf/libft/ft_memchr.c
        printf/libft/ft_memcmp.c
        printf/libft/ft_memcpy.c
        printf/libft/ft_memmove.c
        printf/libft/ft_memset.c
        printf/libft/ft_putchar_fd.c
        printf/libft/ft_putendl_fd.c
        printf/libft/ft_putnbr_fd.c
        printf/libft/ft_putstr_fd.c
        printf/libft/ft_split.c
        printf/libft/ft_strchr.c
        printf/libft/ft_strdup.c
        printf/libft/ft_striteri.c
        printf/libft/ft_strjoin.c
        printf/libft/ft_strlcat.c
        printf/libft/ft_strlcpy.c
        printf/libft/ft_strlen.c
        printf/libft/ft_strmapi.c
        printf/libft/ft_strncmp.c
        printf/libft/ft_strnstr.c
        printf/libft/ft_strrchr.c
        printf/libft/ft_strtrim.c
        printf/libft/ft_substr.c
        printf/libft/ft_tolower.c
        printf/libft/ft_toupper.c
        printf/libft/libft.h
        printf/sources/ft_printchar.c
        printf/sources/ft_printf.c
        printf/sources/ft_printhex.c
        printf/sources/ft_printint.c
        printf/sources/ft_printper.c
        printf/sources/ft_printptr.c
        printf/sources/ft_printstr.c
        printf/sources/ft_printunsint.c
        client.c
        minitalk.h
        )
