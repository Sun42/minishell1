/*
** main.c for get next line in /u/all/sundas_c/cu/rendu/unix/projet/get_next_line
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 13 22:39:26 2008 christophe sundas
** Last update Thu Nov 20 12:52:42 2008 christophe sundas
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"
#include "mysh.h"

static int	cptinline;
static char	buffer[BUFFSIZE];
static int	nb_lu;

char	*get_next_line(int fd)
{
  int	flag;
  char	*ligne;
  
  flag = 1;
  ligne = 0;
  while (flag == 1)
    {
      if (cptinline == nb_lu)
	{
	  cptinline = 0;
	  nb_lu = read(fd, buffer, BUFFSIZE);
	  if (nb_lu == 0)
	    return (0);
	}
      ligne = my_charcat(ligne, buffer[cptinline]);
      if (buffer[cptinline] == '\n')
	flag = 0;
      cptinline++;
    }
  ligne = del_bckslshN(ligne);
  return (ligne);
}

char	*del_bckslshN(char *ligne)
{
  int	i;
  int	j;
  int	max;
  char	*new_string;

  max = my_strlen(ligne);
  if ((new_string = malloc(sizeof(*new_string) * (max + 1))) == NULL)
    exit(-1);
  i = 0;
  j = 0;
  while (i < max)
    {
      if (ligne[i] != '\n')
	{
	  new_string[j] = ligne[i];
	  j++;
	}
      i++;
    }
  new_string[j] = '\0';
  free(ligne);
  return (new_string);
}

char	*my_charcat(char *ligne, char c)
{
  char	*new_string;
  int	old_len;

  old_len = ligne ? my_strlen(ligne) : 0;
  if ((new_string = malloc(sizeof(*new_string) * (old_len + 2))) == NULL)
    exit(-1);
  if (ligne)
    {
      my_strcpy(new_string, ligne);
      new_string[old_len] = c;
      new_string[old_len + 1] = '\0';
      free(ligne);
    }
  else
    {
      new_string[old_len] = c;
      new_string[old_len + 1] = '\0';
    }
  return (new_string);
}
