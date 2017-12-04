#include <iostream>

size_t GetLength(char* target)
{
	size_t index = 0;

	while ( target[index] != '\0' )
	{
		if ( index >= BUFSIZ )
		{
			return -1;
		}

		index++;
	}

	return index;
}

int My_Strcmp(char* src, char* dest)
{
	if ( src == nullptr || dest == nullptr )
	{
		return -1;
	}

	while(1)
	{
		if ( *src == '\0' && *dest == '\0' )
		{
			break;
		}
		else if ( *src > *dest )
		{
			return 1;
		}
		else if ( *src < *dest )
		{
			return -1;
		}

		*src++;
		*dest++;
	}
	
	return 0;
}

void ReverseString( char* str, size_t begin_index, size_t end_index )
{
	if ( str == nullptr )
	{
		return;
	}

	size_t loop_count = (end_index - begin_index) >> 1;
	size_t string_count = end_index - 1;

	for ( size_t index = 0; index < loop_count; ++index )
	{
		char temp = str[ begin_index + index ];
		str[ begin_index + index ] = str[ string_count ];
		str[ string_count ] = temp;
		string_count--;
	}
}

void ReverseWord( char* str )
{
	size_t begin_index = 0;
	size_t index = 0;

	while ( 1 )
	{
		if ( str[ index ] == '\0' )
		{
			return;
		}

		if ( str[ index ] == ' ' )
		{
			ReverseString( str, begin_index, index );
			begin_index = index + 1;
		}

		index++;
	}
}

int main()
{
	char str_1[] = "abc";
	char str_2[] = "cbc";
	char str_3[] = "abcde";
	char str_4[] = "abc";

	std::cout << My_Strcmp( str_1, str_4 ) << std::endl;
	std::cout << My_Strcmp( str_1, str_2 ) << std::endl;
	std::cout << My_Strcmp( str_2, str_1 ) << std::endl;
	std::cout << My_Strcmp( str_3, str_1 ) << std::endl;

	char org_str[] = "do or do not. there is no try";
	std::cout << org_str << std::endl;

	ReverseString( org_str, 0, GetLength(org_str) );
	std::cout << org_str << std::endl;

	ReverseWord( org_str );
	std::cout << org_str << std::endl;

	return 0;
}