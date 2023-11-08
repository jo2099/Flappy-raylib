#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>
#include<time.h>
#include "obstaculo.h"
#include "dificuldade.h"

//obstaculo atual-referencia <= 200
//obstaculo atual<= 200+referencia

void inicializa_obstaculo(OBSTACULO* obstaculo,DIFICULDADE* diff_atual)
{
	
	obstaculo->velocidade = diff_atual->vel_obstaculos;
	obstaculo->hitboxcima.x = SCREEN_WIDTH;
	obstaculo->hitboxcima.y = 0;
	obstaculo->hitboxcima.width = HITBOX_WIDTH;
	//randomiza a altura do obstaculo de cima
	obstaculo->hitboxcima.height = GetRandomValue(0, diff_atual->dif_max_altura + (diff_atual->altura_anterior) );
	printf("\naltura atual: %f\ndiferenca: %f", obstaculo->hitboxcima.height, obstaculo->hitboxcima.height-diff_atual->altura_anterior);
	if (obstaculo->hitboxcima.height < 0) { obstaculo->hitboxcima.height = 0; printf("erro\n");system("pause"); }
		
	(diff_atual->altura_anterior) = obstaculo->hitboxcima.height;
	obstaculo->hitboxbaixo.x = obstaculo->hitboxcima.x;
	obstaculo->hitboxbaixo.y = obstaculo->hitboxcima.height + diff_atual->gap;
	obstaculo->hitboxbaixo.width = HITBOX_WIDTH;
	obstaculo->hitboxbaixo.height = SCREEN_HEIGHT - obstaculo->hitboxbaixo.y;

	//printa pos do obstaculo
	printf("obstaculo: %f %f %f %f\n", obstaculo->hitboxcima.x, obstaculo->hitboxcima.y, obstaculo->hitboxbaixo.x, obstaculo->hitboxbaixo.y);
}



void posiciona_obstaculos(OBSTACULO obstaculos[MAX_OBSTACULOS], DIFICULDADE* diff_atual)
{
	diff_atual->num_atual_obstaculos = SCREEN_WIDTH / DISTANCIA_OBSTACULOS;
	diff_atual->altura_anterior = SCREEN_HEIGHT/2;
	for (int i = 0;i < diff_atual->num_atual_obstaculos;i++)
	{
		inicializa_obstaculo(&obstaculos[i],diff_atual);

		obstaculos[i].hitboxbaixo.x += DISTANCIA_OBSTACULOS * i;
		obstaculos[i].hitboxcima.x += DISTANCIA_OBSTACULOS * i;
	}
		printf("\nteste2\n");

}

void desenha_obstaculo(OBSTACULO* obstaculo)
{
	DrawRectangleRec(obstaculo->hitboxcima, GREEN);
	DrawRectangleRec(obstaculo->hitboxbaixo, GREEN);
}

void move_obstaculo(OBSTACULO* obstaculo)
{

	obstaculo->hitboxcima.x -= obstaculo->velocidade;
	obstaculo->hitboxbaixo.x -= obstaculo->velocidade;
}

void printa_obstaculos(OBSTACULO* obstaculos,DIFICULDADE* diff_atual)
{
	for (int i = 0;i < diff_atual->num_atual_obstaculos;i++)
	{
		printf("obstaculo %d: %f %f %f %f\n", i, obstaculos[i].hitboxcima.x, obstaculos[i].hitboxcima.y, obstaculos[i].hitboxbaixo.x, obstaculos[i].hitboxbaixo.y);
	}
}