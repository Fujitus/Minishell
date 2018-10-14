/*
** minishell_manager.c for minishell in /home/costa_d/Documents/PSU/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sat Apr  2 17:46:10 2016 Arnaud Costa
** Last update Thu Apr 14 19:09:56 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

void	simple_exec(t_elem *data, int i, int last_stop)
{
  char  **tab_cmd_tmp;
  char  *path;

  tab_cmd_tmp = tab_maker(data->tab_comande, i, last_stop);
  put_slash(data, tab_cmd_tmp);
  exec_bin(tab_cmd_tmp, data->tab_path, data->env);
  free_tab(data->tab_path);
  free_tab(tab_cmd_tmp);
  path = epur_env(finde_path(data->env));
  data->tab_path = put_in_tab(path, ':');
  free(path);
}

void	sep_manager(t_elem *data, int i, int last_stop)
{
  char  **tab_cmd_tmp;
  char  *path;

  tab_cmd_tmp = tab_maker(data->tab_comande, i, last_stop);
  put_slash(data, tab_cmd_tmp);
  exec_bin(tab_cmd_tmp, data->tab_path, data->env);
  free_tab(data->tab_path);
  free_tab(tab_cmd_tmp);
  path = epur_env(finde_path(data->env));
  data->tab_path = put_in_tab(path, ':');
  free(path);
}

void	minishell_manager(t_elem *data)
{
  int	i;
  int	last_stop;

  i = 0;
  last_stop = 0;
  while (data->tab_comande[i] != '\0')
    {
      if (data->tab_comande[i][0] == ';')
        {
	  sep_manager(data, i, last_stop);
      	  last_stop = i + 1;
        }
      else if (data->tab_comande[i][0] == '|')
      	{
	  i = pip_manager(data, i, last_stop);
	  last_stop = i + 1;
      	}
      else if (data->tab_comande[i][0] == '>')
        {
          i = right_manager(data, i, last_stop);
          last_stop = i + 1;
        }
      i++;
    }
  simple_exec(data, i, last_stop);
}
