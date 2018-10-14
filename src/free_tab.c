/*
** free_tab.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Fri Mar 18 12:49:31 2016 Arnaud Costa
** Last update Tue Apr 12 22:13:55 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

void	free_tab(char **tab)
{
  int	i;

  if (tab == NULL)
    return ;
  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
