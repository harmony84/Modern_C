#include <iostream>

#pragma region "Bubble Sort"  
// Bubble sort = O(N^2)
// 거의 모든 상황에서 최악의 성능을 보여준다.  간단한 로직
void BubbleSort( char* target, size_t count )
{
	for ( size_t i = 0; i < count - 1; ++i )
	{
		for ( size_t j = 1; j < count - i; ++j )
		{
			if ( target[ j - 1 ] > target[ j ] )
			{
				char temp = target[ j ];
				target[ j ] = target[ j - 1 ];
				target[ j - 1 ] = temp;
			}
		}
	}
}
#pragma endregion


int main()
{
#pragma region "Bubble Sort"
	char word[] = { "TOLEARNSORTALGORITHMK" };

	printf( "%s\n", word );

	BubbleSort( word, strlen( word ) );
	
	printf( "%s\n", word );
#pragma endregion
	return 0;
}