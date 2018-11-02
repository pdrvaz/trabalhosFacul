#include "ListaDuplaEstado.h"
#include <stdio.h>
#include <stdlib.h>

int inverte(ListaDuplaEstado **lista)
{
	if (*lista == NULL || (*lista)->proximo == NULL)
		return 0;

	while ((*lista)->proximo != NULL)
	{
		*lista = (*lista)->proximo;
		if ((*lista)->anterior->anterior == NULL)
			(*lista)->anterior->proximo = NULL;
		else
			(*lista)->anterior->proximo = (*lista)->anterior->anterior;
		(*lista)->anterior->anterior = *lista;
	}
	(*lista)->proximo = (*lista)->anterior;
	(*lista)->anterior = NULL;
	
	return 0;
}

/**
 * Insere um valor na lista
 * @param lista Lista
 * @param valor Valor a ser inserido
 * @return Sucesso da operação
 */
int insert(ListaDuplaEstado **lista, int matriz[4][4])
{
	ListaDuplaEstado *novo = malloc(sizeof(ListaDuplaEstado));
	novo->proximo = NULL;
	novo->anterior = NULL;
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			novo->estado[i][j] = matriz[i][j];

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	ListaDuplaEstado *iterador = *lista;
	while (iterador->proximo != NULL)
		iterador = iterador->proximo;
	
	novo->anterior = iterador;
	iterador->proximo = novo;

    return 0;
}

/**
 * Retorna o valor contido na lista na posição pedida
 * @param lista Lista
 * @param posicao Posição do elemento desejado
 * @return Valor contido na posição
 */
int **get(ListaDuplaEstado *lista, int posicao)
{
	int cont = 0;
	while (cont != posicao)
	{
		lista = lista->proximo;
		cont++;
	}

	return lista->estado;
}

/**
 * Conta o número de elementos na lista e retorna este valor
 * @param lista Lista
 * @return Número de elementos na lista
 */
int tamanho(ListaDuplaEstado *lista)
{
	if (lista == NULL)
		return 0;

	int tam = 1;

	while (lista->proximo != NULL)
	{
		lista = lista->proximo;
		tam++;
	}

    return tam;
}

/**
 * Remove o elemento contido na lista na posição pedida
 * @param lista Lista
 * @param posicao Posição do elemento a ser excluído
 * @return Sucesso da operação
 */
int removePos(ListaDuplaEstado **lista, int posicao)
{
	if (posicao >= tamanho(*lista) || posicao < 0)
		return -1;

	ListaDuplaEstado *excluir = malloc(sizeof(ListaDuplaEstado));
	if (posicao == 0)
	{
		excluir = *lista;
		if(tamanho(*lista) > 1)
		{
			*lista = (*lista)->proximo;
			(*lista)->anterior = NULL;
		}
		free(excluir);
		return 0;
	}
	ListaDuplaEstado *iterador = *lista;
	int cont = 0;
	while(cont < posicao)
	{
		iterador = iterador->proximo;
		cont++;
	}

	if (posicao == tamanho(*lista) - 1)
	{
		excluir = iterador;
		(iterador->anterior)->proximo = NULL;
		free(excluir);
		return 0;
	}
	else
	{ 
		excluir = iterador;
		(iterador->proximo)->anterior = iterador->anterior;
		(iterador->anterior)->proximo = iterador->proximo;
		free(excluir);
		return 0;
	}
}

/**
 * Retorna a posição da primeira ocorrência na lista de um valor
 * @param lista Lista
 * @param valor Valor a ser buscado na lista
 * @return Posição do valor. Caso não haja ocorrências, retorna -1
 */
int indexOf(ListaDuplaEstado *lista, int mat[4][4])
{
	if (lista == NULL)
		return -1;

	int pos = -1, cont = 0;
	while (lista != NULL && pos == -1)
	{
		if (comparaMatrizes(mat, lista) == 0);
			pos = cont;

		lista = lista->proximo;
		cont++;
	}

    return pos;
}

/**
 * Remove o  primeiro elemento contido na lista cujo valor
 * é o valor pedido
 * @param lista Lista
 * @param posicao Valor a ser excluído
 * @return Sucesso da operação
 */
int removeEstado(ListaDuplaEstado **lista, int mat[4][4])
{
	return removePos(&(*lista), indexOf(*lista, mat));
}

/**
 * Adiciona um valor na lista em uma posição específica
 * @param lista Lista
 * @param valor Valor a ser inserido
 * @param posicao Posição a ser inserida
 * @return Sucesso da operação
 */
int addPos(ListaDuplaEstado **lista, int matriz[4][4], int posicao)
{
	ListaDuplaEstado *novo = malloc(sizeof(ListaDuplaEstado));
	novo->anterior = NULL;
	novo->proximo = NULL;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			novo->estado[i][j] = matriz[i][j];

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	if (posicao == 0)
	{
		(*lista)->anterior = novo;
		novo->proximo = *lista;
		*lista = novo;
		return 0;
	}

	ListaDuplaEstado *iterador = *lista;
	int cont = 0;
	while (cont < posicao && iterador->proximo != NULL)
	{
		iterador = iterador->proximo;
		cont++;
	}
	
	if (posicao >= tamanho(*lista))
	{
		iterador->proximo = novo;
		novo->anterior = iterador;
		return 0;
	}
	else
	{
		novo->anterior = iterador->anterior;
		novo->proximo = iterador;
		iterador->anterior->proximo = novo;
		iterador->anterior = novo;

		return 0;
	}

}

/*retorna 0 se a matriz eh contida na lista ou -1 se nao*/
int comparaMatrizes(int mat[4][4], ListaDuplaEstado *lista)
{
	if (lista == NULL)
		return -1;

	int igual = -1;
	int i, j;
	while (lista != NULL && igual == -1)
	{
		igual = 0;
		for (i = 0; i < 4 && igual == 0; i++)
		{
			for (j = 0; j < 4 && igual == 0; j++)
			{
				if (mat[i][j] != lista->estado[i][j])
					igual = -1;
			}
		}
		lista = lista->proximo;
	}
	return igual;
}

int getPos(int mat[4][4], ListaDuplaEstado *lista, int posicao)
{
	if (lista == NULL || posicao >= tamanho(lista))
		return -1;

	int cont = 0;
	while (cont != posicao)
	{
		lista = lista->proximo;
		cont++;
	}
		
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			mat[i][j] = lista->estado[i][j];

	return 0;
}