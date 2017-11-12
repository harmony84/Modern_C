#include <iostream>

#pragma region "Bubble Sort"  
// compare count = N*(N-1)/2
// swap count = N   
// bubble sort = O(N2)
void BubbleSort( char* target, size_t count, bool order )
{
	for ( size_t i = 0; i < count - 1; ++i )
	{
		int target_value{ 0 };

		for ( size_t j = 1; j < count - 1; ++j )
		{
			if ( target[ j - 1 ] > target[ j ] )
			{
				target_value = target[ j - 1 ];
				target[ j - 1 ] = target[ j ];
				target[ j ] = target_value;
			}
		}
	}
}

// performance up
void BubbleSort2( char* target, size_t count, bool order )
{
	for ( size_t i = 0; i < count - 1; ++i )
	{
		int target_value{ 0 };
		bool sort = true;

		for ( size_t j = 1; j < count - 1; ++j )
		{
			if ( target[ j - 1 ] > target[ j ] )
			{
				target_value = target[ j - 1 ];
				target[ j - 1 ] = target[ j ];
				target[ j ] = target_value;
				sort = false;
			}
		}

		if ( sort == true )
		{
			break;
		}
	}
}
#pragma endregion


int main()
{
#pragma region "Bubble Sort"
	char word[] = { "TOLEARNSORTALGORITHM" };
	//BubbleSort( word, strlen( word ), true );
	BubbleSort2( word, strlen( word ), true );
#pragma endregion
	return 0;
}