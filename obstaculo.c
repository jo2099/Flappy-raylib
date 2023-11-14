#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>
#include<time.h>
#include "obstaculo.h"
#include "dificuldade.h"
#include<math.h>
//obstaculo atual-referencia <= 200
//obstaculo atual<= 200+referencia

void inicializa_obstaculo(struct obstaculo* obstaculo, struct dificuldade* diff_atual)
{
	Image imagem=LoadImage("./obs_cima.png");
	Image imagem_baixo=LoadImage("./obs_cima.png");
	Texture2D textura;
	Rectangle source;

	ImageResizeNN(&imagem, HITBOX_WIDTH, (SCREEN_HEIGHT));

	ImageFlipVertical(&imagem);
	
	ImageFlipVertical(&imagem_baixo);
	ImageResizeNN(&imagem_baixo, HITBOX_WIDTH, (SCREEN_HEIGHT));

	obstaculo->velocidade = diff_atual->vel_obstaculos;
	obstaculo->hitboxcima.x = SCREEN_WIDTH;
	obstaculo->hitboxcima.y = 0;
	obstaculo->hitboxcima.width = HITBOX_WIDTH;
	//randomiza a altura do obstaculo de cima
	obstaculo->hitboxcima.height = (GetRandomValue((-diff_atual->dif_max_altura)+diff_atual->altura_anterior, diff_atual->dif_max_altura + (diff_atual->altura_anterior)));
	diff_atual->altura_anterior = obstaculo->hitboxcima.height;

	if (obstaculo->hitboxcima.height < 0) { obstaculo->hitboxcima.height = 0; printf("erro\n"); }
	if(obstaculo->hitboxcima.height>=SCREEN_HEIGHT-40) { obstaculo->hitboxcima.height = SCREEN_HEIGHT-40; printf("erro\n"); }


	source=(Rectangle){0,0,imagem.width,obstaculo->hitboxcima.height};
	ImageCrop(&imagem,source);

	ImageFlipVertical(&imagem);
	textura = LoadTextureFromImage(imagem);
	obstaculo->textura_cima=textura;


	(diff_atual->altura_anterior) = obstaculo->hitboxcima.height;
	obstaculo->hitboxbaixo.x = obstaculo->hitboxcima.x;
	obstaculo->hitboxbaixo.y = obstaculo->hitboxcima.height + diff_atual->gap;
	obstaculo->hitboxbaixo.width = HITBOX_WIDTH;
	obstaculo->hitboxbaixo.height = SCREEN_HEIGHT - obstaculo->hitboxbaixo.y;
	
	source=(Rectangle){0,0,imagem_baixo.width,obstaculo->hitboxbaixo.height};
	ImageCrop(&imagem_baixo,source);
	//se o y do obstaculo de baixo for maior que a altura da textura, ele aumenta a altura da textura
	if (obstaculo->hitboxbaixo.height > imagem_baixo.height)
	{
		ImageResize(&imagem_baixo, HITBOX_WIDTH, obstaculo->hitboxbaixo.height);
	}
	obstaculo->textura_baixo=LoadTextureFromImage(imagem_baixo);

	//printa pos do obstaculo
	//printf("obstaculo: %f %f %f %f\n", obstaculo->hitboxcima.x, obstaculo->hitboxcima.y, obstaculo->hitboxbaixo.x, obstaculo->hitboxbaixo.y);
}



void posiciona_obstaculos(struct obstaculo obstaculos[MAX_OBSTACULOS], struct dificuldade* diff_atual)
{
	diff_atual->num_atual_obstaculos = SCREEN_WIDTH / DISTANCIA_OBSTACULOS;
	diff_atual->altura_anterior = SCREEN_HEIGHT / 2;
	for (int i = 0;i < diff_atual->num_atual_obstaculos;i++)
	{
		inicializa_obstaculo(&obstaculos[i], diff_atual);

		obstaculos[i].hitboxbaixo.x += DISTANCIA_OBSTACULOS * i;
		obstaculos[i].hitboxcima.x += DISTANCIA_OBSTACULOS * i;
	}
	printf("\nteste2\n");

}

void desenha_obstaculo(struct obstaculo* obstaculo)
{
	//DrawRectangleRec(obstaculo->hitboxcima, GREEN);
	//DrawRectangleRec(obstaculo->hitboxbaixo, GREEN);
	DrawTexture(obstaculo->textura_cima, obstaculo->hitboxcima.x, obstaculo->hitboxcima.y, WHITE);
	DrawTexture(obstaculo->textura_baixo, obstaculo->hitboxbaixo.x, obstaculo->hitboxbaixo.y, WHITE);

	//DrawTexture(obstaculo->fim_obst, SCREEN_WIDTH/2,SCREEN_HEIGHT/2,WHITE);
}

void move_obstaculo(struct obstaculo* obstaculo)
{

	obstaculo->hitboxcima.x -= obstaculo->velocidade;
	obstaculo->hitboxbaixo.x -= obstaculo->velocidade;
}

void printa_obstaculos(struct obstaculo* obstaculos, struct dificuldade* diff_atual)
{
	for (int i = 0;i < diff_atual->num_atual_obstaculos;i++)
	{
		printf("obstaculo %d: %f %f %f %f\n", i, obstaculos[i].hitboxcima.x, obstaculos[i].hitboxcima.y, obstaculos[i].hitboxbaixo.x, obstaculos[i].hitboxbaixo.y);
	}
}