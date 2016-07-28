/*
** my_str_to_wordtab2.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:18:09 2008 christophe sundas
** Last update Thu Nov 20 17:18:10 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char	**my_str_to_wordtab2(char *str, char delimiteur)
{
  char	**tab;
  int	i;
 
  i = 0;
  if ((tab = malloc(sizeof(*tab) * (count_words2(str, delimiteur) + 1))) == NULL)
    exit(-1);
  while (*str)
    {
      if (*str != delimiteur)
	{
	  if ((tab[i] = malloc(sizeof(**tab) *(word_len2(str, delimiteur) + 1)))== NULL)
	    exit(-1);
	  my_strcat(tab[i], "");
	  my_strncpy(tab[i], str, word_len2(str, delimiteur));
	  i++;
	  str = str + word_len2(str, delimiteur);
	}
      else
	str++;
    }
  tab[i] = 0;
  return (tab);
}

/*
** compte le nombre de mots
*/
int	count_words2(char *str, char delimiteur)
{
  int	i;

  i = 0;
  while (*str)
    {
      if (((*str) == delimiteur) && (*(str + 1) != delimiteur))
	i++;
      str++;
    }
  return (i + 1);
}

/*
** retourne la taile dun mot
*/
int	word_len2(char *str, char delimiteur)
{
  int	i;

  i = 0;
  while ((str[i] != delimiteur) && (str[i] != '\0'))
    i++;
  return (i);
}
