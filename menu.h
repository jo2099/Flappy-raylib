#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"raylib.h"
#include<string.h>
#include"obstaculo.h"

#define MAX_BOTOES 10

typedef struct Botao
{
	Rectangle hitbox;
	char texto[20];
	int selecionado;
	Color cor;
}BOTAO;

typedef struct Menu
{
	BOTAO botoes[MAX_BOTOES];
	int num_botoes;
	int ativo;
	int seletor;

}MENU;

void incializa_menu(MENU* menu, int num_botoes, char texto[MAX_BOTOES][40], int x, int y, int largura, int altura);

void processa_menu(MENU* menu);

void desenha_botao(BOTAO botao);

void desenha_menu(MENU* menu);