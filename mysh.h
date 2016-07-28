/*
** mysh.h for mysh in /u/all/sundas_c/cu/rendu/unix/projet/minishell0.3
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 20 17:20:28 2008 christophe sundas
** Last update Thu Nov 20 20:05:00 2008 christophe sundas
*/

#ifndef __MY_SH_H__
# define __MY_SH_H__

#define MSG_GOODBYE "Bye Bye"
#define MAXPATH 256

/*
** Minishell.h
*/
void	minishell1(void);
void	analyse_cmd(char **cmd, char ***my_env);
char	**my_get_env();
void	handler(int sig);

/*
** cmd_to_wordtab.h
*/
char	**cmd_to_wordtab(char *str);
int	word_len(char *str);
int	char_isprintable(char c);
int	my_nb_word(char *str);

/*
** utils_tab1.h
*/
char	**add_line(char **my_env, char *new_line);
char	**delete_line(char **my_env, int indice);
char	**change_line(char **my_env, char *new_line, int indice);

/*
** utils_tab2.h
*/
int	my_tab_size(char **tab);
void	my_free_tab(char **tab);
void	my_free_tab2(char **tab);

/*
** utils_str.c
*/
int	exist_char(char *str, char c);
char	*mk_line(char **cmd);
char	*mk_line2(char *label, char *value);
char	*eval_tild(char **my_env, char *path);

/*
** utils_label.h
*/
int	exist_label(char *label, char **my_env);
char	*del_label(char *line, char *label);
char	*get_label(char **my_env, int indice);
int	label_len(char *line);
int	find_indice(char **my_env, char *label);

/*
** utils_label2.h
*/
char	*recup_line(char *label, char **my_env);
char	*get_label2(char *line);

/*
** Built-in.h
*/
int	is_builtin(char **cmd);
char	**exec_builtin(char **my_env, char **cmd);

/*
** my_setenv.h
*/
char	**my_setenv(char **my_env, char **cmd);
char	**exec_setenv(char **my_env, char *line);

/*
** my_unsetenv
*/
char	**my_unsetenv(char **my_env, char **cmd);
char	**exec_unsetenv(char **my_env, char *label);

/*
** my_env.h
*/
void	env(char **my_env, char **cmd);
int	count_value(char **cmd);
char	**get_my_env(char **my_env);

/*
** my_cd.h
*/
char	**my_cd(char **my_env, char **cmd);
int	check_cmd_error(char **cmd);

/*
** my_getcwd.h
*/
char	*my_getcwd(void);
char	*get_dirname(unsigned int ino, char *str);
char	**mk_str(int nb);
int	mk_ino(int ino[MAXPATH]);

/*
** exec_cmd.h
*/
void	exec_cmd(char **cmd, char **my_env);
char	*find_binpath(char **cmd, char **my_env);
char	*recup_goodpath(char **cmd, char *pathline);
char	*mk_fullpath(char *str1, char *str2);

/*
** str_to_wordtab2.c
*/
char	**my_str_to_wordtab2(char *str, char delimiteur);
int	count_words2(char *str, char delimiteur);
int	word_len2(char *str, char delimiteur);

#endif
