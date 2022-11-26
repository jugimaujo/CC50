#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        // Mensagem de erro se não houver ou se tiver mais de 1 argumento de linha
        printf("Use: ./substitution key\n");
        return 1;
    }
    
    else
    {
        // Varre argumento de linha
        int valid_i = 0;

        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if(isalpha(argv[1][i]))
            {
                valid_i++;
            }
        }
        
        if(valid_i != 26)
        {
            // Mensagem de erro quando argumento de linha não tem 26 caracteres alfabéticos
            printf("A chave deve conter 26 letras alfabéticas.\n");
            return 1;
        }
        
        else
        {
            string cy_az = argv[1], az = "abcdefghijklmnopqrstuvwxyz";
            
            // Pede o texto que vai ser criptografado.
            string txt = get_string("Plaintext: ");
            char cytxt[strlen(txt)];
            
            for(int cy = 0, ncy = strlen(txt); cy < ncy; cy++)
            {
                cytxt[cy] = txt[cy];
            }
            
            for(int c = 0, n3 = strlen(txt); c < n3; c++)
            {
                for(int l = 0, n4 = strlen(az); l < n4; l++)
                {
                    if(isalpha(txt[c]) && (txt[c] == az[l] || txt[c] == (az[l] - 32)))
                    {
                        cytxt[c] = cy_az[l];
                        if(isupper(txt[c]) && islower(cytxt[c]))
                        {
                            cytxt[c] -= 32;
                        }
                    }
                }
            }
            printf("Cyphertext: %s\n", cytxt);
            return 1;
        }
    }
}
