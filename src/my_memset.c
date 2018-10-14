/*
** thomas_show.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sat Mar 19 14:46:39 2016 Arnaud Costa
** Last update Wed Mar 30 14:03:47 2016 Arnaud Costa
*/

#include "minishell.h"

void	my_memset(char *tab, char set, int size)
{
  while (size >= 0)
    {
      tab[size] = set;
      size--;
    }
}
