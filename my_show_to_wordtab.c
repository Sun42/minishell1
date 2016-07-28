/*
** my_show_to_wordtab.c for affiche un tableau de string in /u/all/sundas_c/cu/rendu/piscine/Jour_08
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Oct 20 10:25:04 2008 christophe sundas
** Last update Thu Nov 20 13:46:30 2008 christophe sundas
*/

#include "my.h"
#include <stdlib.h>

int	my_show_to_wordtab(char **str)
{
  int	i;
  i = 0;
  while (str[i] != NULL)
    {
      my_putstr(str[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
