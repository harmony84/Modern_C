#include <iostream>

#pragma region "Bubble Sort"  
// compare count = N*(N-1)/2
// swap count = N   
// bubble sort = O(N2)
void BubbleSort( char* target, size_t count )
{
	for ( size_t i = 0; i < count; ++i )
	{
		for ( size_t j = 0; j < count - 1; ++j )
		{
			if ( target[ j ] > target[ j + 1 ] )
			{
				char temp = target[ j ];
				target[ j ] = target[ j + 1 ];
				target[ j + 1 ] = temp;
			}
		}
	}
}
#pragma endregion


int main()
{
#pragma region "Bubble Sort"
	char word[] = { "TOLEARNSORTALGORITHM" };
	BubbleSort( word, strlen( word ) );
	
	printf( "%s\n", word );
#pragma endregion
	return 0;
}