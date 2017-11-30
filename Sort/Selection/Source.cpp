#include <iostream>

#pragma region "Selection Sort"  
// compare count = N2/2
// swap count = N   
// selection sort = O(N2)
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
	char word[] = { "TOLEARNSORTALGORITHM" };
	SelectionSort( word, strlen( word ) );
	printf( "%s\n", word );
#pragma endregion
	return 0;
}