#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Passo 1 - pedir numero do cartao de credito
    long n = 0;
    do
    {
        n = get_long("Número do cartão: ");
    }
    while(n < 0);
    
    //Passo 2 - criar algoritmo de Luhn
    printf("%li\n", n % 100);
    
    //Passo 3 - checar quantos algarismos tem no numero do cartão
    //Passo 4 - checar quais são os algarismos iniciais do numero
    //Passo 5 - dizer de qual empresa é esse cartão
}