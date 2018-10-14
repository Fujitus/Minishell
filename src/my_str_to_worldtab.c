/*
** my_str_to_worldtab2.c for minishell2 in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 09:38:38 2016 Arnaud Costa
** Last update Thu Apr 14 20:37:51 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "my_str_to_worldtab.h"

int	h_tab(char *str, char c)
{
  int	i;
  int	htab;

  i = 0;
  htab = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
        htab++;
      i++;
    }
  return (htab);
}

void	init_struct_data(t_tab *tab)
{
  tab->nb_tab = 0;
  tab->z = 0;
  tab->nb = 0;
}

void	increment(t_tab *data, char c, char *str)
{
  while (str[data->nb] != c && str[data->nb] != '\0')
    {
      data->tab_i++;
      data->nb++;
    }
}

char	**put_in_tab(char *str, char c)
{
  t_tab	data;

  init_struct_data(&data);
  if (str == NULL)
    return (NULL);
  data.htab = h_tab(str, c);
  if ((data.tab = malloc(sizeof(char *) * (data.htab + 2))) == NULL)
      return (NULL);
  while (data.nb_tab <= data.htab)
    {
      data.tab_j = 0;
      data.tab_i = 0;
      increment(&data, c, str);
      data.tab[data.nb_tab] = malloc(data.tab_i + 1);
      while (str[data.z] != c && str[data.z] != '\0')
      	data.tab[data.nb_tab][data.tab_j++] = str[data.z++];
      data.tab[data.nb_tab][data.tab_j] = '\0';
      data.nb_tab++;
      data.z++;
      data.nb++;
    }
  data.tab[data.nb_tab] = NULL;
  return (data.tab);
}
