#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <string>


using FilterContainer = std::vector<std::function<bool(int)>>;

FilterContainer filters;

class Widget
{
public:
	bool isValuidated() const { return true; }
	bool isProcessed() const { return true; }
	bool isArchived() const { return true; }

	void addFilter() const
	{
		filters.emplace_back(
			[divisor=divisor]( int value ) { return value % divisor == 0; } );		// same this->division
	}

private:
	int divisor{5};
	std::string str{ "Widget" };
};

class IsValAndArch 
{
public:
	using DataType = std::unique_ptr<Widget>;
	explicit IsValAndArch(DataType&& ptr) : pw(std::move(ptr)) { }

	bool operator()() const { return pw->isValuidated() && pw->isArchived(); }

private:
	DataType pw;
};

#pragma region "by reference"
void addDivisorFilter(int calc)
{
	auto divisor = calc;
	filters.emplace_back(
		[ & ]( int value ) { return value % divisor == 0; } );
}
#pragma endregion

#pragma region "wrong lambda code"
void doSomeWork()
{
	auto pw = std::make_unique<Widget>();
	pw->addFilter();
}
#pragma endregion



int main()
{
	int x = {10};
	auto c1 = [ x ]( int y ) {return x * y > 55; };

	doSomeWork();
	auto output = filters[0](15);

#pragma region "C+ 11 Version"
	auto func_11 = std::bind(
		[]( const std::unique_ptr<Widget>& pw )
	{ return pw->isValuidated() && pw->isArchived(); }
	, std::make_unique<Widget>() );
#pragma endregion

#pragma region "C+ 14 Version"
	auto func_14 = [ pw = std::make_unique<Widget>() ]
	{
		return pw->isValuidated() && pw->isArchived();
	};
#pragma endregion

	// alternative lambda 
	std::unique_ptr<Widget> pw = std::make_unique<Widget>();
	auto func = IsValAndArch( std::move(pw) );

#pragma region "decltype"
	auto decl_func = []( auto&& x )
	{
		return std::forward<decltype( x )>( x );
	};

	auto val = decl_func(std::move( std::string( "aaaa" )));
#pragma endregion


	return 0;
}