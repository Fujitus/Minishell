/*
** tools_error.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Mar 20 16:21:47 2016 Arnaud Costa
** Last update Tue Apr 12 22:05:15 2016 Arnaud Costa
*/

#include <unistd.h>
#include "minishell.h"

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar_error(str[i]);
      i++;
    }
  return (-1);
}
