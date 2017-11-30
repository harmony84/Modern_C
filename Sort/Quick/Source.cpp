#include <iostream>
#include <memory>

#pragma region "Quick Sort"  
// quick sort = O(N log n),  worst = N^2
void QuickSort( char* target, size_t left_index, size_t right_index )
{
	char pivot = target[ static_cast< size_t >( ( left_index + right_index ) * 0.5f ) ];
	size_t left = left_index;
	size_t right = right_index;

	while ( left <= right )
	{
		while ( target[ left ] < pivot )
		{
			++left;
		}

		while ( target[ right ] > pivot )
		{
			--right;
		}

		if ( left <= right )
		{
			char temp = target[ left ];
			target[ left ] = target[ right ];
			target[ right ] = temp;

			++left;
			--right;
		}
	}

	if ( left_index < right )
	{
		QuickSort( target, left_index, right );
	}

	if ( right_index > left )
	{
		QuickSort( target, left, right_index );
	}
}
#pragma endregion


int main()
{
#pragma region "Quick Sort"
	//char word[] = { "TOLEARNSORTALGORITHMK" };
	char word[] = { "51423" };
	QuickSort( word, 0, strlen( word ) - 1 );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}