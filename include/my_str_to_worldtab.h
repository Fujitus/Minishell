/*
** my_str_to_worldtab.h for minishell in /home/costa_d/Documents/PSU/minishell2/include
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Mar 20 15:34:27 2016 Arnaud Costa
** Last update Sun Mar 20 15:51:35 2016 Arnaud Costa
*/

#ifndef STR_TO_WORDTAB_H
# define STR_TO_WORDTAB_H

typedef struct	s_tab
{
  int		nb;
  int		tab_i;
  int		tab_j;
  int		nb_tab;
  int		htab;
  int		z;
  char		**tab;
}		t_tab;

void		init_struct_data(t_tab *data);
char		**put_in_tab(char *str, char c);
int		h_tab(char *str, char c);

#endif /* !STR_TO_WORDTAB */
