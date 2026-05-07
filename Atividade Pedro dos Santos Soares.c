#include <stdio.h>
#include <stdlib.h>

int main()
{
    char VIP;
    int Idade;

    printf("Você é VIP (s/n):  ");
    scanf("%c", &VIP);

    printf("Sua Idade: ");
    scanf("%d", &Idade);

    if (VIP == 's')
    {
        printf("Você possue acesso direto!");
    }

    else if (Idade >= 18)
    {
        printf("Você pode Entrar!");
    }
    
    else
    {
        printf("Acesso Negado!");
    }
    
    return 0;

}