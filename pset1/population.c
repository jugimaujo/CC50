#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, nf, y = 0;
    do
    {
        n = get_int("Start size: ");
    }
    while(n < 9);
    
    do
    {
        nf = get_int("End size: ");
    }
    while(nf < n);

    while(n < nf)
    {
        n = n + ((n / 3) - (n / 4));
        y++;
    }
    printf("Years: %i\n", y);
}
