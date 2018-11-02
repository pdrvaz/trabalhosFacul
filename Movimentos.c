#include "Movimentos.h"
#include <stdlib.h>


Ponto ReturnPos(int mat[4][4], int valor)
{
	int i, j;
	Ponto Coord;

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (mat[i][j] == valor)
			{
				Coord.y = i;
				Coord.x = j;
			}
		}
	}
	return Coord;
}

int MoveUp(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	if (Coord_xy.y > 0)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y - 1][Coord_xy.x];
		mat[Coord_xy.y - 1][Coord_xy.x] = 0;
		return 0;
	}
	return -1;
}

int MoveDown(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	if (Coord_xy.y < 3)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y + 1][Coord_xy.x];
		mat[Coord_xy.y + 1][Coord_xy.x] = 0;
		return 0;
	}
	return -1;
}

int MoveLeft(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	if (Coord_xy.x > 0)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y][Coord_xy.x - 1];
		mat[Coord_xy.y][Coord_xy.x - 1] = 0;
		return 0;
	}
	return - 1;
}

int MoveRight(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	if (Coord_xy.x < 3)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y][Coord_xy.x + 1];
		mat[Coord_xy.y][Coord_xy.x + 1] = 0;
		return 0;
	}
	return -1;
}