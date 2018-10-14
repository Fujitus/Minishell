/*
** my_getnbr.c for minishell in /home/costa_d/minishell2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Fri Apr  8 12:42:22 2016 Arnaud Costa
** Last update Thu Apr 14 20:39:22 2016 Arnaud Costa
*/

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	type;

  type = 1;
  i = 0;
  res = 0;
  if (str[0] == '-')
    {
      i++;
      type = 0;
    }
  while (str[i] != '\0')
    {
      str[i] = str[i] - 48;
      res = res + str[i];
      if (str[i + 1] != '\0')
        res = res * 10;
      i++;
    }
  if (type == 0)
    res = res * -1;
  return (res);
}
