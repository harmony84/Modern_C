#include <iostream>

#pragma region "Shell Sort"  
// Shell Sort = N*(N-1)/2
// 삽입정렬이 거의 정렬된 배열에서 최적의 성능을 내는 것에서 착안한 정렬 방법
// 간격을 잘 선택하는 경우 O(n.125) 까지도 가능하다고 한다. 시간 복잡도가 명확하지 않고  퀵, 병합 정렬에 비해 크게 좋을 것은 없음
void ShellSort( char* target, size_t count )
{
	for ( size_t col = count >> 1; col > 0; col = col >> 1 )
	{
		for ( size_t row = 0; row < col; ++row )
		{
			for ( size_t i = 0; i < count - col; i += col )
			{
				for ( size_t j = i + col; j > 0; j -= col )
				{
					if ( target[ j - col ] > target[ j ] )
					{
						char temp = target[ j ];
						target[ j ] = target[ j - col ];
						target[ j - col ] = temp;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}
#pragma endregion


int main()
{
#pragma region "Shell Sort"
	char word[] = { "TOLEARNSORTALGORITHMK" };

	printf( "%s\n", word );

	ShellSort( word, strlen( word ) );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}