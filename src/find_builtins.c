/*
** find_builtins.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 17:13:44 2016 Arnaud Costa
** Last update Thu Apr 14 19:58:04 2016 Arnaud Costa
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	finde_builtins(t_elem *data)
{
  if (my_strcmp(data->tab_comande[0], "exit") == 0)
    clean_exit(data);
  else if (my_strcmp(data->tab_comande[0], "env") == 0)
    {
      print_env(data->env);
      return (0);
    }
  else if (my_strcmp(data->tab_comande[0], "cd") == 0)
    return (my_cd(data));
  else if (my_strcmp(data->tab_comande[0], "unsetenv") == 0)
    {
      my_unsetenv(data);
      return (0);
    }
  else if (my_strcmp(data->tab_comande[0], "setenv") == 0)
    {
      my_setenv(data);
      return (0);
    }
  return (1);
}

int	go_home(t_elem *data)
{
  if (my_strcmp(data->tab_comande[0], "cd") == 0
      && data->tab_comande[1] == NULL)
    {
      getcwd(data->oldpwd, 1024);
      chdir(data->home);
      getcwd(data->pwd, 1024);
      return (0);
    }
    else if (my_strcmp(data->tab_comande[0], "cd") == 0
	     && data->tab_comande[1][0] == '~')
      {
	getcwd(data->oldpwd, 1024);
	chdir(data->home);
	getcwd(data->pwd, 1024);
	return (0);
      }
  else
    return (-1);
}

int	my_cd(t_elem *data)
{
  if ((go_home(data)) == 0)
    return (0);
  else if (my_strcmp(data->tab_comande[0], "cd") == 0
	   && data->tab_comande[1][0] == '-')
    {
      chdir(data->oldpwd);
      my_strcpy(data->oldpwd, data->pwd);
      getcwd(data->pwd, 1024);
      return (0);
    }
  else
    {
      getcwd(data->oldpwd, 1024);
      if ((chdir(data->tab_comande[1])) == -1)
	my_putstr_error("no such file or directory\n");
      getcwd(data->pwd, 1024);
      return (0);
    }
  return (0);
}

void	clean_exit(t_elem *data)
{
  int	nb;

  if (data->tab_comande[1] == NULL)
    {
      free_tab(data->tab_comande);
      free_tab(data->tab_path);
      free_tab(data->env);
      free(data->home);
      exit(0);
    }
  nb = my_getnbr(data->tab_comande[1]);
  free_tab(data->tab_comande);
  free_tab(data->tab_path);
  free_tab(data->env);
  free(data->home);
  exit(nb);
}

void	print_env(char **ae)
{
  int	i;

  i = 0;
  while (ae[i] != NULL)
    {
      my_putstr(ae[i]);
      my_putchar('\n');
      i++;
    }
}
