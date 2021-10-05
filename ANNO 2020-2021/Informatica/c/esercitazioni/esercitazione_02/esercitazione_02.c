/*esercizio con le matrici e puntatori*/

#include <stdio.h>

static char daytab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31}, 
                             {0,31,29,31,30,31,30,31,31,30,31,30,31}}

int day_of_the_year(int yer, int month, int day){   //ci dice il numero di giorno nell'anno in base alla data che mettiamo

    int i, leap;
    leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    for(i=1; i<month; i++)
        day += daytab[leap][i];
    return day;

}

void month(int year, int yearday, int *pmonth, int *pday){

    int i, leap;
    leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    for(i=1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth=1;
    *pday = yearday;

}

