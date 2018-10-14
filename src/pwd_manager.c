/*
** pwd_manager.c for minishell in /home/costa_d/Documents/PSU/minishell2/PSU_2015_minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Apr 10 12:27:24 2016 Arnaud Costa
** Last update Tue Apr 12 22:15:53 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

void	get_pwd(t_elem *data)
{
  if ((data->pwd = malloc(sizeof(char) * 1024)) == NULL)
    exit(0);
  if ((data->oldpwd = malloc(sizeof(char) * 1024)) == NULL)
    exit(0);
}
