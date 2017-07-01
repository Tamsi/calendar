/*
** employee.c for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sat Jul  1 14:26:30 2017 Tamsi Besson
** Last update Sat Jul  1 16:01:58 2017 Tamsi Besson
*/

#include "calendar.h"

void    disp_employee()
{
  int   i;

  i = 0;
  while (employee[i].id)
    {
      printf("*\n%s %s\n", employee[i].first_name, employee[i].last_name);
      printf("position: %s\n", employee[i].position);
      printf("city: %s\n", employee[i].id);
      i++;
    }
}

void            sort_by_name()
{
  int           i;
  int           j;
  t_employee    temp;

  i = 0;
  while (employee[i].id)
    {
      j = 0;
      while (employee[j + 1].id)
        {
          if (strcmp(employee[j].last_name, employee[j + 1].last_name) > 0 ||
            (strcmp(employee[j].last_name, employee[j + 1].last_name) == 0 &&
              strcmp(employee[j].first_name, employee[j + 1].first_name) > 0))
            {
              temp = employee[j];
              employee[j] = employee[j + 1];
              employee[j + 1] = temp;
            }
          j++;
        }
      i++;
    }
}

void    sort_by_zip()
{
  int   i;
  int   j;
  t_employee  temp;

  i = 0;
  while (employee[i].id)
    {
      j = 0;
      while (employee[j + 1].id)
  {
    if (atoi(employee[j].zipcode) > atoi(employee[j + 1].zipcode))
      {
        temp = employee[j];
        employee[j] = employee[j + 1];
        employee[j + 1] = temp;
      }
    if (atoi(employee[j].zipcode) == atoi(employee[j + 1].zipcode))
      sort_by_name();
    j++;
  }
      i++;
    }
}

void    sort_by_id()
{
  int   i;
  int   j;
  t_employee  temp;

  i = 0;
  while (employee[i].id)
    {
      j = 0;
      while (employee[j + 1].id)
  {
    if (strcmp(employee[j].id, employee[j + 1].id) > 0)
      {
        temp = employee[j];
        employee[j] = employee[j + 1];
        employee[j + 1] = temp;
      }
    if (strcmp(employee[j].id, employee[j + 1].id) == 0)
      sort_by_name();
    j++;
  }
      i++;
    }
}

void    sort_by_job()
{
  int   i;
  int   j;
  t_employee  temp;

  i = 0;
  while (employee[i].id)
    {
      j = 0;
      while (employee[j + 1].id)
  {
    if (strcmp(employee[j].position, employee[j + 1].position) > 0)
      {
        temp = employee[j];
        employee[j] = employee[j + 1];
        employee[j + 1] = temp;
      }
    if (strcmp(employee[j].position, employee[j + 1].position) == 0)
      sort_by_name();
    j++;
  }
      i++;
    }
}
