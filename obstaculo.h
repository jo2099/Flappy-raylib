
#pragma once
#include"raylib.h"
#include "dificuldade.h"
#define MAX_OBSTACULOS 30
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define HITBOX_WIDTH 75
#define DISTANCIA_OBSTACULOS 300

//#define GAP 150
//#define VELOCIDADE_OBSTACULOS 5
//#define DIF_ALTURA_OBSTACULOS 50

typedef struct obstaculo
{
	float velocidade;
	Rectangle hitboxbaixo;
	Rectangle hitboxcima;
	Texture2D textura_cima;
	Texture2D textura_baixo;
	Texture2D fim_obst;


}OBS;


void inicializa_obstaculo(struct obstaculo* obstaculo, struct dificuldade* diff_atual);//coloca o obstaculo na direita da tela e com uma velocidade fixa
void desenha_obstaculo(struct obstaculo* obstaculo);//desenha o obstaculo
void move_obstaculo(struct obstaculo* obstaculo);//move o obstaculo para a esquerda
void posiciona_obstaculos(struct obstaculo obstaculos[MAX_OBSTACULOS], struct dificuldade* diff_atual);//posiciona os obstaculos na tela a uma distancia especifica
void printa_obstaculos(OBS* obstaculos, struct dificuldade* diff);//printa as posicoes dos obstaculos




