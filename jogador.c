#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>
#include "Jogador.h"

#define ALTURA_DO_PULO 0.55
#define GRAVIDADE 0.058
#define IMPULSO -2
#define TAM_SPRITE 25

void inicializa_jogador(JOGADOR* jogador)
{
	jogador->x = 100;
	jogador->y = 100;
	jogador->score = 0;
	jogador->hitbox.x = jogador->x;
	jogador->hitbox.y = jogador->y;
	jogador->hitbox.width = 35;
	jogador->hitbox.height = 35;
	jogador->velocidade = 0;
	jogador->aceleracao = 0;

	Image image=LoadImage("./flappy.png");
	ImageResize(&image, jogador->hitbox.width+17, jogador->hitbox.height+17);

	//faz a imagem ter o tamanho da hitbox



	if(image.data==NULL)
	{
		printf("Erro ao carregar imagem do jogador\n");
		exit(1);
	}

	jogador->sprite=LoadTextureFromImage(image);

}

void desenha_jogador(JOGADOR* jogador)
{
	//DrawRectangleRec(jogador->hitbox, YELLOW);
	DrawTexture(jogador->sprite, jogador->x-TAM_SPRITE/2.5, jogador->y-TAM_SPRITE/3.5, WHITE);
}

void move_jogador(JOGADOR* jogador)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		jogador->aceleracao = -ALTURA_DO_PULO;
		jogador->velocidade = IMPULSO;
	}
	jogador->aceleracao += GRAVIDADE; //aceleracao = aceleracao + gravidade
	jogador->velocidade += jogador->aceleracao; //velocidade = velocidade + aceleracao
	jogador->y += jogador->velocidade; //posicao y = posicao y + velocidade
	jogador->hitbox.y = jogador->y;
	jogador->hitbox.x = jogador->x;

	if (jogador->y >= SCREEN_HEIGHT - jogador->hitbox.height)
	{
		jogador->y = SCREEN_HEIGHT-jogador->hitbox.height;
		jogador->aceleracao = 0;
		jogador->velocidade = 0;
	}


}