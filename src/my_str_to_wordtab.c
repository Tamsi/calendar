/*
** my_str_to_wordtab.c for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016/src
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri Jun 30 12:09:34 2017 Tamsi Besson
** Last update Fri Jun 30 14:28:37 2017 Tamsi Besson
*/

#include "calendar.h"

static char    *fill_tab(char *str, char *dest, int debut, char sep)
{
  int   i;

  i = 0;
  while ((str[debut] != sep) && (str[debut] != '\0'))
    {
      dest[i] = str[debut];
      debut++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int     count_for_malloc(char *str, int bg, char sep)
{
  int   i;

  i = 0;
  while (str[bg] != sep && (str[bg] != '\0'))
    {
      bg++;
      i++;
    }
  return (i);
}

char    **my_str_to_wordtab(char *str, char sep)
{
  int   i;
  int   j;
  char  car_prec;
  char  **tab;

  i = 0;
  j = 0;
  tab = malloc((word_count(str) + 1) * sizeof(tab));
  while (str[i] != '\0')
    {
      if ((car_prec == sep) && (str[i] != sep))
        {
          tab[j] = malloc(count_for_malloc(str, i, sep) * sizeof(**tab));
          fill_tab(str, tab[j], i, sep);
          j++;
        }
      car_prec = str[i];
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
