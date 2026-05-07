#include <stdio.h>
#include <stdlib.h>

struct funcionarios //é um tipo de dado struct funcionario alem de uma variavel como float, int, ...
{
	char nome[80];
	int nD, nHMes;
	float sH, sB, dINSS, dIR, sL;
	
};

int cadastraf(struct funcionarios f[40], int nf);
void mostraf(struct funcionarios f[40], int nf);


int main()
{
	int nf = 0;
	struct funcionarios f[40];//dentro desta f eu guardo uma struct
	char op;
	
	do//vamos usar o do while , pois é preciso que se faça pelo menos o cadastro de 1 funcionario
	{
		nf = cadastraf(f, nf);	
		printf("\n Deseja cadastrar outro funcionario?(s/n)");
		scanf("%c",&op);			
    }while(nf < 39 && op == 's');//é o s de sim "s" ou não "n"
	
	mostraf(f, nf);
	
}

int cadastraf(struct funcionarios f[40], int nf)//eu coloco o int ao invez de void pois e preciso 	que retorne um int
{
	printf(" Nome do funcionario na posiçao %d", nf);
	gets(f[nf].nome);
	
	printf("\n Digite o numero de dependentes do funcionario = ");
	scanf("%d",&f[nf].nD);
	
	printf("\n Qual o salario por hora?");
	scanf("%f",&f[nf].sH);
	
	printf("\n Digite o numero de horas trabalhadas no mes = ");
	scanf("%d",&f[nf].nHMes);
	
	f[nf].sB = f[nf].sH * f[nf].nHMes + 320.50 * f[nf].nD;
	
	if(f[nf].sB < 4800)
	{
		f[nf].dINSS = (10/100) * f[nf].sB;
	}else
	{
		f[nf].dINSS = f[nf].sB - 1500;
	}
	
	  if(f[nf].sB - f[nf].dINSS <= 5000)
	  {
	 	f[nf].dIR = 0;
	  } 
	     else if(f[nf].sB - f[nf].dINSS <= 10000)
          {
	     	  f[nf].dIR = (10/100) * f[nf].sB;
          }
		     else
		     {
		   	   f[nf].dIR = (20/100) * f[nf].sB;
		     }
	
	f[nf].sL = f[nf].sB -f[nf].dINSS - f[nf].dIR;
	nf++;
	return nf;	     
}

void mostraf(struct funcionarios f[40], int nf)
{
	int i;
	
	for(i = 0; i < nf; i++)
	{
		printf("\n Nome = &s", f[i].nome);
		printf("\n Salario bruto = %.2f",f[i].sB);
		printf("\n Desconto INSS = %.2f",f[i].dINSS);
		printf("\n Desconto IR = %.2f", f[i].dIR);
		printf("\n Salario liquido = %.2f",f[i].sL);
	}
}