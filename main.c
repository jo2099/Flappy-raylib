
#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>
#include "Jogador.h"
#include "obstaculo.h"


int	main()
{
	int inicio = 0;
	struct obstaculo obstaculos[MAX_OBSTACULOS];
	char pontos[20];
	struct dificuldade dificuldade_atual;
	char arquivo[20] = "dificuldade.txt";
	JOGADOR jogador;


	


	
	printf("\nteste\n");


	system("pause");

	//tela basica raylib
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World");
	inicializa_jogador(&jogador);
	define_diff(&dificuldade_atual, arquivo);
	//inicializa os obstaculos separados por uma distancia de 100 pixels
	posiciona_obstaculos(obstaculos, &dificuldade_atual);
	SetTargetFPS(60);

	//loop do jogo
	while (!WindowShouldClose())
	{
		//processamento do jogo
		if (IsKeyPressed(KEY_SPACE))
			inicio = 1;
		if (inicio == 1)
		{

			move_jogador(&jogador);
			atualiza_diff(&dificuldade_atual, jogador.score, obstaculos);
			jogador.score++;

			for (int i = 0;i < dificuldade_atual.num_atual_obstaculos;i++)
			{
				move_obstaculo(&obstaculos[i]);
				if (CheckCollisionRecs(jogador.hitbox, obstaculos[i].hitboxbaixo) || CheckCollisionRecs(jogador.hitbox, obstaculos[i].hitboxcima))
				{
					jogador.vidas--;
					inicializa_jogador(&jogador);
					inicio = 0;
					define_diff(&dificuldade_atual, arquivo);
					posiciona_obstaculos(obstaculos, &dificuldade_atual);
					WaitTime(1);
				}
				if (obstaculos[i].hitboxbaixo.x + obstaculos[i].hitboxbaixo.width < 0) //verifica se o obstaculo saiu da tela e o reposiciona na direita
					inicializa_obstaculo(&obstaculos[i], &dificuldade_atual);

			}
		}


		//desenha o jogo
		BeginDrawing();
		ClearBackground(SKYBLUE);
		desenha_jogador(&jogador);
		for (int i = 0;i < dificuldade_atual.num_atual_obstaculos;i++)
			desenha_obstaculo(&obstaculos[i]);

		_itoa_s(jogador.score, pontos, 20, 10);
		DrawText("score:", (SCREEN_WIDTH / 2) - 100, SCREEN_HEIGHT / 2, 20, RED);DrawText(pontos, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, RED);

		EndDrawing();

	}

	return 0;
}