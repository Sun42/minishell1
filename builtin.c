/*
** builtin.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:14:23 2008 christophe sundas
** Last update Thu Nov 20 17:14:25 2008 christophe sundas
*/

#include "my.h"
#include "mysh.h"

int	is_builtin(char **cmd)
{
  if (my_strcmp(cmd[0], "setenv") == 0)
    return (1);
  if (my_strcmp(cmd[0], "env") == 0)
    return (1);
  if (my_strcmp(cmd[0], "unsetenv") == 0)
    return (1);
  if (my_strcmp(cmd[0], "cd") == 0)
    return (1);
  return(0);
}

char	**exec_builtin(char **my_env, char **cmd)
{
  if (my_strcmp(cmd[0], "setenv") == 0)
    {
      return (my_setenv(my_env, cmd));
    }
  if (my_strcmp(cmd[0], "unsetenv") == 0)
    {
      return (my_unsetenv(my_env, cmd));
    }
  if (my_strcmp(cmd[0], "env") == 0)
    {
      env(my_env, cmd);
    }
    if (my_strcmp(cmd[0],"cd") == 0)
    {
      return (my_cd(my_env, cmd));
    }
    return (my_env);
}
