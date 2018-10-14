/*
** tab_maker.c for minishell in /home/costa_d/Documents/PSU/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sat Apr  2 18:00:05 2016 Arnaud Costa
** Last update Sat Apr  9 15:31:12 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

char	**tab_maker(char **tab_cmd, int pos_curs, int last_stop)
{
  char	**new_tab_cmd;
  int	h_tab;
  int	i;

  i = 0;
  h_tab = 0;
  h_tab = pos_curs - last_stop;
  if ((new_tab_cmd = malloc(sizeof(char *) * (h_tab + 1))) == NULL)
    return (NULL);
  while (last_stop < pos_curs)
    {
      if ((new_tab_cmd[i] = malloc(sizeof(char *) *
				   (my_strlen(tab_cmd[last_stop]) + 1))) == NULL)
	return (NULL);
      new_tab_cmd[i] = my_strcpy(new_tab_cmd[i], tab_cmd[last_stop]);
      last_stop++;
      i++;
    }
  new_tab_cmd[i] = NULL;
  return (new_tab_cmd);
}
