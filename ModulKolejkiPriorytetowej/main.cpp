#include "PQueue.h"
#include <time.h>

int main()
{
	srand( ( unsigned int )time( NULL ) );
	//kolejka na 11
	PQueue* pQueue = PQInit( 11 );
	//wygeneruj przynajmniej dziesiêæ elementów od 1 do 40
	for ( int i = 0; i < 10; i++ )
	{
		int nPrior = rand() % 15 + 1;
		int nKey = rand() % 40 + 1;
		PQEnqueue( pQueue, nKey, nPrior );
		printf( "%d\t%d\n", nPrior, nKey );
	}
	
	PQPrint( pQueue );
	printf( "\n\n" );
	
	//raz dequeue

	printf( "\n%d\n", PQDequeueu( pQueue ) );
	PQPrint( pQueue );
	printf( "\n\n" );
	//dwa enqueue
	for ( int i = 0; i < 2; i++ )
	{
		int nPrior = rand() % 15 + 1;
		int nKey = rand() % 40 + 1;
		PQEnqueue( pQueue, nKey, nPrior );
		printf( "%d\t%d\n", nPrior, nKey );
	}
	PQPrint( pQueue );
	printf( "\n\n" );
	//raz dequeue
	printf( "\n%d\n", PQDequeueu( pQueue ) );
	PQPrint( pQueue );
	printf( "\n\n" );
	//dwa enqueue //error powinien wyskoczyæ
	for ( int i = 0; i < 2; i++ )
	{
		int nPrior = rand() % 15 + 1;
		int nKey = rand() % 40 + 1;
		PQEnqueue( pQueue, nKey, nPrior );
		printf( "%d\t%d\n", nPrior, nKey );
	}
	PQPrint( pQueue );
	printf( "\n\n" );
	while ( !PQIsEmpty( pQueue ) )
	{
		printf( "\n%d\n", PQDequeueu( pQueue ) );
		PQPrint( pQueue );
	}
	return 0;
}