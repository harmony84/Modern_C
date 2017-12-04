#include <iostream>
#include <memory>

#pragma region "Merge Sort"  
// Merge sort = O(N log n)
// 전반적으로 퀵 소트보다 뒤떨어지고 데이터 크기만한 메모리가 더 필요하다.
// 장점 : 데이터의 상태에 별 영향을 받지 않고 안정화 정렬임
void Merge( char* target, size_t first, size_t mid, size_t last )
{
	size_t front_index = first;
	size_t back_index = mid + 1;

	size_t index = first;

	//auto merge_array = std::make_unique<char[]>(last+2);
	char* merge_array = new char[last+2]{};

	while ( front_index <= mid && back_index <= last )
	{
		if ( target[ front_index ] <= target[ back_index ] )
		{
			merge_array[ index ] = target[ front_index++ ];
			//printf( "1_1\t%d\t%d\t%d\t%s\t%s\n", front_index, back_index, index, merge_array, target );
		}
		else
		{
			merge_array[ index ] = target[ back_index++ ];
			//printf( "1_2\t%d\t%d\t%d\t%s\t%s\n", front_index, back_index, index, merge_array, target );
		}

		++index;
	}

	if ( front_index > mid )
	{
		for ( size_t i = back_index; i <= last; ++i, ++index )
		{
			merge_array[ index ] = target[ i ];
			//printf( "2_1\t%d\t%d\t%d\t%s\t%s\n", front_index, back_index, index, merge_array, target );
		}
	}
	else
	{
		for ( size_t i = front_index; i <= mid; ++i, ++index )
		{
			merge_array[ index ] = target[ i ];
			//printf( "2_2\t%d\t%d\t%d\t%s\t%s\n", front_index, back_index, index, merge_array, target );
		}
	}

	for ( size_t i = first; i <= last; ++i )
	{
		target[ i ] = merge_array[ i ];
	}
	
	delete [] merge_array;
}

void MergeSort( char* target, size_t first, size_t last )
{
	if ( first < last )
	{
		size_t middle = static_cast< size_t >( ( first + last ) * 0.5f );

		MergeSort( target, first, middle );
		MergeSort( target, middle+1, last );

		Merge( target, first, middle, last );
	}
}

#pragma endregion


int main()
{
#pragma region "Merge Sort"
	char word[] = { "TOLEARNSORTALGORITHMK" };
	//char word[] = { "51423" };
	MergeSort( word, 0, strlen( word ) - 1 );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}