/*
** utils_tab2.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:22:21 2008 christophe sundas
** Last update Thu Nov 20 17:22:22 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

/*
** taille d'un tableau
*/
int	my_tab_size(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      i++;
    }
  return (i);
}

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (i < (my_tab_size(tab) - 1))
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	my_free_tab2(char **tab)
{
  int	i;
  int	tabsize;

  tabsize = my_tab_size(tab);
  i = 1;
  while (i < (tabsize -1))
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
