/*
** update_path.c for minishell in /home/costa_d/Documents/PSU/minishell2
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu Mar 17 13:53:15 2016 Arnaud Costa
** Last update Tue Apr 12 22:16:46 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "minishell.h"

void	put_slash(t_elem *data, char **tab_comande)
{
  int	i;
  int	j;

  if (data->tab_path == NULL)
    return ;
  j = 0;
  while (data->tab_path[j] != NULL)
    {
      i = 0;
      while (data->tab_path[j][i] != '\0')
	i++;
      if (data->tab_path[j][i - 1] == '/')
	data->tab_path[j] = put_bin_name(data->tab_path[j],
					 tab_comande[0]);
      else
	data->tab_path[j] = put_slash_bin_name(data->tab_path[j], tab_comande[0]);
      j++;
    }
}

char	*put_slash_bin_name(char *str1, char *str2)
{
  char	*new_str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  new_str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
  if (new_str == NULL)
    return (NULL);
  while (str1 && str1[i] != '\0')
    {
      new_str[i] = str1[i];
      i++;
    }
  new_str[i] = '/';
  i++;
  while (str2 && str2[j] != '\0')
    {
      new_str[i] = str2[j];
      i++;
      j++;
    }
  free(str1);
  new_str[i] = '\0';
  return (new_str);
}

char	*put_bin_name(char *str1, char *str2)
{
  char	*new_str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((new_str = malloc(my_strlen(str1) + my_strlen(str2) + 2)) == NULL)
    return (NULL);
  while (str1 && str1[i] != '\0')
    {
      new_str[i] = str1[i];
      i++;
    }
  while (str2 && str2[j] != '\0')
    {
      new_str[i] = str2[j];
      i++;
      j++;
    }
  free(str1);
  new_str[i] = '\0';
  return (new_str);
}
