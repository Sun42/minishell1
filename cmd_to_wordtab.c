/*
** cmd_to_wordtab.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:14:42 2008 christophe sundas
** Last update Thu Nov 20 17:14:43 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

/*
** tranforme la ligne de commande en tableau de string
*/
char	**cmd_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	w_len;

  i = 0;
  if ((tab = malloc(sizeof(*tab) * (my_nb_word(str) + 1))) == NULL)
    exit(-1);
  while (*str)
    {
      if (char_isprintable(*str) == 1)
        {
	  w_len = word_len(str);
	  if ((tab[i] = malloc(sizeof(**tab) * (w_len + 1))) == NULL)
	    exit(-1);
	  my_strcpy(tab[i], "");
	  my_strncat(tab[i], str, w_len);
	  i++;
	  str = str + w_len;
        }
      else
        str++;
    }
  tab[i] = 0;
  return (tab);
}

/*
** Compte le nombre de mots dans la ligne de cmd
*/
int	my_nb_word(char *str)
{
  int	nb;

  nb = 0;
  while (*str)
    {
      if (char_isprintable(*str))
	{
	  nb++;
	  str = str + word_len(str);
	}
      else
	str++;
    }
  return (nb);
}

/*
** Retourne la longueur d'un mot
*/
int	word_len(char *str)
{
  int	i;

  i = 0;
  while (char_isprintable(str[i]))
    i++;
  return (i);
}

/*
**le char fait-il parti dun mot? 
*/
int	char_isprintable(char c)
{
  if ((c <= ' ') || (c > '~'))
    return (0);
  return (1);
}
