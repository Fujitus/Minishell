/*
** pip_manager.c for minishell in /home/costa_d/minishell2/PSU_2015_minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Apr 10 13:15:35 2016 Arnaud Costa
** Last update Thu Apr 14 19:09:29 2016 Arnaud Costa
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int	pip_manager(t_elem *data, int i, int last_stop)
{
  char  **tab_cmd_tmp;
  char  **tab_cmd_tmp2;
  char  *path;

  tab_cmd_tmp = tab_maker(data->tab_comande, i, last_stop);
  put_slash(data, tab_cmd_tmp);
  last_stop = i + 1;
  path = epur_env(finde_path(data->env));
  data->tab_path_tmp = put_in_tab(path, ':');
  while (data->tab_comande[i])
    i++;
  tab_cmd_tmp2 = tab_maker(data->tab_comande, i, last_stop);
  put_slash_tmp(data, tab_cmd_tmp2);
  exec_bin_pipe(tab_cmd_tmp, tab_cmd_tmp2, data);
  free(path);
  last_stop = i + 1;
  path = epur_env(finde_path(data->env));
  data->tab_path_tmp = put_in_tab(path, ':');
  free_tab(tab_cmd_tmp);
  free_tab(tab_cmd_tmp2);
  if (i == h_tab_env(data->tab_comande))
    i--;
  return (i);
}

int	right_manager(t_elem *data, int i, int last_stop)
{
  char	**tab_cmd_tmp;
  char	**tab_cmd_tmp2;
  char	*path;

  tab_cmd_tmp = tab_maker(data->tab_comande, i, last_stop);
  put_slash(data, tab_cmd_tmp);
  last_stop = i + 1;
  path = epur_env(finde_path(data->env));
  data->tab_path_tmp = put_in_tab(path, ':');
  while (data->tab_comande[i])
    i++;
  tab_cmd_tmp2 = tab_maker(data->tab_comande, i, last_stop);
  put_slash_tmp(data, tab_cmd_tmp2);
  to_the_exec(tab_cmd_tmp, tab_cmd_tmp2, data);
  free(path);
  last_stop = i + 1;
  path = epur_env(finde_path(data->env));
  data->tab_path_tmp = put_in_tab(path, ':');
  free_tab(tab_cmd_tmp);
  free_tab(tab_cmd_tmp2);
  if (i == h_tab_env(data->tab_comande))
    i--;
  return (i);
}

int	to_the_exec(char **tab_cmd1, char **tab_cmd2, t_elem *data)
{
  int	find;

  if (tab_cmd1 == NULL || tab_cmd1[0][0] == '\n' || tab_cmd1[0][0] == '\0')
    return (-1);
  if (tab_cmd1[0][0] == '/' || tab_cmd1[0][0] == '.')
    {
      my_putstr_error("Command not found\n");
      return (-1);
    }
  find = accessing_first(data);
  do_the_exec(tab_cmd1, tab_cmd2, data, find);
  return (0);
}

int	do_the_exec(char **tab_cmd1, char **tab_cmd2, t_elem *data, int find)
{
  int	pid;
  int	fd;

  pid = fork();
  if (pid == 0)
    {
      fd = open(tab_cmd2[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
      dup2(fd, 1);
      close(fd);
      execve(data->tab_path[find], tab_cmd1, data->env);
    }
  else
    waitpid(pid, NULL, 0);
  return (0);
}
