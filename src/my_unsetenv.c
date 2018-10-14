/*
** my_unsetenv.c for minishell in /home/costa_d/Documents/PSU/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 31 17:17:51 2016 Arnaud Costa
** Last update Tue Apr 12 22:43:18 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

void	end_of_tab(t_elem *env, int k, char **new_env)
{
  env->env[k] = NULL;
  free_tab(env->env);
  get_env(env, new_env);
  free_tab(new_env);
}

void	my_unsetenv(t_elem *env)
{
  int	i;
  int	k;
  char	**new_env;

  i = 0;
  k = 0;
  if ((new_env = malloc(sizeof(char *) * (h_tab_env(env->env) + 1))) == NULL)
    exit(0);
  while (env->env[i] != NULL)
    {
      if ((my_strncmp(env->env[i], env->tab_comande[1],
		      my_strlen(env->tab_comande[1]))) == 0)
	i++;
      if (env->env[i] == NULL)
	return (end_of_tab(env, k, new_env));
      new_env[k] = malloc(sizeof(char) * (my_strlen(env->env[i]) + 1));
      new_env[k] = my_strcpy(new_env[k], env->env[i]);
      i++;
      k++;
    }
  new_env[k] = NULL;
  free_tab(env->env);
  get_env(env, new_env);
  free_tab(new_env);
}
