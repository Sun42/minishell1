/*
** my_env.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:16:20 2008 christophe sundas
** Last update Thu Nov 20 19:30:22 2008 christophe sundas
*/
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

/*
** Builtin env
*/
void	env(char **my_env, char **cmd)
{
  int	tabsize;
  int	nb;
  char	**new_env;
  int	i;

  tabsize = my_tab_size(cmd);
  if (tabsize < 2)
    {
      my_show_to_wordtab(my_env);
    }
  else
    {
      i = 1;
      nb = count_value(cmd);
      new_env = get_my_env(my_env);
      while (i <= nb)
	{
	  new_env = exec_setenv(new_env, cmd[i]);
	  i++;
	}
      cmd = cmd + nb + 1;
      if (*cmd != 0)
	exec_cmd(cmd, new_env);
    }
}

/*
**Cpt du nombre de new line envs
*/
int	count_value(char **cmd)
{
  int	i;
  int	nb;

  i = 1;
  nb = 0;
  while (cmd[i] && exist_char(cmd[i], '='))
    {
      nb++;
      i++;
    }
  return (nb);
}

/*
** copie de lenv courant
*/
char	**get_my_env(char **my_env)
{
  char	**env2;
  int	tabsize;
  int	i;

  tabsize = my_tab_size(my_env);
  if ((env2 = malloc(sizeof(*env2) * (tabsize +1))) == NULL)
    exit(-1);
  i = 0;
  while (my_env[i])
    {
      if ((env2[i] = malloc(sizeof(**env2) * (my_strlen(my_env[i]) + 1))) == NULL)
	exit(-1);
      my_strcpy(env2[i], "");
      my_strcat(env2[i], my_env[i]);
      i++;
    }
  env2[i] = 0;
  return (env2);
}
