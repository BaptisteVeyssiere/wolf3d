/*
** my_getnbr.c for my_getnbr.c in /home/VEYSSI_B/rendu/test
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  2 22:43:56 2015 Baptiste veyssiere
** Last update Sat Dec 12 20:43:19 2015 Baptiste veyssiere
*/

#include "prototypes.h"

int	my_getnbr(const char *str)
{
  int	i;
  int	j;
  int	limit;
  int	nbr;

  i = 0;
  nbr = 0;
  limit = 0;
  if (str[0] == '-')
    limit = 1;
  while (str[i] != 0)
    i++;
  i--;
  j = 1;
  while (i >= limit)
    {
      nbr += j * (str[i--] - 48);
      j *= 10;
    }
  if (str[0] == '-')
    nbr *= -1;
  return (nbr);
}

double		my_getdouble(const char *str)
{
  int		i;
  double	nbr;
  double	pow;
  int		limit;

  limit = 0;
  if (str[0] == '-')
    limit = 1;
  pow = 1;
  i = limit;
  while (str[i] != '.' && str[i++] != 0)
    pow *= 10;
  pow /= 10;
  i = limit;
  while (str[i] != 0)
    {
      if (str[i] == '.')
	i++;
      nbr += (pow * (str[i] - 48));
      pow /= 10;
      i++;
    }
  if (str[0] == '-')
    nbr *= -1;
  return (nbr);
}
