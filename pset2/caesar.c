#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            int validc = 0;
            if(isdigit(argv[1][i]))
            {
                validc++;
            }
            else
            {
                printf("Use: ./caesar key\n");
                return 1;
            }
        }
        string ptxt = get_string("Plaintext: ");
        
        for(int l = 0; l < strlen(ptxt); l++)
        {
            int key = atol(argv[1]);
            
            if(isalpha(ptxt[l]) && isupper(ptxt[l]))
            {
                if(ptxt[l] + key > 'Z')
                {
                    key -= 26;
                }
                ptxt[l] += key;
            }
            else if(isalpha(ptxt[l]) && islower(ptxt[l]))
            {
                if(ptxt[l] + key > 'z')
                {
                    key -= 26;    
                }
                ptxt[l] += key;
                
            }
        }
        printf("Cyphertext: %s\n", ptxt);
        return 0;
    }
    else
    {
        printf("Use: ./caesar key\n");
        return 1;
    }
}
