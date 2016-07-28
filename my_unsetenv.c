/*
** my_unsetenv.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:20:17 2008 christophe sundas
** Last update Thu Nov 20 17:20:18 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char	**my_unsetenv(char **my_env, char **cmd)
{
  int	i;	
  int	tabsize;

  tabsize = my_tab_size(cmd);
  if (tabsize < 2)
    {
      my_putstr_error("unsetenv: Too few arguments.\n");
    }
  else 
    {
      i = 1;
      while (i < tabsize)
	{
	  my_env = exec_unsetenv(my_env, cmd[i]);
	  i++;
	}
    }
  return (my_env);
}

char	**exec_unsetenv(char **my_env, char *label)
{
  int	indice;

  if (label != NULL)
    {
      indice = find_indice(my_env, label);
      if (indice != -1)
	return (delete_line(my_env, indice));
    }
  return (my_env);
}
