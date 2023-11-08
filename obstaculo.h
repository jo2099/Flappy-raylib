#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>
#include"dificuldade.h"

#define MAX_OBSTACULOS 30
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define HITBOX_WIDTH 50
#define HITBOX_HEIGHT 50

//#define GAP 150
//#define VELOCIDADE_OBSTACULOS 5
//#define DIF_ALTURA_OBSTACULOS 50

typedef struct obstaculo
{
	float velocidade;
	Rectangle hitboxbaixo;
	Rectangle hitboxcima;
	

}OBSTACULO;


void inicializa_obstaculo(OBSTACULO* obstaculo, DIFICULDADE* diff_atual);//coloca o obstaculo na direita da tela e com uma velocidade fixa
void desenha_obstaculo(OBSTACULO* obstaculo);//desenha o obstaculo
void move_obstaculo(OBSTACULO* obstaculo);//move o obstaculo para a esquerda
void posiciona_obstaculos(OBSTACULO obstaculos[MAX_OBSTACULOS], DIFICULDADE* diff_atual);//posiciona os obstaculos na tela a uma distancia especifica
void printa_obstaculos(OBSTACULO* obstaculos,DIFICULDADE* diff);//printa as posicoes dos obstaculos