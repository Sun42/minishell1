/*
** my_setenv.c for mush in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:17:45 2008 christophe sundas
** Last update Thu Nov 20 17:17:47 2008 christophe sundas
*/

#include "my.h"
#include "mysh.h"

/*
** verif la validite des parametre de la cmd avec exec setenv
*/
char	**my_setenv(char **my_env, char **cmd)
{
  if (my_tab_size(cmd) < 2)
    {
      my_show_to_wordtab(my_env);
      return (my_env);
    }
  if (my_tab_size(cmd) > 3)
    {
      my_putstr_error("setenv: Too many arguments.\n");
      return (my_env);
    }
  else
    {
      if (exist_char(cmd[1], '='))
	{
	  my_putstr_error("setenv: Syntax Error.\n");
	  return (my_env);
	}
      else
	{
	  return (exec_setenv(my_env, mk_line(cmd)));
	}
    }
  return (my_env);
}

/*
** si label existe, change la ligne
** sinon ajoute une ligne
*/
char	**exec_setenv(char **my_env, char *line)
{
  int	indice;
 
  if (!exist_label(get_label2(line), my_env))
    return (add_line(my_env, line));
  else
    {
      indice = find_indice(my_env, get_label2(line));
      return (change_line(my_env, line, indice));
    }
}
