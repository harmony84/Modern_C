#include <iostream>

#pragma region "Selection Sort"  
// compare count = N2/2
// swap count = N   
// selection sort = O(N2)
void SelectionSort(char* target, size_t count, bool order)
{
	for ( size_t i = 0; i < count - 1; ++i )
	{
		int target_value = target[ i ];
		int target_index = i;

		for ( size_t j = i + 1; j < count; ++j )
		{
			if (order == true )
			{
				if ( target_value > target[ j ] )
				{
					target_value = target[ j ];
					target_index = j;
				}
			}
			else
			{
				if ( target_value < target[ j ] )
				{
					target_value = target[ j ];
					target_index = j;
				}
			}
		}

		target[ target_index ] = target[ i ];
		target[i] = target_value;
	}
}
#pragma endregion


int main()
{
#pragma region "Selection Sort"
	char word[] = { "TOLEARNSORTALGORITHM" };
	SelectionSort( word, strlen(word), true );
#pragma endregion
	return 0;
}