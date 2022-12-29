#include <stdio.h>

/* print Farhrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

float ConvertFahrToCels(float fahr);

float ConvertCelsToFahr(float cels);

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
        celsius = ConvertFahrToCels(fahr);
        printf("%10.0f >> %7.2f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float ConvertFahrToCels(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

float ConvertCelsToFahr(float cels)
{
    return (cels * (9.0 / 5.0)) + 32.0;
}
