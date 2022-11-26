#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Altura: ");
    }
    while(h < 1 || h > 8);
    
    for(int i = 1; i <= h; i++)
    {
        for(int d = h - i; d > 0; d--)
        {
            printf(" ");
        }
        for(int hash = h - (h - i); hash > 0; hash--)
        {
            printf("#");
        }
        printf("\n");
    }
}