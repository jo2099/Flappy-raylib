#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>
#include "Jogador.h"
#include "obstaculo.h"
#include "menu.h"

void processa_jogo(JOGADOR* jogador,struct dificuldade* dificuldade_atual,OBS obstaculos[MAX_OBSTACULOS],char arquivo[20],int* inicio,int*reinicia)
{
	if (IsKeyPressed(KEY_SPACE))
		(*inicio) = 1;
	if ((*inicio) == 1)
	{
		move_jogador(jogador);
		if(atualiza_diff(dificuldade_atual, jogador->score))
        {

            for(int i=0;i<dificuldade_atual->num_atual_obstaculos;i++)
            {

                obstaculos[i].velocidade+=dificuldade_atual->inc_vel_obstaculos;
            }
        }
		jogador->score++;

		for (int i = 0;i < dificuldade_atual->num_atual_obstaculos;i++)
		{
			move_obstaculo(&obstaculos[i]);
			if (CheckCollisionRecs(jogador->hitbox, obstaculos[i].hitboxbaixo) || CheckCollisionRecs(jogador->hitbox, obstaculos[i].hitboxcima))
			{
				if (*reinicia == 1)
				{
					inicializa_jogador(jogador);
					(*inicio) = 0;
					define_diff(dificuldade_atual, arquivo);
					posiciona_obstaculos(obstaculos, dificuldade_atual);
					WaitTime(1);
					(*reinicia) = 0;
				}
				else (*reinicia) = 1;

			}
			if (obstaculos[i].hitboxbaixo.x + obstaculos[i].hitboxbaixo.width < 0) //verifica se o obstaculo saiu da tela e o reposiciona na direita
				inicializa_obstaculo(&obstaculos[i], dificuldade_atual);
		}
	}
}


int	main()
{
	int inicio = 0;
	int reinicia = 0;
	struct obstaculo obstaculos[MAX_OBSTACULOS];
	char pontos[20];
	struct dificuldade dificuldade_atual;
	char arquivo[20] = "dificuldade.txt";
	JOGADOR jogador;
	MENU menu_principal;
	char botoes_principal[4][40] = { "Jogar","Dificuldade","Ranking","Sair" };
	//tela basica raylib
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FlappyINF");

	incializa_menu(&menu_principal, 4, botoes_principal, SCREEN_WIDTH / 2 - 50, (SCREEN_HEIGHT / 2) + 20,150, 60);
	inicializa_jogador(&jogador);
	define_diff(&dificuldade_atual, arquivo);

	//inicializa os obstaculos separados por uma distancia de 100 pixels
	posiciona_obstaculos(obstaculos, &dificuldade_atual);
	SetTargetFPS(60);

	//loop do jogo
	while (!WindowShouldClose())
	{
		//processamento do jogo
		if (menu_principal.ativo)
			processa_menu(&menu_principal);
		else
		{
			processa_jogo(&jogador, &dificuldade_atual, obstaculos, arquivo,&inicio,&reinicia);

		}


		//desenha o jogo
		BeginDrawing();

		if (menu_principal.ativo)
			desenha_menu(&menu_principal);
		else
		{
			ClearBackground(SKYBLUE);
			desenha_jogador(&jogador);
			for (int i = 0;i < dificuldade_atual.num_atual_obstaculos;i++)
				desenha_obstaculo(&obstaculos[i]);

			_itoa_s(jogador.score, pontos, 20, 10);
			if (!inicio)
			{
				DrawText("Pressione espaco para comecar", SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2, 20, RED);
			}
			DrawText("score:", 20, 20, 20, RED);DrawText(pontos, 100, 20, 20, RED);
		}
		EndDrawing();

	}

	return 0;
}
