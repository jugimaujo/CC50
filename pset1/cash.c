#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int cents = 0;
    float troco;
    do
    {
        troco = get_float("Troco devido: R$");
    }
    while(troco <= 0);
    
    troco = round(troco * 100);

    while(troco > 0)
    {
        if(troco >= 25)
        {
            troco -= 25;
            cents++;
        }
        else if(troco < 25 && troco >= 10)
        {
            troco -= 10;
            cents++;
        }
        else if(troco < 10 && troco >= 5)
        {
            troco -= 5;
            cents++;
        }
        else
        {
            troco -= 1;
            cents++;
        }
    }
    printf("%i\n", cents);
    
}
