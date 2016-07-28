/*
** my_strncmp.c for my strcnmp in /u/epitech_2011s/sundas_c/cu/rendu/piscine/Jour_06
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 14 23:07:17 2008 christophe sundas
** Last update Mon Nov 10 06:06:26 2008 christophe sundas
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	lenght;

  i = 0;
  lenght = my_max_int(my_strlen(s1), my_strlen(s2));
  while ((i < lenght - 1) && (*(s1 + i) == *(s2 + i)) && (i < (n - 1)))
    {
      i = i + 1;
    }
  return (my_cmp_char(*(s1 + i), *(s2 + i)));
}

