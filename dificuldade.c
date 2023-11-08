#include"dificuldade.h"
#include<stdio.h>
#include<stdlib.h>
#include"obstaculo.h"


void define_diff(DIFICULDADE* diff, char string[20])
{
	//le arquivo com nome string e define os valores de diff
	FILE* arq;
	
	arq = fopen(string, "r");

if (arq == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	printf("Arquivo aberto com sucesso\n");
	diff->nivel_atual = 1;
	fscanf(arq, "%d", &diff->score_treshold);
	fscanf(arq, "%d", &diff->gap);
	fscanf(arq, "%d", &diff->inc_gap);
	fscanf(arq, "%d", &diff->dif_max_altura);
	fscanf(arq, "%d", &diff->inc_dif_max_altura);
	fscanf(arq, "%d", &diff->vel_obstaculos);
	fscanf(arq, "%d", &diff->inc_vel_obstaculos);
	fclose(arq);

	//printa valores lidos
	printf("score_treshold: %d\n", diff->score_treshold);
	printf("gap: %d\n", diff->gap);
	printf("inc_gap: %d\n", diff->inc_gap);
	printf("dif_max_altura: %d\n", diff->dif_max_altura);
	printf("inc_dif_max_altura: %d\n", diff->inc_dif_max_altura);
	printf("vel_obstaculos: %d\n", diff->vel_obstaculos);
	printf("inc_vel_obstaculos: %d\n", diff->inc_vel_obstaculos);


}

void atualiza_diff(DIFICULDADE* diff, int score,OBSTACULO obstaculos[MAX_OBSTACULOS])
{
	if(score > (diff->score_treshold) * (diff->nivel_atual))
	{
		(diff->nivel_atual)++;
		printf("\nnivel atual: %d\n", diff->nivel_atual);
		diff->gap -= diff->inc_gap;
		diff->dif_max_altura += diff->inc_dif_max_altura;
		diff->vel_obstaculos += diff->inc_vel_obstaculos;
		for (int i = 0;i < diff->num_atual_obstaculos;i++)
		{
			obstaculos[i].velocidade = diff->vel_obstaculos;
		}
	}
}
