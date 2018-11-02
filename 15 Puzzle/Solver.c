#include <stdlib.h>
#include "Solver.h"
#include "Jogo.h"

int melhorCaminho(int mat[4][4], ListaDuplaEstado **lista)
{
	if (ManhattanDistance(mat) == 0)
		return 1;

	int i;
	movimento *opcoes = malloc(4 * sizeof(movimento));	
	for (i = 0; i < 4; i++)
		opcoes[i].dir = i;

	if (comparaMatrizes(mat, *lista) == -1)
		insert(lista, mat);

	for (i = 0; i < 4; i++)
	{
		if (Move(mat, i) == 0)
		{
			if (comparaMatrizes(mat, *lista) == 0)
				opcoes[i].Manhattan = -1;
			else
				opcoes[i].Manhattan = ManhattanDistance(mat);

			if(opcoes[i].dir % 2 == 0)
				Move(mat, i + 1);
			else
				Move(mat, i - 1);
		}
		else
			opcoes[i].Manhattan = -1;
	}

	selectSortManhattan(opcoes, 4);
	for (i = 0; i < 4; i++)
	{
		if(opcoes[i].Manhattan != -1)
		{
			Move(mat, opcoes[i].dir);

			if(melhorCaminho(mat, lista) == 1)
				return 1;

			removeEstado(lista, mat);
			if (opcoes[i].dir % 2 == 0)
				Move(mat, i + 1);
			else
				Move(mat, i - 1);
		}
	}

	free(opcoes);
	return 0;
}

int ManhattanDistance(int mat[4][4])
{
	int somaDist = 0;
	int valor = 1;

	while(valor < 16)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (mat[i][j] == valor)
				{
					somaDist += abs(i - ((valor - 1) / 4)) + abs(j - ((valor - 1) % 4));
					valor++;
				}
			}
		}
	}
	return somaDist;
}

void selectSortManhattan(movimento vetor[], int size)
{
	if (size <= 1)
		return;

	int posMenor = 0;
	for (int i = 0; i < size; i++)
	{
		if (vetor[posMenor].Manhattan > vetor[i].Manhattan)
			posMenor = i;
	}

	//swap(&(vetor[posMenor]), &(vetor[0]));
	movimento aux = vetor[posMenor];
	vetor[posMenor] = vetor[0];
	vetor[0] = aux;
	selectSortManhattan(&(vetor[1]), size - 1);

	return;
}

void swap(movimento *a, movimento *b)
{
	movimento aux = *a;
	*a = *b;
	*b = aux;

	return;
}