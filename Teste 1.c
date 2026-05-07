#include <stdio.h>

int main() 
{

    float num1, num2, num3, valorF;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1); // %f para ler float

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    printf("Digite o terceiro numero: ");
    scanf("%f", &num3);

    valorF = num1 * num2 * num3;

    printf("\nValor final da Multiplicacao e: %.2f\n", valorF);

    return 0;
}