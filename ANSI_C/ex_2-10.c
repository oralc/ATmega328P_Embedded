#include <stdio.h>

void main (void)
{

    int farenheit;
    int celsius;
    int lower;
    int upper;
    int step;


    lower = 0; /* lower limit */
    upper = 300;
    step = 20;
    farenheit = lower;
    
    while ( farenheit <= upper)
    {
        celsius =5*( farenheit - 32) / 9;
        farenheit = farenheit + step;
        printf ("%d F = %d C\n", farenheit , celsius);
        
        printf ("%d F = %d C\n", farenheit , celsius);
    }


}