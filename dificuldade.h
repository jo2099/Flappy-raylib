#pragma once
#include "obstaculo.h"
#include"raylib.h"

struct dificuldade {
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
};

void define_diff(struct dificuldade* dificuldade, char nome_arq[20]);

int atualiza_diff(struct dificuldade* diff, int score );





