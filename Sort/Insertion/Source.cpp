#include <iostream>
#include <memory>

#pragma region "Insertion Sort"  
// Insertion sort = O(N^2)
// n^2중에서는 빠른 편이나 자료 구조에 따라서 뒤로 밀어내는데 걸리는 시간이 큼
// 이미 정렬되어 있는 자료구조에 자료를 하나씩 삽입/제거 하는 경우에는 좋다. (탐색을 제외한 오버헤드가 매우 적기 때문에)
void InsertionSort( char* target, size_t count )
{
	for ( size_t i = 0; i < count - 1; ++i )
	{
		for ( size_t j = i + 1; j > 0; --j )
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

	printf( "%s\n", word );

	InsertionSort( word, strlen(word) );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}