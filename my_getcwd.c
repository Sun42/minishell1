/*
** my_getcwd.c for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:16:42 2008 christophe sundas
** Last update Thu Nov 20 20:22:49 2008 christophe sundas
*/

#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef HAVE_NOT_DIRENT_H
# include <sys/dir.h>
#else
# include <dirent.h>
#endif
#include "my.h"
#include "mysh.h"

char	*my_getcwd(void)
{

  char	**str;
  int	ino[MAXPATH];
  char	*full_path;
  char	*dname;
  int	i;

  if ((full_path = malloc(sizeof(*full_path) * MAXPATH)) == NULL)
    exit(-1);
  i = mk_ino(ino);
  str = mk_str(i + 1);
  my_strcpy(full_path, "/");
  while (i > 0)
    {
      if ((dname = get_dirname(ino[i - 1], str[i])) != NULL)
	{
	  my_strcat(full_path, dname);
	  if (i > 1)
	    my_strcat(full_path, "/");
      }
      i--;
    }
  my_free_tab(str);
  return (full_path);
}

char	*get_dirname(unsigned int ino, char *str)
{
  DIR			*rep;
#ifdef HAVE_NOT_DIRENT_H
  struct direct		*s_rep;
# else
  struct dirent		*s_rep;
#endif
  struct stat		s_stat;
  char			*found;

  rep = opendir(str);
  while ((s_rep = readdir(rep)))
    {
      if ((stat(mk_fullpath(str, s_rep->d_name), &s_stat)) != -1)
	{
	  if (s_stat.st_ino == ino)
	    {
	      found = my_strdup(s_rep->d_name);
	      closedir(rep);
	      return (found);
	    }
	}
    }
  closedir(rep);
  return (NULL);
}

/*
** en fonction du nombre d'inodes, construit un tableau de ./../../
*/
char	**mk_str(int nb)
{
  char	**str;
  int	i;

  i = 1;
  if ((str = malloc(sizeof(*str) * nb + 1)) == NULL)
    exit(-1);
  if ((str[0] = malloc(sizeof(**str) * 2)) == NULL)
    exit(-1);
  my_strcpy(str[0], ".");
  while (i < nb)
    {
      if ((str[i] = malloc(sizeof(**str) * MAXPATH)) == NULL)
	exit(-1);
      my_strcpy(str[i], str[i- 1]);
      my_strcat(str[i], "/..");
      i++;
    }
  str[i] = 0;
  return (str);
}

/*
** rempli un tableau dinode des reps de cwd 
*/
int		mk_ino(int ino[MAXPATH])
{
  ino_t		root_ino;
  ino_t		cur_ino;
  struct stat	s_stat;
  char		str[MAXPATH];
  int		i;

  i = 0;
  my_strcpy(str, ".");
  if (stat("/", &s_stat) != 0)
    exit(-1);
  root_ino = s_stat.st_ino;
  if (lstat(str, &s_stat) != 0)
    exit(-1);
  cur_ino = s_stat.st_ino;
  ino[i] = s_stat.st_ino;
  while (root_ino != cur_ino)
    {
      i++;
      my_strcat(str, "/..");
      if (lstat(str, &s_stat) != 0)
      	  exit(-1);
      cur_ino = s_stat.st_ino;
      ino[i] = s_stat.st_ino;
    }
  return (i);
}
