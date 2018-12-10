#pragma once
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

typedef struct
{
	int nKey;
	int nPrior;
} PQItem;

typedef struct
{
	PQItem* pQueueArray; //kolejka realizowana w postaci stogu
	int PQSize; // rozmiar kolejki priorytetowej
	int PQCurrSize; //ilo�� element�w w kolejce
} PQueue;

PQueue* PQInit( int nSize );
int		PQIsEmpty( PQueue* pQueue );
void	PQEnqueue( PQueue* pQueue, int nKey, int nPrior );
int		PQDequeueu( PQueue* pQueue );
void	PQClearQueue( PQueue* pQueue );
void	PQRelease( PQueue** pQueue ); //zwalnia pami�� we/wy NULL
void	PQPrint( PQueue* pQueue ); // inorder

void UpdateDown( PQueue* pQueue, int l, int p );
void UpdateUp( PQueue* pQueue, int l, int p );

//dodatkowe //potem usun��
void	DecreaseKey( PQueue* pQueue, int nKey, int nPrior );
void	IncreaseKey( PQueue* pQueue, int nKey, int nPrior );