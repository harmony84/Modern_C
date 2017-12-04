#include <iostream>

#pragma region "Selection Sort"  
// Selection sort = O(N^2)
// 어떻게 정렬이 되어 있든 일관성 있게 n(n-1)/2에 비례하는 시간이 걸린다. 버블보다 두 배 정도 빠름

void SelectionSort( char* target, size_t count )
{
	for ( size_t i = 0; i < count - 1; ++i )
	{
		for ( size_t j = i + 1; j < count; ++j )
		{
			if ( target[ i ] > target[ j ] )
			{
				char temp = target[ i ];
				target[ i ] = target[ j ];
				target[ j ] = temp;
			}
		}
	}
}
#pragma endregion


int main()
{
#pragma region "Selection Sort"
	char word[] = { "TOLEARNSORTALGORITHMK" };
	printf( "%s\n", word );

	SelectionSort( word, strlen( word ) );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}