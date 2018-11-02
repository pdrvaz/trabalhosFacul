#pragma once

#include "ListaDuplaEstado.h"

typedef struct movimento
{
	int Manhattan;
	int dir;
} movimento;

int melhorCaminho(int mat[4][4], ListaDuplaEstado **lista);
int ManhattanDistance(int mat[4][4]);

void selectSortManhattan(movimento vetor[], int size);

void swap(movimento *a, movimento *b);