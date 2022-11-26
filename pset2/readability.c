#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int letter = 0, word = 1, sentence = 0;
    float L = 0, S = 0;
    
    string text = get_string("Text: ");
    
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter++;
        }
        else if(text[i] == ' ')
        {
            word++;
        }
        else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    L = (letter / (float) word) * 100;
    S = (sentence / (float) word) * 100;
    
    float X = 0.0588 * L - 0.296 * S - 15.8;
    
    if(X >= 16)
    {
        printf("Grade: 16+\n");
    }
    else if(X < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade: %.0f\n", X);
    }
        
}
