#pragma once

typedef struct ListaDuplaEstado
{
	int estado[4][4];
    struct ListaDuplaEstado *proximo;
    struct ListaDuplaEstado *anterior;

} ListaDuplaEstado;

/*funcoes basicas*/
int inverte(ListaDuplaEstado **lista);
int insert(ListaDuplaEstado **lista, int mat[4][4]);
int **get(ListaDuplaEstado *lista, int posicao);
int tamanho(ListaDuplaEstado *lista);
int removePos(ListaDuplaEstado **lista, int posicao);

/*funcoes avancadas*/
int indexOf(ListaDuplaEstado *lista, int mat[4][4]);
int removeEstado(ListaDuplaEstado **lista, int mat[4][4]);
int addPos(ListaDuplaEstado **lista, int mat[4][4], int posicao);

int comparaMatrizes(int mat[4][4], ListaDuplaEstado *lista);

int getPos(int mat[4][4], ListaDuplaEstado *lista, int posicao);