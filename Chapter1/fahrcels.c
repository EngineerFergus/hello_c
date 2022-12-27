#include <stdio.h>

/* print Farhrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Fahrenheit >> Celsius\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f >> %7.2f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}