/*
** exec_bin.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 15:47:14 2016 Arnaud Costa
** Last update Mon May  8 13:54:17 2017 Arnaud Costa
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "minishell.h"

int	exec_finder(char **tab_cmd, char **tab_path, char **ae)
{
  int	pid;
  int	status;
  int	i;
  int	find;

  i = 0;
  while (tab_path && tab_path[i] != '\0')
    {
      find = access(tab_path[i], F_OK | X_OK);
      if (find == 0)
        {
          pid = fork();
          if (pid == 0)
	    {
	      printf("%s - %s - %s\n", tab_path[i], tab_cmd[0], tab_cmd[1]);
	      execve(tab_path[i], tab_cmd, ae);
	    }
          else
            waitpid(pid, &status, 0);
          return (0);
        }
      i++;
    }
  if (find == -1 && my_putstr_error("Command not found\n") == -1)
    return (-1);
  return (status);
}

int	exec_bin(char **tab_cmd, char **tab_path, char **ae)
{
  int	status;

  if (tab_cmd[0] == NULL || tab_cmd[0][0] == '\n' || tab_cmd[0][0] == '\0')
    return (-1);
  if (tab_path == NULL || tab_cmd[0][0] == '/' || tab_cmd[0][0] == '.')
    {
      my_putstr_error("Command not found\n");
      return (-1);
    }
  status = exec_finder(tab_cmd, tab_path, ae);
  if (status == 11 || status == 139 || status == SIGSEGV)
    {
      my_putstr_error("Segmentation fault\n");
      return (-1);
    }
  return (0);
}
