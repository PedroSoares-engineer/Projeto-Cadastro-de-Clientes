#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os dados do professor
struct Professor 
{
    char nome[50];
    char sexo;
    int horas;
};

// Função para ler os dados
void lerProfessores(struct Professor p[], int n) 
{
    for(int i = 0; i < n; i++) 
    {
        printf("\nProfessor %d\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]", p[i].nome);

        printf("Sexo (M/F): ");
        scanf(" %c", &p[i].sexo);

        printf("Horas-aula: ");
        scanf("%d", &p[i].horas);
    }
}

// Função para calcular salário líquido
float calcularSalarioLiquido(struct Professor p) 
{
    float bruto = p.horas * 85;
    float desconto;

    if(p.sexo == 'M') 
    {
        if(p.horas <= 70)
            desconto = 0.10;
        else
            desconto = 0.08;
    } 
    else 
    {
        if(p.horas <= 70)
            desconto = 0.07;
        else
            desconto = 0.05;
    }

    return bruto * (1 - desconto);
}

// Função para média das professoras
float mediaFeminino(struct Professor p[], int n) 
{
    float soma = 0;
    int cont = 0;

    for(int i = 0; i < n; i++) {
        if(p[i].sexo == 'F' || p[i].sexo == 'f') 
        {
            soma += calcularSalarioLiquido(p[i]);
            cont++;
        }
    }

    if(cont == 0) return 0;

    return soma / cont;
}

// Função principal
int main() 
{
    struct Professor profs[20];

    // Leitura
    lerProfessores(profs, 20);

    // Exibição
    printf("\n--- DADOS DOS PROFESSORES ---\n");

    for(int i = 0; i < 20; i++) 
    {
        float bruto = profs[i].horas * 85;
        float liquido = calcularSalarioLiquido(profs[i]);

        printf("\nNome: %s", profs[i].nome);
        printf("\nSalario Bruto: %.2f", bruto);
        printf("\nSalario Liquido: %.2f\n", liquido);
    }

    // Média das mulheres
    float media = mediaFeminino(profs, 20);
    printf("\nMedia dos salarios liquidos (Feminino): %.2f\n", media);

    return 0;
}