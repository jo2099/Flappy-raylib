#include"menu.h"

void incializa_menu(MENU* menu, int num_botoes, char texto[MAX_BOTOES][40], int x, int y, int largura, int altura)
{
	menu->num_botoes = num_botoes;
	menu->ativo = 1;
	menu->seletor = 0;
	for (int i = 0;i < num_botoes;i++)
	{
		menu->botoes[i].hitbox.x = x;
		menu->botoes[i].hitbox.y = y + i * (altura + 10);
		menu->botoes[i].hitbox.width = largura;
		menu->botoes[i].hitbox.height = altura;
		strcpy(menu->botoes[i].texto, texto[i]);
		menu->botoes[i].selecionado = 0;
	}
	menu->botoes[0].selecionado = 1;
};

void processa_menu(MENU* menu)
{
	for (int i = 0;i < menu->num_botoes;i++)
	{
		if (menu->botoes[i].selecionado)
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				menu->ativo = 0;
				menu->botoes[i].selecionado = 0;
			}
			menu->botoes[i].cor = RED;
		}
		else menu->botoes[i].cor = GREEN;
	}
	if (IsKeyPressed(KEY_DOWN))
	{
		//seleciona o proximo botao
		menu->botoes[menu->seletor].selecionado = 0;
		menu->seletor = (menu->seletor + 1) % menu->num_botoes;
		if (menu->seletor > menu->num_botoes)
			menu->seletor = 0;
		menu->botoes[menu->seletor].selecionado = 1;
	}
	if (IsKeyPressed(KEY_UP))
	{
		//seleciona o botao anterior
		menu->botoes[menu->seletor].selecionado = 0;
		menu->seletor = (menu->seletor - 1) % menu->num_botoes;
		if (menu->seletor < 0)
			menu->seletor = menu->num_botoes - 1;
		menu->botoes[menu->seletor].selecionado = 1;
	}
}

void desenha_botao(BOTAO botao)
{
	DrawRectangleRec(botao.hitbox, botao.cor);
	//centraliza o texto
	DrawText(botao.texto, botao.hitbox.x + botao.hitbox.width / 2 - MeasureText(botao.texto, 20) / 2, botao.hitbox.y + botao.hitbox.height / 2 - 20 / 2, 20, BLACK);

}

void desenha_menu(MENU* menu)
{
	ClearBackground(SKYBLUE);
	DrawText("FLAPPY INF", SCREEN_WIDTH / 2 - 200, 50, 80, BLACK);
	for (int i = 0;i < menu->num_botoes;i++)
	{
		desenha_botao(menu->botoes[i]);
	}
}