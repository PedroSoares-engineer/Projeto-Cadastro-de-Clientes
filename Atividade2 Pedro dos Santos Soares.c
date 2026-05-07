#include <stdio.h>
#include <stdlib.h>

int main()
{

    float valorcompra, frete = 0, valorF;
    char estado;

    printf("Qual o valor da compra: ");
    scanf("%f", &valorcompra);

    printf("Digite seu Estado (SP(S), MG(M), OUTRO(O)): ");
    scanf("%s", &estado);

    if(valorcompra >= 2000)
    {
        frete = 0;
    }

    else
    {

        if(estado == 'S' || estado == 's')
        {
            frete = 10;
        }

        else if(estado == 'M' || estado == 'm')
        {
            frete = 15;
        }

        else
        {
            frete = 25;
        }

    }

    valorF = valorcompra + frete;

    printf("\nValor da Compra: R$ %.2f", valorcompra);
    printf("\nValor do frete: R$ %.2f", frete);
    printf("\nValor Final: R$ %.2f\n", valorF);

    return 0;

}