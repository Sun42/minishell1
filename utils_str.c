/*
** utils_str.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:21:47 2008 christophe sundas
** Last update Thu Nov 20 17:21:48 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int	exist_char(char *str, char c)
{
  while (*str)
    {
      if (*str == c)
	return (1);
      str++;
    }
  return (0);
}

/*
**Construit une chaine a partir d'un **cmd
** avec cmd[1] et cmd[2]
*/
char	*mk_line(char **cmd)
{
  char	*line;
  int	tabsize;
  int	len;

  tabsize = my_tab_size(cmd);
  len = 0;
 if (tabsize < 2)
    return (NULL);
  if (tabsize == 2)
    len = my_strlen(cmd[1] + 1);
  if (tabsize == 3)
    len = my_strlen(cmd[1]) + my_strlen(cmd[2]) + 1;
  if ((line = malloc(sizeof(*line) * (len + 1))) == NULL)
    exit(-1);
  my_strcpy(line, cmd[1]);
  my_strcat(line, "=");
  if (tabsize == 3)
    my_strcat(line, cmd[2]);
  return (line);
}

/*
**construit une chaine a partir dun label et dune valeur
*/
char	*mk_line2(char *label, char *value)
{
  char	*new_line;
  int	len;

  if ((label == NULL) || (value == NULL))
    return (NULL);
  len = my_strlen(label);
  len = len + my_strlen(value) + 1;
  if ((new_line = malloc(sizeof(*new_line) * len)) == NULL)
    exit(-1);
  my_strcat(new_line, "");
  my_strcpy(new_line, label);
  my_strcat(new_line, "=");
  my_strcat(new_line, value);
  return (new_line);
}

/*
**  retourne le vrai path change le ~
*/
char	*eval_tild(char **my_env, char *path)
{
  char	*new_path;
  int	len1;
  char	*home;

  if ((exist_label("HOME", my_env) == 1) && (*path == '~'))
    {
      home = del_label(recup_line("HOME", my_env), "HOME");
      len1 = my_strlen(home);
      path++;
      len1 = len1 + my_strlen(path);
      if ((new_path = malloc(sizeof(*new_path) * (len1 + 1))) == NULL)
        exit(-1);
      my_strcpy(new_path, home);
      my_strcat(new_path, path);
      return (new_path);
    }
  return (path);
}
