/*
** my_putchar.c for my_putchar in /u/epitech_2011s/sundas_c/cu/rendu/lib/my
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Oct 15 18:38:49 2008 christophe sundas
** Last update Thu Nov 20 13:50:08 2008 christophe sundas
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
