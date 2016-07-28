/*
** utils_tab1.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:22:05 2008 christophe sundas
** Last update Thu Nov 20 22:08:15 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char	**add_line(char **my_env, char *new_line)
{
  char	**new_env;
  int	i;
  int	oldsize;

  oldsize = my_tab_size(my_env);
  if ((new_env = malloc(sizeof(*new_env) * (oldsize + 2))) == NULL)
    exit(-1);
    i = 0;
  while (i < oldsize)
    {
      new_env[i] = my_env[i];
      i++;
    }
  new_env[i] = new_line;
  i++;
  new_env[i] = 0;
  free(my_env);
  return (new_env);
}

char	**delete_line(char **my_env, int indice)
{
  char	**new_env;
  int	oldsize;
  int	i;
  
  i = 0;
  oldsize = my_tab_size(my_env);
  if ((indice >= oldsize) || (indice < 0))
    return (my_env);
  if ((new_env = malloc(sizeof(*new_env) * oldsize)) == NULL)
  while (i < indice)
    {
      new_env[i] = my_env[i];
      i++;
    }
  while (i < (oldsize -1))
    {
      new_env[i] = my_env[i + 1];
      i++;
    }
  new_env[i] = 0;
  free(my_env[indice]);
  free(my_env);
  return (new_env);
}

char	**change_line(char **my_env, char *new_line, int indice)
{
  char	**new_env;
  int	i;
  int	oldsize;

  i = 0;
  oldsize = my_tab_size(my_env);
  if ((indice >= oldsize) || (indice < 0) || (new_line == NULL))
    return (my_env);
  if ((new_env = malloc(sizeof(*new_env) * (oldsize + 1))) == NULL)
    exit(-1);
  while (i < oldsize)
    {
      if (i == indice)
	new_env[i] = new_line;
      else
	new_env[i] = my_env[i];
      i++;
    }
  new_env[i] = 0;
  free(my_env);
  return (new_env);
}
