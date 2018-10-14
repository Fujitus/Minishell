/*
** update_path.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 13:53:15 2016 Arnaud Costa
** Last update Tue Apr 12 22:17:17 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

void	put_slash_tmp(t_elem *data, char **tab_comande)
{
  int	i;
  int	j;

  if (data->tab_path_tmp == NULL)
    return ;
  j = 0;
  while (data->tab_path_tmp[j] != NULL)
    {
      i = 0;
      while (data->tab_path_tmp[j][i] != '\0')
	i++;
      if (data->tab_path_tmp[j][i - 1] == '/')
	data->tab_path_tmp[j] = put_bin_name(data->tab_path_tmp[j],
					     tab_comande[0]);
      else
	data->tab_path_tmp[j] = put_slash_bin_name(data->tab_path_tmp[j],
						   tab_comande[0]);
      j++;
    }
}
