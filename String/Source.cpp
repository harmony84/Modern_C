#include <iostream>

void ReverseString( char* s )
{
	size_t size = strlen( s );
	char temp;

	for ( size_t i = 0; i < static_cast< size_t >( size * 0.5f ); ++i )
	{
		temp = s[ i ];
		size_t target = ( size - 1 ) - i;
		s[ i ] = s[ target ];
		s[ target ] = temp;
	}
}

size_t GetStrlength( char* s )
{
	for ( size_t i = 0; i < BUFSIZ; ++i )
	{
		if ( s[ i ] == '\0' ) return i;
	}

	return -1;
}

char* CustomStrcat( char* buf, char* str )
{
	if ( buf == nullptr || str == nullptr )
	{
		return nullptr;
	}

	size_t source_length = GetStrlength( buf );
	size_t target_length = GetStrlength( str );

	for ( size_t index = 0; index<target_length; ++index)
	{
		buf[ source_length + index ] = str[ index ];
	}
	
	return buf;
}

char* StrtokToSpace( char* s, char** context )
{
	if ( s == nullptr )
	{
		return nullptr;
	}

	size_t length = GetStrlength( s ) + 1;

	if ( length <= 1 )
	{
		return nullptr;
	}

	for ( size_t i = 0; i < length; ++i )
	{
		if ( s[ i ] == ' ' )
		{
			*context = &s[ i + 1 ];
			s[ i ] = '\0';
			return s;
		}
		else if ( s[ i ] == '\0' )
		{
			*context = nullptr;
			s[ i ] = '\0';
			return s;
		}
	}

	return nullptr;
}


char* ReverseStringToWord( char* s )
{
	// case 1
	//char* word;
	//char* dummy = nullptr;
	//char buf[ BUFSIZ ] = {};

	//word = strtok_s( s, " ", &dummy );

	//while ( word != nullptr )
	//{
	//	ReverseString( word );
	//	strcat_s( buf, BUFSIZ, word );
	//	strcat_s( buf, BUFSIZ, " " );
	//	word = strtok_s( NULL, " ", &dummy );
	//}

	// case 2
	char* word;
	char* dummy = nullptr;
	char buf[ BUFSIZ ] = {};

	word = StrtokToSpace( s, &dummy );

	while ( word != nullptr )
	{
		ReverseString( word );
		buf = CustomStrcat( buf, word );
		buf = CustomStrcat( buf, " " );
		word = StrtokToSpace( dummy, &dummy );
	}

	return buf;
}


int main()
{
	char message[] = { "Have a nice day" };
	//char* message = { "Have a nice day" };

	int size = GetStrlength( message );
	auto compute_str = ReverseStringToWord( message );

	//ReverseString(message);

	//size_t message_length_count = strlen(message);

	//for ( size_t source = 0; source < message_length_count-1; ++source )
	//{
	//	for ( size_t target = 1; target < message_length_count; ++target )
	//	{
	//	}
	//}	

	std::cout << std::endl;

	//for ( const char* c : message )
	//{
	//	std::cout << &c;
	//}

	return 0;
}