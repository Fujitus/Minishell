/*
** accessing.c for minishell in /home/costa_d/Documents/PSU/minishell2/PSU_2015_minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 12 22:02:00 2016 Arnaud Costa
** Last update Tue Apr 12 22:02:02 2016 Arnaud Costa
*/

#include <unistd.h>
#include "minishell.h"

int	accessing_first(t_elem *data)
{
  int	i;
  int	find;

  i = 0;
  while (data->tab_path[i] != '\0')
    {
      find = access(data->tab_path[i], F_OK | X_OK);
	if (find == 0)
	  return (i);
      i++;
    }
  return (-1);
}

int	accessing_second(t_elem *data)
{
  int	i;
  int	find;

  i = 0;
  while (data->tab_path_tmp[i] != '\0')
    {
      find = access(data->tab_path_tmp[i], F_OK | X_OK);
      if (find == 0)
	return (i);
      i++;
    }
  return (-1);
}
