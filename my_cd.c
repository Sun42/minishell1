/*
** my_cd.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:16:11 2008 christophe sundas
** Last update Thu Nov 20 17:16:12 2008 christophe sundas
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

char	**my_cd(char **my_env, char **cmd)
{
  int	indice;
  char	*new_pwd;
  char	*new_line;

  if (check_cmd_error(cmd))
    return (my_env);
  if (my_tab_size(cmd) < 2)
    new_pwd = del_label(recup_line("HOME", my_env), "HOME");
  else
    new_pwd = eval_tild(my_env, cmd[1]);
  if (chdir(new_pwd) == -1)
    {
      my_putstr(new_pwd);
      my_putstr(": No such file or directory\n");
    }
  else
    {
      indice = find_indice(my_env, "PWD");
      new_line = mk_line2("PWD", my_getcwd());
      if (indice != -1)
	return (change_line(my_env, new_line, indice));
      else
	return (add_line(my_env, new_line));
    }
  return (my_env);
}

int	check_cmd_error(char **cmd)
{
  if (my_tab_size(cmd) > 2)
    {
      my_putstr_error("cd: Too many arguments.\n");
      return (1);
    }
  return (0);
}
