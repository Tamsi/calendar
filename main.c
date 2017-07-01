/*
** main.c for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri Jun 30 11:32:45 2017 Tamsi Besson
** Last update Sat Jul  1 15:06:15 2017 Tamsi Besson
*/

#include "calendar.h"

t_employee employee[1];
t_meeting meeting[1];

char **parser()
{
  char *line;
  char **tab;
  int i;
  size_t size;

  line = NULL;
  tab = malloc(100 * sizeof(char *));
  i = 0;
  while (getline(&line, &size, stdin) != -1)
    {
      tab[i] = malloc(strlen(line) * sizeof(char) + 1);
      tab[i] = strcpy(tab[i], line);
      i++;
      if (strncmp(line, "END", 3) == 0)
        break;
    }
  tab[i] = NULL;
  return (tab);
}

int     main()
{
  char **tab;

  tab = parser();
  filler_emp(tab);
  disp_employee();
  return (0);
}

