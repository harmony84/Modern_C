#include <memory>
#include <string>
#include <set>

class Widget
{
public:
	Widget( const std::string& str ) : s( str ) { }
	Widget( Widget&& rhs )
		: s( std::move( rhs.s ) )
		//: s( std::forward<std::string>( rhs.s ) )		// Invalid
	{
		++moveCtorCalls;
	}  

	template<typename T>
	void setName(T&& newName) 
	{
		s = std::forward(newName);
	}

private:
	static std::size_t moveCtorCalls;
	std::string s;
};

std::size_t Widget::moveCtorCalls = 0;


std::string nameFromIdx( int idx )
{
	switch ( idx )
	{
	case 0: return "A";
		break;
	case 1: return "B";
		break;
	case 2: return "C";
		break;
	};

	return "F";
}

#pragma region "limit template"
class Person
{
public:
	//explicit Person(std::string n)	 : name(n) { }  // copy by value
	
	template<typename T, typename = std::enable_if_t<
		//!std::is_same<Person, std::decay_t<T>>::value>>			// invalid inherit
		!std::is_base_of<Person, std::decay_t<T>>::value
		&& !std::is_integral<std::remove_reference_t<T>>::value 
		>>
	explicit Person( T&& n ) : name( std::forward<T>( n ) ) {}

	explicit Person( int idx ) : name( nameFromIdx( idx ) ) {}

	Person(const Person& rhs) { printf ("Person copy construct\n"); }
	Person( Person&& rhs ) { printf( "Person move construct\n" ); }

private:
	std::string name;
};

class SpecialPerson : public Person
{
public:
	SpecialPerson( const SpecialPerson& rhs ) : Person( rhs ) { printf( "SpecialPerson copy construct" ); }
	SpecialPerson( SpecialPerson&& rhs ) : Person( std::move( rhs ) ) { printf( "SpecialPerson move construct" ); }
};
#pragma endregion

void process( const Widget& lvalArg )
{
	printf( "Called function Lvalue process\n" );
}

void process( Widget&& rvalArg )
{
	printf( "Called function Rvalue process\n" );
}




#pragma region "exam - should not use universal reference to overoding"
template<typename T>
void logAndProcess( T&& param )
{
	process( std::forward<T>( param ) );
}

// exam : it's wrong overoding 
void logAndProcess( int idx )
{
	process( nameFromIdx( idx ) );
}
#pragma endregion


#pragma region "tag dispatcher"
std::multiset<std::string> names;

template<typename T> void logAndAdd( T&& name );

void logAndAddImpl( int idx, std::true_type )
{
	logAndAdd( nameFromIdx(idx) );
}

template<typename T>
void logAndAddImpl( T&& name, std::false_type )
{
	names.emplace( std::forward<T>( name ) );
}

template<typename T>
void logAndAdd( T&& name )
{
	logAndAddImpl( 
		std::forward<T>( name )
		, std::is_integral <std::remove_reference_t<T>>() );
}
#pragma endregion

int main()
{
	Widget w1( "hello" );

	logAndProcess( w1 ); 
	logAndProcess( std::move( w1 ) );

	//Widget w2( std::move( w1 ) );

	int n {10};
	int&& Rref = std::move(n);

	int nameIdx_1 {2};
	logAndProcess( nameIdx_1 );

	//short nameIdx_2;
	//logAndProcess( nameIdx_2 );		// Error : agree > promotion  ( called function logAndProcess( T&& param ) )



	// tag dispatch
	std::string tagdispatch = "TagDispatch_1";
	logAndAdd( tagdispatch );
	logAndAdd( std::string( "TagDispatch_2" ) );
	logAndAdd( "TagDispatch_3" );
	logAndAdd( 3 );		// overoding

	// limit template
	Person p1( "Nancy" );
	auto cloneOfP( p1 );
	Person p2(5);			// overoding

	return 0;
}