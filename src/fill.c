/*
** fill.c for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri Jun 30 13:02:54 2017 Tamsi Besson
** Last update Sat Jul  1 23:24:46 2017 Tamsi Besson
*/

#include "calendar.h"

static t_meeting fill_meeting(char **parsed_line)
{
  t_meeting meet;
  int i;
  int k;

  k = 0;
  while (parsed_line[k])
  	k++;
  if (k < 2)
  	exit (84);
  meet.place = parsed_line[0];
  meet.date = parsed_line[1];
  meet.zipcode = parsed_line[2];
  meet.participants = malloc(10 * sizeof(char *));
  i = 3;
  k = 0;
  while (parsed_line[i])
    {
      meet.participants[k] = malloc(strlen(parsed_line[i]) * sizeof(char) + 1);
      strcpy(meet.participants[k++], parsed_line[i++]);
    }
  meet.participants[k - 1][strlen(meet.participants[k - 1]) - 1] = '\0';
  meet.participants[k] = NULL;
  return (meet);
}

static t_employee fill_employee(char **parsed_line)
{
  t_employee emp;
  int k;

  k = 0;
  while (parsed_line[k])
  	k++;
  if (k < 4)
  	exit (84);
  emp.last_name = parsed_line[0];
  emp.first_name = parsed_line[1];
  emp.position = parsed_line[2];
  emp.id = parsed_line[3];
  emp.zipcode = parsed_line[4];
  emp.zipcode[strlen(emp.zipcode) - 1] = '\0';
  return (emp);
}

void filler_emp(char **tab)
{
  int i;
  int j;

  i = 0;
  j = 0;
  filler_meet(tab);
  disp_meeting();
  while (tab[i])
    {
      if (strncmp(tab[i], "new_employee", 12) == 0)
        employee[j++] = fill_employee(my_str_to_wordtab(tab[i], ' '));
      if (strncmp(tab[i], "fire", 4) == 0)
        fire(tab[i]);
      info_employees(tab, i);
      i++;
    }
}

void filler_meet(char **tab)
{
  int i;
  int k;

  i = 0;
  k = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "new_meeting", 11) == 0)
        meeting[k++] = fill_meeting(my_str_to_wordtab(tab[i], ' '));
      if (strncmp(tab[i], "invite", 6) == 0)
        invite(tab[i]);
      if (strncmp(tab[i], "info_meetings sortById", 23) == 0)
        sort_meeting_by_id();
      i++;
    }
}
