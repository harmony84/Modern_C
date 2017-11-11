#include <iostream>
#include <memory>

#pragma region "Insertion Sort"  
// compare = a little
// insert = a lot of
 //insertion sort = O(N2)
void InsertionSort( char target[], size_t count, bool order )
{
	for ( size_t i = 1; i < count; ++i )
	{
		int target_value = target[ i ];
		size_t j = i;

		if ( order == true )
		{
			while ( target[ j - 1 ] > target_value && j > 0 )
			{
				target[ j ] = target[ j - 1 ];
				--j;
			}
		}
		else
		{
			while ( target[ j - 1 ] < target_value && j > 0 )
			{
				target[ j ] = target[ j - 1 ];
				--j;
			}
		}

		target[ j ] = target_value;
	}
}

void IndirectInsertionSort( char target[], std::unique_ptr<int[]>& index, size_t count, bool order)
{
	for ( size_t i = 0; i < count; ++i )
	{
		index[ i ] = i;
	}

	for ( size_t i = 1; i< count; ++i)
	{
		int target_value = index[ i ];
		size_t j = i;

		while ( j > 0 && target[ index[ j - 1 ] ] > target[ target_value ] )
		{
			index[ j ] = index[ j - 1 ];
			--j;
		}

		index[ j ] = target_value;
	}
}
#pragma endregion


int main()
{
#pragma region "Insertion Sort"
	char word[] = { "TOLEARNSORTALGORITHM" };
	size_t count = strlen( word );
	//InsertionSort( std::add_lvalue_reference_t<char[]>( word ), count, true );

	// indirect sort (integer index sort)
	std::unique_ptr<int[]> word_index = std::make_unique<int[]>( count );
	IndirectInsertionSort( std::add_lvalue_reference_t<char[]>( word ), word_index, count, true );

	for ( size_t i = 0; i < count; ++i )
	{
		std::cout << word_index[ i ] << " ";
	}

	std::cout << std::endl;

	for ( size_t i = 0; i < count; ++i )
	{
		std::cout << word[ word_index[ i ] ];
	}

	std::cout << std::endl;

#pragma endregion
	return 0;
}