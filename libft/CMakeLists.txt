cmake_minimum_required(VERSION 3.21)
project(libft C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(libft
        srcs/ft_isfunc.c
        srcs/ft_strncmp.c
        srcs/ft_toupper.c
        libft.h)

add_executable(ft_strdup srcs/ft_strdup.c)