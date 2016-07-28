/*
** minishell.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:15:48 2008 christophe sundas
** Last update Fri Nov 21 13:10:53 2008 christophe sundas
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"
#include "get_next_line.h"

/*
** Fonction principale, lit entree standard
*/
void	minishell1(void)
{
  char	*cmdline;
  char	**cmd;
  char	**my_env;

  /*  signal(SIGINT, handler);*/
  my_env = my_get_env();
  my_putstr("$>");
  while ((cmdline = get_next_line(0)))
    {
      cmd = cmd_to_wordtab(cmdline);
      analyse_cmd(cmd, &my_env);
      my_free_tab(cmd);
      free(cmdline);
      my_putstr("$>");
    }
  my_free_tab(my_env);
}
/*
void	handler(int sig)
{
  signal(sig, handler);
  my_putchar('\n');
  my_putstr(MSG_GOODBYE);
  my_putchar('\n');
  exit(1);
}
*/
/*
** Analyse la cmd recue et dispatch
*/
void	analyse_cmd(char **cmd, char ***my_env)
{
  if (my_strcmp(cmd[0],"exit") == 0)
    {
      my_putstr(MSG_GOODBYE);
      my_putchar('\n');
      exit(1);
    }
  if (is_builtin(cmd))
    {
      *my_env = exec_builtin(*my_env, cmd);
    }
  else
    {
      exec_cmd(cmd, *my_env);
    }
}

/*
** Retourne les variables d'environnement
*/
char		**my_get_env()
{
  extern char	**environ;
  char		**my_env;
  int		i;

  if ((my_env = malloc(sizeof(*my_env) * (my_tab_size(environ) + 1))) == NULL)
    exit (-1);
  i = 0;
  while (environ[i])
    {
      if ((my_env[i] = malloc(sizeof(**my_env) * (my_strlen(environ[i]) + 1))) == NULL)
        exit(-1);
      my_strcpy(my_env[i], environ[i]);
      i++;
    }
  my_env[i] = 0;
  return (my_env);
}
