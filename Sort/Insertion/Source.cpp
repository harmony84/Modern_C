#include <iostream>
#include <memory>

#pragma region "Insertion Sort"  
// compare = a little
// insert = a lot of
 // insertion sort = O(N^2)
void InsertionSort( char* target, size_t count )
{
	for ( size_t i = 1; i < count; ++i )
	{
		for (size_t j = i; j > 0; --j)
		{
			if ( target[ j - 1 ] > target[ j ] )
			{
				char temp = target[ j - 1 ];
				target[ j - 1 ] = target[ j ];
				target[ j ] = temp;
			}
			else
			{
				break;
			}
		}
	}
}
#pragma endregion


int main()
{
#pragma region "Insertion Sort"
	char word[] = { "TOLEARNSORTALGORITHMK" };
	InsertionSort( word, strlen(word) );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}