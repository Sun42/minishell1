/*
** utils_label.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:20:46 2008 christophe sundas
** Last update Thu Nov 20 17:20:52 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

/*
** cherche un label dans l'environnement
*/
int	exist_label(char *label, char **my_env)
{
  int	i;

  i = 0;
  while (my_env[i] != 0)
    {
      if (my_strncmp(label, my_env[i], label_len(my_env[i])) == 0)
        return (1);
      i++;
    }
  return (0);
}


/*
** Retourne la valeur d'une ligne sans le label
*/
char	*del_label(char *line, char *label)
{
  line = line + my_strlen(label) + 1;
  return (line);
}

/*
** Retourne un label avec son = en fonction d'un indice
*/
char	*get_label(char **my_env, int indice)
{
  char	*label;
  int	len;

  len = label_len(my_env[indice]) + 1;
  if ((label = malloc(sizeof(*label) * (len + 1))) == NULL)
    exit(-1);
    my_strncpy(label, my_env[indice], len);
    return (label);
}

/*
** Retourne la taille d'un label
*/
int	label_len(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '=')
    {
      i++;
    }
  return (i);
}

/*
** Retourne l'indice dans le tableau en fonction d'un label
** -1 si pas trouve
*/
int	find_indice(char **my_env, char *label)
{
  int	i;

  i = 0;
  while (my_env[i])
    {
      if (my_strncmp(my_env[i], label , label_len(my_env[i])) == 0)
        {
          return (i);
        }
      i++;
    }
  return (-1);
}
