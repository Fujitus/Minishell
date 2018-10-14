/*
** get_env.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Fri Mar 18 11:22:35 2016 Arnaud Costa
** Last update Fri Apr  8 18:51:11 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

int	h_tab_env(char **ae)
{
  int	i;

  i = 0;
  while (ae && ae[i] != NULL)
    i++;
  return (i);
}

void	get_env(t_elem *env, char **ae)
{
  int	i;
  int	j;

  i = 0;
  env->env = malloc(sizeof(char *) * (h_tab_env(ae) + 2));
  if (env->env == NULL)
    return ;
  while (ae[i] != '\0')
    {
      j = 0;
      env->env[i] = malloc(sizeof(char) * (my_strlen(ae[i]) + 2));
      if (env->env[i] == NULL)
	return ;
      while (ae[i][j] != '\0')
	{
	  env->env[i][j] = ae[i][j];
	  j++;
	}
      env->env[i][j] = '\0';
      i++;
    }
  env->env[i] = NULL;
}
