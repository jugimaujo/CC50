#include <cs50.h>
#include <stdio.h>

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
        for(int p1 = h - (h - i); p1 > 0; p1--)
        {
            printf("#");
        }
        for(int lac = 0; lac < 2; lac++)
        {
            printf(" ");
        }
        for(int p2 = h - (h - i); p2 > 0; p2--)
        {
            printf("#");
        }
        printf("\n");
    }
}