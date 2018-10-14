/*
** main.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 11:14:00 2016 Arnaud Costa
** Last update Tue Apr 12 22:03:03 2016 Arnaud Costa
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	find_env(char **ae)
{
  int	i;

  i = 0;
  while (ae[i])
    i++;
  return (i);
}

int	processus(char **ae)
{
  t_elem	data;
  char		*path;
  int		ret_built;
  int		ret_relatif;

  get_env(&data, ae);
  get_pwd(&data);
  while (42)
    {
      data.home = epur_env(finde_home(data.env));
      path = epur_env(finde_path(data.env));
      data.tab_path = put_in_tab(path, ':');
      data.tab_comande = get_commande();
      ret_built = finde_builtins(&data);
      ret_relatif = exec_relative_path(data.tab_comande, data.env);
      if (ret_built != 0 && ret_relatif != 0)
      	minishell_manager(&data);
      free(path);
      free_tab(data.tab_path);
      free_tab(data.tab_comande);
    }
}

int	main(int ac, char **av, char **ae)
{
  (void)ac;
  (void)av;
  int	env_error;

  env_error = find_env(ae);
  if (ae[0] == NULL || env_error == 0)
    return (-1);
  processus(ae);
  return (0);
}
