/*
** exec_bin.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 15:47:14 2016 Arnaud Costa
** Last update Wed Apr 13 14:01:55 2016 Arnaud Costa
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

int	do_the_pip(char **tab_cmd1, char **tab_cmd2, t_elem *data, int *find)
{
  int	tab_fd[2];
  int	pid;

  pipe(tab_fd);
  pid = fork();
  if (pid == 0)
    {
      dup2(tab_fd[1], 1);
      close(tab_fd[0]);
      execve(data->tab_path[find[0]], tab_cmd1, data->env);
    }
  else
    {
      close(tab_fd[1]);
      dup2(tab_fd[0], 0);
      execve(data->tab_path_tmp[find[1]], tab_cmd2, data->env);
      waitpid(pid, NULL, 0);
    }
  return (0);
}

int	exec_bin_pipe(char **tab_cmd1, char **tab_cmd2, t_elem *data)
{
  int	find[2];
  int	pid;

  if (tab_cmd1 == NULL || tab_cmd1[0][0] == '\n' || tab_cmd1[0][0] == '\0')
    return (-1);
  if (tab_cmd1[0][0] == '/' || tab_cmd1[0][0] == '.')
    {
      my_putstr_error("Command not found\n");
      return (-1);
    }
  find[0] = accessing_first(data);
  find[1] = accessing_second(data);
  if (find[0] != -1 && find[1] != -1)
    {
      pid = fork();
      if (pid == 0)
	do_the_pip(tab_cmd1, tab_cmd2, data, find);
      else
	waitpid(pid, NULL, 0);
    }
  else if (my_putstr_error("Command not found\n") == -1)
    return (-1);
  return (0);
}
