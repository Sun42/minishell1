/*
** my_putstr.c for my_put_str.c in /u/all/sundas_c/cu/rendu/piscine/Jour_04
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct  9 15:09:57 2008 christophe sundas
** Last update Mon Nov 10 16:24:21 2008 christophe sundas
*/

#include "my.h"

int	my_putstr(char *str)
{
  while (*str != 0)
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}
