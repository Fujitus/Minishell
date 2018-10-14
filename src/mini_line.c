/*
** mini_line.c for minishell in /home/costa_d/Documents/PSU/minishell2/PSU_2015_minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 12 22:18:40 2016 Arnaud Costa
** Last update Tue Apr 12 22:19:23 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

char	*mini_line(t_elem *data)
{
  char	*line;
  int	i;

  i = 0;
  line = malloc(sizeof(char) * (my_strlen(data->tab_comande[1]) + 2));
  while (data->tab_comande[1][i])
    {
      line[i] = data->tab_comande[1][i];
      i++;
    }
  line[i] = '=';
  line[i + 1] = '\0';
  return (line);
}
