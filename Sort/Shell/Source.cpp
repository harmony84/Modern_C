#include <iostream>

#pragma region "Shell Sort"  
// compare count = N*(N-1)/2
// swap count = N   
// shell sort = O(N2)
void ShellSort( char* target, size_t count )
{
	for ( size_t col = static_cast< size_t >( count * 0.5f ); col > 0; col = static_cast< size_t >( col * 0.5f ) )
	{
		for ( size_t row = 0; row < col; ++row )
		{
			for ( size_t i = col; i < count - col; i += col )
			{
				for ( size_t j = i; j > 0; j -= col )
				{
					if ( target[ j - col ] > target[ j ] )
					{
						char temp = target[ j - col ];
						target[ j - col ] = target[ j ];
						target[ j ] = temp;
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
	ShellSort( word, strlen( word ) );

	printf( "%s\n", word );
#pragma endregion
	return 0;
}