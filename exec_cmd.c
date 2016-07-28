/*
** exec_cmd.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:14:56 2008 christophe sundas
** Last update Fri Nov 21 13:11:51 2008 christophe sundas
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/resource.h>
#include "my.h"
#include "mysh.h"

void    kill_fils(int sig);

/*
** fork et execeute une commande
*/
void	exec_cmd(char **cmd, char **my_env)
{
  int	status;
  char	*binpath;
  pid_t my_pid;

  signal(SIGINT,  kill_fils);
  binpath = find_binpath(cmd, my_env);
  if (binpath == NULL)
    binpath = cmd[0];
  if ((my_pid = fork()) < 0)
    exit(-1);
  if (my_pid != 0)
    {
      waitpid(my_pid, &status, 0);
    }
  if (my_pid == 0)
    {
      if (execve(binpath , cmd, my_env) == -1)
        {
	  my_putstr_error(cmd[0]);
	  my_putstr_error(": Command not found.\n");
	}
      exit(1);
    }
}

void	kill_fils(int sig)
{
  main();
}

/*
** Recupere le binaire adequate si existe, sinon null
*/
char	*find_binpath(char **cmd, char **my_env)
{
  char	*pathline;
  
  pathline = recup_line("PATH", my_env);
  if (pathline == NULL)
    return (NULL);
  return (recup_goodpath(cmd, pathline));
}

/*
** Retourne le path adequate a a partir de la chaine path 
*/
char	*recup_goodpath(char **cmd, char *pathline)
{
  char	**path_tab;
  int	i;
  char	*full_path;

  i = 0;
  path_tab = my_str_to_wordtab2(del_label(pathline, "PATH"), ':');
  while (path_tab[i])
    {
      full_path = mk_fullpath(path_tab[i], cmd[0]);
      if (access(full_path, F_OK) == 0)
	{
	  my_free_tab(path_tab);
	  return (full_path);
	}
      i++;
      free(full_path);
    }
  my_free_tab(path_tab);
  return (NULL);
}

/*
** Make full path
*/
char	*mk_fullpath(char *str1, char *str2)
{
  char	*full_path;

  if ((full_path = malloc(sizeof(*full_path) * (my_strlen(str1) + my_strlen(str2) + 2 ))) == NULL)
    exit(-1);
  my_strcpy(full_path, str1);
  my_strcat(full_path, "/");
  my_strcat(full_path, str2);
  return (full_path);
}
