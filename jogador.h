#ifndef JOGADOR_H
#define JOGADOR_H


#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"raylib.h"
#include "obstaculo.h"


typedef struct Jogador
{
	char nome[20];
	float x; //posicao x do jogador na tela
	float y; //posicao y do jogador na tela
	Rectangle hitbox; //hitbox do jogador
	float velocidade; //velocidade do jogador
	float aceleracao; //aceleracao do jogador
	int score;
	Texture2D sprite;
}JOGADOR;


void inicializa_jogador(JOGADOR* jogador);
void move_jogador(JOGADOR* jogador);

void desenha_jogador(JOGADOR* jogador);

#endif // !JOGADOR_H




