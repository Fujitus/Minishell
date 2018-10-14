/*
** my_setenv.c for minishell in /home/costa_d/Documents/PSU/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Fri Apr  1 19:58:52 2016 Arnaud Costa
** Last update Tue Apr 12 22:19:41 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

void	my_setenv(t_elem *env)
{
  int	i;
  int	ret;

  i = 0;
  if (env->tab_comande[1] == NULL)
    return ;
  if (env->tab_comande[1][0] == '\n')
    return ;
  while (env->env[i] != NULL)
    {
      ret = my_strncmp(env->tab_comande[1], env->env[i],
		       my_strlen(env->tab_comande[1]));
      if (ret == 0)
	{
	  update_env(env, i);
	  return ;
	}
      i++;
    }
  if (ret == -1)
    add_tab_env(env);
  return ;
}

char	*line_env_maker(t_elem *data)
{
  int	i;
  int	j;
  char	*env_line;

  i = 0;
  j = 0;
  if ((env_line = malloc(sizeof(char) * (my_strlen(data->tab_comande[1])
					 + my_strlen(data->tab_comande[2]) + 3))) == NULL)
      return (NULL);
  while (i != my_strlen(data->tab_comande[1]))
    {
      env_line[i] = data->tab_comande[1][j];
      i++;
      j++;
    }
  env_line[i] = '=';
  i++;
  j = 0;
  while (data->tab_comande[2][j] != '\0')
    env_line[i++] = data->tab_comande[2][j++];
  env_line[i] = '\0';
  return (env_line);
}

void	copy_new(t_elem *env, int i, char **new_env)
{
  if (env->tab_comande[2] == NULL)
    {
      if ((new_env[i] = malloc(sizeof(char) *
			       (my_strlen(env->tab_comande[1]) + 2))) == NULL)
        return ;
      my_strcpy(new_env[i], mini_line(env));
    }
  else
    {
      if ((new_env[i] = malloc(sizeof(char) *
			       (my_strlen(env->tab_comande[2]) + 2))) == NULL)
        return ;
      my_strcpy(new_env[i], line_env_maker(env));
    }
}

void	add_tab_env(t_elem *env)
{
  int	i;
  char	**new_env;

  i = 0;
  if ((new_env = malloc(sizeof(char *) * (h_tab_env(env->env) + 3))) == NULL)
    return ;
  while (env->env[i] != NULL)
    {
      if ((new_env[i] = malloc(sizeof(char) *
			       (my_strlen(env->env[i]) + 2))) == NULL)
	return ;
      my_strcpy(new_env[i], env->env[i]);
      i++;
    }
  copy_new(env, i, new_env);
  i++;
  new_env[i] = NULL;
  free(env->env);
  get_env(env, new_env);
  free(new_env);
}

void	update_env(t_elem *env, int i)
{
  int	j;
  int	curs_str;
  int	max;

  j = 0;
  curs_str = 0;
  while (env->env[i][j] != '=')
    j++;
  j++;
  if (env->tab_comande[2] == NULL)
    {
      max = my_strlen(env->env[i]);
      while (j != max)
	env->env[i][j++] = '\0';
      return ;
    }
  else
    {
      while (env->tab_comande[2][curs_str] != '\0')
	env->env[i][j++] = env->tab_comande[2][curs_str++];
      while (env->env[i][j] != '\0')
	env->env[i][j++] = '\0';
    }
}
