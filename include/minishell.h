/*
** minishell.h for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 11:00:09 2016 Arnaud Costa
** Last update Thu Apr 14 19:11:30 2016 Arnaud Costa
*/

#include "get_next_line.h"
#include "my_str_to_worldtab.h"

#ifndef	MINISHELL_H_
# define MINISHELL_H_

#  ifndef PROMPT
#   define PROMPT "$> "
#endif /* !PROMPT */

typedef struct	s_elem
{
  char		**env;
  char		**tab_comande;
  char		**tab_path;
  char		**tab_path_tmp;
  char		*home;
  char		*pwd;
  char		*oldpwd;
}		t_elem;

void	minishell_manager(t_elem *data);
char	**tab_maker(char **tab_cmd, int pos_cur, int last_stop);
void	my_putchar(char c);
void	my_putchar_error(char c);
void	my_putstr(char *str);
void	my_memset(char *tab, char set, int size);
int	my_putstr_error(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
char	*epur_str(char *str);
void	my_prompt();
char	*finde_path(char **ae);
char	*finde_home(char **ae);
char	**get_commande();
char	*epur_env(char *str);
void	put_slash(t_elem *data, char **tab_comande);
void	put_slash_tmp(t_elem *data, char **tab_comande);
char	*put_slash_bin_name(char *str1, char *str2);
char	*put_bin_name(char *str1, char *str2);
int	exec_bin(char **tab_cmd, char **tab_path, char **ae);
int	finde_builtins(t_elem *data);
void	print_env(char **ae);
void	get_env(t_elem *env, char **ae);
void	my_setenv(t_elem *env);
void	update_env(t_elem *env, int i);
void	add_tab_env(t_elem *env);
void	my_unsetenv(t_elem *env);
int	h_tab_env(char **ae);
void	free_tab(char **rab);
int	exec_relative_path(char **tab_bin, char **ae);
void	clean_exit(t_elem *data);
void	my_memset(char *tab, char set, int size);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strcpy(char *dest, char *src);
void	print_tab(char **tab);
int	exec_bin_pipe(char **tab_cmd1, char **tab_cmd2, t_elem *data);
int	my_getnbr(char *str);
int	my_cd(t_elem *data);
int	pip_manager(t_elem *data, int i, int last_stop);
int	right_manager(t_elem *data, int i, int last_stop);
int	accessing_first(t_elem *data);
int	accessing_second(t_elem *data);
char	*add_space(char *cmd);
void	get_pwd(t_elem *data);
void	cpy_it(char *new_cmd, char *cmd, int *i, int *j);
void	copy_new(t_elem *env, int i, char **new_env);
char	*mini_line(t_elem *data);
int	to_the_exec(char **tab_cmd_tmp, char **tab_cmd_tmp2, t_elem *data);
int     do_the_exec(char **tab_cmd1, char **tab_cmd2, t_elem *data, int find);

#endif /* !MINISHELL_H_ */
