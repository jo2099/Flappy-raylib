#pragma once

#define DISTANCIA_OBSTACULOS 400
typedef struct dificuldade {
	int score_treshold;
	int nivel_atual;
	int gap;
	int dif_max_altura;
	int vel_obstaculos;
	int inc_gap;
	int inc_dif_max_altura;
	int inc_vel_obstaculos;

	int num_atual_obstaculos;
	int altura_anterior;
}DIFICULDADE;

void define_diff(DIFICULDADE* dificuldade, char nome_arq[20]);

void atualiza_diff(DIFICULDADE* diff, int score);