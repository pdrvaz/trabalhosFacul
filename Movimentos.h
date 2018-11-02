#pragma once

typedef struct Coordenadas
{
	int x, y;
}Ponto;

Ponto ReturnPos(int mat[4][4], int valor);

int MoveUp(int mat[4][4]);
int MoveDown(int mat[4][4]);
int MoveLeft(int mat[4][4]);
int MoveRight(int mat[4][4]);