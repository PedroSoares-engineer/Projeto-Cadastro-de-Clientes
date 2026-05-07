#include <stdio.h>
#include <stdlib.h>

struct Funcionarios
{
    char nome[50];
    char sexo; 
    int idade;
    float salario; 
};

void lerFuncionarios(struct Funcionarios f[], int n)
{
    for(int i = 0; i < n; i++)
    { 
        printf("\nFuncionários %d\n", i+1);

        printf("Nome: "); 
        scanf(" %[^\n]", f[i].nome);

        printf("Sexo (M/F): "); 
        scanf(" %c", &f[i].sexo); 

        printf("Idade: "); 
        scanf("%d", &f[i].idade); 

        printf("Salário-Mês: ");
        scanf("%f", &f[i].salario);

    } 
} 

float SalarioBonus(struct Funcionarios f)
{
    float bonus;
    
    if(f.idade <= 30)
    {
        bonus = 0.2;
    }

    else
    {
        bonus = 0.6;
    }

    return f.salario * (1 + bonus);

}

int main()
{
    struct Funcionarios func[3]; 

    lerFuncionarios(func,3); 
    
    printf("\n--- DADOS DOS FUNCIONÁRIOS ---\n"); 

    for(int i = 0; i < 3; i++) 
    { 
        float bonus = SalarioBonus(func[i]);

        printf("\nNome:  %s\n", func[i].nome); 
        printf("\nSexo:  %c\n", func[i].sexo); 
        printf("\nIdade:  %d\n", func[i].idade);
        printf("\nSalário:  %.2f\n", func[i].salario);
        printf("\nSalário com Bônus:  %.2f\n", bonus);

    } 
    return 0; 
}