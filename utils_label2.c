/*
** utils_label2.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:21:23 2008 christophe sundas
** Last update Thu Nov 20 17:21:24 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

/*
** Retourne une ligne correspondant a son label
*/
char	*recup_line(char *label, char **my_env)
{
  int	i;

  i = 0;
  while (my_env[i] != 0)
    {
      if (my_strncmp(label, my_env[i], label_len(my_env[i])) == 0)
        return (my_env[i]);
      i++;
    }
  return (NULL);
}

char	*get_label2(char *line)
{
  char	*label;
  int	i;
  int	max;

  max = my_strlen(line);
  i = 0;
  while ((i < max) && (line[i] != '='))
    {
      i++;
    }
  label = malloc(sizeof(*label) * (i + 1));
  my_strncpy(label, line, i);
  return (label);
}
