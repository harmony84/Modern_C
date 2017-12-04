#include <iostream>
#include <memory>

#pragma region "Quick Sort"  
// Quick sort = O(N log n),  worst = N^2
// 평균적인 상황에서 최고의 성능을 보여줌
// 기준을 잡고 작은것을 앞으로 큰것을 뒤로 빼는 방식 피벗을 잘못 잡을 경우 n^2의 속도까지 나오게 된다.

void QuickSort( char* target, size_t left_index, size_t right_index )
{
	char pivot = target[ ( left_index + right_index ) >> 1 ];

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
	char word[] = { "TOLEARNSORTALGORITHMK" };
	
	printf( "%s\n", word );

	QuickSort( word, 0, strlen( word ) - 1 );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}