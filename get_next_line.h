/*
** get_next_line.h for get next line in /u/all/sundas_c/cu/rendu/unix/projet/get_next_line
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 13 22:39:58 2008 christophe sundas
** Last update Wed Nov 19 20:10:18 2008 christophe sundas
*/
#ifndef __GET_NEXT_LINE_H__
#define __GET_NEXT_LINE_H__
#define BUFFSIZE 48

char	*my_charcat(char *ligne, char c);
char	*del_bckslshN(char *ligne);
char	*get_next_line(int fd);

#endif
